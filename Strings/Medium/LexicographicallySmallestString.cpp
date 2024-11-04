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
Lexicographically Smallest String
You are given a string s and an array arr[] of integers where arr[i] represents the weight
of the character at index i in the string (1-based indexing).
You are allowed to swap the characters in the string that have the same weight in the array.
In other words, if arr[i] = arr[j], you can swap s[i] and s[j].
Your task is to return the lexicographically smallest string that can be formed by applying any
number of such swaps.
Input Format:
● A string s of length N consisting of lowercase English letters.
● An integer array arr[] of length N, where each element represents the weight of the
corresponding character at index i in the string s.
Output Format:
Return the lexicographically smallest string that can be formed by swapping characters with
the same weight.
Constraints:
● 1 ≤ N ≤ 2000
● 1 ≤ arr[i] ≤ 10
4

● String s consists of only lowercase English letters.
Sample Input Sample Output
xvrb bvrx
[2, 1, 2, 2]
Explanation
Choose ‘x’, ’r’, ’b’ as they are of the same weight and sort them. ‘v’ does not have anyone to
swap with so it remains in the same position.
*/
 

//NOTE - This is a greedy + hashing solution designed by me
 
class Solution{
public :
    string solve(string s, vi arr){
        // Weight wise sorted sets of characters.
        map<int, set<char>> m;
        map<char,int> charMap;

        for(int i=0; i < s.size(); i++){
            m[arr[i]].insert(s[i]);
            charMap[s[i]]++;
        }

        string ans = "";
        for(int wt : arr){
            char charToAppend = *m[wt].begin();
            ans += charToAppend;
            charMap[charToAppend]--;
            if(charMap[charToAppend]==0){
                m[wt].erase(m[wt].begin());
                charMap.erase(charToAppend);
            }
        }
        return ans;

    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout << S->solve("xaaniph", {12,1,1,14,9,12,8})<< endl;
cout << S->solve("xvrb", {2, 1, 2, 2}) << endl; // Expected output: "bvrx"
cout << S->solve("abcd", {1, 1, 1, 1}) << endl; // Expected output: "abcd"
cout << S->solve("abcd", {1, 2, 3, 4}) << endl; // Expected output: "abcd"
cout << S->solve("dcba", {1, 2, 1, 2}) << endl; // Expected output: "badc"
return 0 ;
}