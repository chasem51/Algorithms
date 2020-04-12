#ifndef _hw4
#define _hw4

#include <utility>
#include <vector>
#include <algorithm>
#include <string>

template <class T>
void flip(std::vector<T> &v, int i, int j) {
    std::reverse(v.begin()+i, v.begin()+j+1);
}

// (a)
int unsorted_mode(std::vector<int> v);

// (b)
int sorted_mode(std::vector<int> v);

// (c)
std::pair<int,int> unsorted_closest_integers(std::vector<int> v);

// (d)
std::pair<std::pair<int,int>,std::pair<int,int>>
unsorted_closest_coordinates(std::vector<std::pair<int,int>> v);

// (e)
void flip_sort(std::vector<int> &v);

// (f)
void peak_valley_sort(std::vector<int> &v);

// (g)
void length_alpha_sort(std::vector<std::string> &v);

#endif