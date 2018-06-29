#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
#include <vector>

struct input
{
    int height;         /* height of zigzag */
    bool version;       /* print version */
    bool reverse;       /* start from bottom */
    std::string text;   /* text to zigzagify */

    input();
    input(std::vector<std::string> options);
};

#endif
