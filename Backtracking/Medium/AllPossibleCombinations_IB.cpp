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

/*!SECTION : Problem Description ::
 You are given a array of strings A of length N.

You have to return another string array which contains all possible special strings in Lexicographic order.
 A special string is defined as a string with length equal to N,
 and ith character of the string is equal to any character of the ith string in the array A.

 Input :
 A = ['ab', 'cd']

 Output :
 ['ac', 'ad', 'bc', 'bd']
*/

class Solution{
public :
    vector<string> specialStrings(vector<string> &A);
};

void solve(vector<string> &A, vector<string> &ans, string output, int index)
{
    if (index >= A.size())
    {
        ans.push_back(output);
        return;
    }
    string chars = A[index];
    for (int i = 0; i < chars.size(); i++)
    {
        output.push_back(chars[i]);
        solve(A, ans, output, index + 1);
        output.pop_back();
    }
}

vector<string> Solution::specialStrings(vector<string> &A)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(A, ans, output, index);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vs k = {"aa","bb"};
for(auto x : S->specialStrings(k)){
     cout << x << " ";
}
return 0 ;
}
