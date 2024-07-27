#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    static constexpr int CHAR_COUNT = 26;
    static constexpr int INF = 1e9;

    std::vector<std::vector<int>> buildConversionGraph(const std::vector<char>& originalChars, const std::vector<char>& changedChars, const std::vector<int>& conversionCosts) {
        std::vector<std::vector<int>> graph(CHAR_COUNT, std::vector<int>(CHAR_COUNT, INF));
        for (int i = 0; i < CHAR_COUNT; i++) {
            graph[i][i] = 0;
        }
        for (size_t i = 0; i < conversionCosts.size(); i++) {
            int from = originalChars[i] - 'a';
            int to = changedChars[i] - 'a';
            graph[from][to] = std::min(graph[from][to], conversionCosts[i]);
        }
        return graph;
    }

    void optimizeConversionPaths(std::vector<std::vector<int>>& graph) {
        for (int intermediate = 0; intermediate < CHAR_COUNT; intermediate++) {
            for (int start = 0; start < CHAR_COUNT; start++) {
                if (graph[start][intermediate] < INF) {
                    for (int end = 0; end < CHAR_COUNT; end++) {
                        if (graph[intermediate][end] < INF) {
                            graph[start][end] = std::min(graph[start][end], graph[start][intermediate] + graph[intermediate][end]);
                        }
                    }
                }
            }
        }
    }

    long long computeTotalConversionCost(const std::string& source, const std::string& target, const std::vector<std::vector<int>>& graph) {
        long long totalCost = 0;
        for (size_t i = 0; i < source.length(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';
            if (sourceChar != targetChar) {
                if (graph[sourceChar][targetChar] == INF) {
                    return -1;
                }
                totalCost += graph[sourceChar][targetChar];
            }
        }
        return totalCost;
    }

public:
    long long minimumCost(std::string source, std::string target, std::vector<char>& originalChars, std::vector<char>& changedChars, std::vector<int>& conversionCosts) {
        auto conversionGraph = buildConversionGraph(originalChars, changedChars, conversionCosts);
        optimizeConversionPaths(conversionGraph);
        return computeTotalConversionCost(source, target, conversionGraph);
    }
};