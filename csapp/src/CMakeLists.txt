add_subdirectory(common)
add_subdirectory(hardware)

add_executable(csapp main.c)

target_link_libraries(csapp hardware_lib common_lib)

target_include_directories(csapp PUBLIC "${PROJECT_SOURCE_DIR}/src/headers")
