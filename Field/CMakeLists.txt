add_subdirectory(Room)

add_library(Floor SHARED Floor.h Floor.cpp)

target_include_directories(Floor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
