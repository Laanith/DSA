#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::
 Given four positive integers A, B, C, D, determine if there’s a rectangle such that the lengths of its sides are A, B, C and D (in any order).

If any such rectangle exist return 1 else return 0.
*/

class Solution{
public :
    bool isRectangle(int a, int B, int C, int D);
};

bool Solution::isRectangle(int A, int B, int C, int D){
    map<int, int> m;
    m[A]++;
    m[B]++;
    m[C]++;
    m[D]++;
    if(m.size() != 2)
        return false;
    return m.begin()->second == 2;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout << S->isRectangle(2, 3, 2, 3) << endl
     << S->isRectangle(1, 2, 1, 1);
return 0 ;
}