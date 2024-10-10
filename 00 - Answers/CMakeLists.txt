cmake_minimum_required(VERSION 3.12)

# Set project name and compiler
project(Exercices_PRG1)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXECUTABLE_SUFFIX ".exe") # On Windows, executables have .exe suffix
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
add_compile_options(-Wall -Wextra -Wpedantic -g -Wimplicit-fallthrough)
add_definitions(-DUNICODE -D_UNICODE)

# Collect all .cpp files in the current directory for executables
file(GLOB CPP_FILES CONFIGURE_DEPENDS "*.cpp")

# Collect all subdirectories (assumed to be potential libraries)
file(GLOB LIBRARY_DIRS CONFIGURE_DEPENDS */)

# Container for the dynamically created libraries
set(LIBRARY_TARGETS)

# Set the output directory for static libraries to a "library" subfolder in the build directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/library)

# Loop over each subdirectory and create a library target
foreach(DIR ${LIBRARY_DIRS})
    # Check if the directory has a .cpp file to determine if it's a library
    file(GLOB LIBRARY_SOURCES "${DIR}/*.cpp")
    if(LIBRARY_SOURCES)
        # Extract library name from directory name
        get_filename_component(LIB_NAME ${DIR} NAME)
        
        # Create a library target for this directory
        add_library(${LIB_NAME} STATIC ${LIBRARY_SOURCES})
        
        # Include the directory for header file search
        include_directories(${DIR})
        
        # Set library output to a specific subdirectory inside the build folder
        set_target_properties(${LIB_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/library)

        # Add this library to the list of targets
        list(APPEND LIBRARY_TARGETS ${LIB_NAME})
    endif()
endforeach()

# List of executables and their required libraries
set(EXE_LIBRARIES)

# For each .cpp file, create an executable and link necessary libraries
foreach(CPP_FILE ${CPP_FILES})
    # Extract the file name without an extension
    get_filename_component(EXE_NAME ${CPP_FILE} NAME_WE)
    
    # Add an executable for each cpp file
    add_executable(${EXE_NAME} ${CPP_FILE})
    
    # Read the contents of the .cpp file
    file(READ ${CPP_FILE} FILE_CONTENTS)

    # Check for each library if its header is included in the .cpp file and link the library if found
    foreach(LIB_NAME ${LIBRARY_TARGETS})
        # Create the expected header file name (e.g., mylibrary/mylibrary.hpp)
        set(LIB_HEADER "${LIB_NAME}/${LIB_NAME}.hpp")

        # Link library if the .cpp file includes its header
        if(FILE_CONTENTS MATCHES "#include[ ]*\"${LIB_HEADER}\"")
            target_link_libraries(${EXE_NAME} PRIVATE ${LIB_NAME})
        endif()
    endforeach()

    # Add the executable to the list of executables for custom targets
    list(APPEND EXE_LIBRARIES ${EXE_NAME})
endforeach()

# Custom target to clean up stale executables
add_custom_target(clean_stale_executables ALL
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/remove_stale_executables.cmake
)

# Write a script to remove stale executables
file(WRITE ${CMAKE_BINARY_DIR}/remove_stale_executables.cmake "
    # Get the list of executable files currently in the build directory
    file(GLOB EXE_FILES_IN_BUILD \"${CMAKE_BINARY_DIR}/*${CMAKE_EXECUTABLE_SUFFIX}\")
    
    # For each executable file in the build directory
    foreach(EXE_FILE \${EXE_FILES_IN_BUILD})
        get_filename_component(EXE_NAME \${EXE_FILE} NAME_WE)

        # Assume the executable is not found in the list of valid ones
        set(EXE_FOUND FALSE)

        # Check if the corresponding .cpp file exists
        foreach(CPP_FILE ${CPP_FILES})
            get_filename_component(CPP_NAME \${CPP_FILE} NAME_WE)

            if(EXE_NAME STREQUAL CPP_NAME)
                set(EXE_FOUND TRUE)
                break()
            endif()
        endforeach()

        # If the executable does not correspond to any .cpp file, remove it
        if(NOT EXE_FOUND)
            file(REMOVE \${EXE_FILE})
        endif()
    endforeach()
")

# Ensure the clean_stale_executables target runs after building all executables
add_dependencies(clean_stale_executables ${EXE_LIBRARIES})
