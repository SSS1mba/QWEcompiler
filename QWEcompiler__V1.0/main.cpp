#include "Compiler.h"

int main()
{
    try
    {
        Lexer l;
        std::string test_string("qwe    rqqq r r");
        auto res = l.analyse(test_string, 0, test_string.length(), InputKeys());
        return 0;
    }
    catch (compile_error ce)
    {
        std::cerr << "Compile error\n";
        std::cerr << ce.what() <<"\n";
    }
}
