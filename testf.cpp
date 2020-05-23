#include <iostream>
#include "roomba.h"

int main() {
    grid maze = {
        {1,1,1,1,1},
        {1,0,0,1,1},
        {0,0,0,0,1},
        {1,1,0,0,1},
        {1,1,0,1,1}
    };
    motion_plan plan = escape_route(maze, {2, 2}, West);

    if (plan.empty())
        std::cout << "No escape!" << std::endl;
    else
        for (Action a : plan)
            switch (a) {
                case go_straight: std::cout << "go_straight" << std::endl; break;
                case go_left:     std::cout << "go_left"     << std::endl;
            }

    return 0;
}