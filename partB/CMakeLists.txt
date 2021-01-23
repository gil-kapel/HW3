SET(TARGETNAME part_b_lib)

set(SRC
    base_event.cpp
    open_event.cpp
    closed_event.cpp
    event_container.cpp
    festival.cpp
)

add_library(${TARGETNAME} STATIC ${SRC})