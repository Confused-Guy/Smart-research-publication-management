# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\interface_user_first_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\interface_user_first_autogen.dir\\ParseCache.txt"
  "interface_user_first_autogen"
  )
endif()
