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
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}



/*!SECTION : Problem Description ::
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

The digit 0 maps to 0 itself.

The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.

*/


void solve(string &A, int idx, string output, vector<string> &res, vector<string> &mapping){
    if(idx >= A.length()){
        res.push_back(output);
        return;
    }
    
    int digit = A[idx] - '0';
    string s = mapping[digit];
    for(auto i : s){
        output.push_back(i);
        solve(A, idx+1, output, res, mapping);
        output.pop_back();
    }
}




class Solution{
    public :
        vs letterCombinations(string A);
};

vs Solution::letterCombinations(string A) {
    vs mapping {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vs res;
    solve(A, 0, "", res, mapping);
    return res;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pvs(S->letterCombinations("23"));
return 0 ;
}