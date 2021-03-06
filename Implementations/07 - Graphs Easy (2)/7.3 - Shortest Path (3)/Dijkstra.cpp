/**
* Description: shortest path!
* Works with negative edge weights (aka SPFA?)
*/

template<int SZ> struct Dijkstra {
    int dist[SZ];
    vector<pi> adj[SZ];
    priority_queue<pi,vector<pi>,greater<pi>> q;
    
    void gen() {
        fill_n(dist,SZ,MOD); dist[0] = 0; 
	
    	q.push({0,0});
    	while (q.size()) {
    		pi x = q.top(); q.pop();
    		if (dist[x.s] < x.f) continue;
    		for (pi y: adj[x.s]) if (x.f+y.s < dist[y.f]) {
    			dist[y.f] = x.f+y.s;
    			q.push({dist[y.f],y.f});
    		}
    	}
    }
};

Dijkstra<100> D;

int main() {
	F0R(i,100) F0R(j,100) if (rand() % 10 == 0) D.adj[i].pb({j,rand() % 10+1});
	D.gen();
	F0R(i,100) cout << D.dist[i] << "\n";
}
