#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <string>
#include <vector>

std::vector<std::string> vectorize_options(int argc, char *input[]);
void print_zigzag_version(int maj, int min);
int parse_options_for_height(std::vector<std::string> options);
bool parse_options_for_version(std::vector<std::string> options);
bool parse_options_for_reverse(std::vector<std::string> options);
std::string parse_options_for_text(std::vector<std::string> options);

#endif
