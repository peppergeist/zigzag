#include "input.hpp"
#include "options.hpp"

input::input(std::vector<std::string> options)
{
    height = parse_options_for_height(options);
    version = parse_options_for_version(options);
    reverse = parse_options_for_reverse(options);
    text = parse_options_for_text(options);
}
