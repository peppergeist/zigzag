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
    input inp;
    std::vector<std::string> options = vectorize_options(argc, argv);
    std::string txt = parse_options_for_text(options);

    if (txt == "")
    {
        std::string cinput;
        while (std::getline(std::cin, cinput))
        {
            if (cinput.empty())
            {
                break;
            }
            else
            {
                inp.text += cinput + "\n";
            }
        }
    }
    else
    {
        inp.text = txt;
    }

    inp.height = parse_options_for_height(options);
    inp.version = parse_options_for_version(options);
    inp.reverse = parse_options_for_reverse(options);

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
