
set(SRC_FILE main.cxx)
add_executable(main ${SRC_FILE})
target_link_libraries(main hello::hello)
