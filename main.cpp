#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  

  Point q(3,4,"Q");
  Point s(2,2,"S");
  //distance should be 5
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;
  cout << "dist between og and S is " << s.getDistance(origin) << endl;
}

void testList() {
  Point p_a(0,0,"A");
  Point p_b(0,2,"B");
  Point p_c(2,0,"C");
  Point p_d(2,2,"D");

  ListOfPoints testlist;
  
  testlist.addPoint(p_a);
  testlist.addPoint(p_c);

  testlist.addAfter(p_b, "A");
  testlist.addAfter(p_d, "C");

  testlist.printList();
  cout << "List size: " << testlist.getSize() << endl;
  // Should be A B C D
}

void testCycle() {
  Point p_a(0,0,"A");
  Point p_b(0,2,"B");
  Point p_c(2,2,"C");
  Point p_d(2,0,"D");

  TSPCycle testcycle;
  
  testcycle.addPoint(p_a);
  testcycle.addPoint(p_c);

  testcycle.addAfter(p_b, "A");
  testcycle.addAfter(p_d, "C");

  testcycle.printList();
  cout << "Length of cycle: " << testcycle.getLength() << endl;
  testcycle.draw();

  // Should be length 8
  // B - C
  // |   |
  // A - D
}

// gets a list of points and runs the solver on this list
// used in test1 and test2 below
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  solver.solve();
  TSPCycle solution = solver.getSolution();


  cout << "Solution found is: " << endl;
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength() << endl;
}

void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");

  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    string s;
    s = 'A'+i;
    p = Point(i,0,s);
    inputTSP.addPoint(p);
  }

  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<50;i++) {
    p = Point(rand() % 1000, rand() % 1000,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  // some coordinates values more than 20, so we do not use draw here

  testSolver(inputTSP);
}

void test4() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");

  cout << "Creating a list of points:" << endl;

  for (int i=0;i<21;i++) {
    string s;
    s = 'A'+i;
    p = Point(i,i,s);
    inputTSP.addPoint(p);
  }

  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test5() {
  ListOfPoints inputTSP;
  Point p[3] = {Point(2,6,"A"),Point(5,9,"B"),Point(8,6,"C")};

  cout << "Creating a list of points:" << endl;
  for (int i = 0; i < 3; i++)
    inputTSP.addPoint(p[i]);

  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();

  testSolver(inputTSP);
}

void test6() {
  ListOfPoints inputTSP;
  Point p[11] = {
    Point(1,1,"A"),
    Point(6,1,"B"),
    Point(8,1,"C"),
    Point(10,1,"D"),
    Point(3,3,"E"),
    Point(6,3,"F"),
    Point(1,4,"G"),
    Point(5,4,"H"),
    Point(8,4,"I"),
    Point(3,7,"J"),
    Point(6,7,"K")
  };
  for (int i=0; i<11; i++) {
    inputTSP.addPoint(p[i]);
  }
  cout << "Printing the list:" << endl;
    inputTSP.printList();
    cout << "\n";
    inputTSP.draw();
    testSolver(inputTSP);
}

void test7() {
  ListOfPoints inputTSP;
  Point p[7] = {
    Point(1,1,"A"),
    Point(5,1,"B"),
    Point(5,5,"C"),
    Point(1,5,"D"),
    Point(3,3,"E"),
    Point(7,3,"F"),
    Point(3,7,"G"),
  };
  for (int i=0; i<7; i++) {
    inputTSP.addPoint(p[i]);
  }
  cout << "Printing the list:" << endl;
    inputTSP.printList();
    cout << "\n";
    inputTSP.draw();
    testSolver(inputTSP);
}

void test8() {
  ListOfPoints inputTSP;
  Point p[11] = {
    Point(7,1,"A"),
    Point(2,1,"B"),
    Point(8,5,"C"),
    Point(10,3,"D"),
    Point(3,1,"E"),
    Point(4,3,"F"),
    Point(2,4,"G"),
    Point(9,4,"H"),
    Point(8,8,"I"),
    Point(3,2,"J"),
    Point(6,9,"K")
  };
  for (int i=0; i<11; i++) {
    inputTSP.addPoint(p[i]);
  }
  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();
  testSolver(inputTSP);
}

void test9() {
  ListOfPoints inputTSP;
  Point p[12] = {
    Point(8,9,"A"),
    Point(10,8,"B"),
    Point(8,11,"C"),
    Point(8,10,"D"),
    Point(10,12,"E"),
    Point(12,9,"F"),
    Point(12,11,"G"),
    Point(12,10,"H"),
    Point(11,8,"I"),
    Point(9,12,"J"),
    Point(9,8,"K"),
    Point(11,12,"L")
  };
  for (int i=0; i<12; i++) {
    inputTSP.addPoint(p[i]);
  }
  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();
  testSolver(inputTSP);
}

int main() {

  cout << "****Test point**" << endl;
  testPoint();
  cout << "****End of test point**" << endl << endl;

  cout << "testing list..." << endl;
  testList();
  cout << "end of test list" << endl << endl;

  cout << "testing cycle..." << endl;
  testCycle();
  cout << "end of testCycle" << endl << endl;

  cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;
 
  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;

  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test3**:" << endl << endl;

  cout << "****test4**:" << endl;
  test4();
  cout << "****end of test4**:" << endl << endl;

  cout << "****test5**:" << endl;
  test5();
  cout << "****end of test5**:" << endl << endl;

  cout << "****test6**:" << endl;
  test6();
  cout << "****end of test6**:" << endl << endl;

  cout << "****test7**:" << endl;
  test7();
  cout << "****end of test7**:" << endl << endl;

  cout << "****test8**:" << endl;
  test8();
  cout << "****end of test8**:" << endl << endl;

  cout << "****test9**:" << endl;
  test9();
  cout << "****end of test9**:" << endl << endl;
  return 0;
}
