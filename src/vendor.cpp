#include "xcx/vendor.hpp"
#include <filesystem>
#include <fmt/color.h>
#include <fmt/core.h>

std::string AddLibs::link = "";

namespace cli {

// Color helpers
inline auto info() { return fmt::fg(fmt::color::cyan) | fmt::emphasis::bold; }

inline auto success() {
  return fmt::fg(fmt::color::green) | fmt::emphasis::bold;
}

inline auto error() { return fmt::fg(fmt::color::red) | fmt::emphasis::bold; }

inline auto highlight() {
  return fmt::fg(fmt::color::rebecca_purple) | fmt::emphasis::bold;
}

} // namespace cli

void AddLibs::add_libraries() {
  fmt::print(fmt::fg(fmt::color::light_cyan), "xcx\n---\n");
  fmt::print(cli::info(), "[INFO] ");
  fmt::print("Adding dependency...\n");

  fmt::print(cli::info(), "[INFO] ");
  fmt::print("Looking for configuration file...\n");

  if (!_check_config_toml()) {
    return;
  }

  // Config found
  fmt::print(cli::success(), "[OK] ");
  fmt::print("Config.toml found \n");

  fmt::print(cli::info(), "[INFO] ");
  fmt::print("Installing package: ");

  fmt::print(cli::highlight(), "{}\n", AddLibs::link);

  fmt::print(cli::success(), "[DONE] ");
  fmt::print("Package '{}' installed successfully\n", AddLibs::link);
}

bool AddLibs::_check_config_toml() {

  std::filesystem::path config = "Config.toml";

  if (!std::filesystem::exists(config)) {

    fmt::print(cli::error(), "[ERROR] ");
    fmt::print("Missing Config.toml file\n");

    return false;
  }

  return true;
}
