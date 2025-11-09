add_executable(procli main.cpp)

target_link_libraries(procli PRIVATE argparse)
target_link_libraries(procli PRIVATE propagation)
