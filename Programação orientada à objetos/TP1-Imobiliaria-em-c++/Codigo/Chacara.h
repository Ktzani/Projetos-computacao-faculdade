#ifndef CHACARA_H
#define CHACARA_H
#include <iostream>
#include <string>
#include "Imovel.h"

using namespace std;

class Chacara : public Imovel
{
private:
    int salao_festa;
    int salao_jogos;
    int campo_futebol;
    int churrasqueira;
    int piscina;

public:
    Chacara(int = 0, float = 0.0, const string = "", const string = "", const string = "", const string = "", int = 0, int = 0, int = 0, bool = false, bool = false, bool = false, bool = false, bool = false);
    virtual ~Chacara();

    bool getSalaoFesta() const;
    void setSalaoFesta(bool );

    bool getSalaoJogos() const;
    void setSalaoJogos(bool );

    bool getCampoFutebol() const;
    void setCampoFutebol(bool );

    bool getChurrasqueira() const;
    void setChurrasqueira(bool );

    bool getPiscina() const;
    void setPiscina(bool );

    virtual void saida(ostream&) const;

    friend ostream& operator << (ostream&, const Chacara&);
};

#endif