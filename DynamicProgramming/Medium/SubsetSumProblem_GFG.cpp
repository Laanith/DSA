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
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 


Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array arr[], its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given sum and false otherwise.
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.
 

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum*N)
 

Constraints:
1 <= N <= 100
1<= arr[i] <= 100
1<= sum <= 104
*/
 
 
class Solution{
public :
    bool func(int index, int target, vi & arr, vvi & dp){
        if(target == 0) return true;
        if(index == 0) return arr[index]==target;
        if(dp[index][target] != -1) return dp[index][target];
        bool notTake = func(index-1, target, arr, dp);
        bool take = false;
        if(target >= arr[index]) take = func(index-1, target-arr[index], arr, dp);
        return dp[index][target] = (notTake || take);
    }
    bool isSubsetSumMemo(int n, vi & arr, int sum){
        vvi dp(n, vi(sum+1, -1));
        return func(n-1, sum, arr, dp);
    }

    bool isSubsetSumTabulation(int n, vi & arr, int sum){
        vvi dp(n, vi(sum+1, 0));
        
        for(int i = 0; i < n; i++) dp[i][0]=true;
        dp[0][arr[0]] = true;

        for(int i = 1; i < n; i++){
            for(int t = 1 ; t <= sum; t++){
                bool notTake = dp[i-1][t];
                bool take = false;
                if(t>=arr[i]) take = dp[i-1][t-arr[i]];
                dp[i][t]= (notTake || take);
            }
        }

        return dp[n-1][sum];
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
int n = 6;
vi A = {3,34,4,12,5,2};
int sum = 9;
cout<<boolalpha<<"Answer by memoization : "<<S->isSubsetSumMemo(n,A,sum)<<endl;
cout<<boolalpha<<"Answer by tabulation : "<<S->isSubsetSumTabulation(n,A,sum)<<endl;
sum = 30;
cout<<boolalpha<<"Answer by memoization : "<<S->isSubsetSumMemo(n,A,sum)<<endl;
cout<<boolalpha<<"Answer by tabulation : "<<S->isSubsetSumTabulation(n,A,sum)<<endl;

return 0 ;
}