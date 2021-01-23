SET(TARGETNAME part_c_lib)

set(SRC
    schedule.cpp
    schedule.h
)

add_library(${TARGETNAME} STATIC ${SRC})