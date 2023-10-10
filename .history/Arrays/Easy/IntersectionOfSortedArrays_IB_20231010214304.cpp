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
Find the intersection of two sorted arrays OR in other words, given 2 sorted arrays, find all the elements which occur in both arrays.

NOTE: For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays should be included multiple times in the final output.


Input 1:
A: [1 2 3 3 4 5 6]
B: [3 3 5]

Output 1: [3 3 5]
*/



class Solution{
    public :
        vi intersection(const vi &A, const vi &B);
};


vi Solution::intersection(const vi &A, const vi &B){
    int i = 0, j = 0;
    vi ans;
    while(i < A.size() && j < B.size()){
        if(A[i] == B[j]) {
            ans.push_back(A[i]);
            i++;
            j++;
        }
        else if (A[i] > B[j]) j++;
        else i++;
    }

    return ans;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,2,3,4,5,6};
vi B = {3,3,5};
pv(S->intersection(A,B));   

return 0 ;
}