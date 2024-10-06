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
#include "Matrix.hpp"
#include "Vector.hpp"
#include "Complex.hpp"
#include "Polynomial.hpp"
#include "UsualFunction.hpp"
#include "IndependentVariable.hpp"

namespace computorv2
{


    /* ----------------------------- isfreeterm ----------------------------- */
    bool isfreeterm(const computorv2::Object* left);
    bool isfreeterm(const computorv2::Vector& left);
    bool isfreeterm(const computorv2::Matrix& left);
    bool isfreeterm(const computorv2::Complex& left);
    bool isfreeterm(const computorv2::Polynomial& left);
    bool isfreeterm(const computorv2::UsualFunction& left);
    bool isfreeterm(const computorv2::IndependentVariable& left);

    /* --------------------------------------------- eql --------------------------------------------- */
    bool eql(const computorv2::Object*              left, const computorv2::Object*              right);
    bool eql(const computorv2::Vector&              left, const computorv2::Vector&              right);
    bool eql(const computorv2::Vector&              left, const computorv2::Matrix&              right);
    bool eql(const computorv2::Vector&              left, const computorv2::Complex&             right);
    bool eql(const computorv2::Vector&              left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::Vector&              left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::Vector&              left, const computorv2::IndependentVariable& right);
    bool eql(const computorv2::Matrix&              left, const computorv2::Vector&              right);
    bool eql(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    bool eql(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    bool eql(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    bool eql(const computorv2::Complex&             left, const computorv2::Vector&              right);
    bool eql(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    bool eql(const computorv2::Complex&             left, const computorv2::Complex&             right);
    bool eql(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::Vector&              right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::Vector&              right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::Vector&              right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ------------------------------------------------------------- derivative ------------------------------------------------------------- */
    computorv2::Polynomial derivative(const computorv2::Object*              left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::Vector&              left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ------------------------------------------------------ add ------------------------------------------------------ */
    computorv2::Object*    add(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Vector     add(const computorv2::Vector&              left, const computorv2::Vector&              right);
    computorv2::Matrix     add(const computorv2::Vector&              left, const computorv2::Matrix&              right);
    computorv2::Vector     add(const computorv2::Vector&              left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::Vector&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::Vector&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::Vector&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     add(const computorv2::Matrix&              left, const computorv2::Vector&              right);
    computorv2::Matrix     add(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     add(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Vector     add(const computorv2::Complex&             left, const computorv2::Vector&              right);
    computorv2::Matrix     add(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    add(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::Vector&              right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::Vector&              right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::Vector&              right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ------------------------------------------------------ sub ------------------------------------------------------ */
    computorv2::Object*    sub(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Vector     sub(const computorv2::Vector&              left, const computorv2::Vector&              right);
    computorv2::Matrix     sub(const computorv2::Vector&              left, const computorv2::Matrix&              right);
    computorv2::Vector     sub(const computorv2::Vector&              left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::Vector&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::Vector&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::Vector&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     sub(const computorv2::Matrix&              left, const computorv2::Vector&              right);
    computorv2::Matrix     sub(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     sub(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Vector     sub(const computorv2::Complex&             left, const computorv2::Vector&              right);
    computorv2::Matrix     sub(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    sub(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::Vector&              right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::Vector&              right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::Vector&              right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ------------------------------------------------------ mul ------------------------------------------------------ */
    computorv2::Object*    mul(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Vector     mul(const computorv2::Vector&              left, const computorv2::Vector&              right);
    computorv2::Matrix     mul(const computorv2::Vector&              left, const computorv2::Matrix&              right);
    computorv2::Vector     mul(const computorv2::Vector&              left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::Vector&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::Vector&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::Vector&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     mul(const computorv2::Matrix&              left, const computorv2::Vector&              right);
    computorv2::Matrix     mul(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     mul(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Vector     mul(const computorv2::Complex&             left, const computorv2::Vector&              right);
    computorv2::Matrix     mul(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    mul(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::Vector&              right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::Vector&              right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::Vector&              right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ------------------------------------------------------ div ------------------------------------------------------ */
    computorv2::Object*    div(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Vector     div(const computorv2::Vector&              left, const computorv2::Vector&              right);
    computorv2::Matrix     div(const computorv2::Vector&              left, const computorv2::Matrix&              right);
    computorv2::Vector     div(const computorv2::Vector&              left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::Vector&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::Vector&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::Vector&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     div(const computorv2::Matrix&              left, const computorv2::Vector&              right);
    computorv2::Matrix     div(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     div(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Vector     div(const computorv2::Complex&             left, const computorv2::Vector&              right);
    computorv2::Matrix     div(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    div(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::Vector&              right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::Vector&              right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::Vector&              right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ------------------------------------------------------ mod ------------------------------------------------------ */
    computorv2::Object*    mod(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Vector     mod(const computorv2::Vector&              left, const computorv2::Vector&              right);
    computorv2::Matrix     mod(const computorv2::Vector&              left, const computorv2::Matrix&              right);
    computorv2::Vector     mod(const computorv2::Vector&              left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::Vector&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::Vector&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::Vector&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     mod(const computorv2::Matrix&              left, const computorv2::Vector&              right);
    computorv2::Matrix     mod(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     mod(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Vector     mod(const computorv2::Complex&             left, const computorv2::Vector&              right);
    computorv2::Matrix     mod(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    mod(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::Vector&              right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::Vector&              right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::Vector&              right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ------------------------------------------------------ pow ------------------------------------------------------ */
    computorv2::Object*    pow(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Vector     pow(const computorv2::Vector&              left, const computorv2::Vector&              right);
    computorv2::Matrix     pow(const computorv2::Vector&              left, const computorv2::Matrix&              right);
    computorv2::Vector     pow(const computorv2::Vector&              left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::Vector&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::Vector&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::Vector&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     pow(const computorv2::Matrix&              left, const computorv2::Vector&              right);
    computorv2::Matrix     pow(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     pow(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Vector     pow(const computorv2::Complex&             left, const computorv2::Vector&              right);
    computorv2::Matrix     pow(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    pow(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::Vector&              right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::Vector&              right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::Vector&              right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);
}
