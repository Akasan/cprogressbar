#ifndef CPROGRESSBAR_H_
#define CPROGRESSBAR_H_

#include <iostream>
#include <string>
#include <map>

enum class ForeColor {
    RED = 31,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};


class CProgressbar{
public:
    CProgressbar(int max, int incrementStepSize=1, int showPercentagetStepSize=5, ForeColor foreColor = ForeColor::WHITE);
    void show(std::string message="") const;
    void increment();
    bool isCompleted() const;
    int getCurrentPercentage() const ;
    void setChild(CProgressbar* childProgressbar);
    void clearChild();
    bool hasChild() const;

private:
    int m_max;
    int m_current;
    int m_incrementStepSize;
    int m_showPercentageStepSize;
    ForeColor m_foreColor;
    CProgressbar *m_childProgressbar;
};

#endif
