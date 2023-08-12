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
 Given an index k, return the kth row of the Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Input : k = 3


Return : [1,3,3,1]

Note: k is 0 based. k = 0, corresponds to the row [1].

Note: Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution{
public :
    vi getRow(int N);
};

vi Solution::getRow(int N){
    int prev = 1;
    vi A;
    A.push_back(1);
    int i = 1;
    while(i<=N){
        int x = prev * (N - i + 1) / i;
        A.push_back(x);
        prev = x;
        i++;
    }

    return A;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pv(S->getRow(5));

return 0 ;
}