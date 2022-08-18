#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>


#define cell (char)254

using namespace std;


bool vida(char arr[][10], int row, int col);
void showarr(char arr[][10], int n, int m);



int main(){
	
	char val;
	
	char map[10][10] = 
	{
		{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
		{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
		{'*', '*', '*', cell, '*', '*', cell, '*', '*', '*'},
		{'*', '*', cell, '*', cell, cell, '*', cell, '*', '*'},
		{'*', '*', '*', cell, '*', '*', cell, '*', '*', '*'},
		{'*', '*', '*', cell, '*', '*', cell, '*', '*', '*'},
		{'*', '*', cell, '*', cell, cell, '*', cell, '*', '*'},
		{'*', '*', '*', cell, '*', '*', cell, '*', '*', '*'},
		{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
		{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
	};
	
	char mapcop[10][10];
	
	showarr(map, 10, 10);

	this_thread::sleep_for(chrono::seconds(1));	
	
	system("cls");
	
	while(true){
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){				
				if(vida(map, i, j)){
					if(map[i][j] == '*'){
						mapcop[i][j] = cell;
					}
					else{
						mapcop[i][j] = '*';
					}
				}
				else{
					mapcop[i][j] = map[i][j];
				}
			}
		}
		
		showarr(mapcop, 10, 10);
		
		this_thread::sleep_for(chrono::seconds(1));
						
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){
				map[i][j]=mapcop[i][j];
			}
		}
		
		system("cls");
		
	}
	return 0;
}




bool vida(char arr[][10], int row, int col){
	
	int cont1 = 0;
	int cont2 = 0;
	
	if(arr[row][col] == '*'){
		if(row != 0 && col != 0){
			for(int i = -1; i < 2; i++){
				for(int j = -1; j < 2; j++){
					if(arr[row+i][col+j] == cell){
						cont1++;
					}
				}
			}
			
			if(cont1 == 3){
				return true;
			}
		}
	}
	
	else{
		if(row != 0 && col != 0){
			for(int i = -1; i < 2; i++){
				for(int j = -1; j < 2; j++){
					if(arr[row+i][col+j] == cell){
						cont2++;
					}
				}
			}
			
			if(cont2-1 != 2 && cont2-1 != 3){
				return true;
			}
		}
	}
	
	return false;	
}


void showarr(char arr[][10], int n, int m){
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
}







