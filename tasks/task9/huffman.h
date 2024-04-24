#include <string>
#include <unordered_map>

std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::unordered_map<char, std::string>& codes);
