#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) {
  m_list = list;
}

void TSPSolver::solve() {
  // get first three points from list
  Point p0 = m_list.getPointAt(0);
  Point p1 = m_list.getPointAt(1);
  Point p2 = m_list.getPointAt(2);

  // add points to m_solution
  m_solution.addPoint(p0);
  m_solution.addPoint(p1);
  m_solution.addPoint(p2);
  
  // if list size greater than 3
  int size = m_list.getSize();
  if (size > 3) {
    // distances used for min calc
    float dist1, dist2, dist3;

    // stores values from formula

    float min;
    float cur;
    // loops from 3 to end of m_list
    for (int i = 3; i < size; i++) {
      // point to be inserted
      Point p_i = m_list.getPointAt(i);
 
      dist1 = p0.getDistance(p_i);
      dist2 = p1.getDistance(p_i);
      dist3 = p1.getDistance(p0);

      min = dist1+dist2-dist3;
      int index = 0;
      // loop finds position in cycle s.t. cur <= min
      for (int j = 0; j < m_solution.getSize(); j++) {
        Point p_j = m_solution.getPointAt(j);
        // j is last index, set j+1 to first point
        Point p_j1 = m_solution.getPointAt(0);
        
        // j is not last index
        if (j != m_solution.getSize()-1) {
          p_j1 = m_solution.getPointAt(j+1);
        }

        float dist4, dist5, dist6;

        dist4 = p_j.getDistance(p_i);
        dist5 = p_j1.getDistance(p_i);
        dist6 = p_j1.getDistance(p_j);

        cur = dist4+dist5-dist6;

        // store cur and index j
        if (cur <= min) {
          min = cur;
          index = j;
        }
      }
      // insert point at index i after index j
      Point p_index = m_solution.getPointAt(index);
      m_solution.addAfter(p_i,p_index.getName());
    }
  } 
}

TSPCycle& TSPSolver::getSolution() {
  // implement me

  // currently returns an empty cycle
  return m_solution;
}

