#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



 
 
/*!SECTION : Problem Description ::
Given an array arr containing n integers and an integer k. Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.

 

Examples:
 

Input :
arr[] = {10, 5, 2, 7, 1, 9}, k = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Input : 
arr[] = {-1, 2, 3}, k = 6
Output : 0
Explanation: 
There is no such sub-array with sum 6.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

 
*/
 
 
class Solution{
public :
int lenOfLongestSubArr(int A[], int N, int K){
    int sum  = 0, maxLen = 0;
    map<int,int> sumToIndex;
    for(int i = 0; i< N ; i++){
        sum+=A[i];
        if(sum==K) maxLen = max(maxLen, i+1);
        if(sumToIndex.find(sum-K)!=sumToIndex.end()) maxLen = max(maxLen, i - sumToIndex[sum-K]);
        if(sumToIndex.find(sum)==sumToIndex.end()) sumToIndex[sum] = i;
    }

    return maxLen;
}
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
int arr[ ] = {20,5,2,7,1,9};
int k = 15;
int N = 6;
pint(S->lenOfLongestSubArr(arr, N, k));
 
 
return 0 ;
}