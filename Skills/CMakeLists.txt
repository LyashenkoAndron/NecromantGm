add_subdirectory(Curse)
add_subdirectory(Necromancy)

add_library(Skill SHARED Skill.h Skill.cpp)
target_include_directories(Skill PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
