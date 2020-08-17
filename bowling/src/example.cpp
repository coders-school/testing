#include "example.hpp"

#include <iostream>

extern void testPrint()
{
    std::cout << "yeah!!! " << __func__ << "\n";
}

extern int testRet(int i)
{
    return i + 2;
}
