#include <filesystem>
#include <iostream>
#include <xcx/tools.hpp>
namespace fs = std::filesystem;
void hello_from_build() {
  std::cout << "We are building your project !!! Dont worry";
}

void _check_build(fs::path prj_path) {
  fs::path build_path = prj_path / "build";
  std::cout << "\b checking contents of build folder : ";
  try {
    if (fs::is_empty(build_path)) {
      std::cout << "Contents of Build folder are empty : ";
    } else {
    }
  } catch (...) {
    std::cout << "Error has occured while determining file contents in the "
                 "build folder \n";
  }
}
