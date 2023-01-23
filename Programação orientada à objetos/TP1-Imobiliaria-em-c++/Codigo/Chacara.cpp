#include "Chacara.h"

Chacara :: Chacara (int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, int quartos, int banheiros, bool salao_festa, bool salao_jogos, bool campo_futebol, bool churrasqueira, bool piscina):
    Imovel(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros), 
    salao_festa(salao_festa),
    salao_jogos(salao_jogos),
    campo_futebol(campo_futebol),
    churrasqueira (churrasqueira),
    piscina(piscina) {}

    Chacara :: ~Chacara() {}

    bool Chacara :: getSalaoFesta() const{
        return salao_festa;
    }
    void Chacara :: setSalaoFesta(bool salao_festa){
        this->salao_festa = salao_festa;
    }

    bool Chacara :: getSalaoJogos() const{
        return salao_jogos;
    }   

    void Chacara :: setSalaoJogos(bool salao_jogos){
        this->salao_jogos = salao_jogos;
    }

    bool Chacara :: getCampoFutebol() const{
        return campo_futebol;
    }

    void Chacara :: setCampoFutebol(bool campo_futebol){
        this->campo_futebol = campo_futebol;
    }

    bool Chacara :: getChurrasqueira() const{
        return churrasqueira;
    }

    void Chacara :: setChurrasqueira(bool churrasqueira){
        this->churrasqueira = churrasqueira;
    }

    bool Chacara :: getPiscina() const{
        return piscina;
    }

    void Chacara :: setPiscina(bool piscina){
        this->piscina = piscina;
    }   

    void Chacara :: saida(ostream& out) const{
        Imovel :: saida(out);

        out << '\t' <<"Chacara: ";
        if(getPiscina()){
            out << "Existe piscina!!" << endl
            << "----- \n" ;
        }

        else {
            out << "NÃO existe piscina!!" << endl
            << "----- \n" ;
        }
    }

    ostream& operator << (ostream& out, const Chacara& Cha){
        Cha.saida(out);
        return out;
    }