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
Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.



Problem Constraints
1 <= length of the array <= 105

1 <= A[i], B <= 109



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the total number of subarrays having bitwise XOR equals to B.



Example Input
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5
*/
 
 
class Solution{
public :
int numSubArraysWithGivenXORBruteForce(vi & nums, int k){
    int count = 0;
    int n = nums.size();
    for(int i = 0 ; i < n; i++){
        int xorSum = 0;
        for(int j = i; j<n;j++){
            xorSum^=nums[j];
            if(xorSum==k) count++;
        }
    }

    return count;
}

int solveOptimal(vi & nums, int k){
    map<int,int> m;
    int n = nums.size();
    int xorSum = 0;
    int count = 0;
    m[0]++;
    for(int i = 0; i < n; i++){
        xorSum^=nums[i];
        if(m.find(k^xorSum)!=m.end()) count+=m[xorSum^k];
        m[xorSum]++;
    }

    return count;

}
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {4, 2, 2, 6, 4};
pint(S->solveOptimal(A,6));
return 0 ;
}