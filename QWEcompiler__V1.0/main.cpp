#include "Compiler.h"

int main()
{
    try
    {

    }
    catch (compile_error ce)
    {
        std::cerr << "Compile error\n";
        std::cerr << ce.what() <<"\n";
    }
}
