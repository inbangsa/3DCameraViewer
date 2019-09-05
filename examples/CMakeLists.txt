PROJECT(OSG_Cookbook)

CMAKE_MINIMUM_REQUIRED(VERSION 2.4.7)


# set cmake policy
IF(COMMAND CMAKE_POLICY)
CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND CMAKE_POLICY)

IF(WIN32)
	IF(MSVC)
		ADD_DEFINITIONS(-D_SCL_SECURE_NO_WARNINGS)
		ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE)
	ENDIF(MSVC)
ELSE(WIN32)
	SET(CMAKE_CXX_FLAGS "-W -Wall -Wno-unused")
ENDIF(WIN32)
#[[
message("What are this symbols:${PATHS} , $ENV{OSG_ROOT} ")
SET(MY_OSG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../install/" )

# find include directory by looking for certain header file
FIND_PATH(OPENSCENEGRAPH_INCLUDE_DIR osg/Referenced
			PATHS
			${MY_OSG_ROOT}/include
			/usr/include
			/usr/local/include
)	

# find library directory by looking for certain library file 
FIND_LIBRARY(OPENSCENEGRAPH_LIB_DIR osg160-osgd.lib osg160-osgUtild.lib osg160-osgViewerd.lib
	PATHS
	${MY_OSG_ROOT}/lib
	/usr/lib
	/usr/local/lib
)
#  make VERBOSE=1  ==> 
# how find_package works https://gitlab.kitware.com/cmake/community/wikis/doc/tutorials/How-To-Find-Libraries
message(STATUS "looked for OSG library.")
message(STATUS "Include file detected: [${OPENSCENEGRAPH_INCLUDE_DIR}].")
message(STATUS "Lib file detected: [${OPENSCENEGRAPH_LIB_DIR}].")

# apply them to following projects

LINK_DIRECTORIES(${MY_OSG_ROOT}/lib)#${OPENSCENEGRAPH_LIB_DIR})#
]]#
#find_package(osg REQUIRED)
INCLUDE_DIRECTORIES(${CMAKE_PREFIX_PATH}/include)
LINK_DIRECTORIES(${CMAKE_PREFIX_PATH}/lib)
SET(EXAMPLE_NAME my_example)
SET(EXAMPLE_FILES osggeometry.cpp)
ADD_EXECUTABLE(${EXAMPLE_NAME} ${EXAMPLE_FILES})

TARGET_LINK_LIBRARIES(${EXAMPLE_NAME}
	osg
	osgUtil
	osgViewer
	osgDB
	osgGA
	osgWidget
	osgVolume
	osgText
	osgTerrain
	osgSim
	osgShadow
	osgAnimation
	osgPresentation
	osgFX
	OpenThreads
)



INSTALL(TARGETS ${EXAMPLE_NAME} RUNTIME DESTINATION
${CMAKE_INSTALL_PREFIX}/bin) 
# cmake -DCMAKE_INSTALL_PREFIX=../ .. or cmake -DCMAKE_INSTALL_PREFIX=../  -DCMAKE_PREFIX_PATH=../install ..
# cmake --build . --clean-first --config debug
# {CMAKE_CURRENT_SOURCE_DIR}/applications/CMakeLists.txt 
# CMAKE_BUILD_TYPE:UNINITIALIZED=RelWithDebInfo || Debug 
# CMAKE_INSTALL_PREFIX:PATH={CMAKE_CURRENT_SOURCE_DIR}/../install

# -DOSG_LIBRARY_STATIC=ON _DDYNAMIC_OPENTHREADS=OFF -DDYNAMIC_OPENSCENEGRAPH=OFF and commented ADD_SUBDIRECTORY(present3D)
# changed in CMAKE_CXX_FLAGS... and CMAKE_C_FLAGS... MD->MT
