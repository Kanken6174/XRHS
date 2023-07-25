file(REMOVE_RECURSE
  "lib3D.a"
  "lib3D.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/3D.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
