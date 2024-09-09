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

309. Best Time to Buy and Sell Stock with Cooldown
Attempted
Medium
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/
 

class Solution {
public:

    int func(int i, int buy, vi & prices, vvi & dp){
        if(i >= prices.size()) return 0;
        // if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            int buyIt = -prices[i] + func(i+1,0,prices,dp);
            int noBuyIt = func(i+1,1,prices,dp);
            return dp[i][buy] = max(buyIt, noBuyIt);
        }
        int sellIt = prices[i] + func(i+2, 1, prices, dp);
        int noSellIt = func(i+1,0,prices,dp);
        return dp[i][buy] = max(sellIt, noSellIt);
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vvi dp(n, vi(2, -1));
        return func(0, 1, prices, dp);
    }
};

 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,2,3,0,2};
pint(S->maxProfit(A));

 
return 0 ;
}