cmake_minimum_required(VERSION 3.11)
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

add_executable(${PROJECT_NAME}Jogo)

target_include_directories(${PROJECT_NAME}Jogo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}Jogo PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(${PROJECT_NAME}Jogo PRIVATE cxx_std_17)
target_sources(${PROJECT_NAME}Jogo PRIVATE ${cpp_source_files} 
src/main.cpp 
src/Being.cpp 
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
src/MainMenu.cpp
src/Menu.cpp 
src/Nest.cpp 
src/Observer.cpp 
src/Obstacle.cpp 
src/Player.cpp 
src/PlayerInputObserver.cpp 
src/Scorpion.cpp  
src/StateMachine.cpp  
src/StateMenu.cpp 
src/States.cpp)

install(TARGETS ${PROJECT_NAME}Jogo)
