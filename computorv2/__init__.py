
COMPUTORV2_SUCCESS          = (0 << 0)
COMPUTORV2_ERROR            = (1 << 0)

ERROR_NOT_ENOUGH_MEMORY     = (1 << 0)
ERROR_NAN                   = (1 << 1)

STATMENT_TYPE_GET           = (1 << 0)
STATMENT_TYPE_SET           = (1 << 1)
STATMENT_TYPE_SOLVE         = (1 << 2)

COMPUTORV2_OPERATION_ADD    = (1 << 0)
COMPUTORV2_OPERATION_SUB    = (1 << 1)
COMPUTORV2_OPERATION_MULT   = (1 << 2)
COMPUTORV2_OPERATION_DIV    = (1 << 3)
COMPUTORV2_OPERATION_EXP    = (1 << 4)

COMPUTORV2_TYPE_INTEGER     = (1 << 0)
COMPUTORV2_TYPE_RATIONAL    = (1 << 1)
COMPUTORV2_TYPE_VECTOR      = (1 << 2)
COMPUTORV2_TYPE_MATRIX      = (1 << 3)
COMPUTORV2_TYPE_COMPLEX     = (1 << 4)

def is_vector(obj):
	if not obj:
		return (False)
	return (obj.type() == COMPUTORV2_TYPE_VECTOR)

def ISINTEGER(obj):
	if not obj:
		return (False)
	return (obj.type() == COMPUTORV2_TYPE_INTEGER)

def ISCOMPLEX(obj):
	if not obj:
		return (False)
	return (obj.type() == COMPUTORV2_TYPE_COMPLEX)

def ISVECTOR(obj):
	if not obj:
		return (False)
	return (obj.type() == COMPUTORV2_TYPE_VECTOR)

def is_digit(c):
	try:
		return (ord('0') <= ord(c) <= ord('9'))
	except:
		pass
	return (False)

def is_var_start(c):
	return (c.lower() in "_abcdefghijklmnopqrstuvwxyz")

def is_var_char(c):
	return (is_digit(c) or is_var_start(c))

class Computorv2Object:

	def __init__(self):
		pass

class Statment:
	def __init__(self):
		self.pos           = 0
		self.str           = None
		self.len           = 0
		self.err           = 0
		self.operation     = 0
		self.result        = None
		self.function_name = None
		self.variable_name = None
		self.vm            = None

	def get_str(self):
		return (self.str)

	def set_pos(self, p):
		self.pos = p
	def set_str(self, s):
		self.str = s
	def set_len(self, l):
		self.len = l

	def skip_spaces(self):
		while ((st.pos < st.len) and st.str[st.pos].isspace()):
			st.pos += 1
		return (COMPUTORV2_SUCCESS)

	def getc(self):
		if (st.pos < st.len):
			return (st.str[st.pos])
		return (None)

	def next(self):
		if (self.pos < self.len):
			self.pos += 1
		if (self.str) and (self.pos < self.len):
			return (self.str[self.pos])
		return (0)

	def get_operation_code(self):
		self.skip_spaces()
		c = self.getc()
		z = self.next()
		if (c == "+"):
			return (COMPUTORV2_OPERATION_ADD)
		if (c == "-"):
			return (COMPUTORV2_OPERATION_SUB)
		if (c == "*"):
			return (COMPUTORV2_OPERATION_MULT)
		if (c == "/"):
			return (COMPUTORV2_OPERATION_DIV)
		if (c == "^"):
			return (COMPUTORV2_OPERATION_EXP)
		print ("operation_code ======> " + c + "\n", c)
		return (0);

class Computorv2Integer:

	def __init__(self, value):
		self.value = int(value)

	def toString(self):
		return (str(self.value))

	def toInteger(self):
		return (self.value)

	def type(self):
		return (COMPUTORV2_TYPE_INTEGER)

class Computorv2Rational:

	def __init__(self, value):
		self.value = float(value)

	def type(self):
		return (COMPUTORV2_TYPE_RATIONAL)

class Computorv2Complex:

	def __init__(self, value = 1):
		self.value = value

	def type(self):
		return (COMPUTORV2_TYPE_COMPLEX)

	def toString(self):
		if (self.value == 1):
			return ("i")
		if (self.value == -1):
			return ("-i")
		return (str(self.value) + "i")

class Computorv2Vector:

	def __init__(self, elements = None):
		self.elements = elements
		if not self.elements:
			self.elements = []

	def multiply(self, scalar):
		i = 0
		while (i < self.size()):
			self.elements[i] *= scalar
			i += 1
		return (self)

	def add(self, element):
		self.elements.append(element)

	def size(self):
		return (len(self.elements))

	def toString(self):
		s = "["
		i = 0
		l = self.size()
		while (i < l - 1):
			s += " " + self.elements[i].toString() + " ,"
			i += 1
		s += " " + self.elements[i].toString() + " ]"
		return (s)

	def type(self):
		return (COMPUTORV2_TYPE_VECTOR)

