#include<bits/stdc++.h>
using namespace std;

int board[100][100];
vector<pair<int,int>> to_move{{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

void print_board(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool can_place(int row,int col,int n){
    return row>=0&&row<n&&col>=0&&col<n&&board[row][col]==0;
}

bool knights_move(int row,int column,int n,int move_no){
    if(move_no==n*n+1) return true;

    for(auto i : to_move){
        if(can_place(row+i.first,column+i.second,n)){
            board[row+i.first][column+i.second]=move_no;
            if(knights_move(row+i.first,column+i.second,n,move_no+1)) return true;
            board[row+i.first][column+i.second]=0;
        }
    }
    return false;

}

int main(){
    memset(board,0,sizeof(board));
    int n;cin>>n;
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=1;
            if(knights_move(i,j,n,2)){
                print_board(n);
                flag=1;
                break;
            }
            board[i][j]=0;
        }
        if(flag==1) break;
    }
    if(!flag) cout<<"can't solve \n";
    
    return 0;
}


/*Solution for a 8X8 Board
1  60 39 34 31 18 9  64 
38 35 32 61 10 63 30 17 
59 2  37 40 33 28 19 8 
36 49 42 27 62 11 16 29 
43 58 3  50 41 24 7  20 
48 51 46 55 26 21 12 15 
57 44 53 4  23 14 25 6 
52 47 56 45 54 5  22 13 
*/