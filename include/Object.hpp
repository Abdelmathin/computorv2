#pragma once

#include <iostream>

namespace computorv2
{
	class Object
	{
		private:
			std::string _name;
		public:
			Object(void);
			virtual ~Object(void);
			Object(const Object& other);
			Object& operator=(const Object& other);

			virtual int                 getType(void) const;
			virtual std::string         getName(void) const;

			void                        setName(std::string name);

			virtual std::string         toString(void) const;
			void                        clear(void);
			virtual computorv2::Object* copy(void) const;
	};
}
