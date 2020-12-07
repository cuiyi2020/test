#include "rwidget.h"
#include "login/rxml.h"
#include "login/rlogin.h"
#include "practice.h"
#include "login/sha.h"
#include "login/rlogin.h"

#include <QApplication>
#include <string>
#include <QDebug>
#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

using namespace std;

void print(QString rhs, bool b);
void print(bool b);
void test_xml();
void test_func();
void test_func1();
void qml_main();
void test_login();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Rwidget w;
    //w.resize(1280, 800);
    //w.show();
    //setvbuf(stdout, 0, _IONBF, 0);
    //test_xml();
    //test_func1();
    //qml_main();
    test_login();
    return a.exec();
}

void test_login(){
    Rlogin *lg = new Rlogin;
    //lg->resize(1280, 800);
    lg->show();
}

void qml_main()
{
    QQuickWidget *view = new QQuickWidget();
    view->setSource(QUrl("qrc:/rock.qml"));
    view->show();
    qDebug()<<"hello";
}

void test_func1(){
//   A a(6);
//   B *b = (B*)&a;
//   b->print();
//   std::cout << b->a << std::endl;
//    C *p = new D();
//    p->func();
    test_sha();
}

void test_xml(){
    Rxml rx;
    bool res = false;
    //bool res = rx.is_ok("admin", "roborock");
    res = rx.is_ok("yangjian", "flmay");
    print("Yangjian is ok?", res);

    res = rx.is_ok("adm", "123");
    print("Before add adm:", res);

    rx.add_user("adm", "123");
    res = rx.is_ok("adm", "123");
    print("After add adm:", res);

    rx.remove_user("adm");
    res = rx.is_ok("adm", "123");
    print("After remove adm:", res);

//    rx.add_user("adm", "123");
//    res = rx.is_ok("adm", "123");
//    print("After add adm:", res);
}

void test_func(){
    string str = "abc ok \n\t\n";
    char s[2] = {};
    int cnt = 0;
    for (int i=str.length()-1; i>=0; --i){
        if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
            continue;
        s[cnt++] = str[i];
        if (cnt >= 2)
            break;
    }
    string ss=s;
    qDebug() << ss.c_str();
}

void print(QString rhs, bool b){
    qDebug() << rhs;
    qDebug() << (b?"Username and password match.":"Username and password do not match.");
}

void print(bool b){
    qDebug() << (b?"Username and password match.":"Username and password do not match.");
}
