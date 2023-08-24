#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb(x) push_back(x)
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}

/*!SECTION : Problem Description ::
 Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
NOTE

No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
*/

class Solution{
public :
    vector<vi> permute(vi &A);
};

void solve(vector<int> &A, vector<vector<int>> &v, vector<int> &v1, int idx)
{
    if (idx >= A.size())
    {
        v.push_back(v1);
        return;
    }

    for (int j = idx; j < A.size(); j++)
    {
        swap(v1[idx], v1[j]);
        solve(A, v, v1, idx + 1);
        swap(v1[idx], v1[j]);
    }
}

vector<vector<int>> Solution::permute(vector<int> &A)
{
    vector<vector<int>> R;
    solve(A, R, A, 0);
    return R;
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1, 2, 3};
for (vi v : S->permute(A)){
        pv(v);
}
 
return 0 ;
}