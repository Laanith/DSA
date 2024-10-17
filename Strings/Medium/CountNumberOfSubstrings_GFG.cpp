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
Count number of substrings
Difficulty: MediumAccuracy: 20.46%Submissions: 125K+Points: 4
Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

Example 1:

Input: S = "aba", K = 2
Output:3
Explanation:The substrings are: "ab", "ba" and "aba".
Input: S = "abaaca", K = 1
Output: 7
Explanation: The substrings are: "a", "b", "a", "aa", "a", "c", "a". 
Your Task:
You don't need to read input or print anything. Your task is to complete the function substrCount() which takes the string S and an integer K as inputs and returns the number of substrings having exactly K distinct characters.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ |S| ≤ 106
1 ≤ K ≤ 26


*/
 
//NOTE -  Number of sub-strings with exactly k distinct characters is same as difference of number of substrings with atmost k characters and number of substrings with atmost k-1 characters. 
 
class Solution{
private:
    long long atMostK(string s, int k){
        unordered_map<char,int> m;
        int left=0;
        long long cnt = 0;
        for(int right=0; right < s.size(); right++){
            m[s[right]]++;
            while(m.size() > k){
                m[s[left]]--;
                if(!m[s[left]]) m.erase(s[left]);
                left++;
            }
            cnt += (right-left+1);
        }
        return cnt;
    }

    long long atMostKEfficient(string s, int k){
        vi v(26, 0);
        int left=0,right=0,dist=0;
        long long cnt = 0;
        while(right < s.size()){
            v[s[right]-'a']++;
            if(v[s[right]-'a']==1) dist++;
            while(dist>k){
                v[s[left]-'a']--;
                if(v[s[left]-'a']==0) dist--;
                left++;
            }
            cnt+=(right-left+1);
            right++;
        }
        return cnt;
    }

public :
    long long subStrCount(string s, int k){
        return atMostKEfficient(s,k)-atMostKEfficient(s,k-1);
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->subStrCount("abaaca", 1));
 
return 0 ;
}