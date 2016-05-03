find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h)
find_library(GLFW_LIBRARY 
			 NAMES GLFW glfw glfw3dll glfw3
			 PATH_SUFFIXES lib64)
	
set(GLFW_INCLUDE_DIRS ${GLFW_INCLUDE_DIR})
set(GLFW_LIBRARIES ${GLFW_LIBRARY})


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GLFW
                                  REQUIRED_VARS GLFW_INCLUDE_DIR GLFW_LIBRARY)

if(GLFW_FOUND AND NOT TARGET GLFW::GLFW)
  add_library(GLFW::GLFW UNKNOWN IMPORTED)
  set_target_properties(GLFW::GLFW PROPERTIES
    IMPORTED_LOCATION "${GLFW_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${GLFW_INCLUDE_DIRS}")
endif()

if (UNIX AND NOT APPLE)
     list(APPEND GLFW_LIBRARIES libXxf86vm.so)
     list(APPEND GLFW_LIBRARIES libGLU.so)
     list(APPEND GLFW_LIBRARIES libX11.so)
     list(APPEND GLFW_LIBRARIES libXrandr.so)
     list(APPEND GLFW_LIBRARIES libpthread.so)
     list(APPEND GLFW_LIBRARIES libXi.so)
 endif()

#mark_as_advanced(GLFW_INCLUDE_DIR GLFW_LIBRARY)
