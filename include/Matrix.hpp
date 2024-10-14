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
            int                        getType(void)     const;
            std::string                getTypeName(void) const;
            std::string                toString(void)    const;
            computorv2::Object*        copy(void)        const;
            bool                       isnull(void)      const;
            bool                       isunity(void)     const;
            bool                       isnegative(void)  const;

            ~Matrix(void);
            Matrix(const Matrix& other);
            Matrix& operator=(const Matrix& other);

            void                setElementAt(unsigned int row, unsigned int column, const computorv2::Object* element);
            computorv2::Object* getElementAt(unsigned int row, unsigned int column) const;
            unsigned int        rows(void)    const;
            unsigned int        columns(void) const;

            Matrix(unsigned int rows, unsigned int columns);
            Matrix(const computorv2::Matrix& other, unsigned int excluded_row, unsigned int excluded_column);

        private:
            unsigned int                       _rows;
            unsigned int                       _columns;
            std::vector< computorv2::Object* > _data;
            void clear(void);
            Matrix(void);
    };
}

#define IS_MATRIX(o) ((OBJECT_TYPE(o) & COMPUTORV2_TYPE_MATRIX) != 0)
#define AS_MATRIX(o) static_cast< const computorv2::Matrix* >(o)

std::ostream& operator<<(std::ostream& left, const computorv2::Matrix& right);
