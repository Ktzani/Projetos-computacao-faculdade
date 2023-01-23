/*Gabriel Catizani Faria Oliveira (20.1.4004)
Lucas Gomes dos Santos (20.1.4108)
Rafael Augusto Freitas Oliveira (20.1.4038)
Robson Novato Lobão (20.1.4018)*/

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


int main (int argc, const char *argv[]){

    Imovel *pontCasa = NULL;

    Imovel *pontAP = NULL;

    Imovel *pontCHA = NULL;

    vector <Imovel*> dados_imoveis;

    string arquivo("database_imoveis.txt");
    string linha;

    ifstream input_file(arquivo);
    if (!input_file.is_open()) {
        cerr << "Não foi possivel abrir o arquivo - '"
             << arquivo << "'" << endl;
        return EXIT_FAILURE;
    }

    // Vamos guardar cada uma das linhas desse arquivo em um vetor de ponteiros para onde cada posiçao dessa ou terá 
    // os itens de uma classe casa, itens de um classe apartamento ou itens de uma classe chacara
    while (getline(input_file, linha)){
        
        vector <string> linhas = explode (linha, ';'); //Aqui foi usada funçao explode que encontramos no site: https://www.ti-enxame.com/pt/php/existe-um-equivalente-em-c-da-funcao-explode-do-php/1069125185/

        if (linhas[0] == "casa"){

            pontCasa = new Casa (1, (float) stof(linhas[1]), linhas[2], linhas[3], linhas[4], linhas[5], stoi(linhas[6]), stoi(linhas[7]), stoi (linhas[8]), stoi(linhas[9]), stoi(linhas[10]));
            dados_imoveis.push_back(pontCasa); //guardo um objeto da classe Casa com seus construtores ja executados
                                               //no final do vetor
                                                 
        }

        else if (linhas[0] == "apartamento"){

            pontAP = new Apartamento(2, (float) stof(linhas[1]), linhas[2], linhas[3], linhas[4], linhas[5], stoi(linhas[6]), stoi(linhas[7]), stoi (linhas[8]), stoi(linhas[9]), stof(linhas[10]), stoi(linhas[11]), stoi(linhas[12]));
            dados_imoveis.push_back(pontAP); //guardo um objeto da classe Apartamento com seus construtores ja executados
                                             //no final do vetor
        }

        else if (linhas[0] == "chacara"){

            pontCHA = new Chacara(3, (float) stof(linhas[1]), linhas[2], linhas[3], linhas[4], linhas[5], stoi(linhas[6]), stoi(linhas[7]), stoi (linhas[8]), stoi(linhas[9]), stoi(linhas[10]), stoi(linhas[11]), stoi(linhas[12]), stoi(linhas[13]));
            dados_imoveis.push_back(pontCHA); //guardo um objeto da classe Chacara com seus construtores ja executados
                                              //no final do vetor
        }   
    }  

    input_file.close(); 

    //Vejo qual funçao sera executada entre as todas que foram pedidas pelo TP de acordo com o numero que foi passado como 
    //argumento na execução do programa
    switch (atoi(argv[1])) {
        //Parte 1 - Sobrecarga do operador cout
        case 1: {
        
            for (int i = 0; i < (int)(dados_imoveis.size()); i++){
                cout << *dados_imoveis[i] << endl;
            }

            break;
        }

        //Parte 2 - Proprietario tem ou nao tem imovel
        case 2: {
            string propri;

            printf("Digite um proprietario para saber se ele tem algum imovel: ");
            getline(cin, propri);

            if (propriIdenti(dados_imoveis, propri)){
                printf("Proprietario tem imóvel\n");
            }

            else {
                printf("Proprietario NÃO tem imóvel\n");
            }   

            break;
        }



        //Parte 3 - Imoveis com valores iguais ou abaixo do esperado
        case 3: {
            float valor;

            printf("Digite o valor que você deseja para seu imóvel: ");
            do{
                cin >> valor;
                if(valor <= 0){
                    printf("Valor do imóvel invalido!! Deve ser maior ou igual a 0.\n");
                    printf("Digite novamente: ");
                }
            } while(valor <= 0); 

            vector<Imovel*> auxValor = valorBarato(dados_imoveis, valor);

            if (auxValor.empty()){

                printf("MUIIITO BARATO\n");
            }

            for(int i = 0; i < (int)(auxValor.size()); i++){

                cout << *auxValor[i] << endl;
            }
            break;
        }

        //Parte 4 - Numero de quartos esperado
        case 4:{
            int nquartos;
            printf("Digite o numero de quartos que você deseja em seu imovel: ");
            do{
                cin >> nquartos;
                if(nquartos <= 0){
                    printf("Numero de quartos invalido! Deve ser maior ou igual a 0.\n");
                    printf("Digite novamente: ");
                }
            } while(nquartos <= 0); 

            vector <Imovel*> auxQuarto = muitosQuartos(dados_imoveis, nquartos);

            for(int i = 0; i < (int)(auxQuarto.size()); i++){

                cout << *auxQuarto[i] << endl;
            }

            break;
        }


        /*Parte 5 - Dado um tipo de imovel, criar uma fuNcao que retorne uma colecao de todos os imoveis deste tipo 
        ordenados pelo seu respectivo valor e exibir os imoveis no main, imprimindo todas as suas caracterısticas
        especificas; */
        case 5: {
            int imo ; // Sendo 1 como o imovel casa, 2 como imovel apartamento e 3 como imovel chacara

            printf("Digite qual imovel você deseja (1 - Casa, 2 - Apartamento, 3 - Chacara): ");
            do{
                cin >> imo;
                if(imo < 1 && imo > 3){
                    printf("Imóvel invalido! Deve ser 1 (Casa), 2(Apartamento) ou 3(Chacara)\n");
                    printf("Digite novamente: ");
                }

            } while(imo < 1 && imo > 3); 

            vector <Imovel*> auxIm = imovelUnico(dados_imoveis, imo);

            for (Imovel* aux : auxIm){

                if (typeid (*aux).name() == typeid(class Casa).name()){

                    Casa* tmp = dynamic_cast<Casa *> (aux);
                    cout << fixed << setprecision(2) << tmp->getValor() << endl;
                    cout << "----- \n";
                    cout << "CASA" << endl;
                    cout << "Andares: " << tmp->getAndares() << endl;
                    cout << "Sala de jantar: ";
                    if (tmp->getSalaJantar()){
                        cout << "SIM!!\n" << endl;
                    }  

                    else {
                        cout <<"NAO!!\n" << endl;
                    }

                    cout << "----- \n";
                }

                else if(typeid (*aux).name() == typeid(class Apartamento).name()){

                    Apartamento* tmp = dynamic_cast<Apartamento*> (aux);
                    cout << fixed << setprecision(2) << tmp->getValor() << endl;
                    cout << "----- \n";
                    cout << "APARTAMENTO" << endl;
                    cout << "Andar: " << tmp->getAndar() << endl;
                    cout << "Taxa de condominio: " << tmp->getTaxaCondominio() << endl;
                    cout << "Elevador: ";
                    if (tmp->getElevador()){
                        cout << "SIM!!" << endl;
                    }  

                    else {
                        cout <<"NAO!!" << endl;
                    }

                    cout << "Sacada: ";
                    if (tmp->getSacada()){
                        cout << "SIM!!\n" << endl;
                    }  

                    else {
                        cout <<"NAO!!\n" << endl;
                    }
                    cout << "----- \n";
                }

                else if(typeid (*aux).name() == typeid(class Chacara).name()){

                    Chacara* tmp = dynamic_cast<Chacara*> (aux);
                    cout << fixed << setprecision(2) << tmp->getValor() << endl;
                    cout << "----- \n";
                    cout << "CHACARA" << endl;
                    cout << "Salão de festa: ";
                    if (tmp->getSalaoFesta()){
                        cout << "SIM!!" << endl;
                    }  

                    else {
                        cout <<"NAO!!" << endl;
                    }


                    cout << "Salao de jogos: ";
                    if (tmp->getSalaoJogos()){
                        cout << "SIM!!" << endl;
                    }  

                    else {
                        cout <<"NAO!!" << endl;
                    }


                    cout << "Campo de futebol: ";
                    if (tmp->getCampoFutebol()){
                        cout << "SIM!!" << endl;
                    }  

                    else {
                        cout <<"NAO!!" << endl;
                    }


                    cout << "Churrasqueira: ";
                    if (tmp->getChurrasqueira()){
                        cout << "SIM!!" << endl;
                    }  

                    else {
                        cout <<"NAO!!" << endl;
                    }


                    cout << "Piscina: ";
                    if (tmp->getPiscina()){
                        cout << "SIM!!\n" << endl;
                    }  

                    else {
                        cout <<"NAO!!\n" << endl;
                    }
                    cout << "----- \n";
                }
            }

            break;
        }


        /*Parte 6 - Dada uma cidade, criar uma funcao que retorne uma unica colecao com todos os imoveis (casa,
        apartamento e chacara) que estejam localizados na cidade especificada. Os imoveis deverao ser exibidos
        no main em ordem decrescente em relacao ao seu valor. */
        case 6: {

            string cidade;

            printf("Digite o nome de uma cidade: ");

            getline(cin, cidade);

            vector<Imovel*> auxCity = cidadeImoveis(dados_imoveis, cidade);

            if(auxCity.empty()){

                printf("CIDADE NÃO EXISTENTE\n");
            }

            for (vector<Imovel*> :: reverse_iterator itr = auxCity.rbegin(); itr != auxCity.rend(); ++itr){

                cout << **itr;
            }

            break;
        }
        /*Parte 7 - Dado o nome de um proprietario, criar uma funcao que retorna um iterador para cada tipo de imovel 
        apontando para o elemento encontrado. No main deve ser mostrado se o imovel foi encontrado e os 
        dados do mesmo para cada um dos tipos de imovel (mostrar os dados comuns e especıficos do imovel 
        conforme o item a). */

        case 7: {
            string prop;

            printf("Digite um proprietario para saber se ele tem algum imovel: ");
            getline(cin, prop);

            vector <vector<Imovel*> :: iterator> vetordeitr;
            
            vetordeitr = retornaIterador(dados_imoveis, prop);

            if(vetordeitr.empty()){
                cout << "Proprietario sem Imoveis" << endl;
            }else{
                
            for(int i = 0; i < (int)(vetordeitr.size()); i++){

                cout << **vetordeitr[i];

            }}

            break;
        }
        
        /*Criar uma funcao que recebe uma unica colecao de imoveis de todos os tipos e que mostre no terminal 
        ou salve em um arquivo (saida.txt) todos os tipos de imoveis. Mostrar os dados comuns e especificos do
        imovel conforme o item a). Um argumento passado para a funcao define qual sera a saida. Nesse caso, é
        necessario downcasting.
        */
        case 8:{

            //se selecionado essa opção, imprime em um arquivo ou no terminal um vetor selecionado

            char aout, voue;
            int v;                                         //variaveis auxiliares
            string nome_arquivo;
            vector<Imovel*> vetor_arquivo;

            do{//seleciona o tipo de saida
                cout << "Deseja adicionar a um arquivo texto, ou mostrar no terminal?"<< endl;
                cout << "(Digite 'a' para arquivo ou 't' para terminal): ";
                cin >> aout;

                if(!(aout == 'a' || aout == 't'))
                    cout << "Por favor digite um valor valido !!" << endl;
                
            }while(!(aout == 'a' || aout == 't'));//segurança

            

            do{//seleciona que tipo de vetor
                cout << "Deseja escolher um vetor, ou escrever manuamente?"<< endl; 
                cout << "(Digite 'v' para selecionar um vetor ou 'e' para escrever manualmente): ";
                cin >> voue;

                if(!(voue == 'v' || voue == 'e'))
                    cout << "Por favor digite um valor valido !!" << endl;
                
            }while(!(voue == 'v' || voue == 'e'));

            if(voue == 'v'){//caso seja vetor
                cout << "Quais imoveis voce deseja:" << endl;

                do{
                    cout << "Digite: " << endl 
                    << "1 para imoveis limitados por um preço" << endl
                    << "2 para imoveis com uma certa quantidade de quartos" << endl
                    << "3 para um tipo especifico de imovel" << endl
                    << "4 para imoveis de um cidade especifica" << endl
                    << "5 para imoveis de um proprietario especifico" << endl;
                    cin >> v;

                    if(v < 1 || v > 5){
                        cout << "Digite um valor valido" << endl;
                    }
                }while(v < 1 || v > 5);

                vetor_arquivo = selecionaVetor(dados_imoveis, v);

            }else{//caso seja manualmente
                vetor_arquivo = vetorManual();
            }

            if(aout == 'a'){//caso seja arquivo
                if(vetor_arquivo.empty()){
                    cout << "Registro vazio, impossivel criar aquivo" << endl;
                }
                
                cout << "Qual o nome do arquivo(digite o nome depois .txt): " << endl;
                cin >> nome_arquivo;

                salvaArquivo(nome_arquivo, vetor_arquivo);
            }else{//caso seja printar no terminal
                if(vetor_arquivo.empty()){
                    cout << "Registro vazio, impossivel criar aquivo" << endl;
                }

                for(int i = 0; i < (int)(vetor_arquivo.size()); i++) {//printa o vetor
                    cout << fixed << setprecision(2);
                    cout << *vetor_arquivo[i] << endl;
                }
            }
            
            break;
        }
        
    }
    
    return EXIT_SUCCESS;
}