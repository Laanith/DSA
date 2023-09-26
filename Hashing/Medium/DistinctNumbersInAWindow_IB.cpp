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
#define umapii unordered_map<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}



/*!SECTION : Problem Description ::
You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE:  if B > N, return an empty array.


Example Input
Input 1:

 A = [1, 2, 1, 3, 4, 3]
 B = 3
Input 2:

 A = [1, 1, 2, 2]
 B = 1

 Outputs 
 Output 1:

 [2, 3, 3, 2]
Output 2:

 [1, 1, 1, 1]

*/



class Solution{
    public :
        vi dNums(vi &A, int B);
};


vi Solution::dNums(vi &A, int B){
    vi x;
    if(B > A.size()) return x;
    umapii m;
    vi ans;
    for(int i = 0 ; i < B; i++){
        m[A[i]]++;
    }
    int left = 0;
    ans.push_back(m.size());
    for(int i = B; i < A.size(); i++){
        m[A[left]]--;
        if(m[A[left]] == 0) m.erase(A[left]);
        left++;
        m[A[i]]++;
        ans.push_back(m.size());
    }

    return ans;
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,2,1,3,4,3};
pv(S->dNums(A, 3));

return 0 ;
}