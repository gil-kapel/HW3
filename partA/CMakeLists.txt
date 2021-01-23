SET(TARGETNAME part_a_lib)

set(SRC
    date_wrap.cpp
)

add_library(${TARGETNAME} STATIC ${SRC})

# target_include_directories(${TARGETNAME} PUBLIC
#     # ./
# )