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
557. Reverse Words in a String III
Solved
Easy
Topics
Companies
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/
 
 
class Solution{
private :
    void Reverse(string & word){
        int i = 0, j = word.length()-1;
        while(i <= j){
            swap(word[i], word[j]);
            i++; j--;
        }
        return;
    }
public :
    string reverseWords(string s){
        string word = "";
        string sentence = "";
        int i = 0;
        while(i < s.length()){
            if(s[i]!=' ') word+=s[i];
            else {
                Reverse(word);
                sentence+=(word + ' ');
                word = "";
            }
            i++;
        }

        Reverse(word);
        sentence+=word;
        return sentence;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->reverseWords("Let's take LeetCode contest")<<endl;
cout<<S->reverseWords("Laanith Chouhan")<<endl;

 
return 0 ;
}