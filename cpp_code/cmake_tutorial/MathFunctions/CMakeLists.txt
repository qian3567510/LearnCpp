# TODO 14: Remove mysqrt.cxx from the list of sources

# TODO 1: Add a library called MathFunctions with sources MathFunctions.cxx
# and mysqrt.cxx
# Hint: You will need the add_library command
#add_library(MathFunctions MathFunctions.cxx mysqrt.cxx)
add_library(MathFunctions MathFunctions.cxx )
target_include_directories(MathFunctions
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# TODO 7: Create a variable USE_MYMATH using option and set default to ON
option(USE_MYMATH "Using the customsized Math library instead of standard lib" OFF)

# TODO 8: If USE_MYMATH is ON, use target_compile_definitions to pass
# USE_MYMATH as a precompiled definition to our source files
if (USE_MYMATH)
    target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
# TODO 12: When USE_MYMATH is ON, add a library for SqrtLibrary with
# source mysqrt.cxx
    add_library(MYSqrt_Library STATIC mysqrt.cxx)
    target_link_libraries(MYSqrt_Library PUBLIC tutorial_compiler_flag)
# TODO 13: When USE_MYMATH is ON, link SqrtLibrary to the MathFunctions Library
    target_link_libraries(MathFunctions PRIVATE MYSqrt_Library)
endif()

target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flag)

# TODO 1: Create a variable called installable_libs that is a list of all
# libraries we want to install (e.g. MathFunctions and tutorial_compiler_flags)
# Then install the installable libraries to the lib folder.
# Hint: Use the TARGETS and DESTINATION parameters
set(installable_libs MathFunctions tutorial_compiler_flag)
if(TARGET MYSqrt_Library)
  list(APPEND installable_libs MYSqrt_Library)
endif()
install(TARGETS ${installable_libs} DESTINATION lib)

# TODO 2: Install the library headers to the include folder.
# Hint: Use the FILES and DESTINATION parameters
install(FILES MathFunctions.h DESTINATION include)


