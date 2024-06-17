// main.cpp

//对需要使用到的包，要使用g++ -std=c++23 -fmodules-ts -x c++-system-header iostream 先编译gcm输出到gcm.cache目录

//编译方式一
//g++ -std=c++23 -fmodules-ts -x c++-system-header iostream
//g++ -std=c++23 -fmodules-ts .\helloworld.cpp .\main.cpp -o main.exe

//编译方式二
//g++ -std=c++23 -fmodules-ts -x c++-system-header iostream
//g++ -std=c++23 -fmodules-ts -c .\helloworld.cpp
//g++ -std=c++23 -fmodules-ts -c .\main.cpp
//g++ -std=c++23 -fmodules-ts .\helloworld.o .\main.o -o main.exe

import helloworld; // 导入声明
 
int main()
{
    hello();
}