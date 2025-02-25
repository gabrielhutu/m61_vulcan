CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

project(m61_vulcan CXX)


find_package(CURL REQUIRED)

add_library(file_reader STATIC src/lib/filereader.cpp)
add_library(ssh STATIC src/lib/ssh/ssh.cpp)
add_library(web STATIC src/lib/web/http.cpp)

add_executable(${PROJECT_NAME} ./src/main.cpp)
target_link_libraries(${PROJECT_NAME} ssh web file_reader CURL::libcurl uring)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET file_reader PROPERTY CXX_STANDARD 20)
set_property(TARGET ssh PROPERTY CXX_STANDARD 20)
set_property(TARGET web PROPERTY CXX_STANDARD 20)

