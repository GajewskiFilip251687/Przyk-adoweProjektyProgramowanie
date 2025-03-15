#include <iostream>

using namespace std;

int main()
{
    /* ----------- SEKCJA PIERWSZA -----------*/
    cout<<"---- SEKCJA PIERWSZA ----"<<endl<<endl;
    int arr2D[2][3] = {{1,2,3}, {4,5,6}};
    int (*ws)[3];
    ws = arr2D;
    cout << "Nasza dwojka o indeksach 0 i 1: " << arr2D[0][1] << endl;
    cout << "Nasza dwojka o indeksach 0 i 1 wskaznikiem: " << *(*(ws+0)+1) << endl;
    arr2D[0][1] = 8;
    cout << "Nasza osemka po podmianie na indexach 0 i 1: " << arr2D[0][1] << endl;
    cout<<endl;
    /* ----------- SEKCJA DRUGA -----------*/
    cout<<endl<<"---- SEKCJA DRUGA ----"<<endl<<endl;

    char chArr[4][10]={"jeden",{'d','w','a'},{"trzy"}};
    cout<<"Wpisz slowo..."; cin>>chArr[3];
    char (*wsChar)[10];
    wsChar = chArr;

    cout<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<10; j++){
            if(*(*(wsChar+i)+j) != ' ')
            cout<<*(*(wsChar+i)+j)<<" ";
        }
        cout<<endl<<endl;
    }

    for(int k=0; k<4; k++){
        cout<<chArr[k]<<endl;
    }
    /* ----------- SEKCJA TRZECIA -----------*/
    cout<<endl<<"---- SEKCJA TRZECIA ----"<<endl<<endl;
    const int ilosc_osob = 3;
    char data[ilosc_osob][2][15];

    for(int i=0; i<ilosc_osob; i++){
        cout<<"Podaj imie "<<i+1<<". osoby: ";
        cin>>data[i][0];

        cout<<"Podaj nazwisko "<<i+1<<". osoby: ";
        cin>>data[i][1];
        cout<<endl;
    }
    cout<<"Dane osob:"<<endl;
    for(int i=0; i<ilosc_osob; i++){
        cout<<i+1<<". osoba: "<<endl;
        cout<<" "<<data[i][1]<<" "<<data[i][0];
        cout<<endl;
    }

    return 0;
}
