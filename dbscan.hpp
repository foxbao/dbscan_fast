#include <vector>

auto dbscan(const std::vector<std::vector<float>>& data, float eps, int min_pts) 
        -> std::vector<std::vector<size_t>>;