#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

#include "iostream"
#include "xcx/setup.hpp"
#include <unordered_map>
#include <xcx/tools.hpp>

enum Comms { init = 1, run = 2, build, add, help }; // commands avaliable
int main(int argc, char *argv[]) {
  enum Comms cmd;
  std::unordered_map<std::string, Comms> cmd_map = {{"new", Comms::init},
                                                    {"run", Comms::run},
                                                    {"build", Comms::build},
                                                    {"add", Comms::add},
                                                    {"--help", Comms::help}};
  if (argc < 2) {

    std::cout << "XCX : command not provided " << std::endl;
    std::cout << "Run 'xcx --help' to view avaliable commands";
    return 0;
  }

  auto cmd_it = cmd_map.find(argv[1]);
  // To check if the cmd is in the map
  if (cmd_it == cmd_map.end()) {
    std::cout << "XCX : command not found : ";
    return 0;
  }
  cmd = cmd_it->second;

  switch (cmd) {
  case 1: {

    auto project = BasicProject(argv[2]);
    break;
  }
  case 2:
    std::cout << "Running";
    break;
  case 3:
    hello_from_build();
    break;
  case 4:
    std::cout << "add libs ";
    break;
  case 5: {
    std::cout << "\nXCX - v.0.1\n";
    std::cout << "Usage:\n";
    std::cout << "  xcx <command> [options]\n\n";

    std::cout << "Commands:\n";
    std::cout << "  new <project_name>   Create a new project\n";
    std::cout << "  run                  Run the project\n";
    std::cout << "  build                Build the project\n";
    std::cout << "  add                  Add libraries\n";
    std::cout << "  --help               Show this help message\n\n";
    break;
  }
  default:
    std::cout << " XCX: Incorrect command";
  }
  return 0;
}
