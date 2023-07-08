#include <iostream>
#include <string>
#include <chrono>
#include <limits>
#include <unordered_set>
#include "Graph.h"

/* Macro to explicity print tests that are run along with colorized result. */
#define TEST(EX) (void)((fprintf(stdout, "(%s:%d) %s:", __FILE__, __LINE__,\
                 #EX)) && ((EX && fprintf(stdout, "\t\x1b[32mPASSED\x1b[0m\n"))\
                 || (fprintf(stdout, "\t\x1b[31mFAILED\x1b[0m\n")) ))

bool compare(const double& d1, const double& d2) {
    return std::abs(d1 - d2) <= std::numeric_limits<double>::epsilon();
}

int main() {
    Graph graph("example/small.csv");
    auto n = graph.nodes();
    TEST(graph.nodes() == unordered_set<string>({"A", "B", "C", "D", "E", "F", "G"}));
    TEST(graph.num_nodes() == 7);
    TEST(graph.edge_weight("A", "B") == 1);
    TEST(graph.num_edges() == 6);

    vector<tuple<string, string, int>> result {{"A", "B", 1}, {"B", "C", 1}};
    auto start = std::chrono::steady_clock::now();
    TEST(graph.shortest_path_weighted("A", "C") == result);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    TEST(elapsed.count() <= 1000.0); // microseconds

    start = std::chrono::steady_clock::now();
    TEST(graph.smallest_connecting_threshold("A", "C") == 1);
    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    TEST(elapsed.count() <= 1000.0); // microseconds
}
