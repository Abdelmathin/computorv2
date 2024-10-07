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

# include <iostream>

typedef int t_error;

#define COMPUTORV2_EPSILON                   0.0000001
#define ABS(x)                               ( (x) >= 0 ? (x) : -(x) )
#define IS_ZERO(x)                           ( ABS(x) < COMPUTORV2_EPSILON )

#define COMPUTORV2_CASE_INSENSITIVE          1
#define COMPUTORV2_SUCCESS                   (0 << 0)
#define COMPUTORV2_ERROR                     (1 << 0)

#define ERROR_NOT_ENOUGH_MEMORY              (1 << 0)
#define ERROR_NAN                            (1 << 1)

#define STATMENT_TYPE_UNKNOWN                (0 << 0)
#define STATMENT_TYPE_GET                    (1 << 0) /* x = ? */
#define STATMENT_TYPE_SET_VARIABLE           (1 << 1) /* x = y */
#define STATMENT_TYPE_SET_FUNCTION           (1 << 2) /* f(x) = 2 * x */
#define STATMENT_TYPE_SOLVE                  (1 << 3) /* x = y ? */

#define COMPUTORV2_OPERATION_NONE            (0 << 0)
#define COMPUTORV2_OPERATION_ADD             (1 << 0)
#define COMPUTORV2_OPERATION_SUB             (1 << 1)
#define COMPUTORV2_OPERATION_MULT            (1 << 2)
#define COMPUTORV2_OPERATION_DIV             (1 << 3)
#define COMPUTORV2_OPERATION_EXP             (1 << 4)
#define COMPUTORV2_OPERATION_MATRIX_MULT     (1 << 5)
#define COMPUTORV2_OPERATION_MOD             (1 << 6)

#define COMPUTORV2_TYPE_UNKNOWN              (0 << 0)
#define COMPUTORV2_TYPE_INTEGER              (1 << 0)
#define COMPUTORV2_TYPE_RATIONAL             (1 << 1)
#define COMPUTORV2_TYPE_VECTOR               (1 << 2)
#define COMPUTORV2_TYPE_MATRIX               (1 << 3)
#define COMPUTORV2_TYPE_COMPLEX              (1 << 4)
#define COMPUTORV2_TYPE_FUNCTION             (1 << 5)
#define COMPUTORV2_TYPE_USUAL_FUNCTION       (1 << 6)
#define COMPUTORV2_TYPE_POLYNOMIAL           (1 << 7)
#define COMPUTORV2_TYPE_INDEPENDENT_VARIABLE (1 << 8)

#define CHARCODE(c)        ((int)(c))
#define IS_DIGIT(c)        (('0' <= c) && (c <= '9'))
#define IS_SPACE(c)        ((c == ' ') || (c == '\t'))
#define IS_VARSTART(c)     ((c == '_') || (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')))
#define IS_VARCHAR(c)      (IS_DIGIT(c) || IS_VARSTART(c))

#define OBJECT_TYPE(obj)   (obj ? ((obj)->getType()) : 0)

namespace computorv2
{
	class Object;
	class Matrix;
	class Vector;
	class Complex;
	class History;
    class Polynomial;
	class VirtualMachine;
    class UsualFunction;
    class IndependentVariable;

	std::string tolower(const std::string s);
	bool        isname(const std::string& name);
	bool        isUsualFunction(const std::string& name);
	std::string ltrim(const std::string s);



    /* ------------------------------ inverse ------------------------------ */
    computorv2::Polynomial inverse(const computorv2::Object*              left);
    computorv2::Polynomial inverse(const computorv2::Vector&              left);
    computorv2::Polynomial inverse(const computorv2::Matrix&              left);
    computorv2::Polynomial inverse(const computorv2::Complex&             left);
    computorv2::Polynomial inverse(const computorv2::Polynomial&          left);
    computorv2::Polynomial inverse(const computorv2::UsualFunction&       left);
    computorv2::Polynomial inverse(const computorv2::IndependentVariable& left);

    /* --------------------- isfreeterm --------------------- */
    bool isfreeterm(const computorv2::Object*              left);
    bool isfreeterm(const computorv2::Vector&              left);
    bool isfreeterm(const computorv2::Matrix&              left);
    bool isfreeterm(const computorv2::Complex&             left);
    bool isfreeterm(const computorv2::Polynomial&          left);
    bool isfreeterm(const computorv2::UsualFunction&       left);
    bool isfreeterm(const computorv2::IndependentVariable& left);

    /* -------------------------------------------- eql -------------------------------------------- */
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

    /* ----------------------------------------------------- derivative ----------------------------------------------------- */
    computorv2::Polynomial derivative(const computorv2::Object*              left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::Vector&              left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial derivative(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ----------------------------------------------------- add ----------------------------------------------------- */
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

    /* ----------------------------------------------------- sub ----------------------------------------------------- */
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

    /* ----------------------------------------------------- mul ----------------------------------------------------- */
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

    /* ----------------------------------------------------- div ----------------------------------------------------- */
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

    /* ----------------------------------------------------- mod ----------------------------------------------------- */
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

    /* ----------------------------------------------------- pow ----------------------------------------------------- */
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
