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
			std::map< std::string, computorv2::Object*> _variables;
			std::map< std::string, computorv2::Object*> _constants;
			std::map< std::string, computorv2::Object*> _localvariables;
		public:
			VirtualMachine(void);
			~VirtualMachine(void);
			VirtualMachine(const VirtualMachine& other);
			VirtualMachine& operator=(const VirtualMachine& other);

			computorv2::Object*         getVariableByName(std::string      name) const;
			computorv2::Object*         getConstantByName(std::string      name) const;
			computorv2::Object*         getLocalVariableByName(std::string name) const;

			void                        setVariableByName(std::string      name, const computorv2::Object* var);
			void                        setConstantByName(std::string      name, const computorv2::Object* var);
			void                        setLocalVariableByName(std::string name, const computorv2::Object* var);

			void                        delVariableByName(std::string      name);
			void                        delConstantByName(std::string      name);
			void                        delLocalVariableByName(std::string name);
			void                        init(void);
			void                        clear(void);
			std::string                 toString(void) const;
	};
}

std::ostream& operator<<(const std::ostream& os, const computorv2::VirtualMachine& vm);
