/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   statment.hpp                                       :+:      :+:    :+:    */
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

#include "Object.hpp"
#include "computorv2.hpp"
#include <iostream>

namespace computorv2
{
	typedef struct statment
	{
		std::string::size_type      _eri       ;
		std::string::size_type      _pos       ;
		std::string                 _str       ;
		std::string::size_type      _len       ;
		t_error                     _err       ;
		std::string                 _errmsg    ;
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
	t_error     statment_fini(computorv2::statment *st);
	t_error     statment_error(computorv2::statment *st);
	t_error     statment_skip_spaces(computorv2::statment *st);
	t_error     statment_skip(computorv2::statment *st, const std::string charset);
	t_error     statment_precedence(computorv2::statment *st, t_error (*perv)(computorv2::statment *st), int operations);
	t_error     statment_operation(computorv2::statment *st, const computorv2::Object* left, const computorv2::Object* right, const int operation_code);
	t_error     statment_parse_number(computorv2::statment *st);
	t_error     statment_parse_variable(computorv2::statment *st);
	t_error     statment_parse_derivative(computorv2::statment *st);
	t_error     statment_parse_matrix(computorv2::statment *st);	
	t_error     statment_parse_function_call(computorv2::statment *st);
	t_error     statment_parse_object(computorv2::statment *st);
	t_error     statment_parse_negation(computorv2::statment *st);
	t_error     statment_parse_exponentiation(computorv2::statment *st);
	t_error     statment_parse_multiplicatives(computorv2::statment *st);
	t_error     statment_parse_additional(computorv2::statment *st);
	t_error     statment_type(computorv2::statment *st);
	t_error     statment_assign_variable(computorv2::statment *st);
	t_error     statment_assign_function(computorv2::statment *st);
	t_error     statment_assign(computorv2::statment *st);
	t_error     statment_parse(computorv2::statment *st);
}
