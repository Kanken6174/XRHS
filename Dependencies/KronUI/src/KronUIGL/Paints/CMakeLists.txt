set(Paints_src
    ./Paints.hpp)

add_library(paints ${Paints_src})

set_target_properties(paints PROPERTIES LINKER_LANGUAGE CXX)