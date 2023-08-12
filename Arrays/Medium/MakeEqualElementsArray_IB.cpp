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

/*!SECTION : Problem Description ::
 Given an array of all positive integers and an element “x”.

You need to find out whether all array elements can be made equal or not by performing any of the 3 operations: add x to any element in array, subtract x from any element from array, do nothing.

 This operation can be performed only once on an element of array.
*/

class Solution{
public :
    bool solve(vi A, int B);
};

bool Solution::solve(vi A, int B){
    int r = A[0] % B;
    int maxele = imi;
    int minele = ima;
    for(auto x : A){
        if(x%B==r){
            maxele = max(maxele, x);
            minele = min(minele, x);
        }
        else
            return false;
    }

    if ((maxele - B == minele) || (maxele == minele) || (maxele - B == minele + B))
        return true;
    return false;
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {2, 3, 1};
cout << S->solve(A, 1) << endl;
return 0 ;
}