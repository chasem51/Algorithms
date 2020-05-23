#include <vector>

using namespace std;

bool canFinish(int n, vector<pair<int, int>> &dependencies);
bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i);