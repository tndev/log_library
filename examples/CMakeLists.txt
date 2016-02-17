link_libraries(logginglib)

set (project_name loglib_example)
find_package(Threads)

##include("loglibrary")


include_directories("../${LOGLIB_SOURCE_DIR}")

add_executable (${project_name} main.cpp)


set_property(TARGET ${project_name} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${project_name} PROPERTY CXX_STANDARD_REQUIRED ON)


target_link_libraries (${project_name} ${LOGLIB_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
