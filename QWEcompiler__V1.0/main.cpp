#include "Compiler.h"
#include "UserFileInput.h"

int main()
{
    Compiler compiler;

    try
    {
        std::string source_code_path_with_name = user_dialog_to_findout_directory();
        std::string source_code = read_from_file(source_code_path_with_name);

        std::string output_file_path = qwExe_file_path_reader();
        std::string output_file_name = qwExe_file_name_reader();

        compiler.compile(source_code, output_file_path, output_file_name);


        return 0;
    }



    catch (const Exit& exit)
    {
        std::cerr << "End of programm\n";
        return 0;
    }
    catch (const compile_error& ce)
    {
        std::cerr << "Compile error\n";
        std::cerr << ce.what() <<"\n";
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Compile execution error\n";
        std::cerr << ex.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Uncknown error\n";
    }
}
