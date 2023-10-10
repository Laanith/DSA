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
#define umapii unordered_map<int,int>
#define vvi vector<vector<int>>
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}
void ps(string A){cout<<A<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



/*!SECTION : Problem Description ::
Fizzbuzz is one of the most basic problems in the coding interview world. Try to write a small and elegant code for this problem.

Given a positive integer A, return an array of strings with all the integers from 1 to N. 

But for multiples of 3 the array should have “Fizz” instead of the number. 

For the multiples of 5, the array should have “Buzz” instead of the number. 

For numbers which are multiple of 3 and 5 both, the array should have “FizzBuzz” instead of the number.

Look at the example for more details.

Example

A = 5
Return: [1 2 Fizz 4 Buzz]

*/



class Solution{
    public :
        vs FizzBuzz(int A);
};

vs Solution::FizzBuzz(int A){
    vector<string> s;
    for(int i = 1 ; i <= A; i++){
        if(i%3==0 && i%5 ==0) s.push_back("FizzBuzz");
        else if(i%3==0 && i%5 != 0)  s.push_back("Fizz");
        else if(i%5==0 && i%3 != 0) s.push_back("Buzz");
        else s.push_back(to_string(i));
    }
    return s;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pvs(S->FizzBuzz(5));

return 0 ;
}