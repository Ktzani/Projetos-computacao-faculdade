#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include <iostream>
#include <string>
#include "Imovel.h"

using namespace std;

class Apartamento : public Imovel{
private:
    int andar;
    float taxa_condominio;
    int elevador;
    int sacada;

public:
    Apartamento(int = 0, float = 0.0, const string = "", const string = "", const string = "", const string = "", int = 0, int = 0, int = 0, int = 0, float = 0.0, bool = false, bool = 0);
    virtual ~Apartamento();

    int getAndar() const;
    void setAndar(int );

    float getTaxaCondominio() const;
    void setTaxaCondominio(float );

    bool getElevador() const;
    void setElevador(bool );

    bool getSacada() const;
    void setSacada(bool );

    virtual void saida(ostream&) const;

    friend ostream& operator << (ostream&, const Apartamento&);
};

#endif