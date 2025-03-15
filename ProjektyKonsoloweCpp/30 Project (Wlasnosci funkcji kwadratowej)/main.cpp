#include <iostream>
#include <math.h>
using namespace std;
float coefficient_A, coefficient_B, coefficient_C;
float delta, x0, x1, x2;
float p,q;
float ValueOfFunction(float x, float a, float b, float c){
	return a*pow(x,2) + b*x + c;
}
int main(int argc, char** argv){
	cout<<"f(x)= ax^2 + bx + c"<<endl;
/// POBRANIE WSPOLCZYNNIKOW
	do{
		cout<<"Podaj wspolczynnik a: "; cin>>coefficient_A;
	}while(coefficient_A==0);
	cout<<"Podaj wspolczynnik b: "; cin>>coefficient_B;
	cout<<"Podaj wspolczynnik c: "; cin>>coefficient_C;
	cout<<"\n\n";
/// DELTA I MSC ZEROWE
	delta=pow(coefficient_B,2)-4*coefficient_A*coefficient_C;
	if(delta<0){
		cout<<"Ta funkcja kwadratowa nie ma miejsc zerowych."<<endl;
	}else if(delta==0){
		x0=(-coefficient_B)/(2*coefficient_A);
		cout<<"Delta wynosi "<<delta<<" zatem miejscem zerowym jest: x0: "<<x0<<endl;
	}else if(delta>0){
		x1=(-coefficient_B-sqrt(delta))/(2*coefficient_A);
		x2=(-coefficient_B+sqrt(delta))/(2*coefficient_A);
		cout<<"Delta wynosi "<<delta<<" zatem miejscami zerowymi sa: x1: "<<x1<<" , x2: "<<x2<<endl;
	}
/// I WARTOSCI WIEKSZE MNIEJSZE OD ZERA
	if(delta>0&&coefficient_A>0){
		cout<<"\nFunkcja ta przyjmuje wartosci wieksze od zera w przedzialach (-inf, "<<x1<<")u("<<x2<<", inf)."<<endl;
		cout<<"Funkcja ta przyjmuje wartosci mniejsze od zera w przedziale ("<<x1<<", "<<x2<<")."<<endl;
	}
	else if(delta>0&&coefficient_A<0){
		cout<<"\nFunkcja ta przyjmuje wartosci wieksze od zera w przedzialach ("<<x1<<", "<<x2<<")."<<endl;
		cout<<"Funkcja ta przyjmuje wartosci mniejsze od zera w przedziale (-inf, "<<x1<<")u("<<x2<<", inf)."<<endl;
	}
	else if(delta==0&&coefficient_A>0){
		cout<<"\nFunkcja ta przyjmuje wartosci wieksze od zera w przedzialach (-inf, "<<x0<<")u("<<x0<<", inf)."<<endl;
		cout<<"Funkcja ta NIE przyjmuje wartosci mniejszych od zera."<<endl;
	}
	else if(delta==0&&coefficient_A<0){
		cout<<"\nFunkcja ta NIE przyjmuje wartosci wiekszych od zera."<<endl;
		cout<<"Funkcja ta przyjmuje wartosci mniejsze od zera w przedzialach (-inf, "<<x0<<")u("<<x0<<", inf)."<<endl;
	}else if(delta<0&&coefficient_A>0){
		cout<<"\nFunkcja ta przyjmuje wartosci wieksze od zera w przedziale (-inf, inf)."<<endl;
		cout<<"Funkcja ta NIE przyjmuje wartosci mniejszych od zera."<<endl;
	}else if(delta<0&&coefficient_A<0){
		cout<<"\nFunkcja ta NIE przyjmuje wartosci wiekszych od zera."<<endl;
		cout<<"Funkcja ta przyjmuje wartosci mniejsze od zera w przedziale (-inf, inf)."<<endl; 
	}
/// DZIEDZINA 
	cout<<"\nDziedzina tej funkcji jest zbior liczb rzeczywistych"<<endl;
/// WIERZCHOLEK
	p=(-coefficient_B)/(2*coefficient_A);
	q=(-delta)/(4*coefficient_A);
	cout<<"\nWierzcholek tej paraboli znajduje sie w punkcie: W("<<p<<","<<q<<")"<<endl;
/// POSTAC KANONICZNA I ILOCZYNOWA
	cout<<"\nPostac ogolna tej funkcji: f(x)= "<<coefficient_A<<"x^2 + "<<coefficient_B<<"x + "<<coefficient_C<<endl;
	cout<<"Postac kanoniczna tej funkcji: f(x)= "<<coefficient_A<<"(x - "<<p<<")^2 + "<<q<<endl;
	if(delta>0)cout<<"Postac iloczynowa tej funkcji: f(x)= "<<coefficient_A<<"(x - "<<x1<<")(x - "<<x2<<")"<<endl;
	if(delta==0)cout<<"Postac iloczynowa tej funkcji: f(x)= "<<coefficient_A<<"(x - "<<x0<<")^2"<<endl;
/// NAJWIEKSZA I NAJMNIEJSZA WARTOSC I PRZEDZIALY MONOTONICZNOSCI I ZBIOR WARTOSCI
	if(coefficient_A<0){
		cout<<"\nZbiorem wartosci tej funkcji jest zbior (- infinity, "<<q<<")"<<endl;
		cout<<"Najwieksza wartosc tej f-cji: "<<q<<endl;
		cout<<"Najmniejsza wartosc tej f-cji: inf"<<endl;
		cout<<"Funkcja ta rosnie w przedziale (- infinity, "<<p<<"), a maleje w przedziale ("<<p<<", infinity)"<<endl;
	}else if(coefficient_A>0){
		cout<<"\nZbiorem wartosci tej funkcji jest zbior ("<<q<<", infinity)"<<endl;
		cout<<"Najwieksza wartosc tej f-cji: inf"<<endl;
		cout<<"Najmniejsza wartosc tej f-cji: "<<q<<endl;
		cout<<"Funkcja ta maleje w przedziale (- infinity, "<<p<<"), a rosnie w przedziale ("<<p<<", infinity)"<<endl;
	}
/// OBLICZANIE WARTOSCI FUNKCJI
	char choice;
	cout<<"\nChcesz policzyc wartosc tej funkcji dla podanego argumentu? (Y/N) "; cin>>choice;
	if(choice=='Y' || choice=='y'){
		float arg;
		cout<<"Podaj argument dla ktorego chcesz obliczyc wartosc swojej funkcji: "; cin>>arg;
		cout<<"Wartosc tej funkcji dla "<<arg<<" wynosi: "<<ValueOfFunction(arg,coefficient_A,coefficient_B,coefficient_C)<<endl;
	}
	cout<<endl<<"Dziekujemy za uzycie naszego programu!"<<endl;
	//system("pause");
	getchar();getchar();
	return 0;
}