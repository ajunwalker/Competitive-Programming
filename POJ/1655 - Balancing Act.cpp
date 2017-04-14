#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 20001
vector <int> node[MAX_SIZE];
bool visited[MAX_SIZE];
int score[MAX_SIZE];

int dfs(int a, int size){
    visited[a] = true;
    int total_subtree = 1;
    int max_subtree = 0;
    for(int i = 0; i < node[a].size(); ++i){
        if (!visited[node[a][i]]) {
            int subtree_size = dfs(node[a][i], size);
            max_subtree = max(max_subtree, subtree_size);
            total_subtree += subtree_size;
        }
    }
    score[a] = max(max_subtree, size-total_subtree);
    return total_subtree;
}

int main(){
    int cases, num;
    cin >> cases;

    while(cases--){
        cin >> num;

        for(int i = 0; i < MAX_SIZE; ++i){
            visited[i] = false;
            node[i].clear();
        }

        for(int i = 0; i < num-1; ++i){
            int start, end;
            cin >> start >> end;
            node[start].push_back(end);
            node[end].push_back(start);
        }

        int ind = - 1;
        int balance = -1;
        dfs(1, num);
        for(int i = 1; i < num; ++i){
            if (balance == -1 || score[i] < balance){
                ind = i;
                balance = score[i];
            }
        }
        cout << ind << " " << balance << endl;
    }

}
