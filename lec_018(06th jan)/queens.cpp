#include<iostream>
#include<vector>
#include<string>
using namespace std;
int QueensComb(vector<int> &box, int qpsf, int tnq,int lqpl ,string ans){
    if(qpsf == tnq){
        cout << ans<< endl;
        return 1;
    }
    int count = 0;
    for(int i = lqpl; i < box.size(); i++){
        count += QueensComb(box, qpsf+1, tnq, i+1, ans+"b"+to_string(i)+"q"+to_string(qpsf));
    }
    return count;
}
int QueensPerm(vector<int> &box, vector<bool> &vis, int qpsf, int tnq,int lqpl ,string ans){
    if(qpsf == tnq){
        cout << ans<< endl;
        return 1;
    }
    int count = 0;
    for(int i = lqpl; i < box.size(); i++){
        if(!vis[i]){
        vis[i] = true;
        count += QueensPerm(box, vis, qpsf+1, tnq, 0, ans+"b"+to_string(i)+"q"+to_string(qpsf));
        vis[i] = false;}
    }
    return count;
}
//subseq combination
//subseq permutation
int queensCombi2D(vector<vector <bool>> &board, int qpsf, int tnq, string ans, int lqpl){
    if(qpsf == tnq){
        cout<< ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = lqpl; i < board.size()*board[0].size(); i++){
        int x = i/board[0].size();
        int y = i%board[0].size();
        count += queensCombi2D(board, qpsf+1, tnq, ans+"("+to_string(x)+","+to_string(y)+") ", i+1);
    }
    return count;

}
int queensPermu2D(vector<vector <bool>> &board, int qpsf, int tnq, string ans, int lqpl){
    if(qpsf == tnq){
        cout<< ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = lqpl; i < board.size()*board[0].size(); i++){
        int x = i/board[0].size();
        int y = i%board[0].size();
        if(!board[x][y]){
            board[x][y] = true;
        count += queensPermu2D(board, qpsf+1, tnq, ans+"("+to_string(x)+","+to_string(y)+") ", 0);
        board[x][y] = false;
        }
    }
    return count;

}
void basicquestion(){
    vector<int> box{0,0,0,0,0};
    vector<bool> vis(4,false);
    vector<vector<bool>> board(4,vector<bool>(4,false));
    // cout<<queensPermu2D(box, vis, 0, 3, 0,"");
    cout<< queensPermu2D(board, 0,4,"",0);
    
}
int main(){
    basicquestion();
    return 0;
}