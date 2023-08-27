#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define si stack<int>
#define qi queue<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl<<endl;for(auto x : A) cout<<x<<"\n";cout<<endl<<endl;}



/*!SECTION : Problem Description ::
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
*/



class Solution{
    public :
        vector<vs> solveNQueens(int A);
};

bool isok(vector<string> v,int x,int y)

{

    int i;

    for(i=0;i<=x;i++)

    {

        if(v[i][y]=='Q')return false;

    }

    int r=x;

    int c=y;

    for(;r>=0&&c>=0;)

    {

        if(v[r][c]=='Q')return false;

        r--;c--;

    }

    

    r=x;

    c=y;

    for(;r>=0&&c<v.size();)

    {

        if(v[r][c]=='Q')return false;

        r--;c++;

    }

    return true;

}



void solve(vector<vector<string> >&s, vector<string> &v, int row,int n)

{

    if(row>=n)

    {

        s.push_back(v);

        return;

    }

    

    for(int i=0;i<n;i++)

    {

        if(isok(v,row,i))

        {

            v[row][i]='Q';

            solve(s,v,row+1,n);

        }        

        v[row][i]='.';

    }

    return;

}
vector<vs> Solution::solveNQueens(int A){
    vector<vs> s;
    vs v(A);
    string g = "";
    for(int i = 0 ; i < A; i++){
        g = g+".";
    }
    for(int i = 0 ; i < A; i++){
        v[i] = g;
    }
    solve(s,v,0,A);
    return s;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
for(auto x : S->solveNQueens(8)){
    pvs(x);
}


return 0 ;
}