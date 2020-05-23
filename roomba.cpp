#include "roomba.h"
#include "limits.h"
#include <queue>
#include <vector>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;

class Node {
public:
	Node(int i, int j, int dist, int left, int up, Node* parent, Heading state, Action movement) :
		_i(i), _j(j), _dist(dist), _left(left), _up(up), _parent(parent), _state(state), _movement(movement) {};
public:
	int _i, _j, _dist, _left, _up;
	Node *_parent;
	Heading _state;
	Action _movement;
};


int row_North[] = { -1, 0, 0, 0 };
int col_North[] = { 0, -1, 0, 0 };

int row_South[] = { 0, 0, 0, 1 };
int col_South[] = { 0, 0, 1, 0 };

int col_East[] = { -1, 0, 0, 0 };
int row_East[] = { 0, 0, 1, 0 };

int row_West[] = { 0, 0, 0, -1 };
int col_West[] = { 0, 0, 1, 0 };


bool isValid(grid mat, grid visited, int row, int col)
{
	return (row >= 0) && (row < mat.size()) && (col >= 0) && (col < visited[0].size())
		&& !mat[row][col] && !visited[row][col];
}

void printpath(Node *node, motion_plan &escape_plan) {
	if (node == NULL) return;
	if (node->_movement == go_straight) {
		escape_plan.push_back(go_straight);
	}
	if (node->_movement == go_left) {
		escape_plan.push_back(go_left);
	}
	printpath(node->_parent, escape_plan);
}



motion_plan escape_route(grid const &M, coordinate init_coordinate, Heading init_heading) {

	// pushing back peripherals to check later
	vector<coordinate> peripherals;
	std::vector<Action> escape_plan;
	escape_plan.clear();
	std::map<int, vector<Action>> plans;
	Heading state = init_heading;

	vector<std::vector<bool>> new_grid(M.size() + 2, std::vector < bool> (M[0].size() + 2, 0));
	for (int i = 1; i < M.size() + 1; i++) {
		for (int j = 1; j < M[0].size() + 1; j++) {
			new_grid[i][j] = M[i - 1][j - 1];
		}
	}

	// top
	for (int i = 1; i < 2; i++) {
		for (int j = 1; j < M.size() + 1; j++) {
			if (new_grid[i][j] == 0) {
				peripherals.push_back(coordinate{ i - 1, j });
			}
		}
	}

	// left side
	for (int i = 1; i < M.size() + 1; i++) {
		for (int j = 1; j < 2; j++) {
			if (new_grid[i][j] == 0) {
				peripherals.push_back(coordinate{ i, j - 1 });
			}
		}
	}
	// bottom
	for (int i = M.size(); i < M.size() + 1; i++) {
		for (int j = 1; j < M[0].size() + 1; j++) {
			if (new_grid[i][j] == 0) {
				peripherals.push_back(coordinate{ i + 1, j  });
			}
		}
	}
	// right side
	for (int i = 1; i < M.size() + 1; i++) {
		for (int j = M.size(); j < M.size() + 1; j++) {
			if (new_grid[i][j] == 0) {
				peripherals.push_back(coordinate{ i, j + 1 });
			}
		}
	}

	for (int z = 0; z < peripherals.size(); z++) {
		
		int x = peripherals[z].first;
		int y = peripherals[z].second;

		int i = init_coordinate.first + 1;
		int j = init_coordinate.second + 1;


		grid visited = new_grid;
		// initially all cells are unvisited
		for (int i = 0; i < visited.size(); i++) {
			for (int j = 0; j < visited[i].size(); j++) {
				visited[i][j] = false;
			}
		}
		// create an empty queue
		queue<Node*> q;

		// need to also set next point to true
		visited[i][j] = true;
		//q.push(&Node({ i, j, 0 , 0 , 0, nullptr, init_heading }));
		Node *node = nullptr;
		// stores length of longest path from source to destination
		int min_dist = INT_MAX;

		Node *n = new Node(i, j, 0, 0, 0, node, state, go_straight);
		q.push(n);

		// run till queue is not empty
		while (!q.empty())
		{
			Node *node = q.front();
			q.pop();

			// (i, j) represents current cell and dist stores its
			// minimum distance from the source
			int i = node->_i, j = node->_j, dist = node->_dist;
			state = node->_state;

			// if destination is found, update min_dist and stop
			if (i == x && j == y)
			{
				min_dist = dist;
				printpath(node, escape_plan);
				vector<Action> output;
				for (int i = 1; i < escape_plan.size() - 1; i++) {
					output.push_back(escape_plan[i]);
				}
				plans.insert(std::pair<int, vector<Action>>(min_dist, output));
				break;
			}

			Action movement;
			for (int k = 0; k < 4; k++)
			{
				// check if it is possible to go to position
				// (i + row[k], j + col[k]) from current position
				if (state == North) {
					if (isValid(new_grid, visited, i + row_North[k], j + col_North[k]))
					{
						// mark next cell as visited and enqueue it
						Heading temp;
						if (row_North[k] != 0) {
							temp = North;
							movement = go_straight;
						}
						if (col_North[k] != 0) {
							temp = East;
							movement = go_left;
						}
						Node *n = new Node(i + row_North[k], j + col_North[k], dist + 1, row_North[k], col_North[k], node, temp, movement);
						visited[i + row_North[k]][j + col_North[k]] = true;
						q.push(n);
					}
				}

				else if (state == South) {
					if (isValid(new_grid, visited, i + row_South[k], j + col_South[k]))
					{
						Heading temp;
						if (row_South[k] != 0) {
							temp = South;
							movement = go_straight;
						}
						if (col_South[k] != 0) {
							temp = West;
							movement = go_left;
						}
						Node *n = new Node(i + row_South[k], j + col_South[k], dist + 1, row_South[k], col_South[k], node, temp, movement);
						visited[i + row_South[k]][j + col_South[k]] = true;
						q.push(n);
					}
				}
				else if (state == East) {
					if (isValid(new_grid, visited, i + row_East[k], j + col_East[k]))
					{
						Heading temp;
						if (row_East[k] != 0) {
							temp = South;
							movement = go_left;
						}
						if (col_East[k] != 0) {
							temp = East;
							movement = go_straight;
						}
						Node *n = new Node(i + row_East[k], j + col_East[k], dist + 1, row_East[k], col_East[k], node, temp, movement);
						visited[i + row_East[k]][j + col_East[k]] = true;
						q.push(n);
					}
				}

				else if (state == West) {
					if (isValid(new_grid, visited, i + row_West[k], j + col_West[k]))
					{
						Heading temp;
						if (row_West[k] != 0) {
							temp = West;
							movement = go_straight;
						}
						if (col_West[k] != 0) {
							temp = North;
							movement = go_left;
						}
						Node *n = new Node(i + row_West[k], j + col_West[k], dist + 1, row_West[k], col_West[k], node, temp, movement);
						visited[i + row_West[k]][j + col_West[k]] = true;
						q.push(n);
					}
				}
			}
		}

		
	}
	auto minKey = plans.begin()->first;
	return plans[minKey];

	
}
