//
//  Observer.h
//  LocalStocks
//
//  Created by Alan Chávez on 3/7/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <ostream>
#include <fstream>

class Observer
{
    public:
        virtual void update(std::vector<std::string> snapshots) = 0;
};

#endif /* Observer_h */
