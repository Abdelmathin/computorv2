#pragma once

#include "utils.hpp"
#include "VirtualMachine.hpp"
#include <iostream>

namespace computorv2
{
    class Client
    {
        private:
            int                        _fdin;
            int                        _fdout;
            int                        _fderr;
            std::string                _buffer;
            computorv2::VirtualMachine _vm;
        public:
            Client(void);
            ~Client(void);
            Client(const Client& other);
            Client& operator=(const Client& other);

            int  getFdIn(void)  const;
            int  getFdOut(void) const;
            int  getFdErr(void) const;

            void setFdIn(int fd) ;
            void setFdOut(int fd);
            void setFdErr(int fd);

            void init(void);
            void clear(void);

            int  parse_line(std::string line);
            int  check_line(void);
            void addBuffer(std::string buffer);
    };
}
