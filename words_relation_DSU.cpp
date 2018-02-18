#include <bits/stdc++.h>
using namespace std;
int size[1000000],par[1000000];
void initialize(int N){
	for(int i = 0; i < N; i++){
		par[i] = i;
		size[i] = 1;
	}
}
int root (int i){
	while(par[i] != i){
		par[i] = par[par[i]] ;
		i = par[i];
	}
	return i;
}
void _union(int A,int B){
	int root_A = root(A);
	int root_B = root(B);
	if(size[root_A] < size[root_B]){
		par[root_A] = par[root_B];
		size[root_B] += size[root_A];
	}else{
		par[root_B] = par[root_A];
		size[root_A] += size[root_B];
	}

}
bool find(int A,int B){
	if(root(A)==root(B)) return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	initialize(1000000);
	int n,m,q; cin >> n >> m >> q;
	map<string,int> mp;
	for(int i = 0 ; i < n ; i++){
		string s; cin >> s;
		mp[s] = i;
	}
	while(m--){
		int t; string a,b; cin >> t >> a >> b;
		if(t == 1){
			if(find(mp[a],mp[b]+n)){
				puts("NO");
				continue;
			}
			_union(mp[a],mp[b]);
			_union(mp[a]+n,mp[b]+n);
		}else{
			if(find(mp[a],mp[b])){
				puts("NO");
				continue;
			}
			_union(mp[a],mp[b]+n);
			_union(mp[a]+n,mp[b]);
		}
		puts("YES");
	}
	while(q--){
		string a,b; cin >> a >> b;
		if(find(mp[a],mp[b])) puts("1");
		else if(find(mp[a],mp[b]+n)) puts("2");
		else puts("3");
	}
}
