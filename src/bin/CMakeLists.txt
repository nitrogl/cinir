#    Date : Dec 21, 2015
# Authors : Roberto Metere
#
# Test cmake file.

# Make sure the compiler can find include files from the "eopsi" library.
include_directories (
  "${PROJECT_SOURCE_DIR}/"
  "../"
  )

# Make sure the linker can find the library once it is built.
link_directories (
  "${PROJECT_BINARY_DIR}/"
  )


# Add executable "example"
add_executable(example example.cpp)
target_link_libraries (example "${LIBRARY_NAME}")
set_target_properties (example PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)
configure_file("example.ini" "example.ini" COPYONLY)

# Copyright (C) 2015 Roberto Metere
