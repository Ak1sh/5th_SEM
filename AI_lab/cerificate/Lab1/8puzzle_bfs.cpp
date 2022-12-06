#include <bits/stdc++.h>
using namespace std;


char finalState[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','.'}};

int checkValid(int row,int col){
    if(row >=0 && row <3  && col <3 && col>=0 )return 1;
    return 0;
}

void print(char board[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<board[i][j]<<" ";
        }cout<<"\n";
    }cout<<"\n";
}

void swap(char board[][3],int nc,int nr,int cc,int cr){
    int temp = board[nr][nc];
    board[nr][nc] = board[cr][cc];
    board[cr][cc] = temp;
}

int heuristic(char matrix[][3]){
    int count =0 ;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(matrix[i][j] != finalState[i][j]){
                count++;
            }
        }
    }
    return count;
}

pair<int,int> findPos(char board[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] =='.'){
                return {i,j}; 
            }
        }
    }
    return {-1,-1};
}

void bfs(char board[][3],vector<pair<int,int>> &ans){
    queue<pair<int,pair<int,int>>> q;
    //<heuristic<row,col>>;
    int h = heuristic(board);
    //cout<<"h == "<<h<<"\n";
    pair<int,int> emptyPos = findPos(board);
    //cout<<"empty pos == r = " << emptyPos.first<<" c ==  : "<<emptyPos.second<<" \n";
    q.push({h,emptyPos});
    int delRow[] = {0,1,0,-1};
    int delCol[] = {1,0,-1,0};
    pair<int,int> bestMove;
    while(!q.empty()){
        //cout<<"what?";
        int currRow = q.front().second.first;
        int currCol = q.front().second.second;
        int currHeuristic = q.front().first;
        //cout<<currHeuristic<<" \n";
        if(currHeuristic == 0)return;
        q.pop();
        int nRow,nCol;
        for(int i=0;i<4;i++){
            nRow = currRow + delRow[i];
            nCol = currCol + delCol[i];
            
            if(checkValid(nRow,nCol)){
                swap(board,nCol,nRow,currCol,currRow);
                //print(board);
                int newHeuristic = heuristic(board);
                if(newHeuristic < currHeuristic){
                    currHeuristic = newHeuristic;
                    bestMove = {nRow,nCol};
                }
                swap(board,nCol,nRow,currCol,currRow);
            }
        }
        swap(board,bestMove.second,bestMove.first,currCol,currRow);
        cout<<"move block of row == " << bestMove.first<< " and Col == "<<bestMove.second<<"\n"; 
        print(board);
        ans.push_back(bestMove);
        q.push({currHeuristic,bestMove});
    }
}

int main(){
    char board[3][3];
    cout<<"Enter 9 position values : ";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>board[i][j];
        }
    }
    cout<<"\n\n\n";
    //cout<<"hello";
    vector<pair<int,int>> ans;
    cout<<"Play the following moves to complete the game : \n\n";
    bfs(board,ans);
    
    
    //cout<<"hello";
    return 0;
}


//1 2 3 . 4 6 7 5 8
