#include "Interpretator.h"

int main()
{
    try
    {

    }
    catch (compile_errors ce)
    {
        std::cerr << "Compile error\n";
        std::cerr << ce.what() <<"\n";
    }
}
