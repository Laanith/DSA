#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}

/*!SECTION : Problem Description ::
 Given a sorted array A containing N integers both positive and negative.

You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.

Try to this in O(N) time.
*/

class Solution{
public :
    vi solve(vi A);
};

vi Solution::solve(vi A){
    vi B;
    for(auto x : A){
        B.push_back(x * x);
    }
    sort(B.begin(), B.end());
    return B;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {-3, 0, 1, 2, 4};
pv(S->solve(A));
return 0 ;
}