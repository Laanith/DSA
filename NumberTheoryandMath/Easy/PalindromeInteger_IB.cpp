#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed. Negative numbers are not palindromic.
*/

class Solution{
public :
    bool isPalindrome(int A);
};

bool Solution::isPalindrome(int A){
    auto k = to_string(A);
    auto s = k;
    reverse(k.begin(), k.end());
    return k == s;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout << S->isPalindrome(121121) << " " << S->isPalindrome(124);

return 0 ;
}