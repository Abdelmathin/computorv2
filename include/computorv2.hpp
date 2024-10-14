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
# include <map>

typedef int t_error;

#define COMPUTORV2_EPSILON                   0.0000001
#define ABS(x)                               ( (x) >= 0 ? (x) : -(x) )
#define IS_ZERO(x)                           ( ABS(x) < COMPUTORV2_EPSILON )

#define MAX_MATRIX_DET_SIZE                  4
#define MAX_MATRIX_ROWS                      4
#define MAX_MATRIX_COLUMNS                   4

#define CHARACTER_SINGLE_QUOTE               0x27 /* ' */
#define CHARACTER_PLUS                       '+'
#define CHARACTER_MINUS                      '-'
#define CHARACTER_ASTERISK                   '*'
#define CHARACTER_SLASH                      '/'
#define CHARACTER_CARET                      '^'
#define CHARACTER_MODULUS                    '%'

#define COMPUTORV2_CASE_INSENSITIVE          1
#define COMPUTORV2_SUCCESS                   (0 << 0)
#define COMPUTORV2_ERROR                     (1 << 0)

// #define ERROR_NOT_ENOUGH_MEMORY              (1 << 0)
// #define ERROR_NAN                            (1 << 1)

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
#define COMPUTORV2_OPERATION_POW             (1 << 4)
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
#define IS_SPACE(c)        ((c == ' ') || (c == '	'))
#define IS_VARSTART(c)     ((c == '_') || (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')))
#define IS_VARCHAR(c)      (IS_DIGIT(c) || IS_VARSTART(c))

#define OBJECT_TYPE(obj)   (obj ? ((obj)->getType()) : 0)

namespace computorv2
{
	class Object;
	class Matrix;
	class Complex;
    class Polynomial;
	class VirtualMachine;
    class UsualFunction;
    class IndependentVariable;

    const std::string crlf = "\r\n";

	std::string tolower(const std::string s);
	bool        isname(const std::string& name);
	bool        isUsualFunction(const std::string& name);
    std::string ltrim(const std::string str);
    std::string rtrim(const std::string str);
    std::string trim(const std::string str);
    std::string ltrim(const std::string str, const std::string charset);
    std::string rtrim(const std::string str, const std::string charset);
    std::string trim(const std::string str, const std::string charset);

    void variables(const computorv2::Object* left, std::map< std::string, const computorv2::Object*>& right);
    computorv2::Object* replace(const computorv2::Object* left, std::map< std::string, const computorv2::Object*>& right);
    computorv2::Object* evaluate(const computorv2::Object* left);

    /* ----------------------- transpose ----------------------- */
    computorv2::Matrix  transpose(const computorv2::Matrix& left);

    /* ----------------------- cofactor ----------------------- */
    computorv2::Matrix  cofactor(const computorv2::Matrix& left);

    /* ----------------------- adjugate ----------------------- */
    computorv2::Matrix  adjugate(const computorv2::Matrix& left);

    /* ---------------------- det ---------------------- */
    computorv2::Object* det(const computorv2::Matrix& left);

