#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::
 You are given an array A of strings and we have to serialize it and return the serialized string.

Serialization: Scan each element in a string, calculate its length and append it with a string and a element separator or deliminator (the deliminator is ~). We append the length of the string so that we know the length of each element.

For example, for a string 'interviewbit', its serialized version would be 'interviewbit12~'.
*/

class Solution{
public :
    string serialize(vector<string> &A);
};

string Solution::serialize(vector<string> &A){
    string s = "";
    for(auto x : A){
        int k = x.size();
        s += x;
        s += to_string(k);
        s += "~";
    }

    return s;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vector<string> A = {"Laanith", "Bunny"};
cout << S->serialize(A) << "\n";

return 0 ;
}