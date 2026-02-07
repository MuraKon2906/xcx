#include "xcx/vendor.hpp"
#include <fmt/color.h>
#include <fmt/core.h>

std::string AddLibs::link = "";

void AddLibs::add_libraries() {
  fmt::print(fmt::fg(fmt::color::rebecca_purple), "adding {} ", AddLibs::link);
}
