#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

void display_board(char const arr[]){
    for(size_t i = 0; i < 3;i++){
        for(size_t j = 0; j < 3; j++){
            cout<<" "<<arr[j + (i * 3)]<<" ";
        };
        cout<<"\n";
    };
}

char x_or_o(int turn){
    if(turn == 0)
        return 'O';
    else if(turn == 1)
        return 'X';
    else if(turn % 2 == 0)
        return 'O';
    else
        return 'X';
    
    turn++;
}

char make_change(int move,char player, char arr[]){
    if(arr[move -1] != 'O' && arr[move -1] != 'X'){
    arr[move - 1] = player;
    return 'v';
    }
    else {
        cout<<"That spot's taken. Try another spot."<<endl;
        return 'i';
    }
}

int check_winner(char const arr[], char player, int l){
    
    vector <char> row {};
    vector <char> column {};
vector <char> diagonal {};

    for(size_t i = 0; i < 3; i++){
        for(size_t j = 0; j < 3; j++){
            row.push_back(arr[j + (i*3)]);
        }
        if(row.at(0) == row.at(1) &&  row.at(1) == row.at(2)){
                cout<<player<< " won! Good game!"<<endl;
                row.clear();
                return l - 1;
            } else 
                row.clear();
                
    }
    
    for(size_t i = 0; i < 3; i++){
        for(size_t j = 0; j < 9; j+= 3){
           column.push_back(arr[j + i]);
        }
    if(column.at(0) == column.at(1) &&  column.at(1) == column.at(2)){
                cout<<player<< " won! Good game!"<<endl;
                column.clear();
                return l - 1;
            } else 
                column.clear();
    }
    
    for(size_t i = 0; i < 9; i+= 2){
        diagonal.push_back(arr[i]);
    }
        
    if((diagonal.at(0) == diagonal.at(2) &&  diagonal.at(2) == diagonal.at(4)) || (diagonal.at(1) == diagonal.at(2) &&  diagonal.at(2) == diagonal.at(3))){
                cout<<player<< " won! Good game!"<<endl;
                diagonal.clear();
                return l - 1;
            } else {
                diagonal.clear();
                return l + 2;
                
            }
    
    
    
}

int main()
{
    
	char board[9] {'1','2','3','4','5','6','7','8','9'};
    
    srand(time(NULL));
    
    int moves_to_win {2};
    
    for(size_t i = rand() % 2; i < moves_to_win; i++){
    display_board(board);
    char player = x_or_o(i);
    
    
    int move {};
    cout<<"\nIt is " << player << "'s turn: ";
    cin>>move;
    
    char check = make_change(move,player,board);
    if(check == 'i')
        i--;
    
    moves_to_win = check_winner(board,player,i);
    

        
    }
    
    
    
    
	return 0;
}
