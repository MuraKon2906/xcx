#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <toml++/toml.h>
#include <xcx/tools.hpp>

namespace fs = std::filesystem;
PrjBuild::PrjBuild() { _cmake_setup(); }

bool PrjBuild::_is_build() {
  if (std::filesystem::is_directory("build")) {
    return true;

  } else {
    return false;
  }
}

void PrjBuild::_cmake_setup() {
  if (!_is_build()) {
    std::cout << "XCX : Build doesn't exist. Aborting.\n";
    return;
  }

  fs::path build_dir = fs::current_path() / "build";
  fs::path cmd = "cmake -S . -B " + build_dir.string();

  std::system(cmd.string().c_str());
}
