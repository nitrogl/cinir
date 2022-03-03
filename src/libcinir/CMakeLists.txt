#    Date : Dec 21, 2015
# Authors : Roberto Metere
#
# The library
add_library (${LIBRARY_NAME} SHARED
        exception.cpp
        utils.cpp
        section.cpp
        reader.cpp
        libcinir.rc
        )

# Arrange some properties, differing between OSes
if (WIN32)
  set_target_properties (${LIBRARY_NAME}
        PROPERTIES
        PREFIX ""
        OUTPUT_NAME ${LIBRARY_NAME}
        VERSION "${LIBRARY_VERSION_RELEASE}.${LIBRARY_VERSION_MAJOR}.${LIBRARY_VERSION_MINOR}"
        SOVERSION "${LIBRARY_VERSION_RELEASE}"
        )
else(WIN32)
  set_target_properties (${LIBRARY_NAME}
        PROPERTIES
        OUTPUT_NAME ${LIBRARY_NAME}
        VERSION "${LIBRARY_VERSION_RELEASE}.${LIBRARY_VERSION_MAJOR}.${LIBRARY_VERSION_MINOR}"
        SOVERSION "${LIBRARY_VERSION_RELEASE}"
        )
endif(WIN32)

if (UNIX)
include(GNUInstallDirs)
install (
        TARGETS ${LIBRARY_NAME}
        DESTINATION "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/"
        )

# Installing headers for developers
install ( # main header (it should be enough to include in programs)
        FILES "../lib${LIBRARY_NAME}.h"
        DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
        )
install ( # the needed included files
        DIRECTORY "../lib${LIBRARY_NAME}/"
        DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lib${LIBRARY_NAME}"
        FILES_MATCHING REGEX "[a-z]+\\.(h|hpp)"
        )
endif (UNIX)

# Copyright (C) 2015 Roberto Metere
