#include <iostream>
using namespace std;
	char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int choice;
	int row,column;
	char turn='X';
	bool tie=false;
	//function to display the board of game..
  void displayinterface(){
	system("CLS");
	cout<<"\t\t Tic Tac Toe Game \n";
	cout<<"\t\t player1 [X]\n\t\t player2 [O]\n";
	cout<<"\t\t      |       |          \n";
	cout<<"\t\t"<< board[0][0]<<"     | "<<board[0][1]<<"     | "<<board[0][2]<<endl;
	cout<<"\t\t _ _ _| _ _ _ |_ _ _     \n";
	cout<<"\t\t      |       |          \n";
	cout<<"\t\t"<< board[1][0]<<"     | "<<board[1][1]<<"     | "<<board[1][2]<<endl;
	cout<<"\t\t _ _ _| _ _ _ |_ _ _     \n";
	cout<<"\t\t      |       |          \n";
	cout<<"\t\t"<< board[2][0]<<"     | "<<board[2][1]<<"     | "<<board[2][2]<<endl;
	cout<<"\t\t _ _ _| _ _ _ |_ _ _     \n";
	cout<<"\t\t      |       |          \n";
	cout<<"\t\t      |       |          \n";
   }
    /*making function to give the turn to each player 
    or to take their choice to replace that no with  symbol of player..*/
     void playerturn(){
             if(turn =='X'){
             cout<<"Player1 [X] turn \n Select from (1-9)\n";	
        }
           else if(turn =='O') {
         cout<<"Player2 [O] turn \n Select from (1-9)\n" ;
        }
          else{
	     cout<<"Invalid!!  \n";
      }
        cin >>choice;
       switch(choice){

           case 1: row=0;column=0;break;
           case 2: row=0;column=1;break;
           case 3: row=0;column=2;break;
	       case 4: row=1;column=0;break;
	       case 5: row=1;column=1;break;	
	       case 6: row=1;column=2;break;
           case 7: row=2;column=0;break;
           case 8: row=2;column=1;break;
	       case 9: row=2;column=2;break;
	       default:
	         	cout<<"Invalid!!.\n Please select within range.";
    }
 //checking wheather the box is filled or empty
	    if (turn=='X'&& board[row][column]!='X'&&board[row][column]!='O'){
	    	  board[row][column]='X';
		     turn='O';
	   }
		else  if(turn=='O'&& board[row][column]!='O'&&board[row][column]!='X') {
	      board[row][column]='O';
		  turn='X';
	  }
	     else
	    {
		cout<<"Box is already filled .. Please select anyother\n ";
		playerturn();
	    }
     displayinterface();
    }
   // making function to check wheather the game is over or still continued..
    bool gameover(){
  	//check win..
     	for(int i=0;i<3;i++)
	  {
		  if(board[i][0]==board[i][1]&&board[i][0]==board[i][2] 
		  || board[0][i]==board[1][i]&&board[0][i]==board[2][i]){
		     return false;	
	    	}
	    }
    if (board[0][0]==board[1][1]&& board[0][0]==board[2][2]
	||board[0][2]==board[1][1]&& board[0][2]==board[2][0]){
        return false;
     }
     //if box is not filled..
          for(int i=0;i<3;i++){
	           for(int j=0;j<3;j++){
	            	if(board[i][j]!='X'&&board[i][j]!='O'){	
	                 	return true;
                       	}
                }
         }
	        tie=true;
            	return false;
   }
    int main() {
	   while(gameover()){
	         displayinterface();
             playerturn();
             gameover();
       }
	    if(turn=='X'&& tie==false){
	         	cout<<"Player2 [O] Wins..!!\n Congratulations! you win\n";
	         }
         else if(turn=='O'&& tie==false){
		    cout<<"Player1 [X] Wins..!!\n Congratulations! You win\n";
         	}
	      else{
	         	cout<<" It is tie \n Alas ! No one is Winner.."<<endl;
	     }
	 
		 	return 0;
    }
