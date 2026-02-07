// Handles all the features that
// are neccessary to add 3rd party
// dependencies

#pragma once

#include <string>
class AddLibs {
public:
  static void add_libraries(); // main method in main.cpp
  static std::string link;

private:
  static bool _check_config_toml(); // checks if Config.toml is present or not
};
