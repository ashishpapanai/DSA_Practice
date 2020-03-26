#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> dir {{0,1}, {-1,1}, {-1,0},{-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}};
vector<string> dir_name {"R","1","U","2","L","3","D","4"};

bool isSafe(int x,int y,int er,int ec,vector<vector<bool>> & board){

    if(x < 0 || y < 0 || x > er || y > ec || board[x][y]) return false;
    return true;
}

int floodfill(int sr,int sc,int er,int ec,vector<vector<bool>> & board, string ans){

    if(sr == er && sc == ec){
        cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    board[sr][sc] = true;

    for(int d = 0;d< 8;d++){
        
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];

        if(isSafe(x,y,er,ec,board))
            count += floodfill(x,y,er,ec,board,ans + dir_name[d]);
    }

    board[sr][sc] = false;
    return count;
}

void floodfill(){

    vector<vector<bool>> board(3,vector<bool>(3,false));

    cout<<floodfill(0,0,2,2,board,"");

}

int main(){

    floodfill();

    return 0;
}
