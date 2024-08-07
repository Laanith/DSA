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
void selectionSort(int arr[], int n);
int select(int arr[], int i, int n);

};

int Solution::select(int arr[], int i, int n){
    int minIndex = ima;
    int minVal = ima;
    for(int j=i; j<n;j++){
        if(arr[j]<minVal){
            minVal = arr[j];
            minIndex =j;
        }
    }

    return minIndex;
}


void Solution::selectionSort( int arr[], int n){
    for(int i=0; i <n; i++){
        int minIndex = select(arr, i, n);
        swap(arr[i], arr[minIndex]);
    }

    return;
}

 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

int arr[] = {2,3,4,1,5,67,35};
S->selectionSort(arr, 7);
for(auto x : arr){cout<<x<<" ";}
 
return 0 ;
}