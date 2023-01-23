#ifndef IMOVEL_H
#define IMOVEL_H
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Imovel{
private:
    int id;
    float valor;
    string proprietario, rua, bairro, cidade;
    int numero, quartos, banheiros;

public:
    Imovel(int = 0, float = 0.0, const string = "", const string = "", const string = "", const string = "", int = 0, int = 0, int = 0);
    virtual ~Imovel();

    int getId() const;
    void setId(int);

    float getValor() const;
    void setValor(float);

    string getProprietario() const;
    void setProprietario(string);

    string getRua() const;
    void setRua(string);

    string getBairro() const;
    void setBairro(string);

    string getCidade() const;
    void setCidade(string);

    int getNumero() const;
    void setNumero(int);

    int getQuartos() const;
    void setQuartos(int);

    int getBanheiros() const;
    void setBanheiros(int);

    virtual void saida(ostream&) const;

    friend std::ostream& operator<<(std::ostream&, const Imovel&);
    
};

#endif