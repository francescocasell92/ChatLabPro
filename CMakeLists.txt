cmake_minimum_required(VERSION 3.17)
project(ChatLabPro)

add_subdirectory(test)
set(CMAKE_CXX_STANDARD 17)
set( SOURCE_FILES User.h User.cpp Message.h Observer.h Subject.h Chat.h MessageNotify.h )



add_executable(ChatLabPro main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ChatLabPro core)
