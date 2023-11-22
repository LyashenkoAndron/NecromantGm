add_library(Enemy SHARED Enemy.cpp Enemy.h)
target_include_directories(Enemy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
