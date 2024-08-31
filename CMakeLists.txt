cmake_minimum_required(VERSION 3.15)
project(IntoTheWoods++ VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

if(NOT SFML_FOUND)
  message("local installation of SFML not found, \
  cloning sfml 2.x.x repo")
  include(FetchContent)
  FetchContent_Declare(sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG e39f48742b702400424db46f3b28e8a09459ca38 #Este é o commit hash do commit mecionado acima
  )
  FetchContent_MakeAvailable(sfml)
endif()

set(INTOTHEWOODS_PATH ${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_sources(${PROJECT_NAME} PRIVATE ${cpp_source_files} 
src/Being.cpp
src/Button.cpp
src/Character.cpp
src/CollisionManager.cpp
src/Enemy.cpp
src/Entity.cpp
src/EntityList.cpp
src/Evening.cpp
src/EventManager.cpp
src/Game.cpp
src/GraphicManager.cpp
src/Ground.cpp
src/InputManager.cpp
src/Level.cpp
src/main.cpp
src/MainMenu.cpp
src/MenuObserver.cpp
src/Nest.cpp
src/NewGameMenu.cpp
src/Observer.cpp
src/Obstacle.cpp
src/Player.cpp
src/PlayerinputObserver.cpp
src/Scorpion.cpp
src/State.cpp
src/StateMachine.cpp
src/StateMenu.cpp
src/TallGrass.cpp
src/Trap.cpp
)

#exemplo de variavel
set(INTO_THE_WOODS_PATH ${PROJECT_SOURCE_DIR})

#Exemplo de passagem de variavel CMAKE para variavel do Codigo
configure_file(${PROJECT_SOURCE_DIR}/include/DefineSource/SourcePath.h.in ${PROJECT_SOURCE_DIR}/include/DefineSource/SourcePath.h)

install(TARGETS ${PROJECT_NAME})