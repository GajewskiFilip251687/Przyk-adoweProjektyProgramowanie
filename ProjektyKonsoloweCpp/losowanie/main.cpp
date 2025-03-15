#include <iostream>
#include <ctime>
#include <math.h>
#include <conio.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void zadanie1();
void zadanie2();
void duze_lotto();
void bubble_sort();

int main()
{
    int choice = 0;
    bool running = true;
    while(running){
        system("cls");
        cout<<"---MENU ZADAN---"<<endl;
        cout<<"Wybierz numer zadanie ktore chcesz wykonaæ: "<<endl;
        cout<<"0. Opuszczenie mojego zajebistego programu (nie polecam!)."<<endl;
        cout<<"1. Zadanie obliczajajace srednia z zadanego przedzialu pseudolosowych liczb."<<endl;
        cout<<"2. Zadanie wyswietlajace zadana ilosc poteg liczby 2."<<endl;
        cout<<"3. Zadanie DUZE LOTTO."<<endl;
        cout<<"4. Bubble sort losowej tablicy."<<endl;
        cout<<"Twoj wybor: ";cin>>choice;
        system("cls");
        switch(choice){
        case 0:
            cout<<"Program terminated..."<<endl;
            running = false;
            break;
        case 1:
            zadanie1();
            getch();
            break;
        case 2:
            zadanie2();
            getch();
            break;
        case 3:
            duze_lotto();
            getch();
            break;
        case 4:
            bubble_sort();
            getch();
            break;
        default:
            cout<<"Operacja nieznana, upewnij sie ze wybierasz poprawna liczbe!"<<endl;
            getch();
        }
    }

    return 0;
}

void zadanie1(){
    // zmiennne zalezne od wyboru uzytkownika
    int range_min, range_max;
    cout<<"Podaj zakresy min i max dla losowania liczb, oddziel je spacja: "; cin>>range_min>>range_max;
    if(range_min>range_max){
        int temp = range_min;
        range_min = range_max;
        range_max = temp;
    }

    int ilosc;
    cout<<"Podaj ile chcesz miec wylosowanych liczb (zalecane 1-1000): "; cin>>ilosc;
    int *avg = new int[ilosc];

    // niezalezne zmienne w programie
    srand(time(NULL));
    double randomNum;
    long double suma = 0;
    double srednia = 0;

    cout<<"Losowe liczby z przedzialu "<<range_min<<" a "<<range_max<<" :"<<endl;
    // petla for ktora zapisuje
    for(int i=0; i<ilosc;i++){
        randomNum = rand()%(range_max-range_min+1) + range_min;
        cout<<randomNum<<" , ";
        avg[i] = randomNum;
        suma += randomNum;
        usleep(1000);
    }
    // liczenie sredniej z calej tablicy pseudolosowych liczb
    srednia = suma/ilosc;
    cout<<endl<<"Srednia wartosc: "<<srednia<<endl;
    delete [] avg;
}

void zadanie2(){
    int ilosc;
    cout<<"Ile chcesz miec kolejnych poteg liczby 2? (max 16): "; cin>>ilosc;
    int my_num = 2;
    int *pot_asc = new int[ilosc];
    int *pot_des = new int[ilosc];

    cout<<"kolejne potegi liczby "<<my_num<<" rosnaco :"<<endl;

    for(int i=0; i<ilosc;i++){
        pot_asc[i] = pow(my_num, i);
        cout<<my_num<<"^"<<i<<" = "<<pot_asc[i]<<endl;
        usleep(1000);
    }
    cout<<"\nkolejne potegi liczby "<<my_num<<" malejaco :"<<endl;

    for(int i=ilosc-1; i>=0;i--){
        pot_des[i] = pow(my_num, i);
        cout<<my_num<<"^"<<i<<" = "<<pot_des[i]<<endl;
        usleep(1000);
    }
    cout<<"Tablica z potegami rosnaco: ";
    for(int i=0; i<ilosc;i++){
        cout<<pot_asc[i]<<" ,";
    }

    cout<<endl<<"Tablica z potegami malejaco: ";

    for(int i=ilosc-1; i>=0;i--){
        cout<<pot_des[i]<<" ,";
    }
    cout<<endl;
    delete [] pot_asc;
    delete [] pot_des;
}

void duze_lotto(){
    cout<<"---Duze lotto---"<<endl;
    int lotto[6];
    srand(time(NULL));
    int rng_min = 1;
    int rng_max = 6;

    int i = 1;
    int random = rand()%(rng_max-rng_min+1) + rng_min;
    lotto[0]=random;
    do{
        random = rand()%(rng_max-rng_min+1) + rng_min;
        for(int j=0; j<i; j++){
            if(lotto[j]!=random){
                lotto[i]=random;
                i++;
            }
        }


    }while(i<6);


    cout<<"Wylosowane liczby to:"<<endl;
    for(int i=0; i<6;i++){
        cout<<lotto[i]<<" ";
    }
}

void bubble_sort(){
    const int arr_count = 100;
    int arr[arr_count];
    srand(time(NULL));

    cout<<"Losowe nie posortowane dane: "<<endl;

    for(int i=0; i<arr_count;i++){
        arr[i] = rand()%1000;
        cout<<arr[i]<<" ";
    }
    /*-------------BUBBLE SORT FOR FOR----------------*/

    for(int j=0; j<arr_count;j++){
        for(int i=0; i<arr_count-1;i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1]=temp;
            }
        }
    }

    cout<<"\n\nLosowe posortowane bombelkowo dane z for for: "<<endl;

    for(int i=0; i<arr_count;i++){
        cout<<arr[i]<<" ";
    }

    /* -------------BUBBLE SORT DO WHILE----------------*/
    bool zmiana=true;
    do{
        zmiana = false;
        for(int i=0; i<arr_count-1;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i], arr[i+1]);
                zmiana = true;
            }
        }
    }while(zmiana==true);

    cout<<"\n\nLosowe posortowane bombelkowo dane z do while: "<<endl;

    for(int i=0; i<arr_count;i++){
        cout<<arr[i]<<" ";
    }

}
