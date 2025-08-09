#include "Compiler.h"

int main()
{
    try
    {
        Compiler c;
        std::string test_string("   input:qwer base qwe    rqqq r r amien");
        c.compile(test_string,"file1");
        return 0;
    }
    catch (const compile_error& ce)
    {
        std::cerr << "Compile error\n";
        std::cerr << ce.what() <<"\n";
    }
}
