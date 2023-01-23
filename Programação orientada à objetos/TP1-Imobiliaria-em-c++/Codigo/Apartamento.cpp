#include "Apartamento.h"

Apartamento :: Apartamento(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, int quartos, int banheiros, int andar, float taxa_condominio, bool elevador, bool sacada):
    Imovel(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros), 
    andar(andar), 
    taxa_condominio(taxa_condominio), 
    elevador(elevador), 
    sacada(sacada){}

    Apartamento :: ~Apartamento(){}

    int Apartamento :: getAndar() const{
        return andar;
    }

    void Apartamento :: setAndar(int andar){
        this->andar = andar;
    }

    float Apartamento :: getTaxaCondominio() const{
        return taxa_condominio;
    }

    void Apartamento :: setTaxaCondominio(float taxa_condominio){
         
        this->taxa_condominio = taxa_condominio < 0 ? 0 : this->taxa_condominio;
    }

    bool Apartamento :: getElevador() const{
        return elevador;
    }

    void Apartamento :: setElevador(bool elevador){
        this->elevador = elevador;
    }

    bool Apartamento :: getSacada() const{
        return sacada;
    }
        
    void Apartamento :: setSacada(bool sacada){
        this->sacada = sacada;
    }

    void Apartamento :: saida(ostream& out) const{
        Imovel :: saida(out);

        out << '\t' << "Apartamento: ";
        if (getElevador()){
            out << "Existe elevador!!" << endl
            << "----- \n" ;
        }

        else {
            out << "NÃO existe elevador!!" << endl
            << "----- \n" ;
        }
    }

    ostream& operator << (ostream& out, const Apartamento& Ap){
        Ap.saida(out);
        return out;
    }