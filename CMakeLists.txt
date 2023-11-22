cmake_minimum_required(VERSION 3.16)
project(MyProject)

add_subdirectory(Characters)
add_subdirectory(Field)
add_subdirectory(Skills)


add_executable(main Game.cpp)
target_link_libraries(main Character Hero Skill Curse Necromancy Enemy Floor Room)
