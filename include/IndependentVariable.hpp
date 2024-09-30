#pragma once

#include "Object.hpp"
#include "Complex.hpp"
#include <iostream>

namespace computorv2
{
	class IndependentVariable: public computorv2::Object
	{
		private:
			std::string           _name;
			computorv2::Complex*  _coefficient;
			computorv2::Rational* _exponent;
			computorv2::Object*   _constant;
		public:
			IndependentVariable(void);
			~IndependentVariable(void);
			IndependentVariable(const IndependentVariable& other);
			IndependentVariable& operator=(const IndependentVariable& other);

			int                   getType(void) const;
			std::string           getName(void) const;
			computorv2::Complex*  getCoefficient(void) const;
			computorv2::Rational* getExponent(void) const;
			computorv2::Object*   getConstant(void) const;

			void                  setName(std::string name);
			void                  setCoefficient(const computorv2::Complex* coefficient);
			void                  setExponent(const computorv2::Rational* exponent);
			void                  setConstant(const computorv2::Object* constant);
			std::string           toString(void) const;
			void                  init(void);
			void                  clear(void);
			computorv2::Object*   copy(void) const;
	};
}
