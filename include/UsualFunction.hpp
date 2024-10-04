#pragma once

#include "Object.hpp"
#include <iostream>

namespace computorv2
{
    class UsualFunction: public computorv2::Object
    {
        private:
            UsualFunction(void);
            std::string         _name;
            computorv2::Object* _body;
            void                setName(const std::string& name);
            void                setBody(const computorv2::Object* body);
            void                init(void);
            void                clear(void);
        public:
            UsualFunction(const std::string& name, const computorv2::Object* body);
            ~UsualFunction(void);
            UsualFunction(const UsualFunction& other);
            UsualFunction& operator=(const UsualFunction& other);

            int                  getType(void)  const;
            std::string          getName(void)  const;
            computorv2::Object*  getBody(void)  const;
            std::string          toString(void) const;
            computorv2::Object*  copy(void)     const;
            computorv2::Object*  evaluate(void) const;
            bool                 isnull(void)   const;
            bool                 isunity(void)  const;
    };
}
