#pragma once

#include <string>
class BasicProject {
private:
  std::string prj_name;                   // private version of the prjname;
  void _create_prj_src(std::string name); // Creates the Projects source folder
  void _create_sub_folders(); // Creates sub folders like "include/" , "src/" ,
                              // "docs" .. etc;
  //
  void _create_files();   // handles file creation like "main.cpp" , "lib.cpp" ,
                          // "lib.hpp" .. etc
  void _write_to_files(); // writes content to files to initialize the projects
                          // like "CMakeLists.txt" and "main.cpp"

public:
  BasicProject(std::string prjname);
};
