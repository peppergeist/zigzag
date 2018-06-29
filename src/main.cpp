#include <iostream>
#include <string>
#include <vector>
#include "input.hpp"
#include "options.hpp"
#include "splitter.hpp"

#define MAJOR_VERSION 1
#define MINOR_VERSION 0

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        print_zigzag_version(MAJOR_VERSION, MINOR_VERSION);
        return 0;
    }

    input inp(vectorize_options(argc, argv));

    if (inp.version)
    {
        print_zigzag_version(MAJOR_VERSION, MINOR_VERSION);
    }

    std::vector<std::string> output = split_text_into_zigzag_rows(inp);
    for (int i = 0; i < output.size(); ++i)
    {
        std::cout << output[i] << std::endl;
    }

    return 0;
}
