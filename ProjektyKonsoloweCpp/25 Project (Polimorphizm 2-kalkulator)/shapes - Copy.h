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
    Kwadrat(float=1);
    virtual void obliczPole();
};
////////////////////
class Prostokat :public Shape{
    float a,b;
public:
    Prostokat(float x=1, float y=1);
    virtual void obliczPole();
};
/////////////////////
class Trojkat :public Shape{
    float a,h;
public:
    Trojkat(float x=2, float y=1);
    virtual void obliczPole();
};
/////////////////////
class Romb :public Shape{
    float a,h;
public:
    Romb(float x=2, float y=1);
    virtual void obliczPole();
};
////////////////////
class Trapez :public Shape{
    float a,b,h;
public:
    Trapez(float x=2, float y=4, float z=1);
    virtual void obliczPole();
};
//////////////////////
class Kolo :public Shape{
    float r;
public:
    Kolo(float x=1);
    virtual void obliczPole();
};
//////////////////////////