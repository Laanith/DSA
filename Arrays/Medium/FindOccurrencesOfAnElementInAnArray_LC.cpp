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
    vi countOccurrencesOfElement(vi nums, vi queries,int x){
        vi index, ans;
        for(int i=0; i < nums.size(); i++) if(nums[i]==x) index.push_back(i);
        for(auto q : queries) ans.push_back((q-1 < index.size()) ? index[q-1] : -1);
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pv(S->countOccurrencesOfElement({1,3,1,7}, {1,3,2,4},1));
 
 
return 0 ;
}