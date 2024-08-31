
COMPUTORV2_SUCCESS               = (0 << 0)
COMPUTORV2_ERROR                 = (1 << 0)

ERROR_NOT_ENOUGH_MEMORY          = (1 << 0)
ERROR_NAN                        = (1 << 1)

STATMENT_TYPE_GET                = (1 << 0)
STATMENT_TYPE_SET                = (1 << 1)
STATMENT_TYPE_SOLVE              = (1 << 2)

COMPUTORV2_OPERATION_ADD         = (1 << 0)
COMPUTORV2_OPERATION_SUB         = (1 << 1)
COMPUTORV2_OPERATION_MULT        = (1 << 2)
COMPUTORV2_OPERATION_DIV         = (1 << 3)
COMPUTORV2_OPERATION_EXP         = (1 << 4)

COMPUTORV2_TYPE_INTEGER          = (1 << 0)
COMPUTORV2_TYPE_RATIONAL         = (1 << 1)
COMPUTORV2_TYPE_VECTOR           = (1 << 2)
COMPUTORV2_TYPE_MATRIX           = (1 << 3)
COMPUTORV2_TYPE_COMPLEX          = (1 << 4)
COMPUTORV2_OPERATION_MATRIX_MULT = (1 << 5)
COMPUTORV2_OPERATION_MOD         = (1 << 6)

def GETTYPEOF(obj):
	if obj:
		return (obj.type())
	return (0)

def ISINTEGER(obj):
	return ((GETTYPEOF(obj) & COMPUTORV2_TYPE_INTEGER) != 0)

def ISRATIONAL(obj):
	return ((GETTYPEOF(obj) & COMPUTORV2_TYPE_RATIONAL) != 0)

def ISCOMPLEX(obj):
	return ((GETTYPEOF(obj) & COMPUTORV2_TYPE_COMPLEX) != 0)

def ISVECTOR(obj):
	return ((GETTYPEOF(obj) & COMPUTORV2_TYPE_VECTOR) != 0)

def ISMATRIX(obj):
	return ((GETTYPEOF(obj) & COMPUTORV2_TYPE_MATRIX) != 0)

def ISDIGIT(c):
	try:
		return (ord('0') <= ord(c) <= ord('9'))
	except:
		pass
	return (False)

def CHARCODE(c):
	return (ord(c))

def ISVARSTART(c):
	return (c.lower() in "_abcdefghijklmnopqrstuvwxyz")

def IS_VAR_CHAR(c):
	return (ISDIGIT(c) or ISVARSTART(c))

class Computorv2Object:
	pass

class Statment:
	pos           = 0
	str           = None
	len           = 0
	err           = 0
	operation     = 0
	result        = None
	function_name = None
	variable_name = None
	vm            = None

class Computorv2Integer:

	def __init__(self, value):
		self.value = int(value)

	def multiply(self, v):
		self.value *= v
		return (self)

	def toString(self):
		return (str(self.value))

	def toInteger(self):
		return (self.value)

	def type(self):
		return (COMPUTORV2_TYPE_INTEGER)

class Computorv2Rational:

	def __init__(self, value):
		self.value = float(value)

	def multiply(self, v):
		self.value *= v
		return (self)

	def toFloat(self):
		return (self.value)

	def type(self):
		return (COMPUTORV2_TYPE_RATIONAL)

	def toString(self):
		return (str(self.value))

class Computorv2Complex:

	def __init__(self, value = 1):
		self.value = value

	def multiply(self, v):
		self.value *= v
		return (self)

	def toNumber(self):
		return (self.value)

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
			self.elements[i].multiply(scalar)
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

def computorv2_operation(st, left, right, operation_code):
	st.result = None
	if (operation_code == COMPUTORV2_OPERATION_ADD):
		if (ISINTEGER(left) and ISINTEGER(right)):
			st.result = Computorv2Integer(left.toInteger() + right.toInteger())
			return (0)
	if (operation_code == COMPUTORV2_OPERATION_MULT):
		if (ISINTEGER(left) and ISINTEGER(right)):
			st.result = Computorv2Integer(left.toInteger() * right.toInteger())
			return (0)
		if (ISINTEGER(left) and ISRATIONAL(right)):
			st.result = Computorv2Rational(left.toInteger() * right.toFloat())
			return (0)
		if (ISINTEGER(left) and ISCOMPLEX(right)):
			st.result = Computorv2Complex(left.toInteger() * right.toNumber())
			return (0)
		if (ISINTEGER(left) and ISVECTOR(right)):
			st.result = right.multiply(left.toInteger())
			return (0)
	raise

def computorv2_statment_get_str(st):
	return (st.str)

def computorv2_statment_set_pos(st, p):
	st.pos = p

def computorv2_statment_set_str(st, s):
	st.str = s

def computorv2_statment_set_len(st, l):
	st.len = l

def computorv2_statment_getc(st):
	if (st.pos < st.len):
		return (st.str[st.pos])
	return (0)

def computorv2_statment_next(st):
	if (st.pos < st.len):
		st.pos += 1
	if (st.str) and (st.pos < st.len):
		return (st.str[st.pos])
	return (0)

