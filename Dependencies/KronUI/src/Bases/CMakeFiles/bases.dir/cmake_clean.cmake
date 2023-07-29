file(REMOVE_RECURSE
  "libbases.a"
  "libbases.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/bases.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
