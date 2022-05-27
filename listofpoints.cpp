#include "listofpoints.hpp"

ListOfPoints::ListOfPoints() {
}

void ListOfPoints::addAfter(Point& newPt, string name) {
  // loops until names match
  for(vector<int>::size_type i = 0; i < m_points.size(); i++){
    // name at index i = input name
    if (m_points[i].getName() == name) {
      // add point after input name at index i+1
      m_points.insert(m_points.begin() + (i+1), newPt);
      break;
    }
  }
}

void ListOfPoints::addPoint(Point& newPt)  {
  // add point to end of vector
  m_points.push_back(newPt);
}

Point& ListOfPoints::getPointAt(unsigned int i) {
  return m_points[i];
}

int ListOfPoints::getSize() const {
  // return size of vector
  return m_points.size();
}

void ListOfPoints::printList() const {
  // prints at each iteration for vector
  for (vector<int>::size_type i = 0; i < m_points.size(); i++) {
    cout << m_points[i] << endl;
  }
}

void ListOfPoints::draw() const {
  string arr[21][21];
  // fill arr with dashes
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      arr[i][j] = '-';
    }
  }
  // set xpos & ypos in outer loop
  // iterates through m_points vector
  for (vector<int>::size_type k = 0; k < m_points.size(); k++) {
    int xpos = m_points[k].getX();
    int ypos = m_points[k].getY();
    // inner loops interate through arr
    for (int i = 0; i < 21; i++) {
      for (int j = 0; j < 21; j++) {
        // set point name to matching arr position
        if (i == xpos && j == ypos) {
          arr[20-j][i] = m_points[k].getName();
        }
      }
    }
  }
  // loop to add spacing
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}
 