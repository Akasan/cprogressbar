#ifndef CPROGRESSBAR_H_
#define CPROGRESSBAR_H_

#include <iostream>
#include <string>

class CProgressbar{
public:
    CProgressbar(int max, int incrementStepSize=1, int showPercentagetStepSize=5);
    void show(std::string message="") const;
    void increment();

private:
    int m_max;
    int m_current;
    int m_incrementStepSize;
    int m_showPercentageStepSize;
};

#endif
