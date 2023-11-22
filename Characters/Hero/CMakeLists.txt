add_library(Hero SHARED Hero.cpp Hero.h)

target_link_libraries(Hero PRIVATE Necromancy)
target_link_libraries(Hero PRIVATE Curse)
target_include_directories(Hero PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
