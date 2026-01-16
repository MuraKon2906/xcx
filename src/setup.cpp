#include "xcx/setup.hpp"
#include <iostream>
#include <string>

// Constructor
BasicProject::BasicProject(std::string prjname) : prj_name(prjname) {
  _create_prj_src(prj_name);
  _create_sub_folders();
  _create_files();
  _write_to_files();
}

// -------- Private Method Definitions --------

void BasicProject::_create_prj_src(std::string name) {
  std::cout << "Creating project source for: " << name << "\n";
}

void BasicProject::_create_sub_folders() {
  std::cout << "Creating sub folders\n";
}

void BasicProject::_create_files() { std::cout << "Creating files\n"; }

void BasicProject::_write_to_files() { std::cout << "Writing to files\n"; }
