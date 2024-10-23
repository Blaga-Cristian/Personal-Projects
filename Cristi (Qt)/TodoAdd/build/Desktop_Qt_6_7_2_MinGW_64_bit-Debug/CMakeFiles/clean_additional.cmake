# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TodoAdd_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TodoAdd_autogen.dir\\ParseCache.txt"
  "TodoAdd_autogen"
  )
endif()
