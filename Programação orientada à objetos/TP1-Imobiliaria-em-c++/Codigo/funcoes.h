#ifndef FUNCOES_H
#define FUNCOES_H

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

using namespace std;

bool propriIdenti (vector <Imovel*> imoveis, string propri);

vector<Imovel*> valorBarato (vector <Imovel*> imoveis, float valor);

vector<Imovel*> muitosQuartos (vector <Imovel*> imoveis, int quartos); 

vector<Imovel*> imovelUnico (vector <Imovel*> imoveis, int imo);

vector<Imovel*> cidadeImoveis (vector <Imovel*> imoveis, string cidade);

vector<Imovel*> bubble_sort(vector<Imovel*> imoveis);

vector<string> explode(string const & s, char delim); 

vector<vector<Imovel*> :: iterator> retornaIterador(vector<Imovel*> imoveis, string propri);

vector<Imovel*> selecionaVetor(vector <Imovel*> dados_imoveis, int v);

void salvaArquivo(string nome, vector<Imovel*> imoveis);

vector<Imovel*> vetorManual();

#endif