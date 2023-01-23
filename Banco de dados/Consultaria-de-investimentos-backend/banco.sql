CREATE TABLE Usuario (
    codigo serial PRIMARY KEY,
    nome VARCHAR ( 50 ) NOT NULL,
    login VARCHAR ( 20 ) UNIQUE NOT NULL,
    senha VARCHAR ( 50 ) NOT NULL,
    logradouro VARCHAR ( 50 ) NOT NULL,
    complemento VARCHAR ( 20 ),
    numero INT NOT NULL,
    bairro VARCHAR ( 50 ) NOT NULL,
    CEP DECIMAL (8,0) NOT NULL, -- Certo?
    cidade VARCHAR ( 50 ) NOT NULL,
    estado CHAR (2) NOT NULL
);
 
CREATE TABLE Telefone_usuario (
    codigo_usuario INT NOT NULL,
    telefone VARCHAR ( 20 ) NOT NULL, -- Certo?
    CONSTRAINT FK_Usuario FOREIGN KEY (codigo_usuario) REFERENCES Usuario (codigo)
);
 
CREATE TABLE Pessoa_Fisica (
    codigo_usuario INT UNIQUE NOT NULL,
    sexo CHAR ( 1 ) CHECK (sexo == M || sexo == F) NOT NULL,
    data_nascimento TIMESTAMP NOT NULL,
    CONSTRAINT FK_Usuario FOREIGN KEY (codigo_usuario) REFERENCES Usuario (codigo)
);
 
CREATE TABLE Fundo_Investimentos (
    codigo_usuario INT UNIQUE NOT NULL,
    codigo_ativo INT NOT NULL,
    tipo VARCHAR ( 25 ) NOT NULL,
    CONSTRAINT FK_Usuario FOREIGN KEY (codigo_usuario) REFERENCES Usuario (codigo)
    CONSTRAINT FK_Ativo FOREIGN KEY (codigo_ativo) REFERENCES Classe_Ativos(codigo)
);
 
CREATE TABLE Pessoa_Juridica (
    codigo_usuario INT UNIQUE NOT NULL,
    CNAE INT NOT NULL,
    data_abertura TIMESTAMP NOT NULL,
    situacao_cadastral VARCHAR ( 20 ) NOT NULL,
    CONSTRAINT FK_Usuario FOREIGN KEY (codigo_usuario) REFERENCES Usuario (codigo)
);
 
CREATE TABLE Analista (
    nss INT UNIQUE NOT NULL PRIMARY KEY,
    nome VARCHAR ( 50 ),
    tipo VARCHAR ( 20 ) NOT NULL,
    login VARCHAR ( 20 ) UNIQUE NOT NULL,
    senha VARCHAR ( 50 ) NOT NULL,
    logradouro VARCHAR ( 50 ) NOT NULL,
    complemento VARCHAR ( 20 ),
    numero INT NOT NULL,
    bairro VARCHAR ( 50 ) NOT NULL,
    CEP DECIMAL (8,0) NOT NULL, -- Certo?
    cidade VARCHAR ( 50 ) NOT NULL,
    estado CHAR (2) NOT NULL
);
 
CREATE TABLE Telefone_analista (
    nss_analista INT NOT NULL,
    telefone VARCHAR ( 20 ) NOT NULL, -- Certo?
    CONSTRAINT FK_Analista FOREIGN KEY (nss_analista) REFERENCES Analista (nss)
);
 
CREATE TABLE Bolsa_valores (
    nome VARCHAR ( 50 ) UNIQUE NOT NULL,
    abreviacao VARCHAR ( 10 ) PRIMARY KEY,
    indice DECIMAL (9, 2) NOT NULL -- Certo?
);
 
CREATE TABLE Classe_ativos (
    codigo VARCHAR ( 10 ) PRIMARY KEY,
    bolsa VARCHAR ( 10 ) NOT NULL,
    CONSTRAINT FK_Ativos FOREIGN KEY (bolsa) REFERENCES Bolsa_valores (abreviacao)
);
 
