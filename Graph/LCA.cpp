#include <bits/stdc++.h>//ABC-294-G
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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

int op(int a,int b){
    return min(a,b);
}
int rmq_e(){
    return 1e9;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<Edge>> g(n);
    rep(i,n-1){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        g[a].emplace_back(b,c,i);
        g[b].emplace_back(a,c,i);
    }
    vector<int> et;
    vector<int> in(n),ein(n-1),eout(n-1), ew(n-1);
    auto dfs = [&](auto dfs, int v, int p=-1) ->void {
        in[v]=et.size();
        et.push_back(v);
        for(auto e: g[v]){
            if(e.to == p) continue;
            ein[e.id] =et.size()-1;
            ew[e.id] =e.cost;
            dfs(dfs, e.to, v);
            eout[e.id] = et.size()-1;
            et.push_back(v);
        }
    };
    dfs(dfs,0);
    segtree<int,op,rmq_e> rmq(et.size());
    rep(i,et.size()) rmq.set(i,in[et[i]]);
    fenwick_tree<ll> d(et.size());
    rep(i,n-1) d.add(ein[i],ew[i]);
    rep(i,n-1) d.add(eout[i], -ew[i]);
    
    int q;
    cin>>q;
    rep(qi,q){
        int type,a,b;
        cin>>type>>a>>b;
        if(type==1){
            a--;
            int dif=b-ew[a];
            ew[a]=b;
            d.add(ein[a],dif);
            d.add(eout[a], -dif);
        }
        else{
            a--;
            b--;
            int l=in[a],r=in[b];
            if(l>r) swap(l,r);
            int c=et[rmq.prod(l,r+1)];
            ll ans=0;
            if(a!=c) ans+=d.sum(in[c],in[a]);
            if(b!=c) ans+=d.sum(in[c],in[b]);
            cout<<ans<<endl;
            
        }
    }
    

}