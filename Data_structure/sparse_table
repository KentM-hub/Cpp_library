#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define all(a) a.begin(),a.end()
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF=1000000005;
const ll MOD = 998244353;
using mint = atcoder::modint998244353;
using Graph = vector<vector<int>>;
template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }

int main() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> vec;
    map<pair<ll,ll>,ll> mp;
    ll b=1;
    while(b<=n){
        for(int i=1;i<=n;i++){
            if(i+b-1>n) break;
            vec.push_back({i,i+b-1});
        }
        b*=2;
    }
    for(int i=0;i<vec.size();i++){
        mp[vec[i]]=i+1;
    }
    cout<<vec.size()<<endl;
    for(auto e:vec){
        cout<<e.first<<" "<<e.second<<endl;
    }
    ll q;
    cin>>q;
    rep(i,q){
        ll l,r;
        cin>>l>>r;
        ll b=1;
        while(b*2<=r-l+1) b*=2;
        cout<<mp[{l,l+b-1}]<<" "<<mp[{r-b+1,r}]<<endl;
    }


    return 0;
}


