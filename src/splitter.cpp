#include <string>
#include <vector>
#include <iostream>
#include "input.hpp"

std::vector<std::string> split_text_into_zigzag_rows(input inp)
{
    std::vector<std::string> output(inp.height, "");
    int row = (inp.reverse ? inp.height - 1 : 0);
    bool going_down = !inp.reverse;

    for (int i = 0; i < inp.text.size(); ++i)
    {
        if (inp.text[i] == '\n')
        {
            inp.text = inp.text.substr(i + 1, std::string::npos);
            std::vector<std::string> remaining = split_text_into_zigzag_rows(inp);
            output.insert(output.end(), remaining.begin(), remaining.end());
            return output;
        }

        for (int r = 0; r < output.size(); ++r)
        {
            if (r == row && inp.text[i] != '\t')
            {
                output[r].push_back(inp.text[i]);
            }
            else
            {
                output[r].push_back(' ');
            }
        }

        if (going_down)
        {
            if (row < inp.height - 1)
            {
                ++row;
            }
            else
            {
                if (row > 0)
                {
                    --row;
                }

                going_down = !going_down;
            }
        }
        else
        {
            if (row > 0)
            {
                --row;
            }
            else
            {
                if (row < inp.height - 1)
                {
                    ++row;
                }

                going_down = !going_down;
            }
        }
    }

    return output;
}
