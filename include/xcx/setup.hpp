#pragma once

#include <string>
class BasicProject {
private:
  std::string prj_name;                   // private version of the prjname;
  bool _create_prj_src(std::string name); // Creates the Projects source folder
  void _create_sub_folders(); // Creates sub folders like "include/" , "src/" ,
                              // "docs" .. etc;
  //
  // Writes foundational working code to the
  // following files : main , core and cmake
  void _write_to_main();
  void _write_to_core();
  void _write_to_core_hpp();
  void _write_to_cmake();
  void _wrtite_to_toml();

public:
  BasicProject(std::string prjname);
};
