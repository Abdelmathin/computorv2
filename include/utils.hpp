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

typedef int t_error;

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
#define COMPUTORV2_TYPE_INDEPENDENT_VARIABLE (1 << 6)

#define CHARCODE(c)     ((int)(c))
#define ISDIGIT(c)      (('0' <= c) && (c <= '9'))
#define ISSPACE(c)      ((c == ' ') || (c == '\t'))
#define ISVARSTART(c)   (c == '_') || (('a' <= c) && (c <= 'z'))
#define IS_VAR_CHAR(c)  (ISDIGIT(c) || ISVARSTART(c))

#define GETTYPEOF(obj)  (obj ? ((obj)->getType()) : 0)
#define ISRATIONAL(obj) ((GETTYPEOF(obj) & COMPUTORV2_TYPE_RATIONAL) != 0)

namespace computorv2
{
	class Object;
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
	t_error     statment_assign(computorv2::statment *st);
	t_error     statment_parse(computorv2::statment *st);
}
