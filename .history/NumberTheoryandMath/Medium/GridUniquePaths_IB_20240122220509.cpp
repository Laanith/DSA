#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vvi vector<vector<int>>
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
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1)
              OR  : (0, 0) -> (1, 0) -> (1, 1)
*/

class Solution{
public :
    int uniquePaths(int A, int B);
};


int Solution::uniquePaths(int A, int B){
    vvi dp(A, vi(B, -1));
    int result = paths(0, 0, A, B, dp);
    return result;
}

int paths(int i,int j,int A,int B,vvi &dp){
    if(i==A-1  && j==B-1)
        return 1;

    if(i >= A || j >= B)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];


    else
        return dp[i][j] = paths(i + 1, j, A, B, dp) + paths(i, j + 1, A, B, dp);
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
 
 
return 0 ;
}