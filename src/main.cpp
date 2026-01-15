#include "iostream"
#include <xcx/setup.h>

int main(int argc, char *argv[]) {
  if (argc > 1) {
    init_new_prj(argv[1]);
  }
  return 0;
}
