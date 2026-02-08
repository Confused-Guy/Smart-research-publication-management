# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\conference_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\conference_autogen.dir\\ParseCache.txt"
  "conference_autogen"
  )
endif()
