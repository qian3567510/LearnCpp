add_library(MathFunctions MathFunctions.cpp mysqrt.cpp )

target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} )