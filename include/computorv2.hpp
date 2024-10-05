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

namespace computorv2
{
	/* operations */
	computorv2::Object*    pow(const computorv2::Object* left, const computorv2::Object* right);


	bool isfreeterm(const computorv2::Object* obj);



	/* Complex (add) */
	computorv2::Complex    add(const computorv2::Complex& left, const computorv2::Complex& right);


	/* Polynomial (add) */
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

	/* Object (eql) */
	bool                   eql(const computorv2::Object* left, const computorv2::Object* right);

	/* derivative (Object) */
	computorv2::Polynomial derivative(const computorv2::Object* obj);

	/* derivative (Complex) */
	computorv2::Polynomial derivative(const computorv2::Complex& obj);

	/* derivative (Polynomial) */
	computorv2::Polynomial derivative(const computorv2::Polynomial& obj);
}
