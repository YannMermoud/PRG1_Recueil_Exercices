cmake_minimum_required(VERSION 3.12)

# Set project name and compiler
project(Exercices_PRG1)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXECUTABLE_SUFFIX ".exe") # On Windows, executables have .exe suffix

add_compile_options(-Wall -Wextra -Wpedantic -g)

# Collect all .cpp files in the current directory
file(GLOB CPP_FILES CONFIGURE_DEPENDS "*.cpp")

# For each .cpp file, create an executable
foreach(CPP_FILE ${CPP_FILES})
    # Extract the file name without an extension
    get_filename_component(EXE_NAME ${CPP_FILE} NAME_WE)
    
    # Add an executable for each cpp file
    add_executable(${EXE_NAME} ${CPP_FILE})
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
add_dependencies(clean_stale_executables ${EXE_NAME})
