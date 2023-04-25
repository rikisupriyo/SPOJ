#include <bits/stdc++.h>
using namespace std;

/* functions */

#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define SQ(a) (a)*(a)
#define rep(i,a,b) for (int i=a; i<b; i++)
#define crep(i,a,b) for (int i=a; i<=b; i++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

/* types */

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define vl vector<long long>
#define vvl vector<vl>
#define vc vector<char>
#define vvc vector<vc>
#define vs vector<string>
#define vb vector<bool>
#define vvb vector<vb>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

/* utils */


void yes() {cout<<"YES\n";}
void no() {cout<<"NO\n";}

void setIO() {
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

/* constants */

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const int INF = 1e9+10;

bool vis[8][8];
int lvl[8][8]; 

int getX(string s) {return s[0] - 'a';}
int getY(string s) {return s[1] - '1';}

vpii moves = {{2, -1}, {2, 1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}};

bool isValid(int x, int y) {return x>=0 && y>=0 && x<8 && y<8;}

int bfs(string s, string d) {
	int sX = getX(s), sY = getY(s);
	int dX = getX(d), dY = getY(d);

	queue<pii> q;
	q.push({sX, sY});
	vis[sX][sY] = true;
	lvl[sX][sY] = 0;
	while(!q.empty()) {
		pii u = q.front(); q.pop();

		for(auto move:moves) {
			int cX = u.f + move.f; int cY = u.s + move.s;

			if(!isValid(cX, cY)) continue;
			if(!vis[cX][cY]) {
				q.push({cX, cY});
				vis[cX][cY] = true;
				lvl[cX][cY] = lvl[u.f][u.s] + 1;
			}
		}
		if(lvl[dX][dY] != INF) break;
	}
	return lvl[dX][dY];
}

void solve(){
	string s1, s2;
	cin>>s1>>s2;
	cout<<bfs(s1, s2)<<"\n";
}

void reset() {
	rep(i,0,8) {
		rep(j,0,8) {
			lvl[i][j] = INF;
			vis[i][j] = false;
		}
	}
}

int main(){
	
	setIO();

	int t;
	cin>>t;

	while(t--){
		reset();
		solve();
	}
	
	return 0;
}