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
Given an array arr of n positive integers, your task is to find all the leaders in the array. An element of the array is considered a leader if it is greater than all the elements on its right side or if it is equal to the maximum element on its right side. The rightmost element is always a leader.

Examples

Input: n = 6, arr[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
Input: n = 5, arr[] = {10,4,2,4,1}
Output: 10 4 4 1
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side
Input: n = 4, arr[] = {5, 10, 20, 40} 
Output: 40
Explanation: When an array is sorted in increasing order, only the rightmost element is leader.
*/
 
 
class Solution{
public :
    vi leaders(int n, int arr[]){
        vi maxOnRight(n);
        maxOnRight[n-1] = -1;
        int maxi = arr[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            maxi = max(maxi, arr[i+1]);
            maxOnRight[i] = maxi;
        }

        vi ans;
        for(int i = 0; i < n; i++ ){
            if(arr[i]>=maxOnRight[i]){
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }

    vi leadersOptimal(int n, int arr[]){
        int maxUntilNow = imi;
        vi ans;
        for(int i = n-1; i >=0 ; i--){
            if(arr[i] >= maxUntilNow) ans.push_back(arr[i]);
            maxUntilNow = max(maxUntilNow , arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
int arr[] = {16,17,4,3,5,2};
pv(S->leaders(6, arr));
pv(S->leadersOptimal(6,arr));
int arr2[] = {30,10,10,5};
pv(S->leaders(4, arr2));
pv(S->leadersOptimal(4,arr2));



return 0 ;
}