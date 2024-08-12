#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define unseti unordered_set<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}cout << endl;}



 
 
/*!SECTION : Problem Description ::
931. Minimum Falling Path Sum
Medium
Topics
Companies
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

*/
 
 
class Solution{
public :
    int func(int i,int j,vvi &matrix, vvi & dp, int n, int m){
        if(j<0 || j>=m) return ima;
        if(i==0) return  dp[i][j] = matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int s = func(i-1,j,matrix,dp,n,m);
        int ld = func(i-1,j-1,matrix,dp,n,m);
        int rd = func(i-1,j+1,matrix,dp,n,m);
        return dp[i][j] = (matrix[i][j] + min(ld,min(s,rd)));
    }

    int minFallingPathSum(vvi & matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vvi dp(n, vi(m, -1));

        int ans= ima;

        for(int i = 0 ; i < m; i++){
            ans = min(func(n-1,i,matrix,dp,n,m),ans);
        }

        pvvi(matrix);
        pvvi(dp);
        return ans;
    }

    int minFallingPathSumTabulation(vvi & matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vvi dp(n,vi(m,-1));

        for(int i=0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i==0) {dp[i][j] = matrix[i][j]; continue;}
                int s = 1e9, ld = 1e9, rd = 1e9;
                if(j>0) ld = dp[i-1][j-1];
                if(j<m-1) rd = dp[i-1][j+1];
                s = dp[i-1][j];
                dp[i][j] = (matrix[i][j] + min(s,min(ld,rd)));
            }
        }


        int ans = ima;
        for(int x : dp[m-1]) ans = min(ans, x);
        return ans;

    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi matrix = {{2,1,3}, {6,5,4}, {7,8,9}};
pint(S->minFallingPathSum(matrix));

pint(S->minFallingPathSumTabulation(matrix));


 
return 0 ;
}