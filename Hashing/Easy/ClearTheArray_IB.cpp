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
Clear the Array
Programming
Hashing
Very Easy
61.5% Success

11

15

Bookmark
Problem Description

You are given an array A of size N. In one operation, you can select a subsequence of A such that no two elements are the same in the selected subsequence and delete the selected elements from the array A. 

Find the minimum number of operations required to delete all the elements.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 109
*/
 
 
class Solution{
public :
    int solve(vi & A){
        map<int,int> m;
        for(int i : A) m[i]++;
        int maxFreq = 0;
        for(pi p : m) maxFreq = max(maxFreq, p.second);
        return maxFreq;

    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {3,1,3};
pint(S->solve(A));
vi B = {1,1};
pint(S->solve(B));

 
return 0 ;
}