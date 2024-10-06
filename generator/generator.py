import os
import sys
import time
computorv2_cpp ='''


/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   computorv2.cpp                                     :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+      */
/*   By: ahabachi <abdelmathinhabachi@gmail.com>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+            */
/*   Created: 2024/08/19 17:40:12 by ahabachi          #+#    #+#              */
/*   Updated: 2024/09/24 06:34:37 by ahabachi         ###   ########.fr        */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*    ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗   ██╗████████╗ ██████╗ ██████╗    */
/*   ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔══██╗   */
/*   ██║     ██║   ██║██╔████╔██║██████╔╝██║   ██║   ██║   ██║   ██║██████╔╝   */
/*   ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║   ██║   ██║   ██║   ██║██╔══██╗   */
/*   ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ╚██████╔╝   ██║   ╚██████╔╝██║  ██║   */
/*    ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝ ╚═╝  ╚═╝   */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*  █████████            ██████████         ██████████         ██████████      */
/*  ██     ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██            ██████████         ██████████                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*      ████████         ██████████         ██████████                 ██      */
/*                                                                             */
/* **************************************************************************  */

#ifndef __COMPUTORV2_SOURCES_COMPUTORV2
# define __COMPUTORV2_SOURCES_COMPUTORV2

# include "../include/computorv2.hpp"
# include "../include/Object.hpp"
# include "../include/Matrix.hpp"
# include "../include/Vector.hpp"
# include "../include/Complex.hpp"
# include "../include/Polynomial.hpp"
# include "../include/UsualFunction.hpp"
# include "../include/IndependentVariable.hpp"
# include <sstream>
# include <unistd.h>

std::string computorv2::tolower(const std::string s)
{
	std::string u = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		u += std::tolower(s[i]);
	}
	return (u);
}

bool computorv2::isname(const std::string& name)
{
	const std::string::size_type len = name.size();
	if ((len < 1) || (!IS_VARSTART(name[0])))
	{
		return (false);
	}
	for (std::string::size_type i = 0; i < len; ++i)
	{
		if (!IS_VARCHAR(name[i]))
		{
			return (false);
		}
	}
	return (true);
}

bool computorv2::isUsualFunction(const std::string& name)
{
	if (name == "ln")
	{
		return (true);
	}
	return (false);
}

std::string computorv2::ltrim(const std::string s)
{
	std::string::size_type first = s.find_first_not_of("\\v\\f\\t ");
	if (first == std::string::npos)
	{
		return ("");
	}
	return (s.substr(first, (s.length() - first)));
}


'''

