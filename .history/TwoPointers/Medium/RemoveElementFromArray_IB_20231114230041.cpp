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



Given an array A and a value B, remove all the instances of that value in the array.
Also, return the number of elements left in the array after the operation. It does not matter what is left beyond the expected length.
Try to do it in less than linear additional space complexity.


Problem Constraints
1 <= |A| <= 106
0 <= Ai , B <= 2 * 109


Input Format
The first argument is an integer array A.
The second argument is an integer B.


Output Format
Return an integer denoting the number of elements left in the array after the operation, also update the given array A.


Example Input
A = [4, 1, 1, 2, 1, 3]
B = 1


Example Output
Length  : 3
Array A : [4, 2, 3]



Example Explanation
If array A is [4, 1, 1, 2, 1, 3]
and the value element is 1,
then the new length is 3, and A is now [4, 2, 3]

*/

class Solution{
public :
    int removeElement(vi &A, int B);
};


int Solution::removeElement(vi &A, int B){
    int i = 0;
    for (int j = 0; j < A.size(); j++){
        if(A[j] != B)
            swap(A[i++], A[j]);
    }

    return i;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {4, 1, 1, 2, 1, 3};
pint(S->removeElement(A, 1));
pv(A);

return 0 ;
}