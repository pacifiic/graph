#include <iostream>
#include <list>
#include <vector>

using namespace std;
class undi_graph {
    int vNum;
    vector< vector<int> > neighbors;
public:
    undi_graph(const int& num, const vector< vector<int> > &edges);
    void visitAction(const int &v);
    void bfs(void);
    void dfs(const int& mode);
    void dfs_help(const int& mode, const int& v, vector<bool> &visited);
};

undi_graph::undi_graph(const int& num, const vector< vector<int>> &edges)
        : neighbors(num, vector<int>(0)) {
    vNum = num;
    for (int i=0; i<edges.size(); i++) {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
}

void undi_graph::visitAction(const int& v) {
    cout << v << " ";
}

void undi_graph::bfs(void) {
    vector<bool> visited(vNum, false);
    list<int> q;
    for (int v=0; v<vNum; v++) {
        q.push_back(v);
        int currV;
        while(!q.empty()) {
            currV = q.front();
            q.pop_front();

            if (!visited[currV]) {
                visited[currV] = true;
                visitAction(currV);
                for (const int& n: neighbors[currV]) {
                    q.push_back(n);
                }
            }
        }
    }
}
void undi_graph::dfs(const int& mode) {
    vector<bool> visited(vNum, false);
    for (int v=0; v<vNum; v++) {
        dfs_help(mode, v, visited);
    }
}
void undi_graph::dfs_help(const int &mode, const int &v, vector<bool> & visited) {
    if (!visited[v]) {
        visited[v] = true;
        if (mode==0) {
            visitAction(v);
        }
        for (const int & n : neighbors[v]) {
            dfs_help(mode, n, visited);
        }
        if (mode==1) {
            visitAction(v);
        }
    }
}
int main(void) {
    int myVNum = 10;
    vector< vector<int> > myEdges{{0,1}, {1,4}, {1,5}, {2,3}, {4,6}, {5,6}, {5,7}, {6,9}, {7,8}};
    undi_graph myGraph(myVNum, myEdges);
    cout << "[BFS] ";
    myGraph.bfs();
    cout << endl;

    cout << "[DFS preorder] ";
    myGraph.dfs(0);
    cout << endl;

    cout << "[DFS postorder] ";
    myGraph.dfs(1);
    cout << endl;

    return 0;
}
