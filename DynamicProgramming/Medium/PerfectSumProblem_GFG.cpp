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
erfect Sum Problem
Difficulty: MediumAccuracy: 20.58%Submissions: 360K+Points: 4
Given an array arr of size n of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7.

Examples:

Input: 
n = 6, arr = [5, 2, 3, 10, 6, 8], sum = 10
Output: 
3
Explanation: 
{5, 2, 3}, {2, 8}, {10} are possible subsets.
Input: 
n = 5, arr = [2, 5, 1, 4, 3], sum = 10
Output: 
3
Explanation: 
{2, 1, 4, 3}, {5, 1, 4}, {2, 5, 3} are possible subsets.

Expected Time Complexity: O(n*sum)
Expected Auxiliary Space: O(n*sum)

Constraints:
1 ≤ n*sum ≤ 106
0 ≤ arr[i] ≤ 106

*/
 
 
class Solution{
public :

 int checkAndIncrement(int index, int sum,int arr[], int n, int target, int & iter) {
        if(sum>target) return 0;
        if(index >= n && sum == target) return 1;
        else if(index>=n) return 0;
        int count = 0;
        count += checkAndIncrement(index + 1, sum + arr[index],arr, n, target, ++iter);  
        count += checkAndIncrement(index + 1, sum, arr, n, target, ++iter);   
        return count;            
    }


    int func(int index, int arr[], int n, int target, int & iter, vvi &dp){
        //NOTE - A DP version of top-down memoization
        if(target == 0 ) return 1;
        if(index == 0) return target == arr[0];
        if(dp[index][target]!=-1) return dp[index][target];
        int notPick = func(index-1,arr,n,target,++iter,dp);
        int pick = 0;
        if(arr[index]<=target) pick = func(index-1,arr,n,target-arr[index],++iter, dp);
        return dp[index][target] = (pick+notPick);

    }


    int countSums(int arr[], int n, int target){
        vvi dp(n,vi(target+1, -1));
        int count = 0;
        int iter = 0;
        count = func(n-1,arr,n,target,iter, dp);
        cout<<"Function calls : "<<iter<<endl;
        return count;
    }



};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
int A[] = {5,2,3,10,6,8};
int n =6, sum = 10;
pint(S->countSums(A,n,sum));
int B[] = {1,2,3,4,5,6,7,8,9,10};
n = 10, sum = 11;
pint(S->countSums(B,n,sum));
int C[] = {2,5,1,4,3};
pint(S->countSums(C,5,10));

return 0 ;
}