// cmake -DCMAKE_PREFIX_PATH=C:\Qt\6.7.1\mingw_64 -S .. -B .
// cmake -DCMAKE_PREFIX_PATH=C:\Qt\6.7.1\msvc2019_64 -S .. -B .
#include "app.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // 实例化窗口
    MyWindow wind;
    // 显示窗口
    wind.show();
    // 消息循环
    return app.exec();
}
