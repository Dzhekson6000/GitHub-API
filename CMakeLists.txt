cmake_minimum_required(VERSION 2.8)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})

SET( LIB GitHub-API )
SET( PROJECT_ROOT "${CMAKE_SOURCE_DIR}/" )

SET( LIB_INSTALL_PATH /usr/local/lib )
SET( HEADERS_INSTALL_PATH /usr/local/include/GitHub-API )

SET( MAJOR_VERSION 1.0.0 )
SET( MINOR_VERSION 1.0 )

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

SET( LIB_HEADERS ${PROJECT_ROOT}/include/ )

SET( HEADERS ${HEADERS} ${LIB_HEADERS})

#--------------------------------------------------------------------
# Set Threads.
#--------------------------------------------------------------------
find_package (Threads)
SET( REQUIRED_LIBRARIES ${REQUIRED_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
#--------------------------------------------------------------------
# Set SiTNetwork.
#--------------------------------------------------------------------
SET(SITNETWORK_INCLUDE_DIRS /usr/local/include/SiTNetwork )
SET(SITNETWORK_LIBRARY /usr/local/lib/libSiTNetwork.so )

SET( REQUIRED_LIBRARIES ${REQUIRED_LIBRARIES} ${SITNETWORK_LIBRARY})
SET( HEADERS ${HEADERS} ${SITNETWORK_INCLUDE_DIRS} )
#--------------------------------------------------------------------
# Compile
#--------------------------------------------------------------------
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o0 -g3 -std=c++11")

INCLUDE_DIRECTORIES(${HEADERS})
LINK_DIRECTORIES( ${LIB_INSTALL_PATH} )

#ADD_LIBRARY( ${LIB} SHARED ${PROJECT_SOURCES} )
ADD_EXECUTABLE( ${LIB} ${PROJECT_SOURCES} )

TARGET_LINK_LIBRARIES( ${LIB} ${REQUIRED_LIBRARIES})

SET_TARGET_PROPERTIES(${LIB}
	PROPERTIES 
	VERSION ${MAJOR_VERSION}
	SOVERSION ${MINOR_VERSION}
)

INSTALL( TARGETS ${LIB} DESTINATION ${LIB_INSTALL_PATH} )
INSTALL( DIRECTORY ${LIB_HEADERS}
         DESTINATION ${HEADERS_INSTALL_PATH}
         FILES_MATCHING PATTERN "*.h" )
