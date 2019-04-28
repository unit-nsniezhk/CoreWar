cmake_minimum_required(VERSION 3.13)

project(corewar)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(srcs SRCS)

add_executable(corewar
        ${SRCS})

target_include_directories(corewar
        PUBLIC includes
        PUBLIC libft/includes)

target_link_directories(corewar
        PUBLIC libft)

target_link_libraries(corewar libft.a)

