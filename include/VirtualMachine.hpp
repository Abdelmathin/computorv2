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
#include "Object.hpp"
#include <iostream>
#include <map>

namespace computorv2
{
	class VirtualMachine
	{
		private:
			std::map< std::string, computorv2::Object*> _variables;
			std::map< std::string, computorv2::Object*> _constants;
			std::map< std::string, computorv2::Object*> _independents;
		public:
			VirtualMachine(void);
			~VirtualMachine(void);
			VirtualMachine(const VirtualMachine& other);
			VirtualMachine& operator=(const VirtualMachine& other);

			computorv2::Object* getVariableByName(const std::string name) const;
			computorv2::Object* getConstantByName(const std::string name) const;
			computorv2::Object* getIndependentByName(const std::string name) const;

			void                setVariableByName(const std::string name, computorv2::Object* var);
			void                setConstantByName(const std::string name, computorv2::Object* var);
			void                setIndependentByName(const std::string name, computorv2::Object* var);

			void                delVariableByName(const std::string name);
			void                delConstantByName(const std::string name);
			void                delIndependentByName(const std::string name);

			void                clear(void);
	};
}
