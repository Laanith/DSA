#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN

using namespace std;

void printvector(vi A){cout << endl;for(auto x : A)
        cout << x << ' ';
  cout  << endl;
}

/*!SECTION : Problem Description ::
 You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array [Basically you have to sort the array]. Traverse array only once.
*/

class Solution{
public :
    vi solve(vi A);
};

vi Solution::solve(vi A){
    int zeroptr = 0;
    int nonzeroptr = ima;
    for (int i = 0; i < A.size(); i++){
        if(A[i] != 0){
            A[zeroptr] = A[i];
            nonzeroptr = min(nonzeroptr, i);
            zeroptr++;
        }
    }

    for (int i = zeroptr; i < A.size(); i++){
        A[i] = 0;
    }

    return A;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1};
printvector(S->solve(A));
return 0 ;
}