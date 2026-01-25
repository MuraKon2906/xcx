#pragma once

// Builds the project and
// stores the executable in build/
class PrjBuild {
public:
  PrjBuild();

private:
  bool _is_build();
  void _cmake_setup();     // generates the neccessary build systems files
  void _create_binaries(); // makes the build system
};
