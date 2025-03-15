#include <iostream>
#include <math.h>
#include <limits>
//#include "shapes.h"
//#include "shapes.cpp"
using namespace std;
char user_choice;

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
        cout<<"Pole tego kadratu wynosi: "<<a*a<<" a jego obwod wynosi "<<4*a<<endl;
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
        cout<<"Pole tego prostokata wynosi: "<<a*b<<" a jego obwod wynosi "<<(2*a) + (2*b)<<endl;
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
        cout<<"Pole tego rombu wynosi: "<<a*h<<" a jego obwod wynosi "<<4*a<<endl;
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
        cout<<"Pole tego kola wynosi: "<<M_PI*r*r<<" a jego obwod wynosi "<<2*M_PI*r<<endl;
    }
};
//////////////////////////

// ---------------- MAIN ----------------- //
int main(int argc, char** argv){
	
	cout<<"Witaj w programie matematycznym obliczajacym pole wybranych figur!"<<endl;
	cout<<"Wybierz jedna z ponizszych opcji."<<endl;

	while(user_choice!='N'||user_choice!='n'){
		cout<<"1. Pole kwadratu."<<endl;
		cout<<"2. Pole prostokata."<<endl;
		cout<<"3. Pole trojkata."<<endl;
		cout<<"4. Pole rombu."<<endl;
		cout<<"5. Pole trapezu."<<endl;
		cout<<"6. Pole kola."<<endl;
		cout<<"\nWpisz (N/n) aby zakonczyc program."<<endl;
		cout<<"Twoj wybor: "; cin>>user_choice;
		// ...
		Shape *wsk;
		switch(user_choice){
			case 'N': case 'n': exit(0); break;
			case '1':{
				float a;
				cout<<"Podaj dlugosc boku: "; cin>>a;
				Kwadrat kw(a); wsk = &kw;
				break;}
			case '2':{
				float a,b;
				cout<<"Podaj dlugosci bokow oddzielone spacja: "; cin>>a>>b;
				Prostokat pr(a,b); wsk = &pr;
				break;}
			case '3':{
				float a,h;
				cout<<"Podaj dlugosc boku i wysokosc trojkata oddzielone spacja: "; cin>>a>>h;
				Trojkat troj(a,h); wsk = &troj;
				break;}
			case '4':{
				float a,h;
				cout<<"Podaj dlugosc boku i wysokosc rombu oddzielone spacja: "; cin>>a>>h;
				Romb rom(a,h); wsk = &rom;
				break;}
			case '5':{
				float a,b,h;
				cout<<"Podaj dlugosci podstaw i wysokosc trapezu oddzielone spacja: "; cin>>a>>b>>h;
				Trapez trp(a,b,h); wsk = &trp; 
				break;}
			case '6':{
				float r;
				cout<<"Podaj promien kola: "; cin>>r;
				Kolo kol(r); wsk = &kol;
				break;}
			default: cout<<"Sorry! Something went wrong!"<<endl<<endl;if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //where must use <limits> lib
				}
				system("cls");
				user_choice='\0';
				continue;
				break;
		}
		wsk -> obliczPole();
		cout<<endl;
	}
	cout<<"Dziekujemy za uzycie naszego programu."<<endl;

	return 0;
}
