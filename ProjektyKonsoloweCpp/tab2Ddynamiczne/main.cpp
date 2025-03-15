#include <iostream>

using namespace std;

int main()
{
    int w,k;
    cout << "Podaj ile chcesz wierszy: "; cin>>w;
    cout << "Podaj ile chcesz kolumn: "; cin>>k;
         /*ZADEKLAROWANIE WSKAèNIKA NA WSKAèNIK*/
    float **pArr = new float* [w];
         /*UTWORZENIE KOLUMN W STRUKTURZE*/
    for(int i=0; i<w; i++){
        pArr[i] = new float [k];
    }
         /*PRZYPISANIE WARTOåCI*/
    for(int i=0; i<w; i++){
        for(int j=0; j<k; ++j){
            pArr[i][j]=(float)(i+j/10.0);
        }
    }
         /*WYPISANIE ZAWARTOåCI TABLICY NA EKRAN*/
    for(int i=0; i<w; i++){
        for(int j=0; j<k; ++j){
            cout<<pArr[i][j]<<"\t";
        }
        cout<<endl;
    }
         /*ZAMIANA MIEJSCAMI OKREåLONYCH WIERSZY I KOLUMN*/
    int n,m;
    cout <<endl<< " Ktore wiersze mam zamienic? (podaj wiersz kolumna po spacji): "; cin>>n>>m;
    float* temp = pArr[n];
    pArr[n] = pArr[m];
    pArr[m] = temp;

        /*WYPISANIE ZAWARTOåCI TABLICY NA EKRAN*/
    for(int i=0; i<w; i++){
        for(int j=0; j<k; ++j){
            cout<<pArr[i][j]<<"\t";
        }
        cout<<endl;
    }

         /*USUNI CIE WSZYSTKIEGO CO DYNAMICZNIE ZADEKLAROWANE*/
    for(int i=0; i<w; i++){
        delete[] pArr[i];
    }
    delete[] pArr;
    pArr = NULL;
    return 0;
}
