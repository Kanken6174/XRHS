set(bases_src
    ./ReflectiveItem.hpp)

add_library(bases ${bases_src})

set_target_properties(bases PROPERTIES LINKER_LANGUAGE CXX)