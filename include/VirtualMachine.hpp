/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   VirtualMachine.hpp                                 :+:      :+:    :+:    */
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

#include "computorv2.hpp"
#include "Object.hpp"
#include <iostream>
#include <map>
#include <vector>

namespace computorv2
{
	class VirtualMachine
	{
		private:
			std::map< std::string, computorv2::Object*>         _variables;
			std::map< std::string, computorv2::Object*>         _constants;
			std::map< std::string, computorv2::Object*>         _localvariables;
			std::map< std::string, std::vector< std::string > > _params;
		public:
			VirtualMachine(void);
			~VirtualMachine(void);
			VirtualMachine(const VirtualMachine& other);
			VirtualMachine& operator=(const VirtualMachine& other);

			computorv2::Object*         getVariableByName(const std::string&      name) const;
			computorv2::Object*         getConstantByName(const std::string&      name) const;
			computorv2::Object*         getLocalVariableByName(const std::string& name) const;

			void                        setVariableByName(const std::string&      name, const computorv2::Object* var);
			void                        setConstantByName(const std::string&      name, const computorv2::Object* var);
			void                        setLocalVariableByName(const std::string& name, const computorv2::Object* var);
			void                        addFunctionParameter(std::string funcname, std::string varname);
			std::vector< std::string >  getFunctionParametersByName(std::string funcname);

			void                        delVariableByName(const std::string&      name);
			void                        delConstantByName(const std::string&      name);
			void                        delLocalVariableByName(const std::string& name);
			void                        init(void);
			void                        clear(void);
			std::string                 toString(void) const;
	};
}

std::ostream& operator<<(const std::ostream& os, const computorv2::VirtualMachine& vm);
