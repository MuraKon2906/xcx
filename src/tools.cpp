#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <toml++/toml.h>
#include <xcx/tools.hpp>

// Color macros
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

PrjBuild::PrjBuild() {
  std::cout << BOLD << CYAN << "\n[XCX] Build System\n" << RESET;

  if (!_is_build()) {
    std::cout << RED << "✖ Build directory not found. Aborting.\n" << RESET;
    return;
  }

  _cmake_setup();
  _create_binaries();

  std::cout << GREEN << "\n✔ Build completed successfully.\n" << RESET;
}

bool PrjBuild::_is_build() { return std::filesystem::is_directory("build"); }

void PrjBuild::_cmake_setup() {
  std::cout << BLUE << "\n➤ Configuring build system...\n" << RESET;
  std::system("cmake -S . -B build");
}

void PrjBuild::_create_binaries() {
  std::cout << YELLOW << "\n➤ Building project binaries...\n" << RESET;
  std::system("cd build && cmake --build .");
}

// PrjRun Implementation
PrjRun::PrjRun() : PrjBuild() { _run_binaries(); }

void PrjRun::_run_binaries() {
  std::cout << "\n Running binaries ... \n";
  if (!std::filesystem::exists("Config.toml")) {
    std::cout << "XCX : Config.toml not found";
  }
  auto config = toml::parse_file("Config.toml");
  std::string prj_name = config["project"]["name"].value_or("dumdum");
  std::string cmd = "cd build && ./" + prj_name;
  std::system(cmd.c_str());
}
