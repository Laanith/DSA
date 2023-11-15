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



Remove Duplicates from the Sorted Array
Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
Note that even though we want you to return the new length, make sure to change the original array as well in place


Problem Constraints
1 <= |A| <= 106
1 <= Ai <= 2 * 109


Input Format
The first argument is an integer array A.


Output Format
Update the array and return the length of the updated array


Example Input
A = [1,1,1,2]


Example Output
3


Example Explanation
For example, Given input array A = [1,1,1,2],
Your function should return length = 3, and A is now [1,1,2].
*/

class Solution{
public :
    int removeDuplicates(vi &A);
};

int Solution::removeDuplicates(vi &A){
    bool count = false;
    int a = 0;
    for (int i = 0; i < A.size(); i++){
        if(A[i] == A[i-1]){
            if(count){
                a++;
                A[i - a] = A[i];
            }
            else {
                count = true;
            }
        }
        else {
            count = false;
        }
    }
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
 
 
return 0 ;
}