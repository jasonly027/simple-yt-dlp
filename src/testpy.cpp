#include "testpy.h"
#include <QDebug>

TestPy::TestPy(QObject *parent)
    : QObject{parent}
{}

void TestPy::doPy() {
    namespace py = pybind11;
    py::print("Helo from button");
}
