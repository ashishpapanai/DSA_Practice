#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isSafeToPlaceQueen(vector<vector<bool>> &board, int x, int y)
{
    vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    for (int i = 0; i < 4; i++)
    {
        for (int radius = 1; radius < max(board.size(), board[0].size()); radius++)
        {
            int a = x + radius * dir[i][0];
            int b = y + radius * dir[i][1];
            if (a < 0 || b < 0 || b >= board[0].size() || a >= board.size())
            {
                break;
            }
            if (board[a][b])
            {
                return false;
            }
        }
    }
    return true;
}
int queensRealCombi(vector<vector<bool>> &board, int qpsf, int tnq, string ans, int lqpl)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = lqpl; i < board.size() * board[0].size(); i++)
    {
        int x = i / board[0].size();
        int y = i % board[0].size();
        if (isSafeToPlaceQueen(board, x, y))
        {
            board[x][y] = true;
            count += queensRealCombi(board, qpsf + 1, tnq, ans + "[" + to_string(x) + "-" + to_string(y) + "] ", i + 1);
            board[x][y] = false;
        }
    }
    return count;
}
bool isSafeToPlaceQueenP(vector<vector<bool>> &board, int x, int y)
{
    vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
    for (int i = 0; i < 8; i++)
    {
        for (int radius = 1; radius < max(board.size(), board[0].size()); radius++)
        {
            int a = x + radius * dir[i][0];
            int b = y + radius * dir[i][1];
            if (a < 0 || b < 0 || b >= board[0].size() || a >= board.size())
            {
                break;
            }
            if (board[a][b])
            {
                return false;
            }
        }
    }
    return true;
}
int queensRealPermu(vector<vector<bool>> &board, int qpsf, int tnq, string ans, int lqpl)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < board.size() * board[0].size(); i++)
    {
        int x = i / board[0].size();
        int y = i % board[0].size();
        if (!board[x][y] && isSafeToPlaceQueenP(board, x, y))
        {
            board[x][y] = true;
            count += queensRealPermu(board, qpsf + 1, tnq, ans + "(" + to_string(x) + "," + to_string(y) + ") ", i + 1);
            board[x][y] = false;
        }
    }
    return count;
}
void basicquestion()
{
    vector<int> box{0, 0, 0, 0, 0};
    vector<bool> vis(4, false);
    vector<vector<bool>> board(4, vector<bool>(4, false));
    // cout<<queensPermu2D(box, vis, 0, 3, 0,"");
    //cout << queensRealPermu(board, 0, 4, "", 0);
    cout << queensRealCombi(board, 0, 4, "", 0);
}
int main()
{
    basicquestion();
    return 0;
}