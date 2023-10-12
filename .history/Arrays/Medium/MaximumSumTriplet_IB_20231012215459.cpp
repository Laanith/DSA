#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define si stack<int>
#define qi queue<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
#define umapii unordered_map<int,int>
#define vvi vector<vector<int>>
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}
void ps(string A){cout<<A<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}

/*!SECTION : Problem Description ::
Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.

Input 1:

 A = [2, 5, 3, 1, 4, 9]

 Output 1:

 16

*/

int getLowerBound(set<int> &A, int p){
    auto it = A.lower_bound(p);
    it--;
    return *it;
}



class Solution{
    public :
        int MaxSumTriplet(vi &A);
};

int Solution::MaxSumTriplet(vi &A){
    int N = A.size();
    vi max_suffix_arr;
    int mx = 0;
    for (int i = A.size() - 1; i >= 0; i++){
        mx = max(mx, A[i]);
        max_suffix_arr.push_back(mx);
    }

    set<int> lower;
    int ans = 0;
    for (int i = 0; i < N - 1; i++){
        if(max_suffix_arr[i+1] > A[i]){
            ans = max(ans, getLowerBound(lower, A[i]) + A[i] + max_suffix_arr[i + 1]);
            lower.insert(A[i]);
        }
    }

    return ans;
}



int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {2, 5, 3, 1, 4, 9};
pint(S->MaxSumTriplet(A));
return 0 ;
}