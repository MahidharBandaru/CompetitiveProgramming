// Idea : Found a recurrence to find the number of binary search trees with nodes from 1 to n and height strictly
// less than h. Let this be dp[n][h]. Found another recurrence to find total number of binary search trees with 
// nodes from 1 to n. Let this be total[n]. Answer is total[n] - dp[n][h]. 
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pb(x) push_back(x)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define Forp(i,s,e) for (ll i = s; i <= e; i++)
#define Forn(i,s,e) for (ll i = s; i >= e; i--)


#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<p.f<<" "<<p.s;return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
unsigned long long less1[36][36];
unsigned long long total[36];
int main(){_
    ll n,h;
    cin >> n >> h;
    for(ll l = 1 ; l <= n ; l++){
        if(l == 1){
            total[l] = 1;
        }
        else{
            for(ll i = 1 ; i <= l ; i++){
                if(i == 1 || i == l){
                    total[l]+=(total[l-1]);
                }
                else{
                    total[l]+=(total[i-1]*total[l-i]);
                }
            }
        }
    }
    for(ll l = 1; l <= n ; l++){
        for(ll i = 1 ; i <= n ; i++){
            if(i <= l){
                if(l == 1){
                    if(i != 1){
                        less1[l][i] = 1;
                    }
                }
                else{
                    for(ll k = 1 ; k < l ; k++){
                        if(k == 1){
                            less1[l][i]+=less1[l-1][i-1];
                        }
                        else{
                            less1[l][i]+=(less1[k-1][i-1]*less1[l-k][i-1]);
                        }
                    }
                    less1[l][i]+=less1[l-1][i-1];
                }
            }
            else{
                less1[l][i] = total[l];
            }
            
            // cout << "less1[l][i] for " << "l = " << l << " i = " << i << " = " << less1[l][i] << endl;
        }
    }
    
    // cout << "total = " << total[n] << endl;
    // cout << "less = " << less1[n][h] << endl;

    cout << total[n]-less1[n][h] << endl;

    return 0;

}