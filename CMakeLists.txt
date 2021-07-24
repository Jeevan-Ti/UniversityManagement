cmake_minimum_required(VERSION 3.12.2)

project(UniversityManagement)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release"
    CACHE STRING "Configuration types" FORCE)
    
add_subdirectory(UniversityManagement)
add_executable(UniversityManagementBuild
  Display.cpp
  Display.h
  File.cpp
  File.h
  icon1.ico
  Messages.cpp
  Messages.h
  News.cpp
  News.h
  Parent.cpp
  Parent.h
  resource.h
  stdafx.cpp
  stdafx.h
  Student.cpp
  Student.h
  targetver.h
  Teacher.cpp
  Teacher.h
  UniversityManagement.cpp
  UniversityManagement.rc
)
# Preprocessor definitions
target_compile_definitions(UniversityManagement PRIVATE
  $<$<CONFIG:Debug>:_UNICODE;_DEBUG;_CONSOLE;_CRT_SECURE_NO_WARNINGS>
  $<$<CONFIG:Release>:_UNICODE;NDEBUG;_CONSOLE>
)

# SDL check
target_compile_options(UniversityManagement PRIVATE
  "$<$<CONFIG:Debug>:/sdl>"
  "$<$<CONFIG:Release>:/sdl>"
)

# Minimal rebuild
if (MSVC)
  target_compile_options(UniversityManagement PRIVATE
    "$<$<CONFIG:Debug>:/Gm>"
    "$<$<CONFIG:Release>:/Gm->"
  )
endif ()

# Precompiled header files
if (MSVC)
  target_compile_options(UniversityManagement PRIVATE
    "$<$<CONFIG:Debug>:/Yu>"
    "$<$<CONFIG:Release>:/Yu>"
  )
  set_property(SOURCE stdafx.cpp
    APPEND_STRING PROPERTY COMPILE_FLAGS
    "$<$<CONFIG:Debug>:/Yc> \
     $<$<CONFIG:Release>:/Yc>")
endif ()
