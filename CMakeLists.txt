cmake_minimum_required(VERSION 3.12)
project(Leopard_project_C)

set(CMAKE_CXX_STANDARD 11)

# Add the source files to the project
set(SOURCES
    src/Admin.cpp
    src/Instructor.cpp
    src/Student.cpp
    src/User.cpp
    src/main.cpp
)

# Add the header files to the project
set(HEADERS
    inc/Admin.h
    inc/Instructor.h
    inc/Student.h
    inc/User.h
)
# Add the SQLite source file to the project
set(SQLITE_SOURCE_DIR "sqlite/sqlite3.c")

# Add the header file directory to the project
include_directories("sqlite/sqlite3.h")

# Add the include directories to the project
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/sqlite
)


# Add the executable target
add_executable(LeopardBuild ${SOURCES} ${HEADERS} sqlite/sqlite3.c)
