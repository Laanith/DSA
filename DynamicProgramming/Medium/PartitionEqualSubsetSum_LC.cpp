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

416. Partition Equal Subset Sum
Medium
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/
 
 
class Solution{
public :
    bool func(int index, int target, vi & arr, vvi & dp){
        if(target==0) return true;
        if(index==0) return arr[0]==target;
        if(dp[index][target]!=-1) return dp[index][target];
        bool notTake = func(index-1,target,arr,dp);
        bool take = false;
        if(target>=arr[index]) take = func(index-1,target-arr[index], arr, dp);
        return dp[index][target] = (notTake || take);
    }

    bool subsetSumTabulation(vi &arr, int n, int target){
        vvi dp(n,vi(target+1,0));
        for(int i = 0; i < n; i++) dp[i][target]=0;
        dp[0][arr[0]] = true;
        for(int i = 1; i<n;i++){
            for(int t = 1; t <= target; t++){
                bool notTake = dp[i-1][t];
                bool take = false;
                if(t>=arr[i]) take = dp[i-1][t-arr[i]];
                dp[i][t] = (notTake || take );
            }
        }

        return dp[n-1][target];
    }


    bool subsetSumMemo(vi & arr, int n, int target){
        // The purpose of this function is to find if there exists a subset in array with sum equal to the
        // target.
        vvi dp(n,vi(target+1, -1));
        return func(n-1,target, arr, dp);
    }
    bool canPartition(vi &arr){
        int sum = 0;
        for(int i = 0 ; i < arr.size(); i++) sum+=arr[i];
        int n = arr.size();
        if(sum%2) return false;
        int target = sum/2;
        return subsetSumMemo(arr, n, target);
    }


    bool canPartitionTabulation(vi &arr){
        int sum = 0;
        for(int i = 0 ; i < arr.size(); i++) sum+=arr[i];
        int n = arr.size();
        if(sum%2) return false;
        int target = sum/2;
        return subsetSumTabulation(arr, n, target);
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,5,11,5};
cout<<boolalpha<<S->canPartition(A)<<endl;
cout<<boolalpha<<S->canPartitionTabulation(A)<<endl;
A = {1,2,3,5};
cout<<boolalpha<<S->canPartition(A)<<endl;
cout<<boolalpha<<S->canPartitionTabulation(A)<<endl;



 
return 0 ;
}