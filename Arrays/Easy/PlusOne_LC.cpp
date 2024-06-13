#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



 
 
/*!SECTION : Problem Description ::
 
*/
 
 
class Solution{
public :
    vi plusOne(vi &digits){
        int sum=0,borrow=0;
        for(int i = digits.size()-1; i>= 0; i--){
            if(i==digits.size()-1) sum = digits[i]+borrow+1;
            else sum = digits[i]+borrow;
            if(sum>9){
                digits[i] = sum%10;
                borrow = sum/10;
            }
            else {
                digits[i] = sum;
                borrow = 0;
            }
            
        }

        if(borrow){
            digits.insert(digits.begin(), borrow);
        }
        return digits;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {9,9,9,9};
vi B = {1,2,3,4,5};
pv(S->plusOne(A));
pv(S->plusOne(B));
 
 
return 0 ;
}