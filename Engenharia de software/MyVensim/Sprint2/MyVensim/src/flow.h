#ifndef FLOW_H
#define FLOW_H
#include <string.h>
#include <iostream>
#include "stock.h"

using namespace std;

class Flow {
protected:
    Stock *source;
    Stock *destiny;
    int ID;
    double (*function) (Stock* sto);
    double lastValue;
    bool varBool;

private:
    Flow(const Flow&);

    Flow& operator= (const Flow&);

public:
    Flow();
    Flow(Stock* = nullptr, Stock* = nullptr, int = 0, double (*)(Stock*) = nullptr, bool = false);

    virtual ~Flow(); 

    void connection(Stock* = nullptr, Stock* = nullptr);

    Stock* getSource() const;
    void setSource(Stock*);

    Stock* getDestiny() const;
    void setDestiny(Stock*);

    double getLastValue() const;
    void setLastValue(double);

    int getId() const;
    void setId(int);

    void clearSource ();
    void clearDestiny ();

    bool getVarBool() const ;
    void setVarBool(bool);

    void execute();
    
};

#endif