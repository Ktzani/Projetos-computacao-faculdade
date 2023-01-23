#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <cstdio>
#include <iomanip>

#include "Imovel.h"
#include "Casa.h"
#include "Apartamento.h"
#include "Chacara.h"
#include "funcoes.h"

using namespace std;

/*Aqui irei percorrer todo o vetor de ponteiros a classe imoveis e ver se o proprietario que foi passado como
parametro tem algum imovel entre todos os imoveis que estão no arquivo e retorno true se tiver e false se nao tiver*/
bool propriIdenti (vector <Imovel*> imoveis, string propri){

    for (Imovel* aux : imoveis){
        
        if(aux->getProprietario() == propri){

            return true;
        }
    }

    return false;
}

/*Aqui irei criar um vetor ponteiros a classe imoveis que vai guardar os objetos(Casa, Apartamento ou Chacara) que 
tenham o valor dele abaixo ou igual do numero passado como parametro e esse vetor é retornado para o main para ser 
impresso os atributos desse imovel com sobrecarga do cout*/
vector<Imovel*> valorBarato (vector <Imovel*> imoveis, float valor){

    vector <Imovel*> ibarato;

    for (Imovel* aux : imoveis){
        
        if (aux->getValor() <= valor){

            ibarato.push_back(aux);
        }
    }   

    return ibarato;
}

/*Aqui irei criar um vetor ponteiros a classe imoveis que vai guardar os objetos(Casa, Apartamento ou Chacara) que 
tenham o numero de quartos acima do numero passado como parametro e esse vetor é retornado para o main para ser 
impresso os atributos desse imovel com sobrecarga do cout*/
vector<Imovel*> muitosQuartos (vector <Imovel*> imoveis, int quartos){

    vector <Imovel*> iquartos;

    for (Imovel* aux : imoveis){

        if(aux->getQuartos() >= quartos){

            iquartos.push_back(aux);
        }
    }

    return iquartos;
}

/* Aqui irei criar um vetor ponteiros a classe imoveis que vai guardar os objetos(Casa, Apartamento ou Chacara) que 
sejam o imovel passado como parametro (1 - casa, 2 - apartamento, 3 - chacara) que foi passada como parametro e esse 
vetor é retornado para o main para ser impresso apenas caracteristicas(atributos) especificas dos imovel passado como 
parametro*/
vector<Imovel*> imovelUnico (vector <Imovel*> imoveis, int imo){

    vector <Imovel*> temp;

    for (Imovel* aux : imoveis){

        if(aux->getId() == imo){

            temp.push_back(aux);
        }
    }

    temp = bubble_sort(temp);

    return temp;
}

/* Aqui irei criar um vetor ponteiros a classe imoveis que vai guardar os objetos(Casa, Apartamento ou Chacara) que 
estejam na cidade que foi passada como parametro e esse vetor é retornado para o main para ser
impresso os seus atributos */
vector<Imovel*> cidadeImoveis (vector <Imovel*> imoveis, string cidade){

    vector <Imovel*> icity;

    //Esse for é usado para percorremos objeto a objeto que está armazenado no vetor de ponteiro a classe Imovel e 
    //guarda os objetos que tem como atributo a cidade passada como parametro nessa novo vetor vazio icity
    for (Imovel* aux : imoveis){

        if(aux->getCidade() == cidade){

            icity.push_back(aux);
        }
    }

    icity = bubble_sort(icity);

    return icity;
}

//Faz a ordenação do vetor de ponteiros a classe imovel pelo atributo do valor do imovel
vector<Imovel*> bubble_sort(vector<Imovel*> imoveis){

    int n = (int)(imoveis.size());
    
    Imovel *aux ;

    for(int i = 0; i < n ; i++){
        for(int j = 1; j < n - i ; j++){

            if(imoveis[j]->getValor() < imoveis[j - 1]->getValor()){
                aux = imoveis[j];
                imoveis[j] = imoveis[j - 1];
                imoveis[j - 1] = aux ;
            }
        }
    }
    return imoveis ;
}

/*Pegamos essa funçao da internet que é uma funçao que é usada em php para pegar strings de uma unica string, 
ou seja, iremos ler as strings que estao entre os ';' e guardando cada uma em um vetor, onde cada string ficará em 
uma posição, porém como nao existe uma funçao propria para isso em c++, pegamos essa função na internet nesse site 
https://www.ti-enxame.com/pt/php/existe-um-equivalente-em-c-da-funcao-explode-do-php/1069125185/ */
vector<string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }

    return result;
}

/*Vamos buscar no vetor de objetos imovel por meio de um iterador, onde quando o proprietario do imovel apontador
pelo iterador foi igual ao proprietário passado como parametro, inserimos o iterador no final de um vetor de iteradores
que apontam para objetos de imóvel. Assim, retornamos esse vetor de iteradores a objeto imóvel com cada um dos imoveis 
do proprietario*/
vector<vector<Imovel*> :: iterator> retornaIterador(vector<Imovel*> imoveis, string propri){

    vector<vector<Imovel*> :: iterator> vecitr;


    for(vector<Imovel*> :: iterator itr = imoveis.begin(); itr != imoveis.end(); ++itr){
        if((*itr)->getProprietario() == propri){

            vecitr.push_back(itr);
        }
    }

    return vecitr;
    
}   

//Salva o vetor que foi criado em um arquivo
void salvaArquivo(string nome, vector<Imovel*> imoveis){

    ofstream arq(nome, ios::out);//abertura do arquivo para leitura
    
    for(Imovel* aux : imoveis){

        if (typeid (*aux).name() == typeid(class Casa).name()) {//se for uma casa

            Casa* imo = dynamic_cast<Casa *>(aux);//Dynamically Cast 
            
            arq << "casa;"//imrime os itens da casa
            << fixed << setprecision(2) << imo->getValor() << ";"
            << imo->getProprietario() << ";"
            << imo->getRua() << ";"
            << imo->getBairro() << ";"
            << imo->getCidade() << ";"
            << imo->getNumero() << ";"
            << imo->getQuartos() << ";"
            << imo->getBanheiros() << ";"
            << imo->getAndares() << ";"
            << imo->getSalaJantar() << ";"
            << endl;
        }

        else if(typeid (aux).name() == typeid(class Apartamento).name()) {//se for um apartamento
            Apartamento *imo = dynamic_cast<Apartamento*> (aux);//Dynamically Cast 

            arq << "apartamento;"//imrime os itens de apartemento
            << fixed << setprecision(2) << imo->getValor() << ";"
            << imo->getProprietario() << ";"
            << imo->getRua() << ";"
            << imo->getBairro() << ";"
            << imo->getCidade() << ";"
            << imo->getNumero() << ";"
            << imo->getQuartos() << ";"
            << imo->getBanheiros() << ";"
            << imo->getAndar() << ";"
            << imo->getTaxaCondominio() << ";"
            << imo->getElevador() << ";"
            << imo->getSacada() << ";"
            << endl;
            
        }

        else if(typeid (*aux).name() == typeid(class Chacara).name()) {//se for chacara
            Chacara *imo = dynamic_cast<Chacara*> (aux);//Dynamically Cast 

            arq << "chacara;"//imprime os imoveis de chacara
            << fixed << setprecision(2) << imo->getValor() << ";"
            << imo->getProprietario() << ";"
            << imo->getRua() << ";"
            << imo->getBairro() << ";"
            << imo->getCidade() << ";"
            << imo->getNumero() << ";"
            << imo->getQuartos() << ";"
            << imo->getBanheiros() << ";"
            << imo->getSalaoFesta() << ";"
            << imo->getSalaoJogos() << ";"
            << imo->getCampoFutebol() << ";"
            << imo->getChurrasqueira() << ";"
            << imo->getPiscina() << ";"
            << endl;
            
        }
    }
    arq.close();
}

//Digita manualmente um item imovel com suas caracteristicas
vector<Imovel*> vetorManual(){

    Imovel *temp;

    int run = 1, num, qua, ban, andares, andar;
    float valor, taxa;
    string tipo, prop, rua, bai, cid, auxiliar; //auxiliares
    bool sala_jantar, elev, sac, festa, jogos, camp, chu, pis;
    char sim_nao;

    vector<Imovel*> imoveis;//auxiliar


    while(run){

        cout << "Digite o modelo do Imovel(casa, apartamento, chacara): ";
        cin >> tipo;//tipo do arquivo

        if(tipo.empty()){
            cout << "Passe argumentos por favor" << endl;//questao de segurança
            continue;
        }

        //Preenchimento de dados padroes de imovel

        do{
            cout << "Valor: ";
            cin >> valor;    
            cin.ignore();

            if(valor < 0){
                cout << "Digite um valor valido !!" << endl;
            }
        }while(valor < 0);

        cout << "Nome do Proprietario: ";
        getline(cin, prop);

        cout << "Rua: ";
        getline(cin, rua);

        cout << "Bairro: ";
        getline(cin, bai);

        cout << "Cidade: ";
        getline(cin, cid);

        do{
            cout << "Numero: ";
            cin >> num;

            if(num < 0){
                cout << "Digite um numero valido !!" << endl;
            }
        }while(num < 0);

        do{
            cout << "Quantos quartos: ";
            cin >> qua;
        
            if(qua < 0){
                cout << "Digite um numero valido !!" << endl;
            }
        }while(qua < 0);

        do{
            cout << "Quantos banheiros: ";
            cin >> ban;
        
            if(ban < 0){
                cout << "Digite um numero valido !!" << endl;
            }
        }while(ban < 0);

        //inicio de preenchimento pela classe selecionada

        if(tipo[1] == 'a'){//se for uma casa vem aqui

            do{
                cout << "Quantos andares: ";
                cin >> andares;

                if(andares < 0){
                    cout << "Digite um numero valido !!" << endl;
                }

            }while(andares < 0);

            cout << "Tem sala de jantar(s/n)? ";
            cin >> sim_nao;
            sala_jantar = (sim_nao == 's') ? true : false;

            temp = new Casa(1, valor, prop, rua, bai, cid, num, qua, ban, andares, sala_jantar);
            //cria o valor e coloca no temporario

        }else if(tipo[1] == 'p'){//se for apartamento vem aqui

            do{
                cout << "Qual o andar do apartamento: ";
                cin >> andar;

                if(andar < 0){
                    cout << "Digite um numero valido !!" << endl;
                }

            }while(andar < 0);

            do{
                cout << "Qual o valor da taxa: ";
                cin >> taxa;

                if(taxa < 0){
                    cout << "Digite um numero valido !!" << endl;
                }

            }while(taxa < 0);

            cout << "Tem elevador(s/n)? ";
            cin >> sim_nao;
            elev = (sim_nao == 's') ? true : false;

            cout << "Tem sacada(s/n)? ";
            cin >> sim_nao;
            sac = (sim_nao == 's') ? true : false;

            temp = new Apartamento(2, valor, prop, rua, bai, cid, num, qua, ban, andar, taxa, elev, sac);
            //cria o valor e coloca no temporario

        }else if(tipo[1] == 'h'){//se for chacara vai aqui

            cout << "Tem salão de festa(s/n)? ";
            cin >> sim_nao;
            festa = (sim_nao == 's') ? true : false;

            cout << "Tem  salaão de jogos(s/n)? ";
            cin >> sim_nao;
            jogos = (sim_nao == 's') ? true : false;

            cout << "Tem campo de futebol(s/n)? ";
            cin >> sim_nao;
            camp = (sim_nao == 's') ? true : false;

            cout << "Tem churrasqueira(s/n)? ";
            cin >> sim_nao;
            chu = (sim_nao == 's') ? true : false;

            cout << "Tem piscina(s/n)? ";
            cin >> sim_nao;
            pis = (sim_nao == 's') ? true : false;

            temp = new Chacara(3, valor, prop, rua, bai, cid, num, qua, ban, festa, jogos, camp, chu, pis);
            //cria o valor e coloca no temporario

        }else{
            cout << "Escreva um tipo valido" << endl;
        }

        imoveis.push_back(temp);//adiciona o item ao vetor

        num = qua = ban = andares = andar = valor = taxa = 0;
        tipo = prop = rua = bai = cid = sim_nao = ' ';//zera tudo por segurança

        cout << "Deseja adicionar mais imoveis(s/n)? ";//caso queira adicionar mais registros
        cin >> sim_nao;

        run = (sim_nao == 's') ? 1 : 0;

    }

    return imoveis;//retorna o vetor criado
}

//switch para a seleção do arquivo que vai ser retornado
vector<Imovel*> selecionaVetor(vector <Imovel*> dados_imoveis, int v){

    vector <Imovel*> retorno;

    switch (v) {
        case 1: {
            float valor;
            
            //vetor de um valor especifico
            cout << "Digite o valor que você deseja para seu imóvel: ";

            do{
                cin >> valor;
                if(valor <= 0){
                    cout << "Valor do imóvel invalido!! Deve ser maior ou igual a 0" << endl;
                    cout << "Digite novamente: " << endl;
                }
            } while(valor <= 0); 

            retorno = valorBarato(dados_imoveis, valor);

            if (retorno.empty()){
                cout << "Nenhum imovel com esse valor" << endl;
            }

            break;
        }

        case 2:{
            int nquartos;

            //pela quantidade de quartos
            cout << "Digite o numero de quartos que você deseja em seu imovel: ";

            do{
                cin >> nquartos;
                if(nquartos <= 0){
                    cout << "Numero de quartos invalido! Deve ser maior ou igual a 0" << endl;
                    cout << "Digite novamente: ";
                }
            } while(nquartos <= 0); 

            retorno = muitosQuartos(dados_imoveis, nquartos);

            for(int i = 0; i < (int)(retorno.size()); i++){

                cout << *retorno[i] << endl;
            }

            break;
        }

        case 3: {
            int imo ;

            //pelo tipo de imovel
            printf("Digite qual imovel você deseja (1 - Casa, 2 - Apartamento, 3 - Chacara): ");
            do{
                cin >> imo;
                if(imo < 1 && imo > 3){
                    printf("Imóvel invalido! Deve ser 1 (Casa), 2(Apartamento) ou 3(Chacara)\n");
                    printf("Digite novamente: ");
                }

            } while(imo < 1 && imo > 3); 

            retorno = imovelUnico(dados_imoveis, imo);

            break;
        }

        case 4: {

            string cidade;

            getchar();

            //pelo nome do imovel
            printf("Digite o nome de uma cidade: ");

            getline(cin, cidade);

            retorno = cidadeImoveis(dados_imoveis, cidade);

            if(retorno.empty()){
                cout << "Nenhum imovel pertencente a cidade " << cidade << endl;
            }

            for (vector<Imovel*> :: reverse_iterator itr = retorno.rbegin(); itr != retorno.rend(); ++itr){
                cout << **itr;
            }

            break;
        }

        case 5: {
            string prop;

            getchar();

            //pelo nome de um proprietario
            printf("Digite um proprietario para saber se ele tem algum imovel: ");
            getline(cin, prop);

            vector <vector<Imovel*> :: iterator> vetordeitr;
            
            vetordeitr = retornaIterador(dados_imoveis, prop);
            if(vetordeitr.empty()){
                cout << "Proprietario sem Imoveis" << endl;
            }
            else{
                for(int i = 0; i < (int)(vetordeitr.size()); i++){
                    retorno.push_back(*vetordeitr[i]);
                } 
            }

            break;
        }
        
    }

    return retorno;
}