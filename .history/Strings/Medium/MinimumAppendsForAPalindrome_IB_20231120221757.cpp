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

/*!SECTION : Problem Description ::
Problem Description

Given a string A consisting of lowercase characters.

We need to tell minimum characters to be appended (insertion at end) to make the string A a palindrome.



Problem Constraints
1 <= |A| <= 105

A consists only of lower-case characters.



Input Format
First argument is an string A.



Output Format
Return a integer denoting the minimum characters to be appended (insertion at end) to make the string A a palindrome.



Example Input
Input 1:

 A = "abede"
Input 2:

 A = "aabb"


Example Output
Output 1:

 2
Output 2:

 2


Example Explanation
Explanation 1:

 We can make string palindrome as "abedeba" by adding ba at the end of the string.
Explanation 2:

 We can make string palindrome as "aabbaa" by adding aa at the end of the string.


*/


//NOTE -  I am just writing the solution discussed in interview Bit and Brute force solution. The efficient solution involves KMP algorithm and LPS array which are complicated for me right now.

class Solution{
public :
    int solve(string A);
    int BruteForce(string A);
};

bool ispalindrome(string A){
    string k = A;
    reverse(A.begin(), A.end());
    return A == k;
}


int Solution::BruteForce(string A){
    int i = 0;
    int ans;
    string k;
    do{
        k = copy(A.begin() + i, A.end());
    }
} 
int Solution::solve(string A){
    int i = 0,j = A.length() - 1;
    int ans = -1;
    while(i <= j){
        if(A[i] != A[j] && j != A.length()-1){
            j = A.length() - 1;
            i = ans + 1;
            ans = -1;
        }

        else if (A[i] != A[j])
            i++;
        else {
            if (ans == -1)
                ans = i;
            j--;
            i++;
        }  

    }
    if (ans == -1)
        return A.length() - 1;
    return ans;
}

 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->solve("aabb"));

return 0;
}