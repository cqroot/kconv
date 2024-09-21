message(${CMAKE_BINARY_DIR})
message(${CMAKE_SOURCE_DIR})
configure_file(config.h.in config.h)

add_executable(kconv main.c)

add_subdirectory(common)
add_subdirectory(converters)

target_include_directories(kconv PUBLIC ${PROJECT_BINARY_DIR}/src)
target_include_directories(kconv PUBLIC converters)

target_link_libraries(kconv PUBLIC common)
target_link_libraries(kconv PUBLIC converters)
