project(System C CXX)

SET(CMAKE_C_STANDARD 11)

SET(CMAKE_CXX_STANDARD)

add_executable(System main.c
        src/mainInterface.c
        head/mainInterface.h
        src/add.c
        head/add.h
        src/show.c
        head/show.h
        src/sort.c
        head/sort.h
        src/delete.c
        head/delete.h
        src/modify.c
        head/modify.h
        src/search.cpp
        head/search.h
        src/statistics.cpp
        head/statistics.h
)