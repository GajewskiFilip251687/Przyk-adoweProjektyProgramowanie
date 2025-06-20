#include <iostream>

using namespace std;

int main()
{
    int w,k;
    cout << "Podaj ile chcesz wierszy: "; cin>>w;
    cout << "Podaj ile chcesz kolumn: "; cin>>k;
         /*ZADEKLAROWANIE WSKAŹNIKA NA WSKAŹNIK*/
    float **pArr = new float* [w];
         /*UTWORZENIE KOLUMN W STRUKTURZE*/
    for(int i=0; i<w; i++){
        pArr[i] = new float [k];
    }
         /*PRZYPISANIE WARTOŚCI*/
    for(int i=0; i<w; i++){
        for(int j=0; j<k; ++j){
            pArr[i][j]=(float)(i+j/10.0);
        }
    }
         /*WYPISANIE ZAWARTOŚCI TABLICY NA EKRAN*/
    for(int i=0; i<w; i++){
        for(int j=0; j<k; ++j){
            cout<<pArr[i][j]<<"\t";
        }
        cout<<endl;
    }
         /*ZAMIANA MIEJSCAMI OKREŚLONYCH WIERSZY I KOLUMN*/
    int n,m;
    cout <<endl<< " Ktore wiersze mam zamienic? (podaj wiersz kolumna po spacji): "; cin>>n>>m;
    float* temp = pArr[n];
    pArr[n] = pArr[m];
    pArr[m] = temp;

        /*WYPISANIE ZAWARTOŚCI TABLICY NA EKRAN*/
    for(int i=0; i<w; i++){
        for(int j=0; j<k; ++j){
            cout<<pArr[i][j]<<"\t";
        }
        cout<<endl;
    }

         /*USUNIĘCIE WSZYSTKIEGO CO DYNAMICZNIE ZADEKLAROWANE*/
    for(int i=0; i<w; i++){
        delete[] pArr[i];
    }
    delete[] pArr;
    pArr = NULL;
    return 0;
}
