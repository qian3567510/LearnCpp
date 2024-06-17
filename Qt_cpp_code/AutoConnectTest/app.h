#include <QMetaObject>
#include <QWidget>
#include <QApplication>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

class MyWindow : public QWidget 
{
    // 这个宏很容易忘了，忘了就不能连接信号和槽了
    Q_OBJECT

public:
    // 构造函数
    MyWindow(QWidget* parent = nullptr);
    // 析构函数
    ~MyWindow();

private:
    // 私有函数
    void initUi(void);
    // 以下是用到的部件（控件）
    QPushButton *btn1;
    QPushButton *btn2;
    QLabel *lb;
    // 布局
    QVBoxLayout *layout;
    QHBoxLayout *sublayout;

    // 这几个函数是用于自动绑定的槽
private slots:
    void on_b1_clicked();
    void on_b2_clicked();
};