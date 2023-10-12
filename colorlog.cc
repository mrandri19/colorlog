#include <iostream>
#include <ranges>
#include <regex>
#include <string>
#include <string_view>

enum class Format { Clear, Red, Green, Yellow, Cyan };
std::ostream &operator<<(std::ostream &os, Format format) {
  switch (format) {
  case Format::Clear:
    return os << "\033[000m";
  case Format::Red:
    return os << "\033[031m";
  case Format::Green:
    return os << "\033[032m";
  case Format::Yellow:
    return os << "\033[033m";
  case Format::Cyan:
    return os << "\033[036m";
  }
  return os; // unreachable
}

Format log_level_color(const std::string_view log_level) {
  if (log_level == "Info")
    return Format::Green;
  if (log_level == "Warn")
    return Format::Yellow;
  if (log_level == "Error")
    return Format::Red;
  return Format::Clear;
}

int main() {
  std::string line;
  std::regex line_regex{
      "^(\\d{2}:\\d{2}:\\d{2}\\.\\d{9}) \\[(\\w+)(\\s+)\\] (.+)$"};
  std::smatch matches;
  while (std::getline(std::cin, line)) {
    if (std::regex_search(line, matches, line_regex)) {
      const auto &timestamp = matches[1];

      const auto &log_level = matches[2];
      const auto &log_space = matches[3];

      const auto &rest = matches[4];

      std::cout << Format::Cyan << timestamp << Format::Clear << " ";
      std::cout << log_level_color(log_level.str()) << "[" << log_level
                << log_space << "]"
                << " ";
      std::cout << rest;
      std::cout << Format::Clear << std::endl;
    } else {
      std::cout << line << std::endl;
    }
  }
  return 0;
}
