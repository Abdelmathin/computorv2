/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:    */
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
#include "Complex.hpp"
#include <iostream>

namespace computorv2
{
    class Vector: public computorv2::Object
    {
        public:
            int                 getType(void)     const;
            std::string         getTypeName(void) const;
            std::string         toString(void)    const;
            computorv2::Object* copy(void)        const;
            computorv2::Object* evaluate(void)    const;
            bool                isnull(void)      const;
            bool                isunity(void)     const;;
            static Vector       null(void);

            Vector(void);
            ~Vector(void);
            Vector(const Vector& other);
            Vector& operator=(const Vector& other);

            Vector(const computorv2::Complex &a, const computorv2::Complex &b);
    };
}

#define IS_VECTOR(o) ((OBJECT_TYPE(o) & COMPUTORV2_TYPE_VECTOR) != 0)
#define AS_VECTOR(o) static_cast< const computorv2::Vector* >(o)

std::ostream& operator<<(std::ostream& left, const computorv2::Vector& right);
