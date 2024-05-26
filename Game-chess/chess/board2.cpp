#include "board2.h"
#include "ui_board2.h"
#include "board.h"
#include "ui_board.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QLabel>
#include <QString>
#include<QDebug>
#include<QTimer>
#include"Step.h"
#include"Stone.h"
#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exdispid.h"
#include "ui_exitapp.h"
#include "exitapp.h"
#include "inform.h"
#include "singlegame.h"
#include "canju.h"
#include "canjuwindow.h"
#include "ui_canjuwindow.h"
#include <QThread>
#include "help.h"
#include <synchapi.h>
#include "board3.h"
//通过id获取行列，与bool类型的获取函数相区别
#define GetRowCol(__row, __col, __id) \
    int __row = _s[__id]._row;\
    int __col = _s[__id]._col

board2::board2(QWidget *parent) :Board(parent),

    ui(new Ui::board2)
{
    ui->setupUi(this);
    ui->setupUi(this);
    //设置标题

    //设置图标(QPixMap也可)
    this->setWindowIcon(QIcon(":/res/tubiao.png"));
     this->setWindowTitle("游戏主界面");
    //展示该谁下了


   //插入背景图片
    QPalette palette;
    QPixmap pixmap(":/res/redcbb.png");
    setFixedSize(pixmap.size());   //让窗口大小就是棋盘图片的大小
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
      chesstype();
        _selectid = -1;
        _bRedTurn = true;
        //新开游戏的按钮，功能为棋子归位重开一局
        GPushButton * newgame = new GPushButton(":/res/newgame.png",":/res/newgamecopy.png");
        newgame->setParent(this);
        newgame->move(25,25);
        QString str=QString::fromUtf8("newgame");
        newgame->setToolTip(str);
        connect(newgame,&QPushButton::clicked,[=]{

            this->close();
            Board *b=new Board();
            b->show();
        });
        //读取游戏的按钮，功能为读取上一次的棋盘
        GPushButton * loadgame = new GPushButton(":/res/loadgame.png",":/res/loadgame.png");
        loadgame->setParent(this);
        loadgame->move(80,25);
        QString str1=QString::fromUtf8("loadgame");
        loadgame->setToolTip(str1);
        connect(loadgame,&QPushButton::clicked,[=]{

           chesstype();
           update();
           Sleep(500);
           qDebug()<<"共有"<<st<<"步";
            for(int j=0;j<2*st;j+=2)
            {
                fupan(j);

            }
                });
        //残局按钮，点击选择所需残局
        GPushButton * endgame = new GPushButton(":/res/endgame.png",":/res/endgame.png");
        endgame->setParent(this);
        endgame->move(135,25);
        QString str6=QString::fromUtf8("endgame");
        endgame->setToolTip(str6);
        connect(endgame,&QPushButton::clicked,[=]{

            this->close();
            canjuwindow *c=new canjuwindow();
            c->show();
        });
        //帮助按钮，点击将显示国际象棋规则
        GPushButton * helps = new GPushButton(":/res/helpgame.png",":/res/helpgame.png");
        helps->setParent(this);
        helps->move(190,25);
        QString str2=QString::fromUtf8("help");
        helps->setToolTip(str2);
        help *he=new help();
        connect(helps,&QPushButton::clicked,he,&QWidget::show);
        //信息按钮，点击将显示本游戏相关信息
        GPushButton * informs = new GPushButton(":/res/inform.png",":/res/inform.png");
        informs->setParent(this);
        informs->move(245,25);
        QString str3=QString::fromUtf8("information");
        informs->setToolTip(str3);
        inform *inf=new  inform();
        connect(informs,&QPushButton::clicked,inf,&QWidget::show);
        //人机按钮，点击进入人机对战
        GPushButton * ai = new GPushButton(":/res/AI.png",":/res/AI.png");
        ai->setParent(this);
        ai->move(300,25);
        QString str5=QString::fromUtf8("AI practice");
        ai->setToolTip(str5);
        connect(ai,&QPushButton::clicked,[=]{

            this->close();
            Singlegame *s=new Singlegame();
            s->show();
        });
        //退出游戏按钮，即点即退
        GPushButton * exitgame = new GPushButton(":/res/exitgame.png",":/res/exitgame.png");
        exitgame->setParent(this);
        exitgame->move(355,25);
        QString str4=QString::fromUtf8("exit");
        exitgame->setToolTip(str4);
        exitapp *e=new exitapp();
        connect(exitgame,&QPushButton::clicked,e,&QWidget::show);

        GPushButton * set= new GPushButton(":/res/changeco.png",":/res/changeco.png");
        set->setParent(this);
        set->move(410,25);
        QString str7=QString::fromUtf8("change");
        set->setToolTip(str7);

        connect(set,&QPushButton::clicked,[=]{
            this->close();
           board3 *b=new board3();
            b->show();



        });




        //创建悔棋按钮
        GPushButton * re = new GPushButton(":/res/huiqi.png",":/res/huiqi.png");
        re->setParent(this);
        re->move(640,420);
        QString r=QString::fromUtf8("Regret");
        re->setToolTip(r);
        connect(re,&QPushButton::clicked,[=]{
                  huiqi();
                });

        //创建认输按钮
        GPushButton * de= new GPushButton(":/res/defeat.png",":/res/defeat.png");
        de->setParent(this);
        de->move(640,500);
        QString d=QString::fromUtf8("Abandon");
        de->setToolTip(d);
        connect(de,&QPushButton::clicked,[=]{
            QString str = _bRedTurn?QStringLiteral("黑棋获胜!"):QStringLiteral("白棋获胜!");
            QMessageBox::information(NULL,  "GAME OVER",str, QMessageBox::Yes);
                });




          update();
}

board2::~board2()
{
    delete ui;
}
