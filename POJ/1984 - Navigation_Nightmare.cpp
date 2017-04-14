#include <cstdio>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

struct Vertex {
    int parent, distx, disty;
} vertex[40001];

struct Edge {
    int start, end, dist;
    char dir;
} edge[40001];

struct Query {
    int start, end, time, id, res;
} query[10001];

bool comparator1 (Query q1, Query q2) { return q1.time < q2.time; }
bool comparator2 (Query q1, Query q2) { return q1.id < q2.id; }

int findCompress(int a){
    if (a == vertex[a].parent) return a;
    int parent = findCompress(vertex[a].parent);
    vertex[a].distx += vertex[vertex[a].parent].distx;
    vertex[a].disty += vertex[vertex[a].parent].disty;
    vertex[a].parent = parent;
    return parent;
}

void makeUnion(Edge e){
    int x = findCompress(e.start);
    int y = findCompress(e.end);
    //cout << x << " " << y << endl;

    if (x != y){
        int dx = 0;
        int dy = 0;

        if (e.dir == 'N'){
            dy = e.dist;
        }
        else if(e.dir == 'E'){
            dx = e.dist;
        }
        else if(e.dir == 'S'){
            dy = -e.dist;
        }
        else if(e.dir == 'W'){
            dx = -e.dist;
        }

        vertex[y].parent = x;
        vertex[y].distx = vertex[e.start].distx - vertex[e.end].distx + dx;
        vertex[y].disty = vertex[e.start].disty - vertex[e.end].disty + dy;
    }
}

int main(){
    int num, lines, queries;

    // Read all edges
    scanf("%d %d", &num, &lines);
    for (int i = 1; i <= lines; ++i){
        scanf("%d %d %d %c", &edge[i].start, &edge[i].end, &edge[i].dist, &edge[i].dir);
        vertex[edge[i].start].parent = edge[i].start;
        vertex[edge[i].start].distx = 0;
        vertex[edge[i].start].disty = 0;
        vertex[edge[i].end].parent = edge[i].end;
        vertex[edge[i].end].distx = 0;
        vertex[edge[i].end].disty = 0;
    }

    // Read all queries
    scanf("%d", &queries);
    for (int i = 0; i < queries; ++i){
        scanf("%d %d %d", &query[i].start, &query[i].end, &query[i].time);
        query[i].id = i;
    }

    // Process Queries
    sort(query, query+queries, comparator1);
    for(int i = 0, j = 1; i < queries; ++i){
        Query q = query[i];
        for(; j <= q.time; ++j){
            makeUnion(edge[j]);
        }
        int x = findCompress(q.start);
        int y = findCompress(q.end);
        if (x == y){
            int diffx = abs(vertex[q.start].distx - vertex[q.end].distx);
            int diffy = abs(vertex[q.start].disty - vertex[q.end].disty);
            query[i].res = diffx + diffy;
        }
        else{
            query[i].res = -1;
        }
    }

    sort(query, query+queries, comparator2);

    for(int i = 0; i < queries; ++i){
        printf("%d\n", query[i].res);
    }
    /*
    for(int i = 1; i <= 7; ++i){
        printf("%d -> %d, diffx:%d diffy:%d\n", i, vertex[i].parent, vertex[i].distx, vertex[i].disty);
    }
    */

    return 0;
}
