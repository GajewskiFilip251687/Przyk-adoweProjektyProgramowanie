#include <iostream>
#include <math.h>
#include "shapes.h"
using namespace std;

///////////////////////////////////////
Kwadrat::Kwadrat(float x=1){
    a = x;
}
virtual void Kwadrat::obliczPole(){
    cout<<"Pole tego kadratu wynosi: "<<a*a<<endl;
}
////////////////////////////////////////
Prostokat::Prostokat(float x=1, float y=1){
    a = x;
    b = y;
}
virtual void Prostokat::obliczPole(){
    cout<<"Pole tego prostokata wynosi: "<<a*b<<endl;
}
////////////////////////////////////////
Trojkat::Trojkat(float x=2, float y=1){
    a = x;
    h = y;
}
virtual void Trojkat::obliczPole(){
    cout<<"Pole tego trojkata wynosi: "<<(a*h)/2<<endl;
}
////////////////////////////////////////
Romb::Romb(float x=2, float y=1){
    a = x;
    h = y;
}
virtual void Romb::obliczPole(){
    cout<<"Pole tego rombu wynosi: "<<a*h<<endl;
}
////////////////////////////////////////
Trapez::Trapez(float x=2, float y=4, float z=1){
    a = x;
    b = y;
    h = z;
}
virtual void Trapez::obliczPole(){
    cout<<"Pole tego trapezu wynosi: "<<((a+b)*h)/2<<endl;
}
////////////////////////////////////////
Kolo::Kolo(float x=1){
    r = x;
}
virtual void Kolo::obliczPole(){
    cout<<"Pole tego kola wynosi: "<<M_PI*r*r<<endl;
}
////////////////////////////////////////