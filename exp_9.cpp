#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// Function to calculate the total distance of a tour
int calculateTourDistance(const vector<int> &tour, const vector<vector<int>> &graph)
{
    int distance = 0;
    int n = tour.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int from = tour[i];
        int to = tour[i + 1];
        distance += graph[from][to];
    }
    // Return to the starting city
    distance += graph[tour[n - 1]][tour[0]];
    return distance;
}
// Brute force TSP solver
vector<int> tspBruteForce(const vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> tour(n);
    // Initialize the tour with cities in order (0, 1, 2, ..., n-1)
    for (int i = 0; i < n; ++i)
    {
        tour[i] = i;
    }
    int minDistance = INT_MAX;
    vector<int> bestTour;
    // Generate all possible permutations of the tour
    do
    {
        int currentDistance = calculateTourDistance(tour, graph);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            bestTour = tour;
        }
    } while (next_permutation(tour.begin() + 1, tour.end()));
    return bestTour;
}
int main()
{
    int n = 4; // Number of cities
    // Define the adjacency matrix representing the distances between cities
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    vector<int> optimalTour = tspBruteForce(graph);
    cout << "Optimal Tour: ";
    for (int city : optimalTour)
    {
        cout << city << " ";
    }
    cout << endl
         << "Minimum Distance: " << calculateTourDistance(optimalTour, graph) << endl;
    return 0;
}