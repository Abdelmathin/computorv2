/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:    */
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
#include <vector>

namespace computorv2
{
    class Matrix: public computorv2::Object
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
            static Matrix       null(void);

            ~Matrix(void);
            Matrix(const Matrix& other);
            Matrix& operator=(const Matrix& other);

            Matrix(unsigned int rows, unsigned int columns);
            Matrix(
                const computorv2::Complex& i00, const computorv2::Complex& i01,
                const computorv2::Complex& i10, const computorv2::Complex& i11
            );
            Matrix(
                const computorv2::Complex &i00, const computorv2::Complex &i01, const computorv2::Complex &i02,
                const computorv2::Complex &i10, const computorv2::Complex &i11, const computorv2::Complex &i12,
                const computorv2::Complex &i20, const computorv2::Complex &i21, const computorv2::Complex &i22
            );
            Matrix(
                const computorv2::Complex &i00, const computorv2::Complex &i01, const computorv2::Complex &i02, const computorv2::Complex &i03,
                const computorv2::Complex &i10, const computorv2::Complex &i11, const computorv2::Complex &i12, const computorv2::Complex &i13,
                const computorv2::Complex &i20, const computorv2::Complex &i21, const computorv2::Complex &i22, const computorv2::Complex &i23,
                const computorv2::Complex &i30, const computorv2::Complex &i31, const computorv2::Complex &i32, const computorv2::Complex &i33
            );
            void                setElementAt(unsigned int row, unsigned int column, const computorv2::Complex& element);
            void                setElementAt(unsigned int row, unsigned int column, const computorv2::Object*  element);
            computorv2::Object* getElementAt(unsigned int row, unsigned int column) const;
            unsigned int        rows(void)    const;
            unsigned int        columns(void) const;
        private:
            void clear(void);
            Matrix(void);
            unsigned int                       _rows;
            unsigned int                       _columns;
            std::vector< computorv2::Object* > _data;
    };
}

#define IS_MATRIX(o) ((OBJECT_TYPE(o) & COMPUTORV2_TYPE_MATRIX) != 0)
#define AS_MATRIX(o) static_cast< const computorv2::Matrix* >(o)

std::ostream& operator<<(std::ostream& left, const computorv2::Matrix& right);
