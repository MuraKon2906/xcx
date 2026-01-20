#include "iostream"
#include "xcx/setup.hpp"
#include <unordered_map>

enum Comms { init = 1, run = 2, build, add }; // commands avaliable
int main(int argc, char *argv[]) {
  enum Comms cmd;
  std::unordered_map<std::string, Comms> cmd_map = {{"new", Comms::init},
                                                    {"run", Comms::run},
                                                    {"build", Comms::build},
                                                    {"add", Comms::add}};
  if (argc < 2) {

    std::cout << "XCX : command not provided " << std::endl;
    std::cout << "Run 'xcx --help' to view avaliable commands";
    return 0;
  } else {
    std::string inp = argv[1];
    cmd = cmd_map.at(inp);
  }

  switch (cmd) {
  case 1: {

    auto project = BasicProject(argv[2]);
    break;
  }
  case 2:
    std::cout << "Running";
    break;
  case 3:
    std::cout << "Building : ";
    break;
  case 4:
    std::cout << "add libs ";
    break;

  default:
    std::cout << " XCX: Incorrect command";
  }
  return 0;
}
