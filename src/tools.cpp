#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <toml++/toml.h>
#include <xcx/tools.hpp>

PrjBuild::PrjBuild() {
  if (!_is_build()) {
    std::cout << "XCX : Build doesn't exist. Aborting.\n";
    return;
  }
  _cmake_setup();
  _create_binaries();
}

bool PrjBuild::_is_build() {
  if (std::filesystem::is_directory("build")) {
    return true;

  } else {
    return false;
  }
}

void PrjBuild::_cmake_setup() {
  std::cout << "\n Creating the necessary Build System files : \n";
  std::system("cmake -S . -B build");
}
void PrjBuild::_create_binaries() {

  std::cout << "\n Building Project Binaries \n";
  std::system("cd build && cmake --build .");
}
