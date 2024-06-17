#设定Cmake的最低版本要求
#cmake_minimum_required(VERSION 2.8...3.13)
#项目名称，可以和文件夹名称不同
#project(cmake_test)
#设定编译器
#set(CMAKE_CXX_COMPILER "g++")
#设定编译选项
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 ")
#添加头文件
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
#命令指定 SRC变量（自己定义就行）来表示多个源文件
# set(SRC main.cpp src/hello.cpp)
#命令指定 SRC变量（自己定义就行）来表示多个源文件
#file(GLOB SRC "src/*.cpp")
#将生成的可执行文件保存至bin文件夹中
#set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#生成可执行文件main.exe(可执行文件名 自己定义就行)，用${var_name}获取变量的值。
#add_executable(test ${SRC})

#设定最低版本要求
cmake_minimum_required (VERSION 3.15)

#设定项目名称 版本号，名称可以和文件夹名称、主文件名称不一致
#project (Tutorial)
project(Tutorial VERSION 1.0.2)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 定义编译时间
string(TIMESTAMP COMPILE_TIME "%Y%m%d-%H%M%S")

configure_file(src/TutorialConfig.h.in TutorialConfig.h)

#set(CMAKE_CXX_COMPILER "g++")

set(SRC_LIST src/tutorial.cpp )

# option 表示提供用户可以选择的选项。命令格式为：option(<variable> "description [initial value])。
option(USE_MYMATH "Use tutorial provided math implementation" ON)

#   处理可选组件的经典方法
#APPEND表示将元素MathFunctions追加到列表EXTRA_LIBS中
#将元素 ${PROJECT_SOURCE_DIR}/src/MathFunctions 追加到列表EXTRA_INCLUDES中
#变量EXTRA_LIBS 存储 MathFunctions 库，变量EXTRA_INCLUDES 存储 MathFunctions 头文件
#EXTRA_LIBS 用来保存需要链接到可执行程序的可选库，EXTRA_INCLUDES用来保存可选的头文件搜索路径
#if(USE_MYMATH)
#  add_subdirectory(src/MathFunctions)
#  list(APPEND EXTRA_LIBS MathFunctions)
#  list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/src/MathFunctions)
#endif()

#   处理可选组件的现代方法
# 在库文件目录的CMakeLists.txt中声明target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} )
# 这样在主CMakeLists.txt的target_include_directories就需要在额外生命头文件的路径
# 现在只要是链接了 MathFunctions 库，就会自动包含 MathFunctions 所在目录的头文件，方式更简洁
if(USE_MYMATH)
  add_subdirectory(src/MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
  #list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/src/MathFunctions)
endif()

#add_subdirectory(src/MathFunctions)

#add_executable(Tutorial src/tutorial.cpp)
add_executable(${PROJECT_NAME} ${SRC_LIST})

#target_link_libraries(${PROJECT_NAME} PUBLIC MathFunctions)
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

#将build目录添加到搜索头文件的路径列表中
#PROJECT_BINARY_DIR 表示当前工程的二进制路径，即编译结果会存放的路径；当前对应于build目录
#${PROJECT_SOURCE_DIR} is a path to the project source
#target_include_directories(${PROJECT_NAME} PUBLIC  ${PROJECT_BINARY_DIR}  ${PROJECT_SOURCE_DIR}/src/MathFunctions)
#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR} ${EXTRA_INCLUDES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR} )