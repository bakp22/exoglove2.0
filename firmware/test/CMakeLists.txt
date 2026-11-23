# Host-side unit tests for the state logic (runs on your laptop, no ESP32).
#   cmake -S firmware/test -B firmware/test/build && cmake --build firmware/test/build
#   ctest --test-dir firmware/test/build --output-on-failure
cmake_minimum_required(VERSION 3.16)
project(exoglove_host_tests C)
enable_testing()

set(MAIN ${CMAKE_CURRENT_SOURCE_DIR}/../main)
add_executable(test_wait test_wait.c ${MAIN}/states/wait.c)
target_include_directories(test_wait PRIVATE ${MAIN}/states ${MAIN}/config)
target_link_libraries(test_wait m)
add_test(NAME wait COMMAND test_wait)
