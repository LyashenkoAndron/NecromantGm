add_subdirectory(Enemy)
add_subdirectory(Hero)

add_library(Character SHARED Character.h Character.cpp)
target_include_directories(Character PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
