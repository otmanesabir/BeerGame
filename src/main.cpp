#include <iostream>
#include <QApplication>
#include <QtWidgets>

#include "../include/welcome.h"


/*! \mainpage Beer Game Sprint 5 Group 19
 *
 * \section runsteps How to run?
 *
 * \subsection program Run the program
 * 
 * cd build (or any directory where the program is built) \n
 * ./beergame 
 * 
 * \subsection testcases Run testcases
 * ./beergame-test \n
 */
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Welcome w;
    w.setWindowTitle("Beer Game");
    w.show();
    // PROCESS GETS INITIATED HERE AND RUNS THE EXECUTABLE FROM THE BUILD.
    return a.exec();
}
