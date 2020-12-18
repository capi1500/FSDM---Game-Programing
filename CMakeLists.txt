cmake_minimum_required(VERSION 3.17)
project(ProgramowanieGier)

set(CMAKE_CXX_STANDARD 17)

# includes
include_directories(src)

# find SFML 2.5
if(WIN32)
    set(SFML_DIR libraries/win/SFML-2.5.1/lib/cmake/SFML/)
else()
    set(SFML_DIR libraries/unix/SFML-2.5.1/lib/cmake/SFML/)
endif(WIN32)

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

# add execs
add_executable(ProgramowanieGier src/main.cpp src/FiniteStateMachine/finiteStateMachine.cpp src/FiniteStateMachine/finiteStateMachine.hpp src/FiniteStateMachine/state.cpp src/FiniteStateMachine/state.hpp src/Objects/object.cpp src/Objects/object.hpp src/Objects/ball.cpp src/Objects/ball.hpp src/Objects/paddle.cpp src/Objects/paddle.hpp src/Utils/function.cpp src/Utils/function.hpp)

# compile options
target_compile_options(ProgramowanieGier PRIVATE -Wall)

# link libraries
target_link_libraries(ProgramowanieGier sfml-graphics sfml-window sfml-system sfml-audio sfml-network)