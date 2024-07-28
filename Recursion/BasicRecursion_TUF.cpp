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

void printNumber(int i, int N){
    if(i==N){cout<<i<<endl; return;}
    cout<<i<<" ";
    printNumber(i+1,N);
}

void printNumberReverse(int i, int N){
    if(i==0) {cout<<endl; return;}
    cout<<i<<" ";
    printNumberReverse(--i, N);
}

void printName(int i, int N, string name){
    if(i==N){cout<<name<<endl; return;}

    cout<<name<<" ";
    printName(i+1, N, name);
}


void reverseArr(vi &A, int l, int r){
    if(l>=r) return;
    swap(A[l], A[r]);
    reverseArr(A,++l,--r);
}


bool checkPalindrome(string s, int l, int r){
    if(l>=r) return true;
    if(s[l]!=s[r]) return false;
    return checkPalindrome(s,++l,--r);
}

 
 
class Solution{
public :
    void printNumberFrom1ToN(int N);
    void printNameNTimes(int N,string name);
    void printNumberFromNto1(int N);
    int sumFrom1toN(int N);
    int factorial(int N);
    void reverse(vi &A);
    bool isPalindrome(string s);
    int NthFibonacci(int N);

};

void Solution::printNumberFrom1ToN(int N){
    printNumber(1,N);
}

void Solution::printNameNTimes(int N,string name){
    printName(1,N,name);
}


void Solution::printNumberFromNto1(int N){
    printNumberReverse(N,N);
}

int Solution::sumFrom1toN(int N){
    if(N==1) return N;
    return N + sumFrom1toN(N-1);
}

int Solution::factorial(int N){
    if(N==1) return 1;
    return N*factorial(N-1);
}

void Solution::reverse(vi &A){
    int l = 0, r = A.size()-1;
    reverseArr(A, l, r);
}


bool Solution::isPalindrome(string s){
    int l = 0, r = s.length()-1;
    return checkPalindrome(s,l,r);
}


int Solution::NthFibonacci(int N){
    if(N<=1) return 1;
    return NthFibonacci(N-1) + NthFibonacci(N-2);
}




 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
S->printNumberFrom1ToN(10);
S->printNameNTimes(5,"Laanith");
S->printNumberFromNto1(10);
pint(S->sumFrom1toN(8));
pint(S->factorial(10));
vi A = {1,2,3,4,5};
pv(A);
S->reverse(A);
pv(A);
cout<<boolalpha<<S->isPalindrome("SaahoohaaS")<<endl;
cout<<boolalpha<<S->isPalindrome("Laanith")<<endl;
pint(S->NthFibonacci(6));
 
 
return 0 ;
}
