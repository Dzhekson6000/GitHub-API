cmake_minimum_required(VERSION 2.8)

SET(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM})
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})

SET( LIB GitHub-API )
SET( PROJECT_ROOT "${CMAKE_SOURCE_DIR}/" )

IF(UNIX AND NOT APPLE)
    SET(LINUX ON)
ENDIF(UNIX AND NOT APPLE)

IF(WIN32)
	MESSAGE(SEND_ERROR "WINDOWS is unsupported yet ;)")
ENDIF(WIN32)

#--------------------------------------------------------------------
# Set source files.
#--------------------------------------------------------------------
AUX_SOURCE_DIRECTORY( ${PROJECT_ROOT}/source SOURCES )

SET(PROJECT_SOURCES
    ${SOURCES}
)

#--------------------------------------------------------------------
# Compile
#--------------------------------------------------------------------
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o0 -g3 -std=c++11")

INCLUDE_DIRECTORIES(
    ${PROJECT_ROOT}/include/
    ${INCLUDE_LIB_DIR}
)

#ADD_LIBRARY( ${LIB} SHARED ${PROJECT_SOURCES} )

ADD_EXECUTABLE( ${LIB} ${PROJECT_SOURCES} )

#TARGET_LINK_LIBRARIES( ${LIB})

SET_TARGET_PROPERTIES(${LIB}
	PROPERTIES 
	VERSION ${MAJOR_VERSION}
	SOVERSION ${MINOR_VERSION}
)
