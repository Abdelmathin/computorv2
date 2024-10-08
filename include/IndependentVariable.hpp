/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   IndependentVariable.hpp                            :+:      :+:    :+:    */
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

namespace computorv2
{
	class IndependentVariable: public computorv2::Object
	{
		public:
            int                        getType(void)     const;
            std::string                getTypeName(void) const;
            std::string                toString(void)    const;
            computorv2::Object*        copy(void)        const;
            computorv2::Object*        evaluate(void)    const;
            bool                       isnull(void)      const;
            bool                       isunity(void)     const;
            bool                       isnegative(void)  const;
            static IndependentVariable null(void);

			IndependentVariable(const std::string& name);
			~IndependentVariable(void);
			IndependentVariable(const IndependentVariable& other);
			IndependentVariable& operator=(const IndependentVariable& other);
			std::string          getName(void) const;
			void                 setName(const std::string& name);
		private:
			IndependentVariable(void);
			std::string _name;
	};
}

#define IS_INDVAR(o) ((OBJECT_TYPE(o) & COMPUTORV2_TYPE_INDEPENDENT_VARIABLE) != 0)
#define AS_INDVAR(o) static_cast< const computorv2::IndependentVariable* >(o)

std::ostream& operator<<(std::ostream& left, const computorv2::IndependentVariable& right);
