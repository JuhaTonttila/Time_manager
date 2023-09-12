

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "nstimemanager.h"


int main() {
    std::vector<std::string> inputs = {"2010-01-06 00:00:00-05:00",
                                       "2010-01-07 00:00:00-05:00",
                                       "2010-01-08 00:00:00-05:00",
                                       "2010-01-09 00:00:00-05:00",
                                       "2010-01-10 00:00:00-05:00",
                                       "2010-01-11 00:00:00-05:00",
                                       "2010-01-12 00:00:00-05:00"};
    std::vector<tm> tminputs;

    for (std::string tt : inputs) tminputs.push_back(TMNG::getTm(tt,TMNG::tfmt));

    std::string start1 = "2010-01-08 00:23:00-05:00";
    std::string start2 = "2010-05-11";

    tm tmst1 = TMNG::getTm(start1,TMNG::tfmt);
    tm tmst2 = TMNG::getTm(start2,"%Y-%m-%d");

    TMNG::incrDays(tmst1,-3);

    std::cout << tmst1.tm_year << " " << tmst1.tm_mday << " " <<
         tmst1.tm_wday << " " << tmst1.tm_mon << " " << tmst1.tm_hour << " " <<
         tmst1.tm_min << " " << tmst1.tm_sec << std::endl;

    std::cout << tmst2.tm_year << " " << tmst2.tm_mday << " " <<
         tmst2.tm_wday << " " << tmst2.tm_mon << " " << tmst2.tm_hour << " " <<
         tmst2.tm_min << " " << tmst2.tm_sec << std::endl;


    std::cout << TMNG::nearestTime(tminputs,tmst1) << std::endl;
    std::cout << TMNG::nearestTime(tminputs,tmst2) << std::endl;

    std::string test = asctime(&tmst1);

    std::cout << test << std::endl;
    std::cout << asctime(&tmst2) << std::endl;
    char buff[100];
    strftime(buff, sizeof(buff), "%a %b %d %Y", &tmst2);
    std::string s(buff); 
    std::cout << s << std::endl;
}