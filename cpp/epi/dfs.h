#ifndef DFS_H
#define DFS_H

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct GraphVertex {
    vector<GraphVertex*> edges;
    int max_distance = 1;
    bool visited = false;
    int id;
    int label;
    const GraphVertex* predecessor = nullptr;
    struct DistanceWithFewestEdges {
        int distance;
        int min_number_edges;
    };
    DistanceWithFewestEdges distance_with_fewest_edges =
        DistanceWithFewestEdges{numeric_limits<int>::max(), 0};
    
    struct VertexWithDistance {
        GraphVertex& vertex;
        int distance;
    };
    vector<VertexWithDistance> edges_with_distance;

    struct Comp {
        bool operator()(const GraphVertex* lhs, const GraphVertex* rhs) {
            return lhs->distance_with_fewest_edges.distance <  rhs->distance_with_fewest_edges.distance ||
                  (lhs->distance_with_fewest_edges.distance == rhs->distance_with_fewest_edges.distance &&
                   lhs->distance_with_fewest_edges.min_number_edges < rhs->distance_with_fewest_edges.min_number_edges);
        }
    };
};

GraphVertex* cloneGraph(GraphVertex* G);

struct MatchResult {
    string winning_team, losing_team;
};

bool canTeamABeatTeamB(const vector<MatchResult>& matches,
                       const string& team_a,
                       const string& team_b);

unordered_map<string, unordered_set<string>>
buildGraph(const vector<MatchResult>& matches);

bool isReachableDFS(const unordered_map<string, unordered_set<string>>& graph,
                    const string& curr,
                    const string& dest,
                    unordered_set<string>* visited_ptr);

#endif