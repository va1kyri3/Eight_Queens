/*  Homework #9
*   Author: Nicolas Restrepo
*   Title: Fancy output for the 8 queens problem
*   Date Modified: 10/23/17
*/

#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

//Function prototypes
bool test(int q[], int column);
void backtrack(int &column);
void print(int q[]);

int main(){
	//Set all initial conditions
	int q[8], c=1;
	q[0] = 0;
	
	//Set backtracking check to false to check whether to reset the row or not
	bool backtracking = false;
	
	//Print heading
  	cout<<"The 8 Queens Problem (all 1s represent queens)"<<endl;
  	cout<<"______________________________________________"<<endl;
	
	//Outer loop will continue program until all solutions are found
	while(1){
		//This loop will carry through the columns
		while(c<8){
			if(backtracking == false){
				q[c] = -1;	
			}
			backtracking = false;
			
			//This loop will carry through the rows
			while(q[c]<8){
				q[c]++;
				if(q[c]==8){
					backtrack(c);					
					continue;
				}
				if(test(q,c)==true){
					break;
				}								
			}
			c++;
		}
		print(q);
		backtrack(c);
		backtracking = true;
	}
}

//Checks for rule validity, returns false if not valid
bool test(int q[], int column){
	for(int i=0; i<column; i++){
		if(q[i]==q[column] || (column-i)==abs(q[column]-q[i]))return false;			
	}
	return true;	
}

//Backtrack function used to go back a column
void backtrack(int &column){
	column--;
	if(column==-1)exit(1);
}

//Print function used to print all results
void print(int q[]){
	static int count = 0;
	count++;
	cout<<"\nSolution # "<<count<<endl;
    cout<<"---------------\n";
      
	int i, j, k, l;
	
	typedef char box[5][7];
	
	//Declare new box types
	box  bb, wb, bq, wq, *board[8][8];
	
	//Fill blank boxes and queen boxes with appropriate characters
	for(i=0; i<5; i++){
		for(j=0; j<7; j++){
			wb[i][j]=' ';
			wq[i][j]=' ';
			bb[i][j]=char(219);
			bq[i][j]=char(219);
			
			if((i==1 || i==2) && (j%2 != 0)){
				wq[i][j]=char(219);
				bq[i][j]=' ';				
			}
			
			if(i==3 &&(j<6 && j>0)){
				wq[i][j]=char(219);
				bq[i][j]=' ';
			}			
			
		}
	}
	
	//Populate the board with blank boxes by dereferencing
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			if((i+j)%2==0){
				if(j==q[i]){
					board[i][j]=&wq;	
				}
				else{
					board[i][j]=&wb;	
				}							
			}
			else{
				if(j==q[i]){
					board[i][j]=&bq;	
				}
				else{
					board[i][j]=&bb;	
				}				
			}
			
			
		}
	}
	
	//Print upper border
	cout<<" ";
	for(i=0; i<7*8; i++){
		cout<<'_';
	}
	cout<<endl;
	
	//Print the board
	for(i=0; i<8; i++){
		for(k=0; k<5; k++){
			cout<<" "<<char(179);
			for(j=0; j<8; j++){
				for(l=0; l<7; l++){
					cout<<(*board[i][j])[k][l];
				}				
			}
			cout<<char(179)<<endl;	
		}
	}
	
	//Print lower border
	cout<<" ";
	for(i=0; i<7*8; i++){
		cout<<char(196);
	}
	cout<<endl;	
}