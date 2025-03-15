#include <iostream>
#include <math.h>

using namespace std;

class Shape{
public:
    virtual void obliczPole()=0;
};
////////////////////
class Kwadrat :public Shape{
    float a;
public:
    Kwadrat(float x=1){
        a = x;
    }
    virtual void obliczPole(){
        cout<<"Pole tego kadratu wynosi: "<<a*a<<endl;
    }
};
////////////////////
class Prostokat :public Shape{
    float a,b;
public:
    Prostokat(float x=1, float y=1){
        a = x;
        b = y;
    }
    virtual void obliczPole(){
        cout<<"Pole tego prostokata wynosi: "<<a*b<<endl;
    }
};
/////////////////////
class Trojkat :public Shape{
    float a,h;
public:
    Trojkat(float x=2, float y=1){
        a = x;
        h = y;
    }
    virtual void obliczPole(){
        cout<<"Pole tego trojkata wynosi: "<<(a*h)/2<<endl;
    }
};
/////////////////////
class Romb :public Shape{
    float a,h;
public:
    Romb(float x=2, float y=1){
        a = x;
        h = y;
    }
    virtual void obliczPole(){
        cout<<"Pole tego rombu wynosi: "<<a*h<<endl;
    }
};
////////////////////
class Trapez :public Shape{
    float a,b,h;
public:
    Trapez(float x=2, float y=4, float z=1){
        a = x;
        b = y;
        h = z;
    }
    virtual void obliczPole(){
        cout<<"Pole tego trapezu wynosi: "<<((a+b)*h)/2<<endl;
    }
};
//////////////////////
class Kolo :public Shape{
    float r;
public:
    Kolo(float x=1){
        r = x;
    }
    virtual void obliczPole(){
        cout<<"Pole tego kola wynosi: "<<M_PI*r*r<<endl;
    }
};
//////////////////////////