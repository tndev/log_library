cmake_minimum_required (VERSION 3.0.0)
project (logginglibrary)

include ( cmake/dist.cmake )


set(LOGLIB_VERSION_MAJOR "0")
set(LOGLIB_VERSION_MINOR "0")
set(LOGLIB_VERSION_PATCH "1")
set(LOGLIB_VERSION_EXTRA "")
set(LOGLIB_VERSION "${LOGLIB_VERSION_MAJOR}.${LOGLIB_VERSION_MINOR}")
set(LOGLIB_VERSION_FULL "${LOGLIB_VERSION}.${LOGLIB_VERSION_PATCH}${LOGLIB_VERSION_EXTRA}")


#set_property(GLOBAL PROPERTY USE_FOLDERS ON)


SET(LOGLIB_SOURCE_DIR "library" )


option(LOGLIB_BUILD_EXAMPLES "Build the LOGLIBs example programs" ON)

if (BUILD_SHARED_LIBS)
	set(_LOGLIB_BUILD_DLL 1)
endif()

#compilerflags ??? MSVC see glfw


add_subdirectory (library)


if (LOGLIB_BUILD_EXAMPLES)
	add_subdirectory (examples)
endif()
