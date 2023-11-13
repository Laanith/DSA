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



Find the contiguous subarray within an array, A of length N which has the largest sum.


Problem Constraints
1 <= N <= 106
-1000 <= A[i] <= 1000


Input Format
The first and the only argument contains an integer array, A.


Output Format
Return an integer representing the maximum possible sum of the contiguous subarray.


Example Input
Input 1:
A = [1, 2, 3, 4, -10]
Input 2:
A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]


Example Output
Output 1:
10
Output 2:
6


//NOTE - I got to know that the algorithm implemented below is called Kadane's algorithm.

*/


class Solution{
public :
    int maxSum(vi A);
};
 
int Solution::maxSum(vi A){
    int sum = 0;
    int maxi = A[0];
    for(auto x : A){
        sum += x;
        maxi = max(maxi, sum);
        if(sum < 0)
            sum = 0;
    }

    return maxi;
}


 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1, 2, 3, 4, -10};
pint(S->maxSum(A));

return 0 ;
}