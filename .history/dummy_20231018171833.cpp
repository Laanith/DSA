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
#define umapii unordered_map<int,int>
#define vvi vector<vector<int>>
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}
void ps(string A){cout<<A<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



/*!SECTION : Problem Description ::


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minGlassesRequired(const vector<int> &arrivals, const vector<int> &departures)
{
    int platformsNeeded = 0;
    int maxPlatforms = 0;

    int i = 0; // Pointer for arrivals
    int j = 0; // Pointer for departures

    while (i < arrivals.size() && j < departures.size())
    {
        if (arrivals[i] < departures[j])
        {
            platformsNeeded++;
            maxPlatforms = max(maxPlatforms, platformsNeeded);
            i++;
        }
        else
        {
            platformsNeeded--;
            j++;
        }
    }

    return maxPlatforms;
}

int main()
{
    vector<int> arrivals = {900, 930, 1000, 1030, 1100};
    vector<int> departures = {1000, 1030, 1100, 1130};

    int minGlasses = minGlassesRequired(arrivals, departures);
    cout << "Minimum glasses required: " << minGlasses << endl;

    return 0;
}