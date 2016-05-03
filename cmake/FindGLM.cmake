find_path(GLM_INCLUDE_DIR "glm/glm.hpp")
#include(FindPackageHandleStandardArgs)
#find_package_handle_standard_args(GLM
#                                  REQUIRED_VARS GLM_INCLUDE_DIR GLM_LIBRARY)

#if(GLM_FOUND AND NOT TARGET GLM::GLM)
#  add_library(GLM::GLM UNKNOWN IMPORTED)
#  set_target_properties(GLM::GLM PROPERTIES
#    INTERFACE_INCLUDE_DIRECTORIES "${GLM_INCLUDE_DIRS}")
#endif()
