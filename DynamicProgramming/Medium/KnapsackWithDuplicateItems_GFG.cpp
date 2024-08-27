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
Given a set of N items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Examples:

Input: N = 2, W = 3, val = {1, 1}, wt = {2, 1}
Output: 3
Explanation: 1.Pick the 2nd element thrice. 2.Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1  = 3 which is <= 3.
Input: N = 4, W = 8, val[] = {6, 1, 7, 7}, wt[] = {1, 3, 4, 5}
Output: 48
Explanation: The optimal choice is to pick the 1st element 8 times.
Your Task:
You do not need to read input or print anything. Your task is to complete the function knapSack() which takes the values N, W and the arrays val and wt as input parameters and returns the maximum possible value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(W)

Constraints:
1 ≤ N, W ≤ 1000
1 ≤ val[i], wt[i] ≤ 100

Seen this question in a real interview before ?
Yes

*/
 
 
class Solution{
public :

    int func(int ind, int w, vi & weights, vi & values, vvi & dp){
        if(ind==0) return int(w/weights[0])*values[0];
        if(dp[ind][w]!=-1) return dp[ind][w];
        int notPick = func(ind-1,w,weights, values, dp);
        int pick = imi;
        if(w>=weights[ind]) pick = values[ind] + func(ind, w - weights[ind], weights, values, dp);
        return dp[ind][w] = max(notPick, pick);
    }

    int knapSack(int maxWt, vi & weights, vi & values){
        int n = weights.size();
        vvi dp(n, vi(maxWt + 1, -1));
        return func(n-1, maxWt, weights, values, dp);
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi w = {1,3,4,5} , val = {6,1,7,7};
cout << S->knapSack(8, w, val) << endl;
 
return 0 ;
}