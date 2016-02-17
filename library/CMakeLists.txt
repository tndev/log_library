set (project_name logginglib)

find_package(Threads)

# sources
set(SOURCES loglib/debug.h loglib/debug.cpp
			loglib/assert.h loglib/assert.cpp
			loglib/string_utils.h loglib/string_utils.cpp
			loglib/thread_info.h loglib/thread_info.cpp
			loglib/thread_info_helper.h loglib/thread_info_helper.cpp)

#${HEADERS}

include_directories("./")



SET(CMAKE_DEBUG_POSTFIX _d)
add_library(${project_name} ${SOURCES} )

if(MSVC)
    # msvc does not append 'lib' - do it here to have consistent name
    set_target_properties(${project_name} PROPERTIES PREFIX "lib")
    set_target_properties(${project_name} PROPERTIES IMPORT_PREFIX "lib")
endif()


set_property(TARGET ${project_name} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${project_name} PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(${project_name}  ${used_libaries} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories (${project_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
