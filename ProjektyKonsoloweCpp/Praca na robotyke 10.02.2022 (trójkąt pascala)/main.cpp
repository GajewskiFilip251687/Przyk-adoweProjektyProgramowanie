#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int width;
bufferinfo()
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbiInfo );
	width = csbiInfo.dwSize.X;
}
///////////////////
int main(int argc, char** argv){
	cout<<"UWAGA UWAGA!!\nDrogi uzytkowniku, wazny komunikat!\nNie mozesz nic klikac podczas wyswietlania trojkata poniewaz nastapi niewiadomy blad."<<endl;
	system("pause");
	int n;
	/*cin>>n;*/
	/*ZALECANY NAJWIEKSZY ROZMIAR ZMINNEJ N TO 20, PO TYM MOGA WYSTAPIC NIEPORZADANE PROBLEMY !!!!!!!!!!!*/
for(n=1; n<=20; n++){
	// ta pentla for dlatego, aby automatycznie wyswietlal sie trojkat
	bufferinfo();
	Sleep(500);
	system("cls");
	int **pascal_triangle = new int* [n];
	for(int i=0; i<n; i++){
		pascal_triangle[i] = new int [n];
	}
	///
	//cout<<"\n---------\n"<<endl;
	for(int i=0; i<n; i++){
		pascal_triangle[i][0] = pascal_triangle[i][i] = 1;
		for(int j=0; j<i-1; j++){
			pascal_triangle[i][j+1] = pascal_triangle[i-1][j] + pascal_triangle[i-1][j+1];
		}
	}
	///
	cout<<'\n';
	int num=width/2;
	for(int i=0; i<n; i++){
		cout.width(n-i);
		cout<<setw(num);
		for(int j=0; j<i+1; j++){
			cout<<pascal_triangle[i][j];//'\t'<<
			int white_space;
			if((0<pascal_triangle[i][j])&&(pascal_triangle[i][j]<10)){white_space=5;}
			if((9<pascal_triangle[i][j])&&(pascal_triangle[i][j]<100)){white_space=4;}
			if((99<pascal_triangle[i][j])&&(pascal_triangle[i][j]<1000)){white_space=3;}
			if((999<pascal_triangle[i][j])&&(pascal_triangle[i][j]<10000)){white_space=2;}
			if((9999<pascal_triangle[i][j])&&(pascal_triangle[i][j]<100000)){white_space=1;}
			for(int k=0; k<white_space; k++){
				cout<<" ";
			}
			
		}
		num-=3; //wartosc najbardziej zblizona do optimum, lepiej juz nie kombinowac
		cout<<'\n';
	}
	delete [] pascal_triangle;
}
	cout<<"\n\n";
	system("pause");
	return 0;
}
//////////////////////////
/*
	 1
    1 1
	\ /
   1 2 1
   \/ \/
  1 3 3 1

	                                 1
    	                          1     1
        	                   1     2     1
            	            1     3     3     1
                	     1     4     6     4     1
		               1     5    10    10    5     1
	               1     6     15    20    15    6     1
        	    1     7     21    35    35    21    7     1
        	 1     8     28    56    70    56    28    8     1
    	  1     9     36    84    126   126   84    36    9     1
	   1     10    45    120   210   252   210   120   45    10    1
	1     11    55    165   330   462   462   330   165   55    11    1
 1     12    66    220   495   792   922   792   495   220   66    12    1


// TO JEST JAKAS SOLUCJA Z INTERNETU SKOPIOWANA
for(int n=1; n<=14; n++){
	Sleep(500);
	system("cls");
	for(int i=0;i<n;i++){
		int val = 1;
		//cout.width(n-i);
		for(int j=0; j<=i; j++){
			cout<< val << " ";
			val = val * (i-j)/(j+1);
		}
		cout<<'\n';
	}
	cout<<endl<<endl;
}
*/
