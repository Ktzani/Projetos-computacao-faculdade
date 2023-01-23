#ifndef CASA_H
#define CASA_H
#include <iostream>
#include <string>
#include "Imovel.h"

using namespace std;

class Casa : public Imovel{
private:
    int andares;
    int sala_jantar;

public:
    Casa(int = 0, float = 0.0, const string = "", const string = "", const string = "", const string = "", int = 0, int = 0, int = 0, int = 0, bool = false);
    virtual ~Casa();

    int getAndares() const;
    void setAndares(int ); 

    bool getSalaJantar() const;
    void setSalaJantar(bool );

    virtual void saida(ostream&) const;
    
    friend ostream& operator << (ostream&, const Casa&);
};

#endif