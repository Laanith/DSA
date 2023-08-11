#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::
You are given two numbers represented as integer arrays A and B, where each digit is an element.
 You have to return an array which representing the sum of the two given numbers.

The last element denotes the least significant bit, and the first element denotes the most significant bit.

Note : Array A and Array B can be of different size. ( i.e. length of Array A may not be equal to length of Array B ).
*/

class Solution{
public :
    vi AddArrays(vi A, vi B);
};

vi Solution::AddArrays(vi A, vi B){
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    vi C;
    int borrow = 0;
    int mini = min(A.size(), B.size());
    for (int i = 0; i < mini; i++){
        int sum = A[i] + B[i] + borrow;
        if(sum >= 10) {
            borrow = sum / 10;
            C.push_back(sum % 10);
        }
        else
            C.push_back(sum % 10);
    }

    if(A.size() < B.size()){
        for (int i = mini; i < B.size(); i++){
            int sum = B[i]+borrow;
            if(sum>=10 ){
                borrow = sum / 10;
                C.push_back(sum % 10); 
            }
            else
                C.push_back(sum);
        }
    }
    else {
        for (int i = mini; i < A.size(); i++)
        {
            int sum = A[i] + borrow;
            if (sum >= 10)
            {
                borrow = sum / 10;
                C.push_back(sum % 10);
            }
            else
                C.push_back(sum);
        }
    }

    if(borrow)
        C.push_back(borrow);

    reverse(C.begin(), C.end());
    return C;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vi A = {1, 2, 3};
vi B = {1,0,0,0};
for(auto x : S->AddArrays(A,B)){
        cout << x << " ";
}

return 0 ;
}