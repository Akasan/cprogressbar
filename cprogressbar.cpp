#include <iostream>
#include <iomanip>
#include <string>
#include "cprogressbar.h"

CProgressbar::CProgressbar(int max, int incrementStepSize, int showPercentageStepSize): m_max(max), m_incrementStepSize(incrementStepSize), m_showPercentageStepSize(showPercentageStepSize){
    m_current = 0;
};

void CProgressbar::increment(){
    m_current += m_incrementStepSize;
}


void CProgressbar::show(std::string message) const {
    int currentPercentage = static_cast<int>(m_current * 100 / m_max);
    std::cout << "\r" << std::setw(3) << currentPercentage << "% [" <<  std::flush;
    int charNum = m_max / m_showPercentageStepSize;
    for(int i=0; i<charNum; i++){
        if(currentPercentage >= (i+1)*m_showPercentageStepSize){
            std::cout << "#" << std::flush; 
        }else{
            std::cout << "-" << std::flush;
        }
    }
    std::cout << "] " << message << std::flush;
}
