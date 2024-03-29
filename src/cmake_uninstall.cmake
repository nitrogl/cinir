# Date : Jan 8, 2015
# Author : Roberto Metere

# Get informations about the installation from the file "install_manifest.txt"
if (NOT EXISTS "/home/rmet/Documents/C++/cinir/src/install_manifest.txt")
        message (FATAL_ERROR "Cannot find install manifest: \"/home/rmet/Documents/C++/cinir/src/install_manifest.txt\"")
endif (NOT EXISTS "/home/rmet/Documents/C++/cinir/src/install_manifest.txt")

# Find any installed file from the manifest
file (READ "/home/rmet/Documents/C++/cinir/src/install_manifest.txt" files)
string (REGEX REPLACE "\n" ";" files "${files}")

# Just loop the deletion of any (possibly) installed
foreach (file ${files})
        # Uninstalling files...
        message (STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"... ")

        # Don't care if existing or not, just try to remove it!
        execute_process (
                COMMAND /usr/bin/cmake -E remove "$ENV{DESTDIR}${file}"
                OUTPUT_VARIABLE rm_out
                RESULT_VARIABLE rm_retval
                )

        # Give a feedback about the removal
        if (${rm_retval} EQUAL 0)
                message ("\"$ENV{DESTDIR}${file}\" successfully removed (if existing).")
        else (${rm_retval} EQUAL 0)
                message ("Error removing \"$ENV{DESTDIR}${file}\" (It could not exist any more.)")
        endif (${rm_retval} EQUAL 0)

endforeach(file)

# Copyright (C) 2015 Roberto Metere. All rights reserved.
