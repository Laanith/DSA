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
188. Best Time to Buy and Sell Stock IV
Hard
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/
 
 
class Solution{
public :
    int func(int i, int buy, int cap, vi & prices, vector<vvi> & dp){
        if(cap==0) return 0;
        if(i >= prices.size()) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        if(buy){
            int buyIt = -prices[i] + func(i+1, 0, cap, prices, dp);
            int noBuyIt = func(i+1,1,cap,prices,dp);
            return dp[i][buy][cap] = max(buyIt, noBuyIt);
        }
        int sellIt = prices[i] + func(i+1,1,cap-1,prices,dp);
        int noSellIt= func(i+1,0,cap,prices,dp);
        return dp[i][buy][cap] = max(sellIt, noSellIt);
    }

    int maxProfit(vi & prices, int k){
        int n = prices.size();
        vector<vvi> dp(n, vvi(2, vi(k+1, -1)));
        return func(0,1,k,prices,dp);
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {3,2,6,5,0,3};
pint(S->maxProfit(A, 2));

 
return 0 ;
}