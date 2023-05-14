#include "cprogressbar.h"
#include <iomanip>
#include <iostream>
#include <string>

std::map<ForeColor, std::string> foreColor2String {
    {ForeColor::RED, "31"},
    {ForeColor::GREEN, "32"},
    {ForeColor::YELLOW, "33"},
    {ForeColor::BLUE, "34"},
    {ForeColor::MAGENTA, "35"},
    {ForeColor::CYAN, "36"},
    {ForeColor::WHITE, "37"},
};

CProgressbar::CProgressbar(int max, int incrementStepSize,
                           int showPercentageStepSize, ForeColor foreColor)
    : m_max(max), m_incrementStepSize(incrementStepSize),
      m_showPercentageStepSize(showPercentageStepSize), m_foreColor(foreColor) {
    m_current = 0;
};

void CProgressbar::increment() { m_current += m_incrementStepSize; }

bool CProgressbar::isCompleted() const { return getCurrentPercentage() == 100; }

int CProgressbar::getCurrentPercentage() const {
    return static_cast<int>(m_current * 100 / m_max);
}

void CProgressbar::setChild(CProgressbar *childProgressbar) {
    m_childProgressbar = childProgressbar;
}

void CProgressbar::clearChild() { m_childProgressbar = nullptr; }

void CProgressbar::show(std::string message) const {
    int currentPercentage = getCurrentPercentage();
    std::cout << "\r" << std::setw(3) << currentPercentage << "% ["
              << std::flush;
    int charNum = m_max / m_showPercentageStepSize;
    for (int i = 0; i < charNum; i++) {
        if (currentPercentage >= (i + 1) * m_showPercentageStepSize) {
            // std::cout << "#" << std::flush;
            std::cout << "\033[1;" << foreColor2String.at(m_foreColor) << "m#\033[0m" << std::flush;
        } else {
            std::cout << "-" << std::flush;
        }
    }
    std::cout << "] " << message << std::flush;
}
