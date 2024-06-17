#include "app.h"
#include <QLayout>
#include <QPushButton>

MyWindow::MyWindow(QWidget *parent)
    : QWidget::QWidget(parent)
{
    // 调用以下函数，初始化UI
    initUi();
    // 一定要在所有东东都初始化完毕后调用才有效
    QMetaObject::connectSlotsByName(this);
}

MyWindow::~MyWindow() = default;

void MyWindow::initUi()
{
    // 按钮1
    btn1 = new QPushButton(this);
    // 设置按钮1的文本
    btn1->setText("左边");
    // 重要：给它个名字
    btn1->setObjectName("b1");

    // 按钮2
    btn2 = new QPushButton(this);
    // 设置按钮2的文本
    btn2->setText("右边");
    // 重要：设置名称
    btn2->setObjectName("b2");

    // 标签
    lb = new QLabel("请点击下面的按钮", this);

    // 布局
    layout = new QVBoxLayout(this);
    layout->addWidget(lb, 0, Qt::AlignTop);
    sublayout = new QHBoxLayout(this);
    // 添加要布局的组件
    sublayout->addWidget(btn1);
    sublayout->addWidget(btn2);
    layout->addLayout(sublayout);

    // 窗口
    this->setWindowTitle("示例王");
    this->resize(240, 100);
}

void MyWindow::on_b1_clicked()
{
    QMessageBox::information(this, "好消息", "左转是男厕", QMessageBox::Ok);
}
void MyWindow::on_b2_clicked()
{
    QMessageBox::information(this, "好消息", "右转是女厕", QMessageBox::Ok);
}