file(REMOVE_RECURSE
  "libpaints.a"
  "libpaints.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/paints.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
