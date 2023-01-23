#ifndef STOCK_H
#define STOCK_H
#include <string.h>
#include <iostream>

using namespace std;

class Stock {
protected:
    double value;
    string ID;

private:
    Stock(const Stock&);

    Stock& operator= (const Stock&);

public:
    Stock();
    Stock(double = 0, const string = "", bool = false);

    virtual ~Stock(); 

    double getInitialValue() const;
    void setInitialValue(double);

    string getId() const;
    void setId(string);

};

#endif