computorv2_hpp = '''
/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   computorv2.hpp                                     :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+      */
/*   By: ahabachi <abdelmathinhabachi@gmail.com>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+            */
/*   Created: 2024/08/19 17:40:12 by ahabachi          #+#    #+#              */
/*   Updated: 2024/09/24 06:34:37 by ahabachi         ###   ########.fr        */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*    ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗   ██╗████████╗ ██████╗ ██████╗    */
/*   ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔══██╗   */
/*   ██║     ██║   ██║██╔████╔██║██████╔╝██║   ██║   ██║   ██║   ██║██████╔╝   */
/*   ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║   ██║   ██║   ██║   ██║██╔══██╗   */
/*   ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ╚██████╔╝   ██║   ╚██████╔╝██║  ██║   */
/*    ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝ ╚═╝  ╚═╝   */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*  █████████            ██████████         ██████████         ██████████      */
/*  ██     ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██            ██████████         ██████████                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*      ████████         ██████████         ██████████                 ██      */
/*                                                                             */
/* **************************************************************************  */

#pragma once

# include <iostream>

typedef int t_error;

#define COMPUTORV2_EPSILON                   0.0000001
#define ABS(x)                               ( (x) >= 0 ? (x) : -(x) )
#define IS_ZERO(x)                           ( ABS(x) < COMPUTORV2_EPSILON )

#define COMPUTORV2_CASE_INSENSITIVE          1
#define COMPUTORV2_SUCCESS                   (0 << 0)
#define COMPUTORV2_ERROR                     (1 << 0)

#define ERROR_NOT_ENOUGH_MEMORY              (1 << 0)
#define ERROR_NAN                            (1 << 1)

#define STATMENT_TYPE_UNKNOWN                (0 << 0)
#define STATMENT_TYPE_GET                    (1 << 0) /* x = ? */
#define STATMENT_TYPE_SET_VARIABLE           (1 << 1) /* x = y */
#define STATMENT_TYPE_SET_FUNCTION           (1 << 2) /* f(x) = 2 * x */
#define STATMENT_TYPE_SOLVE                  (1 << 3) /* x = y ? */

#define COMPUTORV2_OPERATION_NONE            (0 << 0)
#define COMPUTORV2_OPERATION_ADD             (1 << 0)
#define COMPUTORV2_OPERATION_SUB             (1 << 1)
#define COMPUTORV2_OPERATION_MULT            (1 << 2)
#define COMPUTORV2_OPERATION_DIV             (1 << 3)
#define COMPUTORV2_OPERATION_EXP             (1 << 4)
#define COMPUTORV2_OPERATION_MATRIX_MULT     (1 << 5)
#define COMPUTORV2_OPERATION_MOD             (1 << 6)

#define COMPUTORV2_TYPE_UNKNOWN              (0 << 0)
#define COMPUTORV2_TYPE_INTEGER              (1 << 0)
#define COMPUTORV2_TYPE_RATIONAL             (1 << 1)
#define COMPUTORV2_TYPE_VECTOR               (1 << 2)
#define COMPUTORV2_TYPE_MATRIX               (1 << 3)
#define COMPUTORV2_TYPE_COMPLEX              (1 << 4)
#define COMPUTORV2_TYPE_FUNCTION             (1 << 5)
#define COMPUTORV2_TYPE_USUAL_FUNCTION       (1 << 6)
#define COMPUTORV2_TYPE_POLYNOMIAL           (1 << 7)
#define COMPUTORV2_TYPE_INDEPENDENT_VARIABLE (1 << 8)

#define CHARCODE(c)        ((int)(c))
#define IS_DIGIT(c)        (('0' <= c) && (c <= '9'))
#define IS_SPACE(c)        ((c == ' ') || (c == '\\t'))
#define IS_VARSTART(c)     ((c == '_') || (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')))
#define IS_VARCHAR(c)      (IS_DIGIT(c) || IS_VARSTART(c))

#define OBJECT_TYPE(obj)   (obj ? ((obj)->getType()) : 0)

namespace computorv2
{
	class Object;
	class Matrix;
	class Vector;
	class Complex;
	class History;
    class Polynomial;
	class VirtualMachine;
    class UsualFunction;
    class IndependentVariable;

	std::string tolower(const std::string s);
	bool        isname(const std::string& name);
	bool        isUsualFunction(const std::string& name);
	std::string ltrim(const std::string s);

'''

# add, sub, mul, div, mod, eql, drv, pow, neg, replace(old, new)

return_types = {
	"Integer-Integer"                           : "Integer"   ,
	"Integer-Rational"                          : "Rational"  ,
	"Integer-Complex"                           : "Complex"   ,
	"Integer-Vector"                            : "Vector"    ,
	"Integer-Matrix"                            : "Matrix"    ,
	"Integer-Polynomial"                        : "Polynomial",
	"Integer-UsualFunction"                     : "Polynomial",
	"Integer-IndependentVariable"               : "Polynomial",

	"Rational-Integer"                          : "Rational"  ,
	"Rational-Rational"                         : "Rational"  ,
	"Rational-Complex"                          : "Complex"   ,
	"Rational-Vector"                           : "Vector"    ,
	"Rational-Matrix"                           : "Matrix"    ,
	"Rational-Polynomial"                       : "Polynomial",
	"Rational-UsualFunction"                    : "Polynomial",
	"Rational-IndependentVariable"              : "Polynomial",

	"Complex-Integer"                           : "Complex"   ,
	"Complex-Rational"                          : "Complex"   ,
	"Complex-Complex"                           : "Complex"   ,
	"Complex-Vector"                            : "Vector"    ,
	"Complex-Matrix"                            : "Matrix"    ,
	"Complex-Polynomial"                        : "Polynomial",
	"Complex-UsualFunction"                     : "Polynomial",
	"Complex-IndependentVariable"               : "Polynomial",

	"Vector-Integer"                            : "Vector"    ,
	"Vector-Rational"                           : "Vector"    ,
	"Vector-Complex"                            : "Vector"    ,
	"Vector-Vector"                             : "Vector"    ,
	"Vector-Matrix"                             : "Matrix"    ,
	"Vector-Polynomial"                         : "Polynomial",
	"Vector-UsualFunction"                      : "Polynomial",
	"Vector-IndependentVariable"                : "Polynomial",

	"Matrix-Integer"                            : "Matrix"    ,
	"Matrix-Rational"                           : "Matrix"    ,
	"Matrix-Complex"                            : "Matrix"    ,
	"Matrix-Vector"                             : "Matrix"    ,
	"Matrix-Matrix"                             : "Matrix"    ,
	"Matrix-Polynomial"                         : "Polynomial",
	"Matrix-UsualFunction"                      : "Polynomial",
	"Matrix-IndependentVariable"                : "Polynomial",

	"Polynomial-Integer"                        : "Polynomial",
	"Polynomial-Rational"                       : "Polynomial",
	"Polynomial-Complex"                        : "Polynomial",
	"Polynomial-Vector"                         : "Polynomial",
	"Polynomial-Matrix"                         : "Polynomial",
	"Polynomial-Polynomial"                     : "Polynomial",
	"Polynomial-UsualFunction"                  : "Polynomial",
	"Polynomial-IndependentVariable"            : "Polynomial",

	"UsualFunction-Integer"                     : "Polynomial",
	"UsualFunction-Rational"                    : "Polynomial",
	"UsualFunction-Complex"                     : "Polynomial",
	"UsualFunction-Vector"                      : "Polynomial",
	"UsualFunction-Matrix"                      : "Polynomial",
	"UsualFunction-Polynomial"                  : "Polynomial",
	"UsualFunction-UsualFunction"               : "Polynomial",
	"UsualFunction-IndependentVariable"         : "Polynomial",

	"IndependentVariable-Integer"               : "Polynomial",
	"IndependentVariable-Rational"              : "Polynomial",
	"IndependentVariable-Complex"               : "Polynomial",
	"IndependentVariable-Vector"                : "Polynomial",
	"IndependentVariable-Matrix"                : "Polynomial",
	"IndependentVariable-Polynomial"            : "Polynomial",
	"IndependentVariable-UsualFunction"         : "Polynomial",
	"IndependentVariable-IndependentVariable"   : "Polynomial",

}

prototypes = {
	"bool isfreeterm(const computorv2::<left_object> left);"                                                                 : {},
	"bool eql(const computorv2::<left_object> left, const computorv2::<right_object> right);"                                : {},
	"computorv2::Polynomial derivative(const computorv2::<left_object> left, const computorv2::IndependentVariable& right);" : {},
	"<return_type> add(const computorv2::<left_object> left, const computorv2::<right_object> right);"                       : return_types,
	"<return_type> sub(const computorv2::<left_object> left, const computorv2::<right_object> right);"                       : return_types,
	"<return_type> mul(const computorv2::<left_object> left, const computorv2::<right_object> right);"                       : return_types,
	"<return_type> div(const computorv2::<left_object> left, const computorv2::<right_object> right);"                       : return_types,
	"<return_type> mod(const computorv2::<left_object> left, const computorv2::<right_object> right);"                       : return_types,
	"<return_type> pow(const computorv2::<left_object> left, const computorv2::<right_object> right);"                       : return_types,
}

objects = [
	"Vector",
	"Matrix",
	"Complex",
	"Polynomial",
	"UsualFunction",
	"IndependentVariable",
]

default_returns = {
	"bool"               : "false",
	"Vector"             : "computorv2::Vector(0.0, 0.0)",
	"Matrix"             : "computorv2::Matrix(0.0, 0.0, 0.0, 0.0)",
	"Complex"            : "computorv2::Complex(0.0, 0.0)",
	"Polynomial"         : 'computorv2::Polynomial("x")',
	"UsualFunction"      : 'computorv2::UsualFunction("ln", "x")',
	"IndependentVariable": 'computorv2::IndependentVariable("x")',
}

ignored_prototypes = {}

def fix_file_content(content):
	content = content.replace("INDEPENDENTVARIABLE(", "INDVAR(")
	content = content.replace("USUALFUNCTION(", "USFUNC(")
	return (content)

def clear_prototype(prototype):
	for k in " \r\n\t\v\f":
		prototype = prototype.replace(k, " ").strip()
	while ("  " in prototype):
		prototype = prototype.replace("  ", " ")
	return (prototype)

def function_implementation(namespace, prototype):
	for k in " \r\n\t\v\f;":
		prototype = prototype.replace(k, " ").strip()
	while ("  " in prototype):
		prototype = prototype.replace("  ", " ")
	i = prototype.index(" ")
	prototype = prototype[:i] + " " + namespace + "::" + prototype[i:].strip()
	return (prototype)

def ignore_prototype(prototype):
	for k in " \r\n\t\v\f":
		prototype = prototype.replace(k, "").strip()
	if not prototype:
		return  (1)
	if prototype in ignored_prototypes:
		return (1)
	ignored_prototypes[prototype] = 1
	return (0)

TAB      = " " * 4
NEW_LINE = "\n"


for prototype in prototypes:
	function_name     = prototype.split("(")[0].strip().split("\t")[-1].split(" ")[-1]
	have_right_term   = ("<right_object>" in prototype)
	have_static_right = (("<right_object>" not in prototype) and ("right)" in prototype))
	headers           = []
	implementations   = []
	headers.append(prototype.replace("<return_type>", "computorv2::Object*").replace("<left_object>", "Object*").replace("<right_object>", "Object*"))
	if (have_right_term):
		implementations.append("{" + NEW_LINE + TAB + "if (!left || !right)" + NEW_LINE + TAB + TAB + 'throw std::logic_error("Operation \'' + function_name + '\' not supported between null types.");')
	else:
		implementations.append("{" + NEW_LINE + TAB + "if (!left)" + NEW_LINE + TAB + TAB + 'throw std::logic_error("Operation \'' + function_name + '\' not supported for null types.");')
	space_index = 0
	left_index  = -1
	left_string = ""
	if ("left," in headers[-1]):
		left_string = "left,"
		left_index  = headers[-1].index(left_string)
	elif ("left)" in headers[-1]):
		left_string = "left)"
		left_index  = headers[-1].index(left_string)
	NEED_COPY = ""
	for left_object in objects:
		for right_object in objects:
			line = ""
			if ("<return_type>" in prototype):
				for key in prototypes[prototype]:
					key1 = (left_object + "-" + right_object).lower()
					key2 = (right_object + "-" + left_object).lower()
					if (key.lower() == key1) or (key.lower() == key2):
						line = prototype.replace("<return_type>", "computorv2::" + prototypes[prototype][key])
						line = line.replace("<left_object>", left_object + "&").replace("<right_object>", right_object + "&")
						NEED_COPY = ".copy()"
						break
			else:
				line = prototype.replace("<left_object>", left_object + "&").replace("<right_object>", right_object + "&")
			line = clear_prototype(line)
			if ignore_prototype(line):
				continue
			return_type = line.strip().split(" ")[0].split(":")[-1]
			headers.append(line)
			if (headers[-1].index(" ") > space_index):
				space_index = headers[-1].index(" ")
			upleft  = left_object.upper()
			upright = right_object.upper()
			if (have_right_term):
				implementations[0] += NEW_LINE + TAB + "else if (" + ("IS_" + upleft).upper() + "(left) && " + ("IS_" + upright).upper() + "(right))" + NEW_LINE + TAB + TAB + "return (computorv2::" + function_name + "(*AS_" + upleft + "(left), *AS_" + upright + "(right))" + NEED_COPY + ");"
			elif (have_static_right):
				implementations[0] += NEW_LINE + TAB + "else if (" + ("IS_" + upleft).upper() + "(left))" + NEW_LINE + TAB + TAB + "return (computorv2::" + function_name + "(*AS_" + upleft + "(left), right)" + NEED_COPY + ");"
			else:
				implementations[0] += NEW_LINE + TAB + "else if (" + ("IS_" + upleft).upper() + "(left))" + NEW_LINE + TAB + TAB + "return (computorv2::" + function_name + "(*AS_" + upleft + "(left))" + NEED_COPY + ");"
			if (have_right_term):
				implementations.append('{' + NEW_LINE + TAB + "(void)left; (void) right;" + NEW_LINE + TAB + 'throw std::logic_error("Operation \'' + function_name + '\' not supported between types \'' + left_object + '\' and \'' + right_object + '\'' + '.");' + NEW_LINE + TAB + "return (" + default_returns[return_type] + ");" + NEW_LINE + '}')
			else:
				implementations.append('{' + NEW_LINE + TAB + "(void)left;" + NEW_LINE + TAB + 'throw std::logic_error("Operation \'' + function_name + '\' not supported for type: \'' + left_object + '\'' + '");' + NEW_LINE + TAB + "return (" + default_returns[return_type] + ");" + NEW_LINE + '}')
	if (have_right_term):
		implementations[0] += NEW_LINE + TAB + 'throw std::logic_error("Operation \'' + function_name + '\' not supported between types \'" + left->getTypeName() + "\' and \'" + right->getTypeName() + "\'.");'
	else:
		implementations[0] += NEW_LINE + TAB + 'throw std::logic_error("Operation \'' + function_name + '\' not supported for type \'" + left->getTypeName() + "\'.");'
	implementations[0] += NEW_LINE + TAB + "return (0);" + NEW_LINE + "}"
	headers_tmp    = []
	right_index = 0
	for header in headers:
		b_header = header
		spidx    = b_header.index(" ")
		b_header = b_header[:spidx] + (" " * (space_index - spidx)) + b_header[spidx:]
		headers_tmp.append(b_header)
		if (left_index >= 0):
			lfidx    = headers_tmp[-1].index(left_string)
			if (left_index < lfidx):
				left_index = lfidx
	headers1    = []
	right_index = -1
	for header in headers_tmp:
		b_header = header
		if (left_index >= 0):
			lfidx    = b_header.index(left_string)
			b_header = b_header[:lfidx] + (" " * (left_index - lfidx)) + b_header[lfidx:]
		headers1.append(b_header)
		if ("right)" in headers1[-1]):
			rtidx    = headers1[-1].index("right)")
			if (right_index < rtidx):
				right_index = rtidx
	function_headers = []
	long_header      = 0
	for header in headers1:
		b_header = header
		if (right_index >= 0):
			rtidx    = b_header.index("right)")
			b_header = b_header[:rtidx] + (" " * (right_index - rtidx)) + b_header[rtidx:]
		function_headers.append(b_header)
		if (long_header < len(function_headers[-1])):
			long_header = len(function_headers[-1])
	n = int(((long_header - len(function_name)) / 2) - 4)
	computorv2_cpp = computorv2_cpp.strip()
	computorv2_hpp += NEW_LINE + NEW_LINE + TAB + ("/* " + (n * "-") + " " + function_name + " " + (n * "-") + " */")
	computorv2_cpp += NEW_LINE + NEW_LINE + ("/* " + (n * "-") + " " + function_name + " " + (n * "-") + " */")
	header_index = 0
	for header in function_headers:
		computorv2_hpp += NEW_LINE + TAB + header
		computorv2_cpp  = computorv2_cpp.strip() + NEW_LINE + NEW_LINE + function_implementation("computorv2", header).strip() + NEW_LINE + implementations[header_index].strip() + NEW_LINE
		header_index += 1

computorv2_cpp = computorv2_cpp.strip() + NEW_LINE + NEW_LINE + "#endif//!__COMPUTORV2_SOURCES_COMPUTORV2" + NEW_LINE
computorv2_hpp = computorv2_hpp.strip() + NEW_LINE + "}" + NEW_LINE

FILE     = os.path.realpath(__file__)
REPO_DIR = os.path.dirname(os.path.dirname(FILE))

print ("Are you sure, computorv2.cpp and computer v2.hpp will override")
for i in list(range(0, 60))[::-1]:
	print (i, end = "\r")
	time.sleep(1)

with open(REPO_DIR + "/include/computorv2.hpp", "w") as fp:
	fp.write(fix_file_content(computorv2_hpp))

with open(REPO_DIR + "/sources/computorv2.cpp", "w") as fp:
	fp.write(fix_file_content(computorv2_cpp))
