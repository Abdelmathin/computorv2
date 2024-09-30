#pragma once
#include "Object.hpp"
#include <iostream>
#include <map>

namespace computorv2
{
	class VirtualMachine
	{
		private:
			computorv2::Object*                         _independent;
			std::map< std::string, computorv2::Object*> _variables;
			std::map< std::string, computorv2::Object*> _constants;
		public:
			VirtualMachine(void);
			~VirtualMachine(void);
			VirtualMachine(const VirtualMachine& other);
			VirtualMachine& operator=(const VirtualMachine& other);

			computorv2::Object* getIndependentVariable(void) const;
			computorv2::Object* getVariableByName(const std::string name) const;
			computorv2::Object* getConstantByName(const std::string name) const;

			void                setIndependentVariable(computorv2::Object* independent);
			void                setVariableByName(const std::string name, computorv2::Object* var);
			void                setConstantByName(const std::string name, computorv2::Object* var);

			void                clear(void);
	};
}
