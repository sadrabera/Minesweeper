file(REMOVE_RECURSE
  "CMakeFiles/yourProjectName.dir/main.cpp.obj"
  "libyourProjectName.dll.a"
  "yourProjectName.exe"
  "yourProjectName.exe.manifest"
  "yourProjectName.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/yourProjectName.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