def computorv2_skip_spaces(st):
	while ((st.pos < st.len) and st.str[st.pos].isspace()):
		st.pos += 1
	return (COMPUTORV2_SUCCESS)

def get_operation_code(st):
	computorv2_skip_spaces(st)
	c = computorv2_statment_getc(st)
	if (c == "+"):
		computorv2_statment_next(st)
		return (COMPUTORV2_OPERATION_ADD)
	if (c == "-"):
		computorv2_statment_next(st)
		return (COMPUTORV2_OPERATION_SUB)
	if (c == "*"):
		c = computorv2_statment_next(st)
		if (c == "*"):
			return (COMPUTORV2_OPERATION_MATRIX_MULT)
		return (COMPUTORV2_OPERATION_MULT)
	if (c == "/"):
		computorv2_statment_next(st)
		return (COMPUTORV2_OPERATION_DIV)
	if (c == "%"):
		computorv2_statment_next(st)
		return (COMPUTORV2_OPERATION_MOD)
	if (c == "^"):
		computorv2_statment_next(st)
		return (COMPUTORV2_OPERATION_EXP)
	return (0);

def computorv2_parse_number(st):
	c = computorv2_statment_getc(st)
	if not (ISDIGIT(c)):
		return (1)
	st.result = None
	r = 0
	while (ISDIGIT(c)):
		r = 10 * r + (CHARCODE(c) - CHARCODE('0'))
		c = computorv2_statment_next(st)
	if (c != '.'):
		st.result = Computorv2Integer(r)
		return (0)
	c = computorv2_statment_next(st)
	f = 0.1
	while (ISDIGIT(c)):
		r = r + f * (CHARCODE(c) - CHARCODE('0'))
		c = computorv2_statment_next(st)
		f = f / 10.0
	st.result = Computorv2Rational(r)
	return (0)

def computorv2_parse_matrix(self, st):
	c = computorv2_statment_getc(st)
	if (c != '['):
		return (1)
	st.result = None
	computorv2_statment_next(st)
	computorv2_skip_spaces(st)
	c = computorv2_statment_getc(st)
	if (c != '['):
		v = Computorv2Vector()
		while (1):
			computorv2_skip_spaces(st)
			self.parse_object(st)
			computorv2_skip_spaces(st)
			if not st.result:
				# delete (v)
				return (1)
			v.add(st.result)
			c = computorv2_statment_getc(st)
			if (c != ','):
				break
			computorv2_statment_next(st)
		if (c != ']'):
			# delete (v)
			st.result = None
			return (1)
		computorv2_statment_next(st)
		st.result = v
		return (0)
	m = Computorv2Matrix()
	while (1):
		computorv2_skip_spaces(st)
		self.parse_object(st)
		computorv2_skip_spaces(st)
		if not ISVECTOR(st.result):
			# delete(m)
			st.result = None
			return (1)
		m.add(st.result)
		c = computorv2_statment_getc(st)
		if (c != ';'):
			break
		computorv2_statment_next(st)
	if (c != ']'):
		# delete(m)
		st.result = None
		return (1)
	computorv2_statment_next(st)
	st.result = m
	return (0)

class Computorv2:
	def __init__(self):
		pass

	def parse_variable(self, st):
		name = ""
		while (IS_VAR_CHAR(computorv2_statment_getc(st))):
			name += computorv2_statment_getc(st)
			computorv2_statment_next(st)
		if (name == "i"):
			st.result = Computorv2Complex()
			return (0)
		raise

	def parse_object(self, st):
		st.operation = 0
		st.result    = None
		computorv2_skip_spaces(st)
		c = computorv2_statment_getc(st)
		if (ISVARSTART(c)):
			st.err = self.parse_variable(st)
		elif (ISDIGIT(c)):
			st.err = computorv2_parse_number(st)
		elif (c == '('):
			computorv2_statment_next(st)
			computorv2_skip_spaces(st)
			self.parse_additional(st)
			computorv2_skip_spaces(st)
			if (computorv2_statment_getc(st) != ')'):
				# delete...
				st.result = None
				return (1)
			computorv2_statment_next(st) # skip ')'
			return (0)
		elif (c == '['):
			st.err = computorv2_parse_matrix(self, st)
		else:
			print("\n\n\n\n>>>>>> invalid object! >>>>> c = '" + str(c) + "'\n")
			exit(0)
		if (st.err == 0):
			computorv2_skip_spaces(st)
			if computorv2_statment_getc(st) == 0:
				return (0)
			st.operation = get_operation_code(st)
			if (ISVARSTART(computorv2_statment_getc(st))):
				# caseOf(2i):
				print ('# caseOf(2i):')
				st.operation = COMPUTORV2_OPERATION_MULT
		return (st.err)

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
			print (left, right, operation)
			st.err    = computorv2_operation(st, left, right, operation)
		return (st.err)

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
		return (err)

	def parse_line(self, line):
		pass

st = Statment()
cm = Computorv2()

computorv2_statment_set_pos(st, 0)
computorv2_statment_set_str(st, " [3, 1, 4] * [ [4, 3] ; [2, 5] ; [6, 8] ]")
computorv2_statment_set_len(st, len(computorv2_statment_get_str(st)))

cm.parse_statment(st)
print (st.result.toString())
