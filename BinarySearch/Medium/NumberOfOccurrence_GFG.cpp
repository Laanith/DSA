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
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



 
 
/*!SECTION : Problem Description ::
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
*/
 
 
class Solution{
public :
    int count(int arr[], int n , int x){
        int occ = 0;
        int l=0, r = n - 1, mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(arr[mid]==x){ occ++; break;}
            else if ( arr[mid]< x) l = mid+1;
            else r = mid - 1;
        }

        if(occ){
            int lInd = mid, rInd = mid;
            while(rInd < n && arr[rInd+1]==x) {rInd++; occ++;}
            while(lInd >= 0 && arr[lInd - 1]==x) { lInd--; occ++;}
        }

        return occ;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
int arr[] = {1,1,2,2,2,2,3,3};
pint(S->count(arr,8,2));

 
return 0 ;
}