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
122. Best Time to Buy and Sell Stock II
Medium
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/
 
 
class Solution{
public :
    int func(int ind1, int ind2, vi & prices, vvi & dp){
        if(ind1==ind2){
            // cout<<"Profit from "<<ind1<<" to "<<ind2<<" is "<<0<<endl;
            return  dp[ind1][ind2] = 0;
        }
        if(ind1+1==ind2 && prices[ind2]>prices[ind1]){
            // cout<<"Profit from "<<ind1<<" to "<<ind2<<" is "<<prices[ind2]-prices[ind1]<<endl;
            return dp[ind1][ind2] = prices[ind2]-prices[ind1];
        }
        if(ind1+1==ind2 && prices[ind2]<=prices[ind1]){
            // cout<<"Profit from "<<ind1<<" to "<<ind2<<" is "<<0<<endl;
            return dp[ind1][ind2]=0;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int maxProfit = 0;
        for(int i = ind1; i <= ind2-1; i++){
            int profit = func(ind1,i,prices, dp)+func(i+1,ind2, prices, dp);
            maxProfit = max(maxProfit, profit);
        }
        maxProfit = max(maxProfit, prices[ind2]-prices[ind1]);
        // cout<<"Profit from "<<ind1<<" to "<<ind2<<" is "<<maxProfit<<endl;
        return dp[ind1][ind2] = maxProfit;
    }

    int maxProfit(vi & prices){
        int n = prices.size();
        vvi dp(n , vi(n, -1));
        int ans = func(0, n-1 , prices, dp);
        pvvi(dp);
        return ans;
    }

    int maxProfitTab(vector<int>& prices) {
        int n = prices.size();
        vvi dp(n , vi(n, -1));
        
        for(int i = n-1; i>=0; i--){
            for(int j=0; j < n; j++){
                if(i<=j){
                    if(i==j) {dp[i][j] = 0; continue;}
                    else if(i+1==j){
                        if(prices[i]<prices[j]) {dp[i][j] = prices[j]-prices[i]; continue;}
                        else if(prices[i]>=prices[j]) {dp[i][j] = 0; continue;}
                    }
                    else {
                        int maxProf = 0;
                        for(int k = i; k <= j-1; k++){
                            maxProf = max(maxProf, dp[i][k] + dp[k+1][j]);
                        }
                        maxProf = max(maxProf, prices[j]-prices[i]);
                        dp[i][j] = maxProf;
                        continue;
                    }
                }
                }
        }

        pvvi(dp);

        return dp[0][n-1];
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {7,1,5,3,6,4};
// int ans = S->maxProfit(A);
pint(S->maxProfit(A));
pint(S->maxProfitTab(A));
// A = {1,2,3,4,5};
// pint(S->maxProfit(A));
// A = {5,4,3,2,1};
// pint(S->maxProfit(A));

 
return 0 ;
}