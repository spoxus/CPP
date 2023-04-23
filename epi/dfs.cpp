#include <memory>
#include "dfs.h"

using namespace std;

bool canTeamABeatTeamB(const vector<MatchResult>& matches,
                       const string& team_a,
                       const string& team_b) {
    return isReachableDFS(buildGraph(matches),
                          team_a,
                          team_b,
                          make_unique<unordered_set<string>>().get());
}

unordered_map<string, unordered_set<string>>
buildGraph(const vector<MatchResult>& matches) {
    unordered_map<string, unordered_set<string>> graph;
    for (const MatchResult& match : matches) {
        graph[match.winning_team].emplace(match.losing_team);
    }
    return graph;
}

bool isReachableDFS(const unordered_map<string, unordered_set<string>>& graph,
                    const string& curr,
                    const string& dest,
                    unordered_set<string>* visited_ptr) {
    unordered_set<string>& visited = *visited_ptr;
    if (curr == dest) {
        return true;
    } else if (visited.find(curr) != visited.end() ||
               graph.find(curr) == graph.end()) {
        return false;
    }
    visited.emplace(curr);
    for (const string& team : graph.at(curr)) {
        if (isReachableDFS(graph, team, dest, visited_ptr)) {
            return true;
        }
    }
    return false;
}

GraphVertex* cloneGraph(GraphVertex* G) {
    if (!G) return nullptr;
    unordered_map<GraphVertex*, GraphVertex*> vertex_map;
    queue<GraphVertex*> q;
    q.emplace(G);
    vertex_map.emplace(G, new GraphVertex({G->label}));
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (GraphVertex* e : v->edges) {
            if (vertex_map.find(e) == vertex_map.end()) {
                vertex_map.emplace(e, new GraphVertex({e->label}));
                q.emplace(e);
            }
            vertex_map.[v]->edges.emplace_back(vertex_map);
        }
    }
    return vertex_map[G];
}
int main() {}