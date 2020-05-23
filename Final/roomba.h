#ifndef _ROOMBA
#define _ROOMBA

#include <vector>
#include <utility>
#include <cstddef>

enum Heading { North, South, East, West };
enum Action { go_straight, go_left };

typedef std::pair<std::size_t, std::size_t> coordinate; // (0,0) is top left. (1,0) is south of (0,0)
typedef std::vector<std::vector<bool>> grid; // m-length vector of n-length vectors.
typedef std::vector<Action> motion_plan;

motion_plan escape_route(grid const&, coordinate, Heading);

#endif