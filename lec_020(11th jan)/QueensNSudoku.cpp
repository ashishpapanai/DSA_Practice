#include <iostream>
#include <vector>

using namespace std;
#define vb vector<bool>
#define vvb vector<vi>
#define vi vector<int>
#define vvi vector<vi>
int nQueenOptimised(vb &col, vb &diag, vb &adiag, int tnq, string ans, int r)
{
    int n = col.size();
    if (tnq == 0 || r == n)
    {
        if (tnq == 0)
        {
            cout << ans << endl;
            return 1;   
        }
        return 0;
    }
    int count = 0;
    for (int c = 0; c < n; c++)
    {
        if (!col[c] && !diag[r + c] && !adiag[r - c + n - 1])
        {
            col[c] = true;
            diag[r + c] = true;
            adiag[r - c + n - 1] = true;
            count += nQueenOptimised(col, diag, adiag, tnq - 1, ans + "( " + to_string(r) + "," + to_string(c) + " )", r + 1);
            col[c] = false;
            diag[r + c] = false;
            adiag[r - c + n - 1] = false;
        }
    }
    return count;
}
int nQueenBits(int col, int diag, int adiag,int tnq, string ans, int r)
{
    int n = 4;
    if (tnq == 0 || r == n)
    {
        if (tnq == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int c = 0; c < n; c++)
    {
        int w = 1<<c;
        int x = 1<<(r+c);
        int y = 1 <<(r-c+n-1);
        if (!(col&w) && !(diag&x) && !(adiag&y))
        {
            col ^= w;
            diag ^= x;
            adiag ^= y;
            count += nQueenBits(col, diag, adiag, tnq - 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ", r + 1);
            col ^= w;
            diag ^= x;
            adiag ^= y;
        }
    }
    return count;
}
void display(vvi &board)
{
    for (vi ar : board)
    {
        for (int ele : ar)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << endl;
}
vi row(9, 0);
vi col(9, 0);
vvi mat(3, vi(3, 0));

int sudoku_01(vvi &board, vi &calls, int idx)
{
    if (idx == calls.size())
    {
        display(board);
        return 1;
    }

    int x = calls[idx] / 9;
    int y = calls[idx] % 9;
    int count = 0;
    for (int num = 1; num <= 9; num++)
    {
        int mask = 1 << num;
        if (!(row[x] & mask) && !(col[y] & mask) && !(mat[x / 3][y / 3] & mask))
        {
            board[x][y] = num;
            row[x] ^= mask;
            col[y] ^= mask;
            mat[x / 3][y / 3] ^= mask;

            count += sudoku_01(board, calls, idx + 1);

            board[x][y] = 0;
            row[x] ^= mask;
            col[y] ^= mask;
            mat[x / 3][y / 3] ^= mask;
        }
    }
    return count;
}

void sudoku()
{
    vvi board = {{0, 0, 6, 0, 0, 8, 0, 0, 0},
                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    vi calls;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
                calls.push_back(i * 9 + j);
            else
            {
                int mask = 1 << board[i][j];
                row[i] |= mask;
                col[j] |= mask;
                mat[i / 3][j / 3] |= mask;
            }
        }
    }
    cout << sudoku_01(board, calls, 0) << endl;
}

void basicQues()
{
    int col = 0;
    int diag = 0;
    int adiag = 0;
    // cout << nQueenOptimised(col, diag, adiag, 4, "", 0);
    // cout << nQueenBits(col, diag, adiag, 4, "", 0);
    sudoku();
}
int main()
{
    basicQues();
    return 0;
}