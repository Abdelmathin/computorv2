#pragma once

#include "Object.hpp"
#include <iostream>

namespace computorv2
{
	class IndependentVariable: public computorv2::Object
	{
		private:
			IndependentVariable(void);
			std::string _name;
		public:
			IndependentVariable(const std::string& name);
			~IndependentVariable(void);
			IndependentVariable(const IndependentVariable& other);
			IndependentVariable& operator=(const IndependentVariable& other);

			int                  getType(void) const;
			std::string          getName(void) const;

			void                 setName(const std::string& name);

			std::string          toString(void) const;
			computorv2::Object*  copy(void) const;
			bool                 isnull(void) const;
			bool                 isunity(void) const;
	};
}
