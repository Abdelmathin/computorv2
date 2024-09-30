#pragma once

#include "Object.hpp"
#include <iostream>

namespace computorv2
{
    class Function: public computorv2::Object
    {
        private:
            std::string _name;
            std::string _body;
            std::string _ivar;
        public:
            Function(void);
            ~Function(void);
            Function(const Function& other);
            Function& operator=(const Function& other);

            int          getType(void) const;
            std::string  getName(void) const;
            std::string  getBody(void) const;
            std::string  getIndependentVariable(void) const;

            void         setName(const std::string name);
            void         setBody(const std::string body);
            void         setIndependentVariable(const std::string ivar);

            std::string  toString(void) const;
            void         clear(void);
            computorv2::Object* copy(void) const;
    };
}
