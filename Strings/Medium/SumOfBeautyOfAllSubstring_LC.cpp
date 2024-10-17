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
1781. Sum of Beauty of All Substrings
Solved
Medium
Topics
Companies
Hint
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.

*/
 
 
class Solution{
public :
    int Beauty(vi & alp){
        int mf=-1, lf=1e9;
        for(int x : alp){
            mf = max(mf, x);
            if(x) lf = min(lf, x);
        }
        return mf-lf;
    }

    int beautySum(string s){
        int beaut = 0;
        for(int i = 0; i < s.size(); i++){
            vi alp(26, 0);
            for(int j = i; j < s.size(); j++){
                alp[s[j]-'a']++;
                beaut += Beauty(alp);
            }
        }
        return beaut;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->beautySum("aabcb"));
pint(S->beautySum("aabcbaa"));

 
return 0 ;
}