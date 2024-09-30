#pragma once

#include "Object.hpp"
#include <iostream>

namespace computorv2
{
	class IndependentVariable: public computorv2::Object
	{
		private:
			std::string _name;
		public:
			IndependentVariable(void);
			~IndependentVariable(void);
			IndependentVariable(const IndependentVariable& other);
			IndependentVariable& operator=(const IndependentVariable& other);

			int          getType(void) const;
			std::string  getName(void) const;

			void         setName(std::string name);

			std::string  toString(void) const;
			void         clear(void);
	};
}
