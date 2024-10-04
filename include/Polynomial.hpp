#pragma once

#include "Object.hpp"
#include "IndependentVariable.hpp"
#include <iostream>

namespace computorv2
{
	class Polynomial: public computorv2::Object
	{
		private:
			Polynomial(void);
			computorv2::Object*    _coefficient;
			computorv2::Object*    _base;
			computorv2::Object*    _exponent;
			computorv2::Object*    _freeterm;
			void                   init(const computorv2::Object* base);
			void                   delCoefficient(void);
			void                   delBase(void);
			void                   delExponent(void);
			void                   delFreeTerm(void);
		public:
			Polynomial(const std::string& basename);
			Polynomial(const computorv2::IndependentVariable& base);
			Polynomial(const computorv2::IndependentVariable* base);
			~Polynomial(void);
			Polynomial(const Polynomial& other);
			Polynomial&            operator=(const Polynomial& other);
			int                    getType(void) const;

			computorv2::Object*    getCoefficient(void) const;
			computorv2::Object*    getBase(void) const;
			computorv2::Object*    getExponent(void) const;
			computorv2::Object*    getFreeTerm(void) const;

			void                   setCoefficient(const computorv2::Object* coefficient);
			void                   setBase(const computorv2::Object* base);
			void                   setExponent(const computorv2::Object* exponent);
			void                   setFreeTerm(const computorv2::Object* freeterm);

			void                   setCoefficient(const computorv2::Object& coefficient);
			void                   setBase(const computorv2::Object& base);
			void                   setExponent(const computorv2::Object& exponent);
			void                   setFreeTerm(const computorv2::Object& freeterm);

			std::string            toString(void) const;
			computorv2::Object*    copy(void) const;
			void                   simplify(void);
			bool                   isnull(void) const;
			bool                   isunity(void) const;
	};
}
