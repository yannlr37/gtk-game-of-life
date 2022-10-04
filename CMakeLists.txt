cmake_minimum_required(VERSION 2.8)

project( GameOfLife )

find_package( PkgConfig REQUIRED )
pkg_check_modules(GTK REQUIRED gtk+-2.0)

include_directories( ${GTK_INCLUDE_DIRS} )
link_directories( ${GTK_LIBRARY_DIRS} )

add_definitions( ${GTK_CFLAGS_OTHER} )

file(GLOB all_SRCS
	"${PROJECT_SOURCE_DIR}/*.h"
	"${PROJECT_SOURCE_DIR}/*.c"
)

add_executable( GameOfLife main.c ${all_SRCS} )

target_link_libraries( GameOfLife ${CMAKE_THREAD_LIBS_INIT} ${GTK_LIBRARIES} )