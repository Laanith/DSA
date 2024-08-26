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
Partitions with Given Difference
Difficulty: MediumAccuracy: 36.76%Submissions: 125K+Points: 4
Given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be S1 and S2. 
Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference between S1 and S2 is equal to d. Since the answer may be large return it modulo 109 + 7.

Example 1:

Input:
n = 4
d = 3
arr[] =  { 5, 2, 6, 4}
Output: 1
Explanation:
There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
Example 2:

Input:
n = 4
d = 0 
arr[] = {1, 1, 1, 1} 
Output: 6 
Explanation:
we can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in S1 and remaning two 1's in S2.
Thus there are total 6 ways for partition the array arr. 
Your Task:
You don't have to read input or print anything. Your task is to complete the function countPartitions() which takes the integer n and d and array arr and returns the count of partitions.

Expected Time Complexity: O( n*sum(arr))
Expected Space Complexity: O( sum(arr))

Constraint:
1 <= n <= 500
0 <= d  <= 25000
0 <= arr[i] <= 50
*/
 
 
class Solution{
public :

    int mod = int(1e9)+7;

    int func(int ind,int target, vi &arr, vvi & dp){
        // if(target==0) return 1;
        if(ind==0) 
        {
            if(target==0 && arr[0]==0) return 2;
            if(target==0 || target == arr[0]) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notTake = func(ind -1, target, arr, dp);
        notTake%=mod;
        int take = 0;
        if(target >= arr[ind]) take = func(ind-1,target-arr[ind], arr, dp);
        take%=mod;
        return dp[ind][target]=(take+notTake)%mod;
    }


    int countPartitions(vi & arr, int d){
        int n = arr.size();
        int sum = 0;
        for(int x : arr) sum += x;
        int mod = 1e9 + 7;
        if(sum-d < 0 || (sum -d)%2) return 0;
        int target = (sum - d)/2;
        vvi dp(n, vi(target+1,-1));
        return func(n-1, target, arr, dp);
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
int d = 3; 
vi A = {5,2,6,4};
pint(S->countPartitions(A,d));
A = {1,1,1,1};
pint(S->countPartitions(A,0));
A = {0,1,2,2,2,3,0,3,0,1};
pint(S->countPartitions(A,12));


return 0 ;
}