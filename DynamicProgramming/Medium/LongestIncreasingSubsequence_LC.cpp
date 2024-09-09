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
300. Longest Increasing Subsequence
Medium
Topics
Companies
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/
 
 
class Solution{
public :
    int func(int ind, int prev, vi & nums, vvi & dp){
        if(ind>=nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int notTake = imi, take = imi;
        notTake = func(ind+1,prev,nums, dp);
        if((nums[ind] > nums[prev]) || prev == -1) take = 1 + func(ind+1,ind, nums, dp);
        return dp[ind][prev+1] = max(take, notTake);
    }

    int lengthofLIS(vi & nums){
        int n = nums.size();
        vvi dp(n,vi(n+1, -1));
        int ans = func(0,-1,nums, dp);
        pvvi(dp);
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {10,9,2,5,3,7,101,18};
pint(S->lengthofLIS(A));
A = {0,1,0,3,2,3};
pint(S->lengthofLIS(A));
A = {7,7,7,7,7,7,7};
pint(S->lengthofLIS(A));

 
return 0 ;
}