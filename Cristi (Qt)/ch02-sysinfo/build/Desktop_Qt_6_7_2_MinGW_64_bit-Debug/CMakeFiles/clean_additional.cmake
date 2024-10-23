# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ch02-sysinfo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ch02-sysinfo_autogen.dir\\ParseCache.txt"
  "ch02-sysinfo_autogen"
  )
endif()
