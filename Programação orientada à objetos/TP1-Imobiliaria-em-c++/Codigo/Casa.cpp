#include "casa.h"

Casa :: Casa (int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, int quartos, int banheiros, int andares, bool sala_jantar):
    Imovel(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros), 
    andares(andares), 
    sala_jantar(sala_jantar) {}

    Casa :: ~Casa() {}

    int Casa :: getAndares() const{
        return andares;
    }

    void Casa :: setAndares(int andares){
        this->andares = andares;
    } 
    bool Casa :: getSalaJantar() const{
        return sala_jantar;
    }

    void Casa :: setSalaJantar(bool sala_jantar){
        this->sala_jantar = sala_jantar;
    }

    void Casa :: saida (ostream& out) const {
        Imovel :: saida(out);
        out <<'\t' << "Casa: ";
        out << "Numeros andares = " << getAndares() << endl
        << "----- \n" ;
    }


    ostream& operator << (ostream& out, const Casa& C){
        C.saida(out);
        return out;
    }
