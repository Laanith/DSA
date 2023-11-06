#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}

/*!SECTION : Problem Description ::
Problem Description

Given the position of a Bishop (A, B) on an 8 * 8 chessboard.

Your task is to count the total number of squares that can be visited by the Bishop in one move.

The position of the Bishop is denoted using row and column number of the chessboard.



Problem Constraints
1 <= A, B <= 8



Input Format
First argument is an integer A denoting the row number of the bishop.

Second argument is an integer B denoting the column number of the bishop.



Output Format
Return an integer denoting the total number of squares that can be visited by the Bishop in one move.



Example Input
Input 1:

 A = 4
 B = 4


Example Output
Output 1:

 13
*/

class Solution{
public :
    int totalMoves(int A, int B);
};
 
 int Solution::totalMoves(int A,int B){
    if (A == 1 || B == 8 || B == 1 || A == 8)
    {
        return 7;
    }
    if (A == 2 || B == 7 || B == 2 || A == 7)
    {
        return 9;
    }
    if (A == 3 || B == 6 || B == 3 || A == 6)
    {
        return 11;
    }
    return 13;
 }
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
 
 
return 0 ;
}