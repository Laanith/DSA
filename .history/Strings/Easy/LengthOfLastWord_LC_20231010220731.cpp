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
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

*/



class Solution{
    public :
        int LengthOfLastWord(string s);      
};


int Solution::LengthOfLastWord(string s){
    int n = s.length();
    int count = 0;
    int ans = 0;
    for(int i = n-1; i >= 0; i++){
        if(s[i]==' ') count++;
    }
    for(int i = n-count-1; i >= 0; i++){
        if(s[i]!=' ') ans++;
        else break;
    }

    return ans;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->LengthOfLastWord("fly me   to   the moon  "));
return 0 ;
}