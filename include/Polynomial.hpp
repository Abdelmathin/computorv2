#pragma once

#include "Object.hpp"
#include <iostream>

namespace computorv2
{
	class Polynomial: public computorv2::Object
	{
		private:
			std::string            _name;
			computorv2::Object*    _coefficient;
			computorv2::Object*    _exponent;
			computorv2::Object*    _freeterm;
			void                   init(void);
			void                   delCoefficient(void);
			void                   delExponent(void);
			void                   delFreeTerm(void);
		public:
			Polynomial(void);
			~Polynomial(void);
			Polynomial(const Polynomial& other);
			Polynomial&            operator=(const Polynomial& other);
			int                    getType(void) const;

			std::string            getName(void) const;
			computorv2::Object*    getCoefficient(void) const;
			computorv2::Object*    getExponent(void) const;
			computorv2::Object*    getFreeTerm(void) const;

			void                   setName(const std::string& name);
			void                   setCoefficient(const computorv2::Object* coefficient);
			void                   setExponent(const computorv2::Object* exponent);
			void                   setFreeTerm(const computorv2::Object* freeterm);

			std::string            toString(void) const;
			computorv2::Object*    copy(void) const;
			void                   simplify(void);
			bool                   isnull(void) const;
			bool                   isunity(void) const;
	};
}
