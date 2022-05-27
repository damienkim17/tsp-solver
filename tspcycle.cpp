#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
  // implement me
//  cout << "default TSPCycle constructor" << endl;
}

// returns the length of the cycle
float TSPCycle::getLength() const {
  float dist = 0;
  int size = m_points.size();
  // loops calcs distance between next and cur
  for (int i = 0; i < size; i++) {
    Point cur = m_points[i];
    Point next = m_points[0];
    // if i reaches last index set next to first index
    if (i != getSize()-1) {
      next = m_points[i+1];
    }
    // sum distance
    dist += next.getDistance(cur);
  }
  return dist;
}
