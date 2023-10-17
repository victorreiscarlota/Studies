/**
 * Problem that I'm still not able to solve by myself
 * 
 * 
 * Question: 
 * You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
 * If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.
*/



//Stack Overflow user iteration of the code (still not able to fully grasp the solution even after searching)


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

int main(){
class Solution {
public:
    bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild) {
        std::unordered_map<int, std::vector<int>> graph;
        std::vector<int> in_degree(n, 0);

        // Step 1: Build the graph and calculate in-degrees
        for (int node = 0; node < n; ++node) {
            int left = leftChild[node];
            int right = rightChild[node];
            if (left != -1) {
                graph[node].push_back(left);
                in_degree[left]++;
            }
            if (right != -1) {
                graph[node].push_back(right);
                in_degree[right]++;
            }
        }

        // Step 2: Check for valid root candidates
        std::vector<int> root_candidates;
        for (int node = 0; node < n; ++node) {
            if (in_degree[node] == 0) {
                root_candidates.push_back(node);
            }
        }

        if (root_candidates.size() != 1) {
            return false; // There should be exactly one root
        }

        int root = root_candidates[0];

        // Step 3: BFS traversal to check for cycles
        std::queue<int> q;
        std::unordered_set<int> seen;
        q.push(root);
        seen.insert(root);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (graph.find(node) != graph.end()) {
                for (int child : graph[node]) {
                    if (seen.find(child) != seen.end()) {
                        return false; // Cycle detected
                    }
                    seen.insert(child);
                    q.push(child);
                }
            }
        }

        // Step 4: Check if all nodes are visited
        return seen.size() == static_cast<std::unordered_set<int>::size_type>(n);

    }
};
return 0;
};