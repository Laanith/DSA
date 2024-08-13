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
Largest subarray with 0 sum
Difficulty: Medium Accuracy: 41.84% Submissions: 318K+ Points: 4
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Examples:

Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
Output: 5
Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.
Input: arr[] = {2,10,4}, n = 3
Output: 0
Explanation: There is no subarray with 0 sum.
Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
Output: 5
Explanation: The subarray is 0 -4 3 1 0.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 105
-1000 <= arr[i] <= 1000, for each valid i
*/
 
 
class Solution{
public :
    int maxLength(vi & nums, int n){
        int maxLen = 0, sum = 0;
        map<int,int> m;
        for(int i = 0 ; i < n; i++){
            sum += nums[i];
            if(sum==0) maxLen = max(maxLen, i+1);
            if(m.find(sum)!=m.end()) maxLen = max(maxLen, i - m[sum] + 1);
            if(m.find(sum)==m.end()) m[sum] = i+1;
        }

        return maxLen;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A ={15,-2,2,-8,1,7,10,23}; int n = 8;
pint(S->maxLength(A,n));

 
return 0 ;
}