    /* -------------------------------- ln -------------------------------- */
    computorv2::UsualFunction ln(const computorv2::Object*              left);
    computorv2::UsualFunction ln(const computorv2::Matrix&              left);
    computorv2::UsualFunction ln(const computorv2::Complex&             left);
    computorv2::UsualFunction ln(const computorv2::Polynomial&          left);
    computorv2::UsualFunction ln(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction ln(const computorv2::IndependentVariable& left);

    /* -------------------------------- exp -------------------------------- */
    computorv2::UsualFunction exp(const computorv2::Object*              left);
    computorv2::UsualFunction exp(const computorv2::Matrix&              left);
    computorv2::UsualFunction exp(const computorv2::Complex&             left);
    computorv2::UsualFunction exp(const computorv2::Polynomial&          left);
    computorv2::UsualFunction exp(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction exp(const computorv2::IndependentVariable& left);

    /* -------------------------------- sin -------------------------------- */
    computorv2::UsualFunction sin(const computorv2::Object*              left);
    computorv2::UsualFunction sin(const computorv2::Matrix&              left);
    computorv2::UsualFunction sin(const computorv2::Complex&             left);
    computorv2::UsualFunction sin(const computorv2::Polynomial&          left);
    computorv2::UsualFunction sin(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction sin(const computorv2::IndependentVariable& left);

    /* -------------------------------- cos -------------------------------- */
    computorv2::UsualFunction cos(const computorv2::Object*              left);
    computorv2::UsualFunction cos(const computorv2::Matrix&              left);
    computorv2::UsualFunction cos(const computorv2::Complex&             left);
    computorv2::UsualFunction cos(const computorv2::Polynomial&          left);
    computorv2::UsualFunction cos(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction cos(const computorv2::IndependentVariable& left);

    /* -------------------------------- tan -------------------------------- */
    computorv2::UsualFunction tan(const computorv2::Object*              left);
    computorv2::UsualFunction tan(const computorv2::Matrix&              left);
    computorv2::UsualFunction tan(const computorv2::Complex&             left);
    computorv2::UsualFunction tan(const computorv2::Polynomial&          left);
    computorv2::UsualFunction tan(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction tan(const computorv2::IndependentVariable& left);

    /* -------------------------------- sinh -------------------------------- */
    computorv2::UsualFunction sinh(const computorv2::Object*              left);
    computorv2::UsualFunction sinh(const computorv2::Matrix&              left);
    computorv2::UsualFunction sinh(const computorv2::Complex&             left);
    computorv2::UsualFunction sinh(const computorv2::Polynomial&          left);
    computorv2::UsualFunction sinh(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction sinh(const computorv2::IndependentVariable& left);

    /* -------------------------------- cosh -------------------------------- */
    computorv2::UsualFunction cosh(const computorv2::Object*              left);
    computorv2::UsualFunction cosh(const computorv2::Matrix&              left);
    computorv2::UsualFunction cosh(const computorv2::Complex&             left);
    computorv2::UsualFunction cosh(const computorv2::Polynomial&          left);
    computorv2::UsualFunction cosh(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction cosh(const computorv2::IndependentVariable& left);

    /* -------------------------------- tanh -------------------------------- */
    computorv2::UsualFunction tanh(const computorv2::Object*              left);
    computorv2::UsualFunction tanh(const computorv2::Matrix&              left);
    computorv2::UsualFunction tanh(const computorv2::Complex&             left);
    computorv2::UsualFunction tanh(const computorv2::Polynomial&          left);
    computorv2::UsualFunction tanh(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction tanh(const computorv2::IndependentVariable& left);

    /* -------------------------------- arcsin -------------------------------- */
    computorv2::UsualFunction arcsin(const computorv2::Object*              left);
    computorv2::UsualFunction arcsin(const computorv2::Matrix&              left);
    computorv2::UsualFunction arcsin(const computorv2::Complex&             left);
    computorv2::UsualFunction arcsin(const computorv2::Polynomial&          left);
    computorv2::UsualFunction arcsin(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction arcsin(const computorv2::IndependentVariable& left);

    /* -------------------------------- arccos -------------------------------- */
    computorv2::UsualFunction arccos(const computorv2::Object*              left);
    computorv2::UsualFunction arccos(const computorv2::Matrix&              left);
    computorv2::UsualFunction arccos(const computorv2::Complex&             left);
    computorv2::UsualFunction arccos(const computorv2::Polynomial&          left);
    computorv2::UsualFunction arccos(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction arccos(const computorv2::IndependentVariable& left);

    /* -------------------------------- arctan -------------------------------- */
    computorv2::UsualFunction arctan(const computorv2::Object*              left);
    computorv2::UsualFunction arctan(const computorv2::Matrix&              left);
    computorv2::UsualFunction arctan(const computorv2::Complex&             left);
    computorv2::UsualFunction arctan(const computorv2::Polynomial&          left);
    computorv2::UsualFunction arctan(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction arctan(const computorv2::IndependentVariable& left);

    /* -------------------------------- arcsinh -------------------------------- */
    computorv2::UsualFunction arcsinh(const computorv2::Object*              left);
    computorv2::UsualFunction arcsinh(const computorv2::Matrix&              left);
    computorv2::UsualFunction arcsinh(const computorv2::Complex&             left);
    computorv2::UsualFunction arcsinh(const computorv2::Polynomial&          left);
    computorv2::UsualFunction arcsinh(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction arcsinh(const computorv2::IndependentVariable& left);

    /* -------------------------------- arccosh -------------------------------- */
    computorv2::UsualFunction arccosh(const computorv2::Object*              left);
    computorv2::UsualFunction arccosh(const computorv2::Matrix&              left);
    computorv2::UsualFunction arccosh(const computorv2::Complex&             left);
    computorv2::UsualFunction arccosh(const computorv2::Polynomial&          left);
    computorv2::UsualFunction arccosh(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction arccosh(const computorv2::IndependentVariable& left);

    /* -------------------------------- arctanh -------------------------------- */
    computorv2::UsualFunction arctanh(const computorv2::Object*              left);
    computorv2::UsualFunction arctanh(const computorv2::Matrix&              left);
    computorv2::UsualFunction arctanh(const computorv2::Complex&             left);
    computorv2::UsualFunction arctanh(const computorv2::Polynomial&          left);
    computorv2::UsualFunction arctanh(const computorv2::UsualFunction&       left);
    computorv2::UsualFunction arctanh(const computorv2::IndependentVariable& left);

    /* --------------------- isfreeterm --------------------- */
    bool isfreeterm(const computorv2::Object*              left);
    bool isfreeterm(const computorv2::Matrix&              left);
    bool isfreeterm(const computorv2::Complex&             left);
    bool isfreeterm(const computorv2::Polynomial&          left);
    bool isfreeterm(const computorv2::UsualFunction&       left);
    bool isfreeterm(const computorv2::IndependentVariable& left);

    /* -------------------------------------------- eql -------------------------------------------- */
    bool eql(const computorv2::Object*              left, const computorv2::Object*              right);
    bool eql(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    bool eql(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    bool eql(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    bool eql(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    bool eql(const computorv2::Complex&             left, const computorv2::Complex&             right);
    bool eql(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    bool eql(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ------------------------------ neg ------------------------------ */
    computorv2::Object*    neg(const computorv2::Object*              left);
    computorv2::Matrix     neg(const computorv2::Matrix&              left);
    computorv2::Complex    neg(const computorv2::Complex&             left);
    computorv2::Polynomial neg(const computorv2::Polynomial&          left);
    computorv2::Polynomial neg(const computorv2::UsualFunction&       left);
    computorv2::Polynomial neg(const computorv2::IndependentVariable& left);

    /* ------------------------------ inv ------------------------------ */
    computorv2::Object*    inv(const computorv2::Object*              left);
    computorv2::Matrix     inv(const computorv2::Matrix&              left);
    computorv2::Complex    inv(const computorv2::Complex&             left);
    computorv2::Polynomial inv(const computorv2::Polynomial&          left);
    computorv2::Polynomial inv(const computorv2::UsualFunction&       left);
    computorv2::Polynomial inv(const computorv2::IndependentVariable& left);

    /* ----------------------------------------------------- mul ----------------------------------------------------- */
    computorv2::Object*    mul(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Matrix     mul(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     mul(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     mul(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    mul(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mul(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ----------------------------------------------------- div ----------------------------------------------------- */
    computorv2::Object*    div(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Matrix     div(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     div(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     div(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    div(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial div(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ----------------------------------------------------- add ----------------------------------------------------- */
    computorv2::Object*    add(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Matrix     add(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     add(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     add(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    add(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial add(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ----------------------------------------------------- sub ----------------------------------------------------- */
    computorv2::Object*    sub(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Matrix     sub(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     sub(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     sub(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    sub(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial sub(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ----------------------------------------------------- mod ----------------------------------------------------- */
    computorv2::Object*    mod(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Matrix     mod(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     mod(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     mod(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    mod(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial mod(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ----------------------------------------------------- pow ----------------------------------------------------- */
    computorv2::Object*    pow(const computorv2::Object*              left, const computorv2::Object*              right);
    computorv2::Matrix     pow(const computorv2::Matrix&              left, const computorv2::Matrix&              right);
    computorv2::Matrix     pow(const computorv2::Matrix&              left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::Matrix&              left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::Matrix&              left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Matrix     pow(const computorv2::Complex&             left, const computorv2::Matrix&              right);
    computorv2::Complex    pow(const computorv2::Complex&             left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::Complex&             left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::Complex&             left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::Matrix&              right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::Matrix&              right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::Matrix&              right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::Complex&             right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::Polynomial&          right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::UsualFunction&       right);
    computorv2::Polynomial pow(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);

    /* ----------------------------------------------------- drv ----------------------------------------------------- */
    computorv2::Polynomial drv(const computorv2::Object*              left);
    computorv2::Polynomial drv(const computorv2::Object*              left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial drv(const computorv2::Matrix&              left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial drv(const computorv2::Complex&             left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial drv(const computorv2::Polynomial&          left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial drv(const computorv2::UsualFunction&       left, const computorv2::IndependentVariable& right);
    computorv2::Polynomial drv(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right);
}
