#include "job.h"
#include <vector>  
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// a) -- check that the sequence of programming jobs in the vector of pairs is possible.
// perform a depth first search containing three sets, white(unvisited,0), grey(visiting,1), and black(visited,2)

bool dfs(vector<vector<int>> &matrix, vector<int> &white, int i) {
    // if white[i] == 1, we have a duplicate neighbor/parent in the grey set, meaning a cycle.
    if(white[i]){
         return white[i] == 2;
    }

    // label index in grey set (currently visiting)
    white[i] = 1;

    for(auto next:matrix[i]) // loop through the pair
        if(!dfs(matrix, white, next)) return false;

    // label appropriate index in black set as visited
    white[i] = 2;
    return true;
}

bool canFinish(int n, vector<pair<int, int>> &dependencies) { 
    // start with initializing # vertices (jobs) in an adjacency matrix
    vector<vector<int>> matrix(n+1);
    
    for(int i = 0;i < dependencies.size();i++){
        matrix[dependencies[i].first].push_back(dependencies[i].second); // populate index @job1 with corresponding dependency job2
    }

    // instantiate the white set for all unvisited nodes to 0
    vector<int> white(n+1, 0);

    for(int i = 0; i < n; i++){
        if(!white[i]) // for every 0, perform dfs with appropriate index
            if(!dfs(matrix, white, i)){
                return false;
            }
    }
    return true;
}

/*
void numberdependencies(int n, vector<vector<int>> &matrix, vector<bool> &compstack, int originalnext){
    
    for (int step = 0; step < n; step++){
        for (auto next : matrix[step]){
            if (next == originalnext){
                compstack[step] = 1; // mark a dependency as found
                numberdependencies(n, matrix, compstack, step);
            }
        }
    }
}
*/

int counter = 1;

void numberdependencies(int n, vector<vector<int>> &matrix, vector<int> &compstack, int originalnext){
    
    for (int step = 0; step < n; step++){
        for (auto next : matrix[step]){
            if (next == originalnext){ // if you have reached j's dependency
                if(compstack[step] == 0){ // if the dependency does not exist yet
                    counter++;
                }
                compstack[step] = 1; // mark a dependency as found
                numberdependencies(n, matrix, compstack, step);
            }
        }
    }
}

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i) {

    // init counter locally
    counter = 1;

    // start with initializing # vertices (jobs) in an adjacency matrix
    vector<vector<int>> matrix(n + 1);

    for (int i = 0; i < dependencies.size(); i++){
        matrix[dependencies[i].first].push_back(dependencies[i].second);
    }

    // create a vector "stack", later used to determine the connectivity of vertices
    vector<int> compstack(n + 1, 0);

    for(int step = 0; step < n; step++){
        for(auto next: matrix[step]){
            if(next == j){
                if(compstack[step] == 0){ // if the dependency does not exist yet
                    counter++;
                }
                compstack[step] = 1; // mark dependency as found    
                numberdependencies(n, matrix, compstack, step);
            }
        }
    }

    return (i >= counter) ? true : false;
}