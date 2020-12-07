#pragma once
#include <iostream>

class A {
public:
    A(int i):a(i){}
private:
    void print() {std::cout<<"A"<<std::endl;}
    int a;
};

class B {
public:
    void print() {std::cout<<"B"<<std::endl;}
    int a;
};

class C{
public:
    virtual void func(){std::cout << "C" <<std::endl;}
};

class D:public C{
private:
    void func() override{
        std::cout << "D" << std::endl;
    }
};


