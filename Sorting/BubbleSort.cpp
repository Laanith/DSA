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
A custom implementation of bubble sort
*/
 
 
class Solution{
public :

    int bubbleSort(vi &a){
        int i,j;
        int swaps=0;
        bool swapped;
        int n = a.size();
        for(i=0; i < n-1; i++){
            swapped = false;
            for(j=0; j < n-i-1; j++){
                if(a[j] > a[j+1])
                {
                    swap(a[j], a[j + 1]);
                    swapped=true;
                    swaps++;
                }
            }


            if(!swapped) break;


        }
        
    }

};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {5,4,3,2,1};
int swaps = S->bubbleSort(A);
pv(A);
cout<<swaps<<endl;
 
 
return 0 ;
}