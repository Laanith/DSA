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
2035. Partition Array Into Two Arrays to Minimize Sum Difference
Hard
Topics
Companies
Hint
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

 

Example 1:

example-1
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
Example 2:

Input: nums = [-36,36]
Output: 72
Explanation: One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
Example 3:

example-3
Input: nums = [2,-1,0,4,-2,-9]
Output: 0
Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
 

Constraints:

1 <= n <= 15
nums.length == 2 * n
-107 <= nums[i] <= 107

*/
 

//NOTE -  The tabulation approach only works for arrays with positive numbers only. 
//FIXME - The actual leetcode solution can be done by MEET IN THE MIDDLE approach, which is not yet learned by me.
 
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        long long sum = 0, totSum;
        int n = nums.size();
        for(int x : nums) sum += x;
        totSum = sum;
        vvi dp(n, vi(sum+1, 0));

        for(int i = 0; i < n; i++) dp[i][0]=1;
        dp[0][nums[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int t = 1; t <= sum; t++){
                int notTake = dp[i-1][t];
                int take = 0;
                if(t>=nums[i]) take = dp[i-1][t-nums[i]];
                dp[i][t] = (notTake || take);
            }
        }

        long long absDif = ima;
        for(int i = 1; i <= sum; i++){
            if(dp[n-1][i]==1) absDif = min(absDif, abs(totSum - 2*i));
        }
        return int(absDif);
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {3,9,7,3};
pint(S->minimumDifference(A));
 
return 0 ;
}