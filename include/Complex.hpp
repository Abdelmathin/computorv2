#pragma once

#include "Object.hpp"
#include <iostream>

namespace computorv2
{
    class Complex: public computorv2::Object
    {
        private:
            std::string _name;
            double      _real;
            double      _imag;
        public:
            Complex(void);
            ~Complex(void);
            Complex(const Complex& other);
            Complex& operator=(const Complex& other);

            Complex(double real, double image);

            std::string         getName(void)  const;
            double              getReal(void)  const;
            double              getImage(void) const;

            void                setName(std::string name);
            void                setReal(double real) ;
            void                setImage(double imag);

            std::string         toString(void) const;
            void                clear(void);
            computorv2::Object* copy(void) const;
            bool                isnull(void) const;
    };
}

computorv2::Complex operator+(const computorv2::Complex& left, const computorv2::Complex& right);
computorv2::Complex operator-(const computorv2::Complex& left, const computorv2::Complex& right);
computorv2::Complex operator-(const computorv2::Complex& left);
computorv2::Complex operator*(const computorv2::Complex& left, const computorv2::Complex& right);
computorv2::Complex operator*(const computorv2::Complex& left, double right);
computorv2::Complex operator*(double left, const computorv2::Complex& right);
computorv2::Complex operator/(const computorv2::Complex& left, const computorv2::Complex& right);
computorv2::Complex operator/(const computorv2::Complex& left, double right);
computorv2::Complex operator/(double left, const computorv2::Complex& right);
bool                operator==(const computorv2::Complex& left, const computorv2::Complex& right);
