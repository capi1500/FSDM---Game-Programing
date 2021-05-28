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
add_executable(ProgramowanieGier src/main.cpp src/misc/singleton.cpp src/misc/singleton.hpp src/signal/listener.cpp src/signal/listener.hpp src/signal/signal.cpp src/signal/signal.hpp src/finiteStateMachine/finiteState.cpp src/finiteStateMachine/finiteState.hpp src/finiteStateMachine/finiteStateMachine.cpp src/finiteStateMachine/finiteStateMachine.hpp src/finiteStateMachine/finiteStateEvent.cpp src/finiteStateMachine/finiteStateEvent.hpp src/systems/console.cpp src/systems/console.hpp src/misc/message.cpp src/misc/message.hpp src/systems/inputHandler.cpp src/systems/inputHandler.hpp src/entities/entity.cpp src/entities/entity.hpp src/systems/scene.cpp src/systems/scene.hpp src/game.cpp src/game.hpp src/gameEvent.cpp src/gameEvent.hpp src/systems/assetManager.cpp src/systems/assetManager.hpp src/misc/animation.cpp src/misc/animation.hpp src/misc/animatedSprite.cpp src/misc/animatedSprite.hpp src/entities/pacman.cpp src/entities/pacman.hpp src/map/map.cpp src/map/map.hpp src/map/field.cpp src/map/field.hpp src/entities/ghost.cpp src/entities/ghost.hpp src/entities/ghostStates/ghostState.cpp src/entities/ghostStates/ghostState.hpp src/entities/ghostStates/defaultGhostState.cpp src/entities/ghostStates/defaultGhostState.hpp src/entities/ghostStates/fleeGhostState.cpp src/entities/ghostStates/fleeGhostState.hpp src/entities/ghostStates/deadGhostState.cpp src/entities/ghostStates/deadGhostState.hpp src/graphicSettings.cpp src/graphicSettings.hpp src/statistics.cpp src/statistics.hpp src/entities/fruit.cpp src/entities/fruit.hpp)

# compile options
target_compile_options(ProgramowanieGier PRIVATE -Wall)

# link libraries
target_link_libraries(ProgramowanieGier sfml-graphics sfml-window sfml-system sfml-audio sfml-network)