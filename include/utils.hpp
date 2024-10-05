/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:    */
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
#define IS_SPACE(c)        ((c == ' ') || (c == '\t'))
#define IS_VARSTART(c)     ((c == '_') || (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')))
#define IS_VARCHAR(c)      (IS_DIGIT(c) || IS_VARSTART(c))

#define ISDIGIT     IS_DIGIT
#define ISSPACE     IS_SPACE
#define ISVARSTART  IS_VARSTART
#define IS_VAR_CHAR IS_VARCHAR
#define ISNULL IS_ZERO

#define OBJECT_TYPE(obj)    (obj ? ((obj)->getType()) : 0)
#define GETTYPEOF(obj)      OBJECT_TYPE(obj)
#define IS_RATIONAL(obj)    ((GETTYPEOF(obj) & COMPUTORV2_TYPE_RATIONAL)             != 0)
#define IS_COMPLEX(obj)     ((GETTYPEOF(obj) & COMPUTORV2_TYPE_COMPLEX)              != 0)
#define IS_INDEPENDENT(obj) ((GETTYPEOF(obj) & COMPUTORV2_TYPE_INDEPENDENT_VARIABLE) != 0)
#define IS_POLYNOMIAL(obj)  ((GETTYPEOF(obj) & COMPUTORV2_TYPE_POLYNOMIAL)           != 0)

#define AS_OBJECT(obj)      static_cast< const computorv2::Object* >(obj)
#define AS_COMPLEX(obj)     static_cast< const computorv2::Complex* >(obj)
#define AS_INDEPENDENT(obj) static_cast< const computorv2::IndependentVariable* >(obj)
#define AS_POLYNOMIAL(obj)  static_cast< const computorv2::Polynomial* >(obj)



#define ISRATIONAL   IS_RATIONAL
#define ISPOLYNOMIAL IS_POLYNOMIAL

namespace computorv2
{
	class Object;
	class Matrix;
	class Vector;
	class Complex;
	class History;
	class Polynomial;

	class VirtualMachine;
	typedef struct statment
	{
		std::string::size_type      _pos       ;
		std::string                 _str       ;
		std::string::size_type      _len       ;
		t_error                     _err       ;
		int                         _type      ;
		int                         _operation ;
		std::string                 _varname   ;
		std::string                 _funcname  ;
		computorv2::Object*         _result    ;
		computorv2::VirtualMachine* _vm        ;
	} statment;


	std::string tolower(const std::string s);
	bool        isname(const std::string& name);
	bool        isUsualFunction(const std::string& name);
	std::string ltrim(const std::string s);
	char        statment_getc(const computorv2::statment *st);
	char        statment_next(computorv2::statment *st);
	bool        statment_eos(const computorv2::statment *st);
	std::string statment_parsename(computorv2::statment *st);
	int         statment_operation_code(computorv2::statment *st);

	t_error     statment_init(computorv2::statment *st);
	t_error     statment_skip_spaces(computorv2::statment *st);
	t_error     statment_skip(computorv2::statment *st, const std::string charset);
	t_error     statment_precedence(computorv2::statment *st, t_error (*perv)(computorv2::statment *st), int operations);
	t_error     statment_operation(computorv2::statment *st, const computorv2::Object* left, const computorv2::Object* right, const int operation_code);
	t_error     statment_parse_number(computorv2::statment *st);
	t_error     statment_parse_variable(computorv2::statment *st);
	t_error     statment_parse_object(computorv2::statment *st);
	t_error     statment_parse_exponentiation(computorv2::statment *st);
	t_error     statment_parse_multiplicatives(computorv2::statment *st);
	t_error     statment_parse_additional(computorv2::statment *st);
	t_error     statment_type(computorv2::statment *st);
	t_error     statment_assign_variable(computorv2::statment *st);
	t_error     statment_assign_function(computorv2::statment *st);
	t_error     statment_assign(computorv2::statment *st);
	t_error     statment_parse(computorv2::statment *st);
}