CREATE TABLE Renda_Fixa(
    codigo VARCHAR ( 10 ) PRIMARY KEY,
    grupo VARCHAR ( 10 ) NOT NULL,
    CONSTRAINT FK_Renda_Fixa FOREIGN KEY (Codigo) REFERENCES Classe_ativos (codigo)
);

CREATE TABLE FII(
    codigo VARCHAR ( 10 ) PRIMARY KEY,
    setor VARCHAR ( 10 ) NOT NULL,
    dy INT NOT NULL,
    gestora VARCHAR ( 10 ) NOT NULL,
    CONSTRAINT FK_FII FOREIGN KEY (Codigo) REFERENCES Classe_ativos (codigo)
);

CREATE TABLE Acao(
    codigo VARCHAR ( 10 ) PRIMARY KEY,
    caixa DECIMAL (100,0) NOT NULL,
    tipo VARCHAR ( 10 ) NOT NULL,
    divida DECIMAL (5,0) NOT NULL,
    CONSTRAINT FK_ACAO FOREIGN KEY (Codigo) REFERENCES Classe_ativos (codigo)
);
 
CREATE TABLE Moeda(
    abreviacao VARCHAR ( 5 ) PRIMARY KEY,
    lastro VARCHAR ( 50 ) NOT NULL,
);
 
CREATE TABLE Moeda_Pais(
    moeda VARCHAR ( 5 ) PRIMARY KEY,
    pais VARCHAR ( 50 ) NOT NULL,
    CONSTRAINT FK_MOEDA_PAIS FOREIGN KEY (Moeda) REFERENCES Moeda(abreviacao) 
);
 
CREATE TABLE BDR(
    codigo VARCHAR ( 10 ) PRIMARY KEY,
    empresa_estrangeira VARCHAR ( 50 ) NOT NULL,
    fracao DECIMAL (2,0) NOT NULL,
    moeda VARCHAR ( 5 ) NOT NULL,
    CONSTRAINT FK_BDR_ACAO FOREIGN KEY (codigo) REFERENCES Acao(codigo),
    CONSTRAINT FK_BDR_MOEDA FOREIGN KEY (moeda) REFERENCES Moeda(abreviacao)
);
 
 
 
CREATE TABLE Consulta(
    id_consulta INT NOT NULL PRIMARY KEY,
    codigo_usuario INT NOT NULL,
    nss_analista INT NOT NULL,
    CONSTRAINT FK_CONSULTA_USUARIO FOREIGN KEY (codigo_usuario) REFERENCES Usuario(codigo)
    CONSTRAINT FK_CONSULTA_ANALISTA FOREIGN KEY (nss_analista) REFERENCES Analista(nss)
);

CREATE TABLE Investimento(
    codigo_usuario INT NOT NULL,
    data_compra TIMESTAMP NOT NULL,
    valor_corrente DECIMAL (8, 2) NOT NULL,
    quantidade INT NOT NULL,
    codigo_ativo INT NOT NULL,
    PRIMARY KEY (codigo_usuario, data_compra)
    CONSTRAINT FK_INVESTIMENTO_USUARIO FOREIGN KEY (codigo_usuario) REFERENCES Usuario(codigo),
    CONSTRAINT FK_INVESTIMENTO_CLASSE_ATIVOS FOREIGN KEY (codigo_ativo) REFERENCES Classe_Ativos(codigo)
);

CREATE TABLE Resulta_em(
    id_consulta INT NOT NULL
    codigo_usuario INT NOT NULL,
    data_compra TIMESTAMP NOT NULL
    CONSTRAINT FK_RESULTA_EM_INVESTIMENTO FOREIGN KEY (codigo_usuario, data_compra) REFERENCES Investimento (codigo_usuario, data_compra),
    CONSTRAINT FK_RESULTA_EM_CONSULTA FOREIGN KEY (id_consulta) REFERENCES Consulta (id_consulta)
);
 

