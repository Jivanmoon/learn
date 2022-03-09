aux_source_directory(. common_lib)

add_library(common_lib ${common_lib})

include_directories(common_lib "${PROJECT_SOURCE_DIR}/src/headers")