#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 31000
#define MAX_DIST 1e20

struct vertex {
    int x, y, z;
} vertices[MAX];

struct edge {
    int x, y;
} edges[MAX];

double euclid(vertex a, vertex b){
    double dx = pow(a.x - b.x, 2);
    double dy = pow(a.y - b.y, 2);
    double dz = pow(a.z - b.z, 2);
    double dist = sqrt(dx + dy + dz);
    return dist;
}

int difficulty(vertex a, vertex b){
     if(a.z >= b.z) return 0;
     double dx = pow(a.x - b.x, 2);
     double dy = pow(a.y - b.y, 2);
     return (int)(100*(b.z-a.z)/sqrt(dx+dy));
}

vector<double> search(int start, int n, vector<int> graph[]){
    queue<int> q;
    vector<double> dist(n+1,MAX_DIST);
    bool visited[n+1];

    // Initialise distances
    for(int i = 1; i <= n; ++i) visited[i] = false;

    dist[start] = 0;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        visited[curr] = false;

        for(int i = 0; i < graph[curr].size(); ++i){
            int next = graph[curr][i];
            double distance = euclid(vertices[curr],vertices[next]);
            if (dist[next] > dist[curr]+ distance){
                dist[next] = dist[curr]+distance;
                if (!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    return dist;
}

int main(){

    int N, M;
    while(scanf("%d %d", &N, &M) && (N > 0 || M > 0)){

        vector<int> graph1[MAX];
        vector<int> graph2[MAX];

        for(int i = 1; i <= N; ++i) {
            scanf("%d %d %d", &vertices[i].x, &vertices[i].y, &vertices[i].z);
        }

        for(int i = 0; i < M; ++i){
            scanf("%d %d", &edges[i].x, &edges[i].y);
        }

        int start, end, diff;
        scanf("%d %d %d", &start, &end, &diff);

        vector<edge> candidates;

        for(int i = 0; i < M; ++i){

            vertex point1 = vertices[edges[i].x];
            vertex point2 = vertices[edges[i].y];

            double diff1 = difficulty(point1, point2);
            double diff2 = difficulty(point2, point1);

            if(diff1 == diff) candidates.push_back(edges[i]);
            if(diff2 == diff) {
                edge e;
                e.x = edges[i].y;
                e.y = edges[i].x;
                candidates.push_back(e);
            }

            if(diff1 <= diff) {
                graph1[edges[i].x].push_back(edges[i].y);
                graph2[edges[i].y].push_back(edges[i].x);
            }
            if(diff2 <= diff) {
                graph1[edges[i].y].push_back(edges[i].x);
                graph2[edges[i].x].push_back(edges[i].y);
            }
        }

        vector<double> fromStart = search(start, N, graph1);
        vector<double> fromEnd = search(end, N, graph2);

        double minimum = MAX_DIST;
        for (int i = 0; i < candidates.size(); ++i){
            edge candidate = candidates[i];
            vertex edgeStart = vertices[candidate.x];
            vertex edgeEnd = vertices[candidate.y];
            double edgeDist = euclid(edgeStart,edgeEnd);
            double totalDist = fromStart[candidate.x] + edgeDist + fromEnd[candidate.y];
            if(fromStart[candidate.x] < MAX_DIST && fromEnd[candidate.y] < MAX_DIST)minimum = min(minimum,totalDist);
        }
        (fabs(minimum - MAX_DIST) < 1e-6) ? printf("None\n") : printf("%.3f\n", minimum);
    }
}
