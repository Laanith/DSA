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
void pv(vi A){cout << endl<<endl;for(auto x : A) cout << x <<' ';cout << endl<<endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}



/*!SECTION : Problem Description ::
Given an array A of N strings, return all groups of strings that are anagrams.

Represent a group by a list of integers representing the index(1-based) in the original list. Look at the sample case for clarification.

NOTE: Anagram is a word, phrase, or name formed by rearranging the letters, such as 'spar', formed from 'rasp'.
*/



class Solution{
    public :
        vector<vi> anagrams(const vs &A);
};

vector<vi> Solution::anagrams(const vs &A){
    int n=A.size();
    unordered_map<string,vector<int>> mp;
   
    for(int i=0;i<n;i++)
    {
        string a=A[i];
        sort(a.begin(),a.end());
        mp[a].push_back(i+1);
    }
    vector<vector<int>> ans;
    for(auto it :mp)
    {
        vector<int> res=it.second;
        ans.push_back(res);
    }
    return ans;

}




int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vs K  = {"cat","dog","god","tca"};
for(auto v : S->anagrams(K)){
    pv(v);
}

return 0 ;
}