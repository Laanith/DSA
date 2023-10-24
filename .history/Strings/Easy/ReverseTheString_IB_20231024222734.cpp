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
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}

/*!SECTION : Problem Description ::
You are given a string A of size N.



Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.
*/

class Solution{
public :
    string solve(string s);
};

string Solution::solve(string s){
    string ans = "";
    stringstream ss(s);
    string token = "";
    while(getline(ss,token,' ')){
        if(token != ""){
            ans = token + " " + ans;
        }
    }

    int size = ans.size();
    string finalstring = ans.substr(0, size - 1);
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
 
 
return 0 ;
}