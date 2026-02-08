# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/reveiw_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/reveiw_autogen.dir/ParseCache.txt"
  "reveiw_autogen"
  )
endif()
