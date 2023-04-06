#include <bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
//using namespace atcoder;
#define all(a) a.begin(),a.end()
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
const ll INF=1LL<<60;
const ll MOD = 1e9 + 7;
using Graph = vector<vector<int>>;
template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }

struct Edge {
    int to,cost,id;
    Edge() {};
    Edge(int to,int cost,int id): to(to),cost(cost), id(id) {}
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    vector<vector<Edge>> g(n);
    rep(i,n){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        g[a].emplace_back(b,c,i);
        g[b].emplace_back(a,c,i);
    }
    cout<<g[1][0].cost<<endl;
    

}