#include "Imovel.h"

Imovel::Imovel(int id, float valor, string prop, string rua, string bairro, string cidade, int numero, int quartos, int banheiros) :
id(id), valor(valor), proprietario(prop), rua(rua), bairro(bairro), cidade(cidade), numero(numero), quartos(quartos), banheiros(banheiros){}

Imovel :: ~Imovel(){}

int Imovel :: getId() const {
    return id; 
}
void Imovel :: setId(int id){
    this->id = id < 1 ? 0 : this->id;
}

float Imovel :: getValor() const {
    return valor;
}
void Imovel :: setValor(float valor){
    this->valor = valor < 0 ? 0 : this->valor;
}

string Imovel :: getProprietario() const {
    return proprietario;
}
void Imovel :: setProprietario(string proprietario){
    this->proprietario = proprietario;
}

string Imovel :: getRua() const {
    return rua;
}
void Imovel :: setRua(string rua){
    this->rua = rua;
}

string Imovel :: getBairro() const {
    return bairro;
}
void Imovel :: setBairro(string bairro){
    this->bairro = bairro;
}

string Imovel :: getCidade() const {
    return cidade;
}
void Imovel :: setCidade(string cidade) {
    this->cidade = cidade;
}

int Imovel :: getNumero() const {
    return numero;
}
void Imovel :: setNumero(int numero) {
     
    this->numero = numero < 0 ? 0 : this->numero;
}

int Imovel :: getQuartos() const {
    return quartos;
}
void Imovel :: setQuartos(int quartos){
    
    this->quartos = quartos < 0 ? 0 : this->quartos;
}

int Imovel :: getBanheiros() const {
    return banheiros;
}
void Imovel :: setBanheiros(int banheiros){
     
    this->banheiros = banheiros < 0 ? 0 : this->banheiros;
}

//Faço essa função dentro de cada uma das classes, tanto a base que é Imovel, quanto as suas
//derivadas, já que isso vai me facilitar chamar essa construçao de mostrar o atributos da classe
//base para serem chamados dentro da classe derivada e não precisa ficar chamando através de get-
//ters cada um dos métodos que estão definidos na classe base
void Imovel :: saida(ostream& out) const{
    out << "----- \n" 
    << "Proprietario: " << getProprietario() << endl
    << '\t' << "Preço: " << fixed << setprecision(2) << getValor() << endl
    << '\t' << "Numero de quartos: " << getQuartos() << endl
    << '\t' << "Rua: " << getRua() << endl
    << '\t' << "Bairro: " << getBairro() << endl
    << '\t' << "Cidade: " << getCidade() << endl;
}

ostream& operator << (std::ostream& out, const Imovel& I){
    I.saida(out);
    return out;
}