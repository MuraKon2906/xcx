#pragma once
// Builds the project and
// stores the executable in build/
class PrjBuild {
public:
  PrjBuild();

protected:
  bool _is_build();

private:
  void _cmake_setup();     // generates the neccessary build systems files
  void _create_binaries(); // makes the build system
};

class PrjRun : public PrjBuild {

public:
  PrjRun();

private:
  void _run_binaries();
};
