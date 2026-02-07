#include "xcx/vendor.hpp"
#include <filesystem>
#include <fmt/color.h>
#include <fmt/core.h>
std::string AddLibs::link = "";

void AddLibs::add_libraries() {
  if (_check_config_toml()) {

    fmt::print(fmt::fg(fmt::color::rebecca_purple), "adding {} ",
               AddLibs::link);
  }
}

bool AddLibs::_check_config_toml() {
  std::filesystem::path config = "Config.toml";
  if (!std::filesystem::exists(config)) {
    fmt::print("XCX ERROR : Config.toml is missing !!");
    return false;
  } else {
    return true;
  }
}
