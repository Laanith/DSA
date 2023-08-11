#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::
Given an array of integers A, sort the array into a wave-like array and return it.
In other words, arrange the elements into a sequence such that

a1 >= a2 <= a3 >= a4 <= a5.....
NOTE: If multiple answers are possible, return the lexicographically smallest one.
*/

class Solution{
public :
    vector<int> solve(vi A);
};
 
vi Solution::solve(vi A){
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size()-1; i+= 2){
        swap(A[i], A[i + 1]);
    }

    return A;
}
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1, 3, 4, 5, 2, 7, 6};
for( auto x : S->solve(A)){
        cout << x << " ";
}
 
return 0 ;
}