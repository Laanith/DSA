#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::
 Given a number N, verify if N is prime or not.

Return 1 if N is prime, else return 0.

Example :

Input : 7
Output : True
*/

class Solution{
public :
    bool isPrime(int A);
};

bool Solution::isPrime(int A){
    if(A==1)
        return false;
    for (int i = 2; i < int(sqrt(A)) + 1;i++){
        if(A%i==0)
            return false;
    }
    return true;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout << S->isPrime(7) <<" "<<  S->isPrime(4) << endl;

return 0 ;
}