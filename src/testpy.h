#ifndef TESTPY_H
#define TESTPY_H

#include <pybind11/embed.h>
#include <QObject>

class TestPy : public QObject
{
    Q_OBJECT
public:
    explicit TestPy(QObject *parent = nullptr);
    Q_INVOKABLE void doPy();
signals:
};

#endif // TESTPY_H
