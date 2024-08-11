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
void pvvi(vvi A){for(auto v : A){pv(v);} cout << endl;}



 
 
/*!SECTION : Problem Description ::
120. Triangle
Solved
Medium
Topics
Companies
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

*/
 
 
class Solution{
public :

    int func(int i, int j, vvi &triangle, vvi &dp, int n){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n-1) return dp[i][j] = triangle[i][j];
        int down = func(i+1,j,triangle,dp,n);
        int diag = func(i+1,j+1,triangle,dp,n);
        return dp[i][j] = (triangle[i][j] + min(down, diag));
    }


    int minTotalMemoization(vvi &triangle){
        int n = triangle.size();
        vvi dp(n,vi(n,-1));
        int ans = func(0,0,triangle,dp,n);
        pvvi(triangle);
        pvvi(dp);
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
pint(S->minTotalMemoization(triangle));

 
return 0 ;
}