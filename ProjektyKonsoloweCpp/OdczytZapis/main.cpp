#include <iostream>
#include <fstream>

using namespace std;

int ReadArr(const char name[], float *tab, int rozmiar);
int WriteToFile(const char name[], float *tab, int rozmiar);
void DisplayArr(int rozmiar, float *arr);
void bubble_sort(int rozmiar, float *arr);

int main()
{
    const int arr_size = 10;
    float arr[arr_size];
    int quantity = ReadArr("tablica.txt", arr, arr_size);
    DisplayArr(quantity, arr);
    bubble_sort(quantity, arr);
    DisplayArr(quantity, arr);
    int write_good = WriteToFile("tablica-posortowane.txt", arr, quantity);
    if(write_good){
        cout<<"Wystapil problem z zapisem pliku..."<<endl<<endl;
    }

    return 0;
}

void DisplayArr(int rozmiar, float *arr){
    for(int i=0; i<rozmiar;i++){
        if((i%10)==0) cout<<endl;
        if(*(arr+i)>=0) cout<<" ";
        if(*(arr+i)<10) cout<<" ";
        if(*(arr+i)<100) cout<<" ";

        cout<<*(arr+i)<<" ";
    }
    cout<<endl<<endl;
}

int WriteToFile(const char name[], float *tab, int rozmiar){
    ofstream my_file;
    my_file.open(name);
    bool ok;
    ok = my_file.good();
    cout<<"Status otwarcia pliku do zapisu danych: "<<ok<<endl<<endl;
    if(!ok){
        return 1;
    }
    int i=0;
    while(i<rozmiar){
        my_file << tab[i++] << endl;
    }
    my_file.close();

    return 0;
}

int ReadArr(const char name[], float *tab, int rozmiar){
    ifstream my_file;
    my_file.open(name);

    bool ok;
    ok = my_file.good();
    cout<<"Status otwarcia pliku do zapisu danych: "<<ok<<endl<<endl;
    int i=0;
    while(my_file.good() && i<rozmiar){
        my_file >> tab[i++];
    }
    my_file.close();

    return i;
}

void bubble_sort(int rozmiar,float *arr){
    /* -------------BUBBLE SORT DO WHILE----------------*/
    bool zmiana=true;
    do{
        zmiana = false;
        for(int i=0; i<rozmiar-1;i++){
            if(*(arr+i) > *(arr+i+1)){
                swap(*(arr+i), *(arr+i+1));
                zmiana = true;
            }
        }
    }while(zmiana==true);
}
