#include <iostream>

#include "../../../../sources/Object.cpp"
#include "../../../../sources/VirtualMachine.cpp"
#include "../../../../sources/Rational.cpp"
#include "../../../../sources/utils.cpp"

/*
	#! /usr/bin/computorv2

	/usr/bin/computorv2

	/usr/bin/computorv2 --server 0.0.0.0 8080
*/

int main(void)
{
	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "x = ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_GET)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "x = 0";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_SET_VARIABLE)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "x = 0 ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_SOLVE)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "f(2) = ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_GET)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "f(x) = x";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_SET_FUNCTION)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "f(x) = x ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_SOLVE)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "f(2) = 2";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "f(2) = 2 ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_SOLVE)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "f(y) = 2 ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_SOLVE)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "1 + 2 + 3 = ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_GET)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "1 + 2 + 3 = 5";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "1 + 2 + 3";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_GET)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "= 1";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "= ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "= 1 ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "? = ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "? = 1";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "? = 1 ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "x = 0 = 1 ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "x ? =";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "x ? = ?";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "x = ";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "f(x) = ";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "f(x) = ? 5 ";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = "f(x) ?  ";
		st._len = st._str.size();
		computorv2::statment_type(&st);
		if (st._type != STATMENT_TYPE_UNKNOWN)
		{
			std::cout << "LINE: " << __LINE__ << std::endl; exit(0);
		}
	}

	return (0);
}
