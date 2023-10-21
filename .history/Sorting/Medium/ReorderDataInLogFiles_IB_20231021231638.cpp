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
 

#define pp pair<string,int>

/*!SECTION : Problem Description ::
You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.

Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.

Return the final order of the logs.


Problem Constraints
1 <= logs.length <= 1000
3 <= logs[i].length <= 1000
All the tokens of logs[i] are separated by a single space.
logs[i] is guaranteed to have an identifier and at least one word after the identifier.


Input Format
The first argument is a string array A where each element is a log.


Output Format
Return the string array A after making the changes.


Example Input
Input 1:
A = ["dig1-8-1-5-1", "let1-art-can", "dig2-3-6", "let2-own-kit-dig", "let3-art-zero"]
Input 2:

A = ["a1-9-2-3-1","g1-act-car","zo4-4-7","ab1-off-key-dog","a8-act-zoo"]


Example Output
Output 1:
["let1-art-can","let3-art-zero","let2-own-kit-dig","dig1-8-1-5-1","dig2-3-6"]
Output 2:

["g1-act-car", "a8-act-zoo", "ab1-off-key-dog", "a1-9-2-3-1", "zo4-4-7"]
*/

class Solution{
public :
    vs reorderLogs(vs &s);
};

vs Solution::reorderLogs(vs &s){
    vi dig;
    
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
 
 
return 0 ;
}