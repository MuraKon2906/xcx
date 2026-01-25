#pragma once

// Builds the project and
// stores the executable in build/
#include <string>
class PrjBuild {
public:
  PrjBuild();

private:
  bool _is_build();
  std::string _read_toml_file();
  void _create_binaries();
};
