/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Polynomial.hpp                                     :+:      :+:    :+:    */
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
#include "IndependentVariable.hpp"
#include <iostream>

namespace computorv2
{
	class Polynomial: public computorv2::Object
	{
		public:
            int                 getType(void)     const;
            std::string         getTypeName(void) const;
            std::string         toString(void)    const;
            computorv2::Object* copy(void)        const;
            computorv2::Object* evaluate(void)    const;
            bool                isnull(void)      const;
            bool                isunity(void)     const;
            bool                isnegative(void)  const;
            static Polynomial   null(void);
            static Polynomial   unity(void);

			Polynomial(const std::string& basename);
			Polynomial(const Polynomial& other);
			Polynomial(const computorv2::UsualFunction& base);
			Polynomial(const computorv2::IndependentVariable& base);
			Polynomial(const computorv2::Object* base);
			~Polynomial(void);
			Polynomial&            operator=(const Polynomial& other);

			computorv2::Object*    getCoefficient(void) const;
			computorv2::Object*    getBase(void) const;
			computorv2::Object*    getExponent(void) const;
			computorv2::Object*    getFreeTerm(void) const;

			void                   setCoefficient(const computorv2::Object* coefficient);
			void                   setBase(const computorv2::Object* base);
			void                   setExponent(const computorv2::Object* exponent);
			void                   setFreeTerm(const computorv2::Object* freeterm);

			void                   setCoefficient(const double coefficient);
			void                   setExponent(const double exponent);
			void                   setFreeTerm(const double freeterm);

		private:
			Polynomial(void);
			computorv2::Object* _coefficient;
			computorv2::Object* _base;
			computorv2::Object* _exponent;
			computorv2::Object* _freeterm;
			void                init(const computorv2::Object* base);
			void                delCoefficient(void);
			void                delBase(void);
			void                delExponent(void);
			void                delFreeTerm(void);
	};
}

#define IS_POLYNOMIAL(o) ((OBJECT_TYPE(o) & COMPUTORV2_TYPE_POLYNOMIAL) != 0)
#define AS_POLYNOMIAL(o) static_cast< const computorv2::Polynomial* >(o)

std::ostream& operator<<(std::ostream& left, const computorv2::Polynomial& right);
