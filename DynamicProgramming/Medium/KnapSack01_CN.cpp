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
blem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second
*/
 
 
class Solution{
public :
    int func(int ind, int w, vi & weights, vi & values, vvi & dp){
        if(ind==0){
            if(w>=weights[ind]) return values[ind];
            else return 0;
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int notPick = func(ind-1, w, weights, values, dp);
        int pick = imi;
        if(w>=weights[ind]) pick = values[ind] + func(ind-1, w - weights[ind], weights, values, dp);
        return dp[ind][w] = max(pick, notPick);
    }

    int knapsack(vi & weights, vi & values, int maxWeight){
        int n = weights.size();
        vvi dp(n, vi(maxWeight+1, -1));
        int ans = func(n-1, maxWeight, weights, values, dp);
        pvvi(dp);
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi w = {1,2,4,5}, v = {5,4,8,6};
pint(S->knapsack(w,v,5));

 
return 0 ;
}