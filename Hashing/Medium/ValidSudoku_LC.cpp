#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define PYES cout << "YES" << endl
#define PNO cout << "NO" << endl
#define PMINUS cout << -1 << endl
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int, int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define unseti unordered_set<int>
#define pi pair<int, int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A)
{
    for (auto x : A)
        cout << x << ' ';
    cout << endl;
}
void pint(int A) { cout << endl
                        << A << endl; }
void pp(pair<int, int> p) { cout << p.first << ' ' << p.second << endl; }
void pvvi(vvi A)
{
    for (auto v : A)
    {
        pv(v);
    }
    cout << endl;
}

/*!SECTION : Problem Description ::
36. Valid Sudoku
Solved
Medium
Topics
Companies
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.


Example 1:


Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/

class Solution
{
public:
    bool isValid(vector<vector<char>> &board)
    {
        vvi checks(9, vi(27, 0));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int numIndex = board[i][j] - '1';
                int rowNum = i;
                int colNum = 9 + j;
                int blockNum = int(i / 3) * 3 + int(j / 3) + 18;
                if (checks[numIndex][rowNum] ||
                    checks[numIndex][colNum] ||
                    checks[numIndex][blockNum])
                    return false;
                checks[numIndex][rowNum] = 1;
                checks[numIndex][colNum] = 1;
                checks[numIndex][blockNum] = 1;
            }
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    vector<vector<char>> board = 
                {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                 {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
                 {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
                 {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
                 {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
                 {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
                 {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
                 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout<<boolalpha<<S->isValid(board)<<endl;
    return 0;
}