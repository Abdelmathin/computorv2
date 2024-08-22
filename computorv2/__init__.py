
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

def is_digit(c):
	return (c in "0123456789")

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

class Computorv2:
	def __init__(self):
		pass

	def parse_number(self, st):
		pass

	def parse_object(self, st):
		st.operation = 0
		st.skip_spaces()
		c = st.getc();
		if (is_var_start(c)):
			st.err = self.parse_variable(st)
		elif (is_digit(c)):
			st.err = self.parse_number(st)
		else:
			print("\n\n\n\n>>>>>> invalid object!\n")
			exit(0)
		if (st.err):
			st.skip_spaces()
			if (is_var_start(st.getc())):
				# caseOf(2i):
				st.operation = COMPUTORV2_OPERATION_MULT
			else:
				st.operation = computorv2_operation_code(st)

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
			st.err    = self.operation(st.result, left, right, operation)
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
		return (err)

	def parse_line(self, line):
		pass

st = Statment()
cm = Computorv2()

st.set_pos(0)
st.set_str("1 + 2")
st.set_len(5)

cm.parse_statment(st)
