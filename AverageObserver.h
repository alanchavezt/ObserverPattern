//
//  AverageObserver.h
//  LocalStocks
//
//  Created by Alan Chávez on 3/7/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef AverageObserver_h
#define AverageObserver_h

#include "Observer.h"

class AverageObserver : public Observer
{
    private:
        std::string averageFileName = "Average.dat";
    
    public:
        void update(std::vector<std::string> snapshots);
    
};

void AverageObserver::update(std::vector<std::string> snapshots)
{
    std::ofstream averageFile(averageFileName);
    int count = 0;
    double total = 0;
    
    if (averageFile.is_open())
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
                    averageFile << currentLine;
                    break;
                }
                words.push_back(word);
            }
            
            if(words.size() == 0)
            {
                if (count > 0)
                {
                    averageFile << "Average Price: " << (total / count) << "\n";
                    count = 0;
                    total = 0;
                }
            }
            else
            {
                total = total + std::stod(words.at(words.size() - 7));
                count++;
            }
        }
        
        averageFile.close();
    }
}

#endif /* AverageObserver_h */
