target_sources(
    kconv
    PRIVATE data_unit.c data_unit.h unix_timestamp.c unix_timestamp.h
)
target_include_directories(kconv PRIVATE .)
