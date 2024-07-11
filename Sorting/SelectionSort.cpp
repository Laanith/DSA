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
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}


 
 
/*!SECTION : Problem Description ::
 An algorithm to implement selection sort on my own. Just to enhance the existing understanding.
*/
 
 
class Solution{
public :
    void selectionSort(vi &A){
        for(int i=0; i<A.size(); i++){
            int min_index = imi;
            int min_val = ima;
            for(int j=i; j<A.size(); j++ ){
                if(A[j]<min_val){
                    min_val = A[j];
                    min_index = j;
                }
            }
            swap(A[min_index], A[i]);
        }

        return;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {5,6,4,2,1,3};
S->selectionSort(A);
pv(A);
 
 
return 0 ;
}