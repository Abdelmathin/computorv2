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

namespace computorv2
{


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

    /* ------------------------------------------------------ add ------------------------------------------------------ */
    computorv2::Object*    add(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Vector     add(const computorv2::Vector&              left, const computorv2::Vector&              right);
    computorv2::Matrix     add(const computorv2::Vector&              left, const computorv2::Matrix&              right);
    computorv2::Polynomial add(const computorv2::Vector&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::Vector&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::Vector&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     add(const computorv2::Matrix&              left, const computorv2::Vector&              right);
    computorv2::Polynomial add(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::Vector&              right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::Vector&              right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::Vector&              right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
}
