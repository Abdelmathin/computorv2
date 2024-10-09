/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   UsualFunction.hpp                                  :+:      :+:    :+:    */
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
    class UsualFunction: public computorv2::Object
    {
        public:
            int                  getType(void)     const;
            std::string          getTypeName(void) const;
            std::string          toString(void)    const;
            computorv2::Object*  copy(void)        const;
            computorv2::Object*  evaluate(void)    const;
            bool                 isnull(void)      const;
            bool                 isunity(void)     const;
            bool                 isnegative(void)  const;

            std::string         getName(void)  const;
            computorv2::Object* getBody(void)  const;

            UsualFunction(const std::string& name, const computorv2::IndependentVariable& body);
            UsualFunction(const std::string& name, const computorv2::UsualFunction& body);
            UsualFunction(const std::string& name, const computorv2::Object* body);
            ~UsualFunction(void);
            UsualFunction(const UsualFunction& other);
            UsualFunction& operator=(const UsualFunction& other);

        private:
            UsualFunction(void);
            std::string         _name;
            computorv2::Object* _body;
            void                setName(const std::string& name);
            void                setBody(const computorv2::Object* body);
            void                init(void);
            void                clear(void);

    };
}

#define IS_USFUNC(o) ((OBJECT_TYPE(o) & COMPUTORV2_TYPE_USUAL_FUNCTION) != 0)
#define AS_USFUNC(o) static_cast< const computorv2::UsualFunction* >(o)

std::ostream& operator<<(std::ostream& left, const computorv2::UsualFunction& right);
