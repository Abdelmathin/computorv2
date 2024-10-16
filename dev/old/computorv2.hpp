/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   computorv2.hpp                                     :+:      :+:    :+:    */
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

#include "utils.hpp"
#include "Object.hpp"
#include "Complex.hpp"
#include "Polynomial.hpp"
#include "UsualFunction.hpp"
#include "IndependentVariable.hpp"

/*
	add, sub, mul, div, mod, eql, drv, pow, neg, replace(old, new)
*/

namespace computorv2
{
	/* -------------------------------------------- eql -------------------------------------------- */
	bool eql(const computorv2::Object*              left, const computorv2::Object*              right);
	bool eql(const computorv2::Complex&             left, const computorv2::Complex&             right);
	bool eql(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);
	bool eql(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
	bool eql(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
	bool eql(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
	bool eql(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
	bool eql(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
	bool eql(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
	bool eql(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
	bool eql(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
	bool eql(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
	bool eql(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
	bool eql(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
	bool eql(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
	bool eql(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
	bool eql(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);










	/* operations */
	computorv2::Object*    div(const computorv2::Object* left, const computorv2::Object* right);
	computorv2::Object*    pow(const computorv2::Object* left, const computorv2::Object* right);
	bool                   eql(const computorv2::Object* left, const computorv2::Object* right);

	bool                   eql(const computorv2::Complex& left, const computorv2::Complex& right);
	bool                   eql(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);
	bool                   eql(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right);
	bool                   eql(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right);
	bool                   eql(const computorv2::Polynomial& left, const computorv2::Polynomial& right);

	computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::Complex& right);
	computorv2::Polynomial pow(const computorv2::UsualFunction& left, const computorv2::Complex& right);


	bool isfreeterm(const computorv2::Object* obj);



	/* Complex (add) */
	computorv2::Complex    add(const computorv2::Complex& left, const computorv2::Complex& right);


	/* Polynomial (add) */
	computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);
	computorv2::Polynomial add(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right);
	computorv2::Polynomial add(const computorv2::Polynomial& left, const computorv2::Complex& right);
	computorv2::Polynomial add(const computorv2::Complex& left, const computorv2::Polynomial& right);
	computorv2::Polynomial add(const computorv2::Polynomial& left, const computorv2::Polynomial& right);

	/* Object (add) */
	computorv2::Object*    add(const computorv2::Object* left, const computorv2::Object* right);

	/* Complex (mul) */
	computorv2::Complex    mul(const computorv2::Complex& left, const computorv2::Complex& right);

	/* Polynomial (mul) */
	computorv2::Polynomial mul(const computorv2::Polynomial& left, const computorv2::Complex& right);
	computorv2::Polynomial mul(const computorv2::Complex& left, const computorv2::Polynomial& right);
	computorv2::Polynomial mul(const computorv2::Polynomial& left, const computorv2::Polynomial& right);
	computorv2::Object*    mul(const computorv2::Object* left, const computorv2::Object* right);


	/* derivative (Object) */
	computorv2::Polynomial derivative(const computorv2::Object* obj, const computorv2::IndependentVariable& x);

	/* derivative (Complex) */
	computorv2::Polynomial derivative(const computorv2::Complex& obj, const computorv2::IndependentVariable& x);

	/* derivative (IndependentVariable) */
	computorv2::Polynomial derivative(const computorv2::IndependentVariable& y, const computorv2::IndependentVariable& x);

	/* derivative (Polynomial) */
	computorv2::Polynomial derivative(const computorv2::Polynomial& obj, const computorv2::IndependentVariable& x);
}
