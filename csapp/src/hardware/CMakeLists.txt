aux_source_directory(./cpu hardware_cpu_lib)

aux_source_directory(./memory hardware_memory_lib)

add_library(hardware_lib ${hardware_cpu_lib} ${hardware_memory_lib})

include_directories(hardware_lib "${PROJECT_SOURCE_DIR}/src/headers")