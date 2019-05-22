//
//  PercentageChangeObserver.h
//  LocalStocks
//
//  Created by Alan Chávez on 3/7/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef PercentChangeObserver_h
#define PercentChangeObserver_h

#include "Observer.h"

class PercentageChangeObserver : public Observer
{
    private:
        std::string percentageFileName = "Percentage.dat";
    
    public:
        void update(std::vector<std::string> snapshots);
    
};

void PercentageChangeObserver::update(std::vector<std::string> snapshots)
{
    std::ofstream percentageFile(percentageFileName);
    std::vector<std::string> price;
    std::vector<std::string> tickerSymbol;
    std::vector<std::string> percents;
    int percent = 10;
    int count = 0;

    if(percentageFile.is_open())
    {
        for(int i = 0; i < snapshots.size(); i++)
        {
            std::string currentLine = snapshots[i];
            std::istringstream istr(currentLine);
            std::vector<std::string> words;
            std::string word;
            
            while(istr >> word)
            {
                if(word == "Last")
                {
                    percentageFile << "\n" << currentLine << std::endl;
                    break;
                }
                words.push_back(word);
            }

            if(words.size() == 0)
            {
                if (count > 0)
                {
                    for (int i = 0; i < count; i++)
                    {
                        percentageFile << tickerSymbol.at(i) << " " << price.at(i) << " " << percents.at(i) << std::endl;
                    }
                    
                    tickerSymbol.clear();
                    price.clear();
                    percents.clear();
                    count = 0;
                }
            }
            else
            {
                if(std::stod(words.at(words.size() - 5)) >= percent || std::stod(words.at(words.size() - 5)) * -1 >= percent)
                {
                    price.push_back(words.at(words.size() - 7));
                    tickerSymbol.push_back(words.at(words.size() - 8));
                    percents.push_back(words.at(words.size() - 5));
                    count++;
                }
            }
        }
        percentageFile.close();
    }
}

#endif /* PercentChangeObserver_h */
