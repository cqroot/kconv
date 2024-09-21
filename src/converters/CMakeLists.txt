add_library(converters data_unit.c unix_timestamp.c)
target_include_directories(converters PUBLIC ../common)
target_link_libraries(converters PUBLIC common)
