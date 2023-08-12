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
Given an array A of size N. You need to return the pair of Maximum and Minimum element in the given array.
NOTE: You should make minimum number of comparisons.
*/

class Solution{
public :
    pair<int, int> MinMax(vi A);
};

pair<int,int> Solution::MinMax(vi A){
    int maxi = imi;
    int mini = ima;
    for(auto x : A){
        maxi = max(maxi, x);
        mini = min(mini, x);
    }
    return make_pair(maxi, mini);
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {4, 3, 2, 1, 5, 6, 7, 3, 8, 3, 7, 3, 75,656 , 47, 45};
cout << S->MinMax(A).first << " " << S->MinMax(A).second;

return 0 ;
}