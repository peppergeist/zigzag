#include <iostream>
#include <string>
#include <vector>
#include "options.hpp"

std::vector<std::string> vectorize_options(int argc, char *argv[])
{
    std::vector<std::string> output;
    for (int i = 1; i < argc; ++i)
    {
        output.push_back(argv[i]);
    }

    return output;
}

int parse_options_for_height(std::vector<std::string> options)
{
    int h = 4; /* by default, zigzag height is 4 rows */

    for (int i = 0; i < options.size(); ++i)
    {
        if (options[i] == "-h" || options[i] == "--height")
        {
            if (i + 1 >= options.size())
            {
                std::cerr << "Height flag provided but no height was specified."
                    << std::endl;
                exit(1);
            }

            h = std::stoi(options[i + 1], nullptr);

            if (h < 1)
            {
                std::cerr << "Height cannot be less than 1." << std::endl;
                exit(1);
            }
        }
    }

    return h;
}

bool parse_options_for_version(std::vector<std::string> options)
{
    for (int i = 0; i < options.size(); ++i)
    {
        if (options[i] == "-v" || options[i] == "--version")
        {
            return true;
        }
    }

    return false;
}

bool parse_options_for_reverse(std::vector<std::string> options)
{
    for (int i = 0; i < options.size(); ++i)
    {
        if (options[i] == "-r" || options[i] == "--reverse")
        {
            return true;
        }
    }

    return false;
}

std::string parse_options_for_text(std::vector<std::string> options)
{
    std::string text = "";
    bool ignore_flags = false;
    for (int i = 0; i < options.size(); ++i)
    {
        if (options[i][0] != '-')
        {
            if (i < 1
            || (options[i - 1] != "-h" && options[i - 1] != "--height"))
            {
                ignore_flags = true;
            }
        }

        if (ignore_flags)
        {
            text += options[i] + " ";
        }
    }

    return text;
}

void print_zigzag_version(int maj, int min)
{
    std::cout << "Zigzag text widget, version " << maj << "." << min
        << std::endl;
}
