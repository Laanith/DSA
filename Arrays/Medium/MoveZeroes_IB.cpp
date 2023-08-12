#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define ima INT_MAX
#define imi INT_MIN
using namespace std;

/*!SECTION : Problem Description ::
 Given an integer array A, move all 0's to the end of it while maintaining the relative order of the non-zero elements.


Note that you must do this in-place without making a copy of the array.
*/

class Solution{
public :
    vi solveone(vi A);
    vi solvetwo(vi A);
};

vi Solution::solveone(vi A){
    vi X(A.size(), 0);
    int i = 0;
    for(auto x : A){
        if( x != 0){
            X[i] = x;
            i++;
        }
    }

    return X;
}


/* NOTE - This approach is more optimised as it has O(1) space complexity */
vi Solution::solvetwo(vi A){
    int zeroptr = 0;
    int nonzeroptr = imi;
    for (int i = 0; i < A.size(); i++){
        if(A[i] != 0){
            A[zeroptr] = A[i];
            nonzeroptr = max(nonzeroptr, i);
            zeroptr += 1;
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
vi C = {-1, 0, 1, 0, 0, 100, 23, 4, 545};
for(auto x : S->solvetwo(C)){
        cout << x << " ";
}

return 0 ;
}