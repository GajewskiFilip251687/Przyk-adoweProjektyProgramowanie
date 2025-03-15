#include <iostream>
#include <windows.h> // needed to change the font color
#include <limits> // needed in the cin.ignore() function, it for setting the maximum number of characters to ignore
using namespace std;

void table();
void game();
bool endOfGame();
void colorfullText(char ch, int f_num, int l_num);

char tab[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player_sign;
int num_player;
int digit, field;
bool tie, end_game, horizontally, vertically, diagonally_rightToLeft, diagonally_leftToRight;
int color_of_first_player = 9;
int color_of_second_player = 5;
///////////-- MAIN --/////////////////
int main(int argc, char** argv){

	game();

	return 0;
}
/////////////////////////////
void table(){
	
	system("cls");
	if(num_player==1){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_of_first_player);
		cout<<"\t\tPlayer "<<num_player<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}else if(num_player==2){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_of_second_player);
		cout<<"\t\tPlayer "<<num_player<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	
	////////
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	cout<<endl<<endl;

	if(end_game!=true){	
		cout<<"\t\t   |   |   "<<endl;
		cout<<"\t\t ";
		if(tab[0][0]=='X'){colorfullText(tab[0][0], color_of_first_player, 14);}
		else if(tab[0][0]=='O'){colorfullText(tab[0][0], color_of_second_player, 14);}
		else {colorfullText(tab[0][0], 14, 14);}
		cout<<" | ";
		if(tab[0][1]=='X'){colorfullText(tab[0][1], color_of_first_player, 14);}
		else if(tab[0][1]=='O'){colorfullText(tab[0][1], color_of_second_player, 14);}
		else {colorfullText(tab[0][1], 14, 14);}
		cout<<" | ";
		if(tab[0][2]=='X'){colorfullText(tab[0][2], color_of_first_player, 14);}
		else if(tab[0][2]=='O'){colorfullText(tab[0][2], color_of_second_player, 14);}
		else {colorfullText(tab[0][2], 14, 14);}
		cout<<" "<<endl;
		cout<<"\t\t___|___|___"<<endl;
		cout<<"\t\t   |   |   "<<endl;
		cout<<"\t\t ";
		if(tab[1][0]=='X'){colorfullText(tab[1][0], color_of_first_player, 14);}
		else if(tab[1][0]=='O'){colorfullText(tab[1][0], color_of_second_player, 14);}
		else {colorfullText(tab[1][0], 14, 14);}
		cout<<" | ";
		if(tab[1][1]=='X'){colorfullText(tab[1][1], color_of_first_player, 14);}
		else if(tab[1][1]=='O'){colorfullText(tab[1][1], color_of_second_player, 14);}
		else {colorfullText(tab[1][1], 14, 14);}
		cout<<" | ";
		if(tab[1][2]=='X'){colorfullText(tab[1][2], color_of_first_player, 14);}
		else if(tab[1][2]=='O'){colorfullText(tab[1][2], color_of_second_player, 14);}
		else {colorfullText(tab[1][2], 14, 14);}
		cout<<" "<<endl;
		cout<<"\t\t___|___|___"<<endl;
		cout<<"\t\t   |   |   "<<endl;
		cout<<"\t\t ";
		if(tab[2][0]=='X'){colorfullText(tab[2][0], color_of_first_player, 14);}
		else if(tab[2][0]=='O'){colorfullText(tab[2][0], color_of_second_player, 14);}
		else {colorfullText(tab[2][0], 14, 14);}
		cout<<" | ";
		if(tab[2][1]=='X'){colorfullText(tab[2][1], color_of_first_player, 14);}
		else if(tab[2][1]=='O'){colorfullText(tab[2][1], color_of_second_player, 14);}
		else {colorfullText(tab[2][1], 14, 14);}
		cout<<" | ";
		if(tab[2][2]=='X'){colorfullText(tab[2][2], color_of_first_player, 14);}
		else if(tab[2][2]=='O'){colorfullText(tab[2][2], color_of_second_player, 14);}
		else {colorfullText(tab[2][2], 14, 14);}
		cout<<" "<<endl;
		cout<<"\t\t   |   |   "<<endl;
	}
	// --------------------------
	else if(end_game==true){
		cout<<"\t\t   |   |   "<<endl;
		cout<<"\t\t ";
		if(vertically==true){
			int n=0;
			if(field==n){
				if((tab[0][0]=='X')||(tab[0][0]=='O')){colorfullText(tab[0][0], 15+32, 14);}
				else {colorfullText(tab[0][0], 14, 14);}
			}else{
				if(tab[0][0]=='X'){colorfullText(tab[0][0], color_of_first_player, 14);}
				else if(tab[0][0]=='O'){colorfullText(tab[0][0], color_of_second_player, 14);}
				else {colorfullText(tab[0][0], 14, 14);}
			}
		}else if(horizontally==true){
			int n=0;
			if(field==n){
				if((tab[0][0]=='X')||(tab[0][0]=='O')){colorfullText(tab[0][0], 15+32, 14);}
				else {colorfullText(tab[0][0], 14, 14);}
			}else{
				if(tab[0][0]=='X'){colorfullText(tab[0][0], color_of_first_player, 14);}
				else if(tab[0][0]=='O'){colorfullText(tab[0][0], color_of_second_player, 14);}
				else {colorfullText(tab[0][0], 14, 14);}
			}
		}else if(diagonally_leftToRight==true){
			if((tab[0][0]=='X')||(tab[0][0]=='O')){colorfullText(tab[0][0], 15+32, 14);}
			else {colorfullText(tab[0][0], 14, 14);}
		}else{
			if(tab[0][0]=='X'){colorfullText(tab[0][0], color_of_first_player, 14);}
			else if(tab[0][0]=='O'){colorfullText(tab[0][0], color_of_second_player, 14);}
			else {colorfullText(tab[0][0], 14, 14);}
		}
		// ...
		cout<<" | ";
		// ...
		if(vertically==true){
			int n=1;
			if(field==n){
				if((tab[0][1]=='X')||(tab[0][1]=='O')){colorfullText(tab[0][1], 15+32, 14);}
				else {colorfullText(tab[0][1], 14, 14);}
			}else{
				if(tab[0][1]=='X'){colorfullText(tab[0][1], color_of_first_player, 14);}
				else if(tab[0][1]=='O'){colorfullText(tab[0][1], color_of_second_player, 14);}
				else {colorfullText(tab[0][1], 14, 14);}
			}
		}else if(horizontally==true){
			int n=0;
			if(field==n){
				if((tab[0][1]=='X')||(tab[0][1]=='O')){colorfullText(tab[0][1], 15+32, 14);}
				else {colorfullText(tab[0][1], 14, 14);}
			}else{
				if(tab[0][1]=='X'){colorfullText(tab[0][1], color_of_first_player, 14);}
				else if(tab[0][1]=='O'){colorfullText(tab[0][1], color_of_second_player, 14);}
				else {colorfullText(tab[0][1], 14, 14);}
			}
		}else{
			if(tab[0][1]=='X'){colorfullText(tab[0][1], color_of_first_player, 14);}
			else if(tab[0][1]=='O'){colorfullText(tab[0][1], color_of_second_player, 14);}
			else {colorfullText(tab[0][1], 14, 14);}
		}
		// ...
		cout<<" | ";
		// ...
		if(vertically==true){
			int n=2;
			if(field==n){
				if((tab[0][2]=='X')||(tab[0][2]=='O')){colorfullText(tab[0][2], 15+32, 14);}
				else {colorfullText(tab[0][2], 14, 14);}
			}else{
				if(tab[0][2]=='X'){colorfullText(tab[0][2], color_of_first_player, 14);}
				else if(tab[0][2]=='O'){colorfullText(tab[0][2], color_of_second_player, 14);}
				else {colorfullText(tab[0][2], 14, 14);}
			}
		}else if(horizontally==true){
			int n=0;
			if(field==n){
				if((tab[0][2]=='X')||(tab[0][2]=='O')){colorfullText(tab[0][2], 15+32, 14);}
				else {colorfullText(tab[0][2], 14, 14);}
			}else{
				if(tab[0][2]=='X'){colorfullText(tab[0][2], color_of_first_player, 14);}
				else if(tab[0][2]=='O'){colorfullText(tab[0][2], color_of_second_player, 14);}
				else {colorfullText(tab[0][2], 14, 14);}
			}
		}else if(diagonally_rightToLeft==true){
			if((tab[0][2]=='X')||(tab[0][2]=='O')){colorfullText(tab[0][2], 15+32, 14);}
			else {colorfullText(tab[0][2], 14, 14);}
		}else{
			if(tab[0][2]=='X'){colorfullText(tab[0][2], color_of_first_player, 14);}
			else if(tab[0][2]=='O'){colorfullText(tab[0][2], color_of_second_player, 14);}
			else {colorfullText(tab[0][2], 14, 14);}
		}
		// ...
		cout<<" "; colorfullText('.',0,14); cout<<endl; // a to po to, poniewaz przy zmienianiu widoku konsoli z okienka na pelen ekran i naodwrot, za znakami po prawej stronie tabeli zostawala "smuga", dlatego trzeba bylo dac jakis niepostrzerzony znak aby wyglaalo to schludnie graficznie
		cout<<"\t\t___|___|___"<<endl;
		cout<<"\t\t   |   |   "<<endl;
		cout<<"\t\t ";
		// ...
		if(vertically==true){
			int n=0;
			if(field==n){
				if((tab[1][0]=='X')||(tab[1][0]=='O')){colorfullText(tab[1][0], 15+32, 14);}
				else {colorfullText(tab[1][0], 14, 14);}
			}else{
				if(tab[1][0]=='X'){colorfullText(tab[1][0], color_of_first_player, 14);}
				else if(tab[1][0]=='O'){colorfullText(tab[1][0], color_of_second_player, 14);}
				else {colorfullText(tab[1][0], 14, 14);}
			}
		}else if(horizontally==true){
			int n=1;
			if(field==n){
				if((tab[1][0]=='X')||(tab[1][0]=='O')){colorfullText(tab[1][0], 15+32, 14);}
				else {colorfullText(tab[1][0], 14, 14);}
			}else{
				if(tab[1][0]=='X'){colorfullText(tab[1][0], color_of_first_player, 14);}
				else if(tab[1][0]=='O'){colorfullText(tab[1][0], color_of_second_player, 14);}
				else {colorfullText(tab[1][0], 14, 14);}
			}
		}else{
			if(tab[1][0]=='X'){colorfullText(tab[1][0], color_of_first_player, 14);}
			else if(tab[1][0]=='O'){colorfullText(tab[1][0], color_of_second_player, 14);}
			else {colorfullText(tab[1][0], 14, 14);}
		}
		// ...
		cout<<" | ";
		// ...
		if(vertically==true){
			int n=1;
			if(field==n){
				if((tab[1][1]=='X')||(tab[1][1]=='O')){colorfullText(tab[1][1], 15+32, 14);}
				else {colorfullText(tab[1][1], 14, 14);}
			}else{
				if(tab[1][1]=='X'){colorfullText(tab[1][1], color_of_first_player, 14);}
				else if(tab[1][1]=='O'){colorfullText(tab[1][1], color_of_second_player, 14);}
				else {colorfullText(tab[1][1], 14, 14);}
			}
		}else if(horizontally==true){
			int n=1;
			if(field==n){
				if((tab[1][1]=='X')||(tab[1][1]=='O')){colorfullText(tab[1][1], 15+32, 14);}
				else {colorfullText(tab[1][1], 14, 14);}
			}else{
				if(tab[1][1]=='X'){colorfullText(tab[1][1], color_of_first_player, 14);}
				else if(tab[1][1]=='O'){colorfullText(tab[1][1], color_of_second_player, 14);}
				else {colorfullText(tab[1][1], 14, 14);}
			}
		}else if((diagonally_leftToRight==true) || (diagonally_rightToLeft==true)){
			if((tab[1][1]=='X')||(tab[1][1]=='O')){colorfullText(tab[1][1], 15+32, 14);}
			else {colorfullText(tab[1][1], 14, 14);}
		}else{
			if(tab[1][1]=='X'){colorfullText(tab[1][1], color_of_first_player, 14);}
			else if(tab[1][1]=='O'){colorfullText(tab[1][1], color_of_second_player, 14);}
			else {colorfullText(tab[1][1], 14, 14);}
		}
		// ...
		cout<<" | ";
		// ...
		if(vertically==true){
			int n=2;
			if(field==n){
				if((tab[1][2]=='X')||(tab[1][2]=='O')){colorfullText(tab[1][2], 15+32, 14);}
				else {colorfullText(tab[1][2], 14, 14);}
			}else{
				if(tab[1][2]=='X'){colorfullText(tab[1][2], color_of_first_player, 14);}
				else if(tab[1][2]=='O'){colorfullText(tab[1][2], color_of_second_player, 14);}
				else {colorfullText(tab[1][2], 14, 14);}
			}
		}else if(horizontally==true){
			int n=1;
			if(field==n){
				if((tab[1][2]=='X')||(tab[1][2]=='O')){colorfullText(tab[1][2], 15+32, 14);}
				else {colorfullText(tab[1][2], 14, 14);}
			}else{
				if(tab[1][2]=='X'){colorfullText(tab[1][2], color_of_first_player, 14);}
				else if(tab[1][2]=='O'){colorfullText(tab[1][2], color_of_second_player, 14);}
				else {colorfullText(tab[1][2], 14, 14);}
			}
		}else{
			if(tab[1][2]=='X'){colorfullText(tab[1][2], color_of_first_player, 14);}
			else if(tab[1][2]=='O'){colorfullText(tab[1][2], color_of_second_player, 14);}
			else {colorfullText(tab[1][2], 14, 14);}
		}
		// ...
		cout<<" "; colorfullText('.',0,14); cout<<endl; // a to po to, poniewaz przy zmienianiu widoku konsoli z okienka na pelen ekran i naodwrot, za znakami po prawej stronie tabeli zostawala "smuga", dlatego trzeba bylo dac jakis niepostrzerzony znak aby wyglaalo to schludnie graficznie
		cout<<"\t\t___|___|___"<<endl;
		cout<<"\t\t   |   |   "<<endl;
		cout<<"\t\t ";
		// ...
		if(vertically==true){
			int n=0;
			if(field==n){
				if((tab[2][0]=='X')||(tab[2][0]=='O')){colorfullText(tab[2][0], 15+32, 14);}
				else {colorfullText(tab[2][0], 14, 14);}
			}else{
				if(tab[2][0]=='X'){colorfullText(tab[2][0], color_of_first_player, 14);}
				else if(tab[2][0]=='O'){colorfullText(tab[2][0], color_of_second_player, 14);}
				else {colorfullText(tab[2][0], 14, 14);}
			}
		}else if(horizontally==true){
			int n=2;
			if(field==n){
				if((tab[2][0]=='X')||(tab[2][0]=='O')){colorfullText(tab[2][0], 15+32, 14);}
				else {colorfullText(tab[2][0], 14, 14);}
			}else{
				if(tab[2][0]=='X'){colorfullText(tab[2][0], color_of_first_player, 14);}
				else if(tab[2][0]=='O'){colorfullText(tab[2][0], color_of_second_player, 14);}
				else {colorfullText(tab[2][0], 14, 14);}
			}
		}else if(diagonally_rightToLeft==true){
			if((tab[2][0]=='X')||(tab[2][0]=='O')){colorfullText(tab[2][0], 15+32, 14);}
			else {colorfullText(tab[2][0], 14, 14);}
		}
		else{
			if(tab[2][0]=='X'){colorfullText(tab[2][0], color_of_first_player, 14);}
			else if(tab[2][0]=='O'){colorfullText(tab[2][0], color_of_second_player, 14);}
			else {colorfullText(tab[2][0], 14, 14);}
		}
		// ...
		cout<<" | ";
		// ...
		if(vertically==true){
			int n=1;
			if(field==n){
				if((tab[2][1]=='X')||(tab[2][1]=='O')){colorfullText(tab[2][1], 15+32, 14);}
				else {colorfullText(tab[2][1], 14, 14);}
			}else{
				if(tab[2][1]=='X'){colorfullText(tab[2][1], color_of_first_player, 14);}
				else if(tab[2][1]=='O'){colorfullText(tab[2][1], color_of_second_player, 14);}
				else {colorfullText(tab[2][1], 14, 14);}
			}
		}else if(horizontally==true){
			int n=2;
			if(field==n){
				if((tab[2][1]=='X')||(tab[2][1]=='O')){colorfullText(tab[2][1], 15+32, 14);}
				else {colorfullText(tab[2][1], 14, 14);}
			}else{
				if(tab[2][1]=='X'){colorfullText(tab[2][1], color_of_first_player, 14);}
				else if(tab[2][1]=='O'){colorfullText(tab[2][1], color_of_second_player, 14);}
				else {colorfullText(tab[2][1], 14, 14);}
			}
		}else{
			if(tab[2][1]=='X'){colorfullText(tab[2][1], color_of_first_player, 14);}
			else if(tab[2][1]=='O'){colorfullText(tab[2][1], color_of_second_player, 14);}
			else {colorfullText(tab[2][1], 14, 14);}
		}
		// ...
		cout<<" | ";
		// ...
		if(vertically==true){
			int n=2;
			if(field==n){
				if((tab[2][2]=='X')||(tab[2][2]=='O')){colorfullText(tab[2][2], 15+32, 14);}
				else {colorfullText(tab[2][2], 14, 14);}
			}else{
				if(tab[2][2]=='X'){colorfullText(tab[2][2], color_of_first_player, 14);}
				else if(tab[2][2]=='O'){colorfullText(tab[2][2], color_of_second_player, 14);}
				else {colorfullText(tab[2][2], 14, 14);}
			}
		}else if(horizontally==true){
			int n=2;
			if(field==n){
				if((tab[2][2]=='X')||(tab[2][2]=='O')){colorfullText(tab[2][2], 15+32, 14);}
				else {colorfullText(tab[2][2], 14, 14);}
			}else{
				if(tab[2][2]=='X'){colorfullText(tab[2][2], color_of_first_player, 14);}
				else if(tab[2][2]=='O'){colorfullText(tab[2][2], color_of_second_player, 14);}
				else {colorfullText(tab[2][2], 14, 14);}
			}
		}else if(diagonally_leftToRight==true){
			if((tab[2][2]=='X')||(tab[2][2]=='O')){colorfullText(tab[2][2], 15+32, 14);}
			else {colorfullText(tab[2][2], 14, 14);}
		}
		else{
			if(tab[2][2]=='X'){colorfullText(tab[2][2], color_of_first_player, 14);}
			else if(tab[2][2]=='O'){colorfullText(tab[2][2], color_of_second_player, 14);}
			else {colorfullText(tab[2][2], 14, 14);}
		}
		// ...
		cout<<" "; colorfullText('.',0,14); cout<<endl; // a to po to, poniewaz przy zmienianiu widoku konsoli z okienka na pelen ekran i naodwrot, za znakami po prawej stronie tabeli zostawala "smuga", dlatego trzeba bylo dac jakis niepostrzerzony znak aby wyglaalo to schludnie graficznie
		cout<<"\t\t   |   |   "<<endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
///////////////////////////
void game(){
	num_player=0;
	end_game = false; tie = false;
	vertically = false; horizontally = false; diagonally_leftToRight = false; diagonally_rightToLeft = false;
	bool empty[9]={true, true, true, true, true, true, true, true, true};
	while(!endOfGame()){
	////////
		if(num_player==1){
			num_player=2;
		}else if(num_player==2){
			num_player=1;
		}else{
			num_player=1;
		}
	//////
		if(num_player==1){player_sign='X';}
		else if(num_player==2){player_sign='O';}
	//////
		table();
	//////
		cout<<endl;
		if(num_player==1){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_of_first_player);
			cout<<"Player "<<num_player;
		}else if(num_player==2){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_of_second_player);
			cout<<"Player "<<num_player;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<" please enter the number of the box: "; cin>>digit;
		while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Enter the correct number: "; cin>>digit;
			}
			if(!cin.fail()){break;}
		}
	///////
		while((digit<1)||(digit>9)){
			cout<<"Enter the number between 1 and 9! New number: "; cin>>digit;
		}
	///////
		while(empty[digit-1]==false){
			cout<<"This box is already taken! Enter another number: "; cin>>digit;
			while(1){
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout<<"Enter the correct number: "; cin>>digit;
				}
				if(!cin.fail()){break;}
			}
		}
	///////
		switch(digit){
			case 1: tab[0][0]=player_sign; empty[0]=false; break;
			case 2: tab[0][1]=player_sign; empty[1]=false; break;
			case 3: tab[0][2]=player_sign; empty[2]=false; break;
			case 4: tab[1][0]=player_sign; empty[3]=false; break;
			case 5: tab[1][1]=player_sign; empty[4]=false; break;
			case 6: tab[1][2]=player_sign; empty[5]=false; break;
			case 7: tab[2][0]=player_sign; empty[6]=false; break;
			case 8: tab[2][1]=player_sign; empty[7]=false; break;
			case 9: tab[2][2]=player_sign; empty[8]=false; break;
			default: cout<<"Enter the number between 1 and 9 !"<<endl;
		}
	///////
	}
	///////////////////
	// if any player wins or there is a tie
	table();

	tab[0][0]='1';
	tab[0][1]='2';
	tab[0][2]='3';
	tab[1][0]='4';
	tab[1][1]='5';
	tab[1][2]='6';
	tab[2][0]='7';
	tab[2][1]='8';
	tab[2][2]='9';
	///////
	cout<<endl;
	if(tie!=true){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		cout<<"\tWinner is a player "<< num_player <<"!"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	else if(tie==true){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<"There is a tie. No player has won."<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	///////
	cout<<"\nDo you want play again?"<<endl;
	char user_choice='\0';
	/////////
	while((user_choice!='Y')||(user_choice!='y')||(user_choice!='N')||(user_choice!='n')){
		cout<<"Your choice (Y/N): "; cin>>user_choice;
		if(user_choice=='Y'||user_choice=='y'){
			game();
			break;
		}
		else if(user_choice=='N'||user_choice=='n'){
			cout<<"\nOkay, bye."<<endl;
			system("pause");
			break;
			return;
		}else{
			cout<<"Undefined answer! Please enter correct option!"<<endl;
		}
	}
}
//////////////////////////
bool endOfGame(){
	for(int i=0; i<3; i++){
		if((tab[0][i]==tab[1][i]) && (tab[0][i]==tab[2][i])){
			vertically = true;
			field = i;
			end_game = true;
			return true;
		}
		if((tab[i][0]==tab[i][1]) && (tab[i][0]==tab[i][2])){
			horizontally = true;
			field = i;
			end_game = true;
			return true;
		}
	}
	if((tab[0][0]==tab[1][1]) && (tab[0][0]==tab[2][2])){
		diagonally_leftToRight = true;
		end_game = true;
		return true;
	}
	if((tab[0][2]==tab[1][1]) && (tab[0][2]==tab[2][0])){
		diagonally_rightToLeft = true;
		end_game = true;
		return true;
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if((tab[i][j]!='X') && (tab[i][j]!='O')){
				return false;
			}
		}
	}
	tie=true; // there is a tie
	return true;
}
///////////////////
void colorfullText(char ch, int f_num, int l_num){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),f_num);
	cout<<ch;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),l_num);
}
///////////

/*
jeszcze mam pomysla zeby nie dzialac na tablicach tylko na zasadzie wypisywania odpowiedniego symbolu w miejscu dzieki f-cji ponizej, ale obecne dzialanie aplikacji uwazam za lepsze, ale moze kiedys sprobuje

void position(int x, int y){
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
position(0,0);
cout<<"X/O"; //czyli np. w lewej gornej kratce wypisalby sie odpowiedni symbol
*/