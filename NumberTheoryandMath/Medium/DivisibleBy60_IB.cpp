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
 Given a large number represent in the form of an integer array A, where each element is a digit.

You have to find whether there exists any permutation of the array A such that the number becomes divisible by 60.

Return 1 if it exists, 0 otherwise
*/

class Solution{
public :
    bool divBy60(vi &A);
};

bool Solution::divBy60(vi &A){
    int sum = 0;
    bool divby3 = false, evecount = false, zeroatend = false;
    if(A.size() == 1 && A[0] == 0 )
        return true;
    int evencount = 0;
    for(auto x : A){
        sum += x;
        if(x%2==0)
            evecount++;
        if(x ==0 )
            zeroatend = true;
    }


    if(evencount > 1)
        evecount = true;
    if(sum%3==0)
        divby3 = true;
    return divby3 && zeroatend && evecount;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,2,0};
cout << S->divBy60(A);
return 0 ;
}