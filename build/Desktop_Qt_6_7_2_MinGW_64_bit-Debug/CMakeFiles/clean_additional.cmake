# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\biblio_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\biblio_autogen.dir\\ParseCache.txt"
  "biblio_autogen"
  )
endif()
