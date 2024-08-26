#Define a versao minima do CMake para gerar a build
cmake_minimum_required(VERSION 3.15)
#Define nome do projeto e informacoes basicas do projeto como: versao, descricao, url, linguagens utilizadas, etc...
project(IntoTheWoods++ VERSION 1.0)
#Construtura do projeto. (Em tutoriais mais antigos de CMake geralmente utilizam uma variavel para guardar
#os 'source_files', em CMake moderno abandonamos essa funcionalidade e utilizamos as funcoes 'Target')
add_executable(${PROJECT_NAME})


# ---- exemplo de FetchContent
include(FetchContent)
FetchContent_Declare(sfml-dep
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.x)
FetchContent_MakeAvailable(sfml-dep)
# ----- FetchContent

#- Metodo recomendado para projetos com mais de um Dev

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

#exemplo de variavel
set(INTO_THE_WOODS_PATH ${PROJECT_SOURCE_DIR})

#define os diretorios de include
#Isso eh interessante pois faz com que nao seja necessario dar include no 'Relative_Path', ou seja,
#se um arquivo src/Foo.c quer incluir Bar.h inves de dar include em "../include/Bar.h"
#Foo.c pode incluir apenas "Bar.h" se "include" estiver definido como diretorio de include
target_include_directories(${PROJECT_NAME} PUBLIC  
"${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/include/Entities" "${PROJECT_SOURCE_DIR}/include/Entities/Characters"
"${PROJECT_SOURCE_DIR}/include/Entities/Obstacles"
"${PROJECT_SOURCE_DIR}/include/Entities/Characters/Enemies" "${PROJECT_SOURCE_DIR}/include/Utils"
"${PROJECT_SOURCE_DIR}/include/Managers" "${PROJECT_SOURCE_DIR}/include/States" "${PROJECT_SOURCE_DIR}/include/Levels" 
"${PROJECT_SOURCE_DIR}/include/Menus" "${PROJECT_SOURCE_DIR}/include/Observers" "${PROJECT_SOURCE_DIR}/include/DefineSource" "${PROJECT_SOURCE_DIR}/include/Properties")


#Exemplo de passagem de variavel CMAKE para variavel do Codigo
configure_file(${PROJECT_SOURCE_DIR}/include/DefineSource/SourcePath.h.in ${PROJECT_SOURCE_DIR}/include/DefineSource/SourcePath.h)

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system)
