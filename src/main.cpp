#include "iostream"
#include "xcx/setup.hpp"

int main(int argc, char *argv[]) {
  if (argc > 1) {
    auto project = BasicProject(argv[1]);
  }
  return 0;
}
