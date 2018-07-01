// #pragma GCC optimize("Ofast")

// Idea : Found a closed form formula to find the number of squares in a matrix of size m*n. 
//        Used the fact that this formula should equate to k to get a condition.
//        Found that for the given bounds it is enough to iterate till 1e7 to find all possible solutions.

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
    using namespace std;
    int main(){
        ll k;
        cin >> k;
        stack<pll> s;
        vector<pll> ans;
        bool flag = true;
        for(ll i = 1 ; i <= 10000000 ; i++){
            ll n = i;
            ll num = 6*k + n*n*n - n;
            ll den = 3*n*n + 3*n;
            if(num%den == 0){
                ll m = num/den;
                if(n > m){
                    flag = false;
                    break;
                }
                else if(n == m){
                    ans.push_back(make_pair(i,num/den));
                }
                else{
                    ans.push_back(make_pair(i,num/den));
                    s.push(make_pair(num/den,i));
                }
            }
        }
        cout << ans.size() + s.size() << endl;
        for(ll i = 0 ; i < ans.size() ; i++){
            cout << ans[i].f << " " << ans[i].s << endl;
        }
        while(!s.empty()){
            pll t = s.top();
            cout << t.f << " " << t.s << endl;
            s.pop();
        }
		return 0;
            
    }