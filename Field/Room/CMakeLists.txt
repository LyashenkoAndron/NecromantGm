add_library(Room SHARED Room.cpp Room.h)

target_include_directories(Room PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Room PRIVATE Character Hero Curse)