//
//  main.cpp
//  LocalStocks
//
//  Created by Alan Chávez on 3/7/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#include <iostream>

#include "LocalStocks.h"

int main(int argc, const char * argv[])
{
    std::cout << "\nInstantiating localStock Object..." << std::endl;
    LocalStocks localStock;
    
    std::cout << "\nAverage Observer Created!" << std::endl;
    AverageObserver *averageObserver = new AverageObserver();
    
    std::cout << "\nPercent Change Observer Created!" << std::endl;
    PercentageChangeObserver *percentageObserver = new PercentageChangeObserver();
    
    std::cout << "\nCompany Observer Created!" << std::endl;
    CompanyObserver *companyObserver = new CompanyObserver();
    
    std::cout << "\nRegistering Observers..." << std::endl;
    localStock.addObserver(averageObserver);
    localStock.addObserver(percentageObserver);
    localStock.addObserver(companyObserver);
    
    std::cout << "\nNotifying Observers" << std::endl;
    localStock.notifyObserver();
    
}
