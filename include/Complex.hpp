/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:    */
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
    class Complex: public computorv2::Object
    {
        public:
            int                        getType(void)     const;
            std::string                getTypeName(void) const;
            std::string                toString(void)    const;
            computorv2::Object*        clone(void)       const;
            bool                       isnull(void)      const;
            bool                       isunity(void)     const;
            bool                       isnegative(void)  const;
            static Complex             null(void);
            static Complex             unity(void);

            Complex(void);
            ~Complex(void);
            Complex(const Complex& other);
            Complex& operator=(const Complex& other);

            Complex(const double& real);
            Complex(const double& real, const double& image);

            std::string         getName(void)  const;
            double              getReal(void)  const;
            double              getImage(void) const;

            void                setName(const std::string& name);
            void                setReal(const double& real) ;
            void                setImage(const double& imag);
            void                clear(void);
        private:
            std::string _name;
            double      _real;
            double      _imag;
    };
}

#define IS_COMPLEX(o) ((OBJECT_TYPE(o) & COMPUTORV2_TYPE_COMPLEX) != 0)
#define AS_COMPLEX(o) static_cast< const computorv2::Complex* >(o)

std::ostream& operator<<(std::ostream& left, const computorv2::Complex& right);
computorv2::Complex operator*(const computorv2::Complex& left, const computorv2::Complex& right);
computorv2::Complex operator/(const computorv2::Complex& left, const computorv2::Complex& right);
computorv2::Complex operator+(const computorv2::Complex& left, const computorv2::Complex& right);
computorv2::Complex operator-(const computorv2::Complex& left, const computorv2::Complex& right);
