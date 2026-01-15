#include <cstring>
#include <filesystem>
#include <iostream>

int main(int argc, char *argv[]) {
  if (std::strcmp(argv[1], "new") == 0) {
    std::cout << "Creating new project" << std::endl;
  } else {
    std::cout << "Unable to determine the command :" << std::endl;
  }

  return 0;
}
