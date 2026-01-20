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
  _write_to_main();
  _write_to_core();
  // _write_to_core_hpp();
  // _write_to_cmake();
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
// void BasicProject::_write_to_core_hpp() {
//   std::cout << "\n writing to core_hpp\n";
// }
// void BasicProject::_write_to_cmake() { std::cout << "\n writing to cmake\n";
// }
