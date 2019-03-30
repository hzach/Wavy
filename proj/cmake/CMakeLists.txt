cmake_minimum_required( VERSION 2.8 FATAL_ERROR )
set( CMAKE_VERBOSE_MAKEFILE ON )

project( Wavy )

set(CINDER_PATH $ENV{CINDER_PATH})
get_filename_component( APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE )

include( "${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake" )

ci_make_app(
	SOURCES     ${APP_PATH}/src/Wavy.cpp
	INCLUDES    ${APP_PATH}/include
	CINDER_PATH ${CINDER_PATH}
)
