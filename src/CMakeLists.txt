configure_file(config.h.in config.h)
target_include_directories(kconv PRIVATE ${PROJECT_BINARY_DIR}/src)

add_subdirectory(common)
add_subdirectory(converters)
target_sources(kconv PRIVATE main.c)
