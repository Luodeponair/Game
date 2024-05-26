#include "forgetpass.h"
#include "ui_forgetpass.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "regist.h"
#include "ui_regist.h"
#include <QFile>
#include <QTextStream>

forgetpass::forgetpass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forgetpass)
{
    ui->setupUi(this);
    this->setFixedSize(890,590);
    QPalette palette;
    //设置标题
     this->setWindowTitle("找回密码");
    QPixmap pixmap(":/res/bk2..png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    QFont font ( 0, 20, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    QFont fontt ( 0, 15, 75);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->pushButton->setFont(fontt);
    ui->pushButton_2->setFont(fontt);
    ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
    ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
}

forgetpass::~forgetpass()
{
    delete ui;
}

void forgetpass::on_pushButton_clicked()
{
    GameMenu *fater=new GameMenu();
    this->close();
    fater->show();
}


void forgetpass::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit->text();
    QString ques = ui->lineEdit_2->text();

    if (!name.isEmpty() && !ques.isEmpty())
    {
        QFile file("C:/Users/l1472/Desktop/chess1/chess/chess/player.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            QString line;
            bool found = false;
            while (!in.atEnd())
            {
                line = in.readLine();
                QStringList parts = line.split(":");
                if (parts.size() == 2 && parts[0] == name && parts[1].trimmed() == ques)
                {
                    found = true;
                    QMessageBox::information(this, "恭喜!", "请重置密码!");
                    // 然后跳转新窗口，这里应该使用信号与槽来隐藏当前窗口并显示新窗口
                    this->hide();
                    Form *board = new Form();
                    board->show();
                    break;
                }
            }
            if (!found)
            {
                QMessageBox::critical(this, "错误！", "答案或账号有误！");
            }
            file.close();
        }
        else
        {
            QMessageBox::critical(this, "错误！", "无法打开文件！");
        }
    }
    else
    {
        QMessageBox::critical(this, "错误！", "答案为空");
    }
}
