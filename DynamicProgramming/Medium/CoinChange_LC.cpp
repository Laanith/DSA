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
322. Coin Change
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/
 
 
class Solution{
public :

    int func(int ind, int target, vi & coins, int & iter, vvi & dp){
        cout<<"Function calls : "<<iter<<endl;
        if(ind==0){
            if(target%coins[ind]) return 1e9;
            else return target/coins[ind];
        }
        if(dp[ind][target]!=ima) return dp[ind][target];
        int notTake = func(ind-1, target, coins, ++iter, dp);
        int take = ima;
        if(target>=coins[ind]) 1 + func(ind, target-coins[ind], coins, ++iter, dp);
        return dp[ind][target]= min(notTake, take);
    }

    int coinChange(vi & coins, int amt){
        int n = coins.size();
        int iter = 0;
        vvi dp(n, vi(amt+1, ima));
        int ans = func(n-1, amt, coins, iter, dp);
        cout<<iter<<endl;
        if(ans>=1e9) return -1;
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi coins = {1,2,5};
pint(S->coinChange(coins, 11));

 
return 0 ;
}