#ifndef INCL_POINT_FWD_HPP__
#define INCL_POINT_FWD_HPP__

#include <unordered_set>

namespace Go {

class Point;
using PointSet = std::unordered_set<Point*>;
using ConstPointSet = std::unordered_set<const Point*>;

} // namespace Go

#endif /* end of include guard: INCL_POINT_FWD_HPP__ */
