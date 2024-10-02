#pragma once

#include "Object.hpp"
#include <iostream>

namespace computorv2
{
	class Rational: public computorv2::Object
	{
		private:
			std::string _name;
			double      _value;
		public:
			Rational(void);
			~Rational(void);
			Rational(const Rational& other);
			Rational& operator=(const Rational& other);

			Rational(double value);

			int                 getType(void) const;
			std::string         getName(void) const;
			double              getValue(void) const;

			void                setName(std::string name);
			void                setValue(double value);

			std::string         toString(void) const;
			void                clear(void);
			computorv2::Object* copy(void) const;
			bool                isnull(void) const;
			bool                isunity(void) const;
	};
}

bool operator==(const computorv2::Rational& left, const computorv2::Rational& right);
