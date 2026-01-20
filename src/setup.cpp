// color config
#include <fstream>
#include <ostream>
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define BLUE "\033[32m"
#define CYAN "\033[0;36m"

#include "xcx/setup.hpp"
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

// Constructor
BasicProject::BasicProject(std::string prjname) : prj_name(prjname) {
  _create_prj_src(prj_name);
  _create_sub_folders();
  _create_files();
  // _write_to_files();
}

void BasicProject::_create_prj_src(std::string name) {
  try {
    if (fs::create_directories(name)) {
      std::cout << BLUE << "Creating project source for: " << RESET << CYAN
                << name << RESET << "\n";
    } else {
      std::cout << "Failed to initialize the project environment" << "\n";
      throw 0;
    }

  } catch (int status) {

    std::cout << "Creation of project : " << status << std::endl;
  }
}

void BasicProject::_create_sub_folders() {
  std::cout << "Project Type : " << YELLOW << "Basic" << RESET;
  std::vector<std::string> sub_folders = {"include", "src", "build", "docs"};
  fs::path src_path = fs::path(prj_name);
  for (auto dirs : sub_folders) {
    fs::path sub_folder_path = fs::path(src_path / dirs);
    fs::create_directories(sub_folder_path);
  }
}
//
void BasicProject::_create_files() {
  std::vector<fs::path> src_files = {"main.cpp", "core.cpp"};
  fs::path prj_path = prj_name;
  fs ::path src_folder = "src";
  for (auto &file : src_files) {
    fs::path comp_main_path = prj_path / src_folder / file;
    std::ofstream main(comp_main_path);
  }
}
//
// void BasicProject::_write_to_files() { std::cout << "Writing to files\n"; }