class Computorv2Matrix:

	def __init__(self, elements = None):
		self.elements = elements
		if not self.elements:
			self.elements = []

	def add(self, element):
		self.elements.append(element)

	def size(self):
		return (len(self.elements))

	def type(self):
		return (COMPUTORV2_TYPE_MATRIX)

	def toString(self):
		s = ""
		for v in self.elements:
			s += v.toString() + "\n"
		return (s.strip())

class Computorv2:
	def __init__(self):
		pass

	def parse_number(self, st):
		c = st.getc()
		if not (is_digit(c)):
			st.result = None
			return (1)
		r = ""
		while (is_digit(c)):
			r = r + c
			c = st.next()
		name = ""
		while (is_var_char(st.getc())):
			name += st.getc()
			st.next()
		if (name == "i"):
			st.result = Computorv2Complex(int(r, 10))
			return (0)
		if (c != "."):
			st.result = Computorv2Integer(int(r, 10))
			return (0)
		r += "."
		c = st.next()
		while (is_digit(c)):
			r = r + c
			c = st.next()
		name = ""
		while (is_var_char(st.getc())):
			name += st.getc()
			st.next()
		if (name == "i"):
			st.result = Computorv2Complex(float(r))
			return (0)
		st.result = Computorv2Rational(float(r))
		return (0)

	def parse_matrix(self, st):
		c = st.getc()
		if (c != '['):
			st.result = None
			return (1)
		c = st.next()
		st.skip_spaces()
		if (c != '['):
			v = Computorv2Vector()
			while (1):
				st.skip_spaces()
				self.parse_object(st)
				st.skip_spaces()
				v.add(st.result)
				if (st.getc() != ','):
					break
				c = st.next()

			if (st.getc() != ']'):
				st.result = None
				return (1)
			st.next()
			st.result = v
			return (0)
		m = Computorv2Matrix()
		while (1):
			st.skip_spaces()
			self.parse_object(st)
			st.skip_spaces()
			if not is_vector(st.result):
				st.result = None
				return (1)
			m.add(st.result)
			if (st.getc() != ';'):
				break
			c = st.next()
		if (st.getc() != ']'):
			st.result = None
			return (1)
		st.next()
		st.result = m
		return (0)

	def parse_variable(self, st):
		name = ""
		while (is_var_char(st.getc())):
			name += st.getc()
			st.next()
		if (name == "i"):
			st.result = Computorv2Complex()
			return (0)
		raise

	def parse_object(self, st):
		st.operation = 0
		st.result    = None
		st.skip_spaces()
		c = st.getc()
		if (is_var_start(c)):
			st.err = self.parse_variable(st)
		elif (is_digit(c)):
			st.err = self.parse_number(st)
		elif (c == '['):
			st.err = self.parse_matrix(st)
		else:
			print("\n\n\n\n>>>>>> invalid object! >>>>> c = '" + str(c) + "'\n")
			exit(0)
		if (st.err == 0):
			st.skip_spaces()
			c = st.getc()
			if not c:
				return (0)
			if (is_var_start(st.getc())):
				# caseOf(2i):
				st.operation = COMPUTORV2_OPERATION_MULT
			else:
				st.operation = st.get_operation_code()

	def operation(self, st, left, right, operation_code):
		st.result = None
		if (operation_code == COMPUTORV2_OPERATION_MULT):
			if (ISINTEGER(left) and ISINTEGER(right)):
				st.result = Computorv2Integer(left.toInteger() * right.toInteger())
				return (0)
			if (ISINTEGER(left) and ISCOMPLEX(right)):
				st.result = Computorv2Complex(left.toInteger())
				return (0)
			if (ISINTEGER(left) and ISVECTOR(right)):
				st.result = right.multiply(left.toInteger())
				return (0)
		raise

	def precedence(self, st, perv):
		perv(st)
		while (not st.err):
			operation = st.operation;
			if (not operation):
				return (st.err)
			left      = st.result
			st.result = None
			perv(st)
			right     = st.result
			st.result = None
			print (left, right)
			st.err    = self.operation(st, left, right, operation)
		return (st.err);

	def parse_exponentiation(self, st):
		err = self.precedence(st, self.parse_object)
		return (err)

	def parse_multiplicatives(self, st):
		err = self.precedence(st, self.parse_exponentiation)
		return (err)

	def parse_additional(self, st):
		err = self.precedence(st, self.parse_multiplicatives)
		return (err)

	def parse_statment(self, st):
		err = self.parse_additional(st)
		print (st.result.toString())
		return (err)

	def parse_line(self, line):
		pass

st = Statment()
cm = Computorv2()

st.set_pos(0)
st.set_str("   2 * [1, 2, 3]   ")
st.set_len(len(st.get_str()))

cm.parse_statment(st)
