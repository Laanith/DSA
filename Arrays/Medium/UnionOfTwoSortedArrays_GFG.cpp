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
    vi findUnion( int a1[], int n, int a2[], int m){
        vi ans;
        int i=0,j=0;
        while(i<n && j<m){
            if(a1[i] ==a1[i+1]) i++;
            if(a2[j] ==a2[j+1]) j++;
            if(a1[i]<a2[j]) {ans.push_back(a1[i]); i++;}
            else if(a2[j]<a1[i]) {ans.push_back(a2[j]); j++;}
            else if (a1[i] == a2[j]) { ans.push_back(a1[i]); i++; j++;}

        }

        while(i<n){
            while(a1[i]==a1[i+1]) i++;
            ans.push_back(a1[i]); i++;
        }

        while(j<m){
            while(a2[j]==a2[j+1]) j++;
            ans.push_back(a2[j]); j++;
        }

        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
int a1[] = {1,2,3,3};
int a2[] = {3,4,4,5};
pv(S->findUnion(a1,4,a2,4));
 
 
return 0 ;
}