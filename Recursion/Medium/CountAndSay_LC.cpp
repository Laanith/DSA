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
38. Count and Say
Medium
Topics
Companies
Hint
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

 

Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.

 

Constraints:

1 <= n <= 30
*/
 
 
class Solution{
private:
    string RLE(int n){
        if(n==1) return "1";
        if(n==2) return "11";
        string prev = RLE(n-1);
        char ele = prev[0];
        int count = 1;
        string ans = "";
        for(int i = 1; i < prev.size(); i++){
            if(prev[i]!=ele){
                ans += char(count + '0');
                ans += ele;
                count =1 ;
                ele = prev[i];
            }
            else count++;
        }
        ans += char(count + '0');
        ans += ele;
        return ans;
    }
public :
    string countAndSay(int n){
        return RLE(n);
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->countAndSay(1)<<endl;
cout<<S->countAndSay(2)<<endl;
cout<<S->countAndSay(3)<<endl;
cout<<S->countAndSay(4)<<endl;
 
return 0 ;
}