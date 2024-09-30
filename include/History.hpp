#pragma once

#include "Object.hpp"
#include <iostream>
#include <vector>

namespace computorv2
{
    class History: public computorv2::Object
    {
        private:
            std::vector< std::string > _data;
        public:
            History(void);
            ~History(void);
            History(const History& other);
            History& operator=(const History& other);

            std::string         toString(void) const;
            void                clear(void);
            computorv2::Object* copy(void) const;
    };
}
