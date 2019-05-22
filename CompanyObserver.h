//
//  CompanyObserver.h
//  LocalStocks
//
//  Created by Alan Chávez on 3/7/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef CompanyObserver_h
#define CompanyObserver_h

#include "Observer.h"
#include <unordered_set>

class CompanyObserver : public Observer
{
    private:
        std::string companyFileName = "Company.dat";
    
    public:
        void update(std::vector<std::string> snapshots);
};

void CompanyObserver::update(std::vector<std::string> snapshots)
{
    std::ofstream companyFile(companyFileName);
    std::unordered_set<std::string> companies {"ALL", "BA", "BC", "GBEL", "KFT", "MCD", "TR", "WAG"};

    if(companyFile.is_open())
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
                    companyFile << "\n" << currentLine << std::endl;
                    break;
                }
                words.push_back(word);
            }

            if(words.size() != 0)
            {
                if(companies.find(words.at(words.size() - 8)) != companies.end()) {
                    companyFile << currentLine << std::endl;
                }
            }
        }
        
        companyFile.close();
    }
}
#endif /* CompanyObserver_h */
