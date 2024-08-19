cmake_minimum_required(VERSION 3.8)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Jogo src/main.cpp src/Being.cpp src/Character.cpp src/Enemy.cpp src/Entity.cpp src/Game.cpp src/Observer.cpp src/Obstacle.cpp src/Player.cpp src/PlayerInputObserver.cpp src/StateMachine.cpp src/States.cpp)
target_include_directories(Jogo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Jogo PRIVATE sfml-graphics)
target_compile_features(Jogo PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET Jogo
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Jogo>
        VERBATIM)
endif()
install(TARGETS Jogo)