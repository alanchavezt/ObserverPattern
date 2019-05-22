//
//  LocalStocks.h
//  LocalStocks
//
//  Created by Alan Chávez on 3/7/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef LocalStocks_h
#define LocalStocks_h

#include <iostream>
#include <vector>
#include <fstream>
#include "Observer.h"
#include <string>
#include "AverageObserver.h"
#include "PercentageChangeObserver.h"
#include "CompanyObserver.h"

class LocalStocks
{
    protected:
        std::string fileName = "Ticker.dat";
        std::vector<Observer*> observers;
        std::vector<std::string> snapshots;
    
    public:
        LocalStocks();
        void addObserver(Observer* observer);
        void notifyObserver();
};

LocalStocks::LocalStocks()
{
    std::fstream localStockFile(fileName);
    std::string line;
    int i = 0;
    
    if(localStockFile.is_open())
    {
        while(std::getline(localStockFile, line))
        {
            snapshots.push_back(line);
            i++;
        }
    }
}

void LocalStocks::addObserver(Observer* observer)
{
    observers.push_back(observer);
}

void LocalStocks::notifyObserver()
{
    for(int i = 0; i < observers.size(); i++)
    {
        observers[i]->update(snapshots);
        std::cout<<"here";
    }
}


#endif /* LocalStocks_h */
