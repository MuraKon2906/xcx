// color config
#include <cstdlib>
#include <fstream>
#include <ostream>
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define BLUE "\033[32m"
#define CYAN "\033[0;36m"
#define RED "\x1b[31m"
#define GREEN "\033[32m"

#include "xcx/setup.hpp"
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

// Constructor
BasicProject::BasicProject(std::string prjname) : prj_name(prjname) {
  if (!_create_prj_src(prjname)) {
    return;
  }
  _create_sub_folders();
  _write_to_main();
  _write_to_core();
  _write_to_core_hpp();
  _write_to_cmake();
  _wrtite_to_toml();
  _init_git();
  msg_build_once();
}

bool BasicProject::_create_prj_src(std::string name) {
  if (fs::is_directory(name)) {
    std::cout << "XCX :" << RED << "Project Already exists ! " << RESET;

    return false;
  }

  fs::create_directories(name);
  std::cout << BLUE << "Creating project source for: " << RESET << CYAN << name
            << RESET << "\n";
  return true;
}

void BasicProject::_create_sub_folders() {
  std::cout << "Project Type : " << YELLOW << "Basic" << RESET;
  std::vector<std::string> sub_folders = {"include", "src", "build"};
  fs::path src_path = fs::path(prj_name);
  for (auto dirs : sub_folders) {
    fs::path sub_folder_path = fs::path(src_path / dirs);
    fs::create_directories(sub_folder_path);
  }
}

void BasicProject::_write_to_main() {
  fs::path prj_path = prj_name;

  std::string main_content = "#include <iostream>\n\n"
                             "int main() {\n"
                             "    std::cout << \"Hello from " +
                             prj_name +
                             "\" << std::endl;\n"
                             "    return 0;\n"
                             "}\n";

  std::ofstream main_cpp(prj_path / "src/main.cpp");
  main_cpp << main_content;
  main_cpp.close();
}
void BasicProject::_write_to_core() {
  fs::path prj_path = prj_name;
  std::string core_content =
      "#include <iostream>\n"
      "#include \"core.hpp\"\n\n"
      "void hello_from_core() {\n"
      "    std::cout << \"Hello from core\" << std::endl;\n"
      "}\n";
  std::ofstream core_cpp(prj_path / "src/core.cpp");
  core_cpp << core_content;
  core_cpp.close();
}
void BasicProject::_write_to_core_hpp() {
  std::string core_hpp_content = "#pragma once\n\n"
                                 "void hello_from_core();\n";

  fs::path prj_path = prj_name;
  std::ofstream core_hpp(prj_path / "include/core.hpp");

  core_hpp << core_hpp_content;
  core_hpp.close();
}
void BasicProject::_write_to_cmake() {

  fs::path prj_path = prj_name;
  std::string cmake_content = "cmake_minimum_required(VERSION 3.20)\n\n"
                              "project(" +
                              prj_name +
                              " VERSION 0.1 LANGUAGES CXX)\n\n"
                              "set(CMAKE_CXX_STANDARD 17)\n"
                              "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
                              "set(CMAKE_EXPORT_COMPILE_COMMANDS ON)\n\n"
                              "add_executable(${PROJECT_NAME}\n"
                              "    src/main.cpp\n"
                              "    src/core.cpp\n"
                              ")\n\n"
                              "target_include_directories(${PROJECT_NAME}\n"
                              "    PRIVATE\n"
                              "        ${CMAKE_SOURCE_DIR}/include\n"
                              ")\n\n"
                              "target_compile_options(${PROJECT_NAME}\n"
                              "    PRIVATE\n"
                              "        -Wall -Wextra -Wpedantic\n"
                              ")\n";
  std::ofstream cmaketxt(prj_path / "CMakeLists.txt");
  cmaketxt << cmake_content;
  cmaketxt.close();
}
void BasicProject::_wrtite_to_toml() {
  fs::path prj_path = prj_name;
  std::ofstream config_toml(prj_path / "Config.toml");

  if (!config_toml) {
    std::cerr << "Failed to create Config.toml\n";
    return;
  }

  config_toml << "[project]\n"
                 "name = \""
              << prj_name
              << "\"\n"
                 "version = \"0.1.0\"\n"
                 "edition = \"2026\"\n";

  config_toml.close();
}

void BasicProject::_init_git() {
  std::string cmd =
      "cd \"" + prj_name + "\" && git init -b main > /dev/null 2>&1";
  std::system(cmd.c_str());
}

void BasicProject::msg_build_once() {
  std::cout << GREEN << "\n \n ✔ Project is ready!" << RESET << std::endl;
  std::cout << YELLOW << "   Build it once with: " << BLUE << "cd " << prj_name
            << " && xcx build" << RESET << std::endl;
}
