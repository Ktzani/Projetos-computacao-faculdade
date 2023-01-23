#ifndef MODEL_H
#define MODEL_H
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "stock.h"
#include "flow.h"

using namespace std;

class Model {
protected:

    vector <Stock*> stocks;
    vector <Flow*> flows;
    double currentTime;
    double initialTime;
    double finalTime;
    int ID;

private:
    Model(const Model&);

    Model& operator= (const Model&);

public:
    Model();
    Model(double = 0, double = 100, int = 0);

    virtual ~Model(); 

    double getCurrentTime() const;
    void setCurrentTime(double);

    double getInitialTime() const;
    void setInitialTime(double);

    double getFinalTime() const;
    void setFinalTime(double);

    int getId() const;
    void setId(int);

    vector <Stock*> getStocks() const;

    vector <Flow*> getFlows() const;

    void add(Stock*);
    void add(Flow*);
    void add(Flow*, Stock*, Stock*);

    bool remove(string);
    bool remove(int);

    bool run();

    void print_results();
};


#endif