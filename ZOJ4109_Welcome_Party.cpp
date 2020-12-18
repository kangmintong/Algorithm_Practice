#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
vector<int> g[maxn];
int p[maxn],vis[maxn],ans[maxn],use[maxn];
int t,n,m,cur,res;
int x,y,kas;
void bfs(int s) {
	queue<int> pq;
	pq.push(s);
	vis[s] = kas;
	while(!pq.empty()) {
		int top = pq.front();
		pq.pop();
		for(int i = 0; i < g[top].size(); i++) {
			int v = g[top][i];
			if(vis[v] != kas) {
				pq.push(v);
				vis[v] = kas;
			}
		}
	}
}
priority_queue<int,vector<int>,greater<int> > pq;
int main() {
	scanf("%d",&t);
	kas = 0;
	while(t--) {
		kas++;
		cur = 0;
		res = 0;
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);	
		}
		for(int i = 1; i <= n; i++) {
			if(vis[i] != kas) {
				bfs(i);
				use[i] = kas;
				pq.push(i);
				res++;
			}
		}
		while(!pq.empty()) {
			int top = pq.top();
			pq.pop();
			ans[++cur] = top;
			for(int i = 0; i < g[top].size(); i++) {
				int v = g[top][i];
				if(use[v] != kas) {
					pq.push(v);
					use[v] = kas;
				}
			}
		}
		printf("%d\n",res);
		for(int i = 1; i <= n; i++) {
			if(i - 1) printf(" ");
			printf("%d",ans[i]);
		}
		cout << endl;
	}
	return 0;
}

