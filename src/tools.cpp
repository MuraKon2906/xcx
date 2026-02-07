#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <thread>

#include <fmt/color.h>
#include <fmt/core.h>

#include <toml++/toml.h>
#include <xcx/tools.hpp>

namespace cli {

// Text
inline auto text() { return fmt::fg(fmt::color::white); }

// Status
inline auto info() { return fmt::fg(fmt::color::cornflower_blue); }

inline auto success() { return fmt::fg(fmt::color::sea_green); }

inline auto warning() { return fmt::fg(fmt::color::orange); }

inline auto error() {
  return fmt::fg(fmt::color::indian_red) | fmt::emphasis::bold;
}

// Branding
inline auto brand() {
  return fmt::fg(fmt::color::steel_blue) | fmt::emphasis::bold;
}

inline auto highlight() {
  return fmt::fg(fmt::color::white) | fmt::emphasis::bold;
}

// Tags
inline auto tag_info() {
  return fmt::fg(fmt::color::cornflower_blue) | fmt::emphasis::bold;
}

inline auto tag_success() {
  return fmt::fg(fmt::color::sea_green) | fmt::emphasis::bold;
}

inline auto tag_warn() {
  return fmt::fg(fmt::color::orange) | fmt::emphasis::bold;
}

inline auto tag_error() {
  return fmt::fg(fmt::color::indian_red) | fmt::emphasis::bold;
}

} // namespace cli

using namespace std::chrono_literals;

// --------------------------------------------------
// Build
// --------------------------------------------------

int PrjBuild::target_status_code = 0;
int PrjBuild::cmake_status_code = 0;

PrjBuild::PrjBuild() {

  fmt::print(cli::brand(), "xcx\n---");

  fmt::print("\n");

  fmt::print(cli::tag_info(), "[INFO] ");
  fmt::print(cli::text(), "Starting build\n");

  if (!_is_build()) {

    fmt::print(cli::tag_error(), "[ERROR]  ");
    fmt::print(cli::text(), "Build directory not found\n");

    return;
  }

  _cmake_setup();
  _create_binaries();
}

bool PrjBuild::_is_build() { return std::filesystem::is_directory("build"); }

void PrjBuild::_cmake_setup() {

  fmt::print(cli::tag_info(), "[INFO] ");
  fmt::print(cli::text(), "Configuring project\n");

  PrjBuild::cmake_status_code = std::system("cmake -S . -B build");
}

void PrjBuild::_create_binaries() {
  if (cmake_status_code != 0) {

    fmt::print(cli::tag_error(), "[ERROR]  ");
    fmt::print(cli::text(),
               "Error: Could not generate CMake build system files. Please "
               "check your project configuration.\n");

    return;
  }

  fmt::print(cli::tag_info(), "[INFO] ");
  fmt::print(cli::text(), "Compiling sources\n");

  PrjBuild::target_status_code = std::system("cd build && cmake --build .");
  if (target_status_code != 0) {
    fmt::print(cli::tag_error(), "[ERROR]");
    fmt::print(
        cli::text(),
        "Error: Build failed. Compilation did not complete successfully.\n");

    return;
  }

  fmt::print(cli::tag_success(), "[OK]   ");
  fmt::print(cli::text(), "Build completed successfully\n");
}

// --------------------------------------------------
// Run
// --------------------------------------------------

PrjRun::PrjRun() : PrjBuild() {

  if (!_is_build() || target_status_code != 0) {
    fmt::print(cli::tag_error(), "[ERROR]");
    fmt::print(cli::text(), "Target couldn't be built\n");

    return;
  }

  _run_binaries();
}

void PrjRun::_run_binaries() {

  fmt::print(cli::tag_info(), "[INFO] ");
  fmt::print(cli::text(), "Running target");

  for (int i = 0; i < 3; ++i) {
    fmt::print(".");
    std::this_thread::sleep_for(250ms);
  }

  fmt::print("\n");

  if (!std::filesystem::exists("Config.toml")) {

    fmt::print(cli::tag_error(), "[ERROR]  ");
    fmt::print(cli::text(), "Config.toml not found\n");

    return;
  }

  auto config = toml::parse_file("Config.toml");

  std::string prj_name = config["project"]["name"].value_or("dumdum");

  std::string cmd = "cd build && ./" + prj_name;

  fmt::print(cli::tag_info(), "[INFO] ");
  fmt::print(cli::highlight(), "Executing: {}\n", prj_name);

  fmt::print(cli::text(), "================================\n");

  std::system(cmd.c_str());
}
