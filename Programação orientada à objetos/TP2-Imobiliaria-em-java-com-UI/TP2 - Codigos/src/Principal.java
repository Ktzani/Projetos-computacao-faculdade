import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Vector;

public class Principal {

    public static void main(String[] args) throws FileNotFoundException  {
        
        Imovel pontCasa = null;

        Imovel pontAP = null;

        Imovel pontCHA = null;

        Vector <Imovel> dados_imoveis = new Vector<Imovel>();
        
        File caminho = new File ("database_imoveis.txt");

        FileReader lerCaminhoTexto = new FileReader(caminho);

        BufferedReader lerArquivo = new BufferedReader(lerCaminhoTexto);

        try{
            while(lerArquivo.ready()){
                String texto = lerArquivo.readLine();
                String textoSplit [] = texto.split(";");

                // Vamos guardar cada uma das linhas desse arquivo em um vetor de ponteiros para onde cada posiçao dessa ou terá 
                // os itens de uma classe casa, itens de um classe apartamento ou itens de uma classe chacara
                if (textoSplit[0].equals("casa")){

                    pontCasa = new Casa(1, Float.parseFloat(textoSplit[1]), textoSplit[2], textoSplit[3], textoSplit[4], textoSplit[5], Integer.parseInt(textoSplit[6]), Integer.parseInt(textoSplit[7]), Integer.parseInt(textoSplit[8]), Integer.parseInt(textoSplit[9]), Func.intToBoolean(textoSplit[10]));
                    dados_imoveis.add(pontCasa); //guardo um objeto da classe Casa com seus construtores ja executados
                                                 //no final do vetor

                }

                else if (textoSplit[0].equals("apartamento")){

                    pontAP = new Apartamento(2, Float.parseFloat(textoSplit[1]), textoSplit[2], textoSplit[3], textoSplit[4], textoSplit[5], Integer.parseInt(textoSplit[6]), Integer.parseInt(textoSplit[7]), Integer.parseInt(textoSplit[8]), Integer.parseInt(textoSplit[9]), Float.parseFloat(textoSplit[10]), Func.intToBoolean(textoSplit[11]), Func.intToBoolean(textoSplit[12]));
                    dados_imoveis.add(pontAP);  //guardo um objeto da classe Apartamento com seus construtores ja executados
                                                //no final do vetor
                }

                else if (textoSplit[0].equals("chacara")){

                    pontCHA = new Chacara(3, Float.parseFloat(textoSplit[1]), textoSplit[2], textoSplit[3], textoSplit[4], textoSplit[5], Integer.parseInt(textoSplit[6]), Integer.parseInt(textoSplit[7]), Integer.parseInt(textoSplit[8]), Func.intToBoolean(textoSplit[9]), Func.intToBoolean(textoSplit[10]), Func.intToBoolean(textoSplit[11]), Func.intToBoolean(textoSplit[12]), Func.intToBoolean(textoSplit[13]));
                    dados_imoveis.add(pontCHA); //guardo um objeto da classe Chacara com seus construtores ja executados
                                                //no final do vetor

                }
            }

            lerArquivo.close();

        } catch (IOException e){

            System.out.println("Arquivo não encontrado");
        }

        Scanner entrada1 = new Scanner(System.in);

        int teste;

        System.out.print("Digite qual metodo desejas executar (entre 1 e 8): ");

        teste = entrada1.nextInt();

        //Vejo qual funçao sera executada entre as todas que foram pedidas pelo TP de acordo com o numero que foi passado como 
        //argumento na execução do programa
        switch (teste){

            //Parte 1 - Sobrecarga do operador cout
            case 1:{
                for (Imovel elem : dados_imoveis){

                    System.out.println(elem);
                }
            
                break;
            }

            //Parte 2 - Proprietario tem ou nao tem imovel
            case 2: {  
                Scanner entrada2 = new Scanner(System.in);

                String propri;

                System.out.print("Digite um proprietario para saber se ele possui algum imovel: " );
                
                propri = entrada2.nextLine();

                if (Func.propriIdenti(dados_imoveis, propri)){

                    System.out.println("Proprietario tem imovel");
                }

                else {

                    System.out.println("Proprietario NAO tem imovel");
                }  

                entrada2.close();

                break;
            }

            //Parte 3 - Imoveis com valores iguais ou abaixo do esperado
            case 3: {
                Scanner entrada3 = new Scanner(System.in);

                float valor;

                System.out.printf("Digite o valor que voce deseja para seu imovel: ");

                do{
                    
                    valor = entrada3.nextFloat();
                    if(valor <= 0){
                        System.out.print("Valor do imovel invalido!! Deve ser maior ou igual a 0.\n");
                        System.out.print("Digite novamente: ");
                    }

                } while(valor <= 0);

                Vector <Imovel> auxValor = Func.valorBarato(dados_imoveis, valor);

                if (auxValor.isEmpty()){

                    System.out.println("MUIIITO BARATO");
                    break;
                }

                for(Imovel elem : auxValor){

                    System.out.println(elem);
                }

                entrada3.close();
            }

            //Parte 4 - Numero de quartos esperado
            case 4: {
                Scanner entrada4 = new Scanner(System.in);
                int nquartos;

                System.out.print("Digite o numero de quartos que voce deseja em seu imovel: ");
                do{
                    nquartos = entrada4.nextInt();
                    if(nquartos <= 0){
                        System.out.print("Numero de quartos invalido! Deve ser maior ou igual a 0.\n");
                        System.out.print("Digite novamente: ");
                    }
                } while(nquartos <= 0);
                
                Vector <Imovel> auxQuarto = Func.muitosQuartos(dados_imoveis, nquartos);

                for (Imovel elem : auxQuarto){

                    System.out.println(elem);
                }

                entrada4.close();

                break;
            }

            /*Parte 5 - Dado um tipo de imovel, criar uma fuNcao que retorne uma colecao de todos os imoveis deste tipo 
            ordenados pelo seu respectivo valor e exibir os imoveis no main, imprimindo todas as suas caracterısticas
            especificas; */
            case 5: {
                Scanner entrada5 = new Scanner(System.in);
                int imo;

                System.out.print("Digite qual imovel você deseja (1 - Casa, 2 - Apartamento, 3 - Chacara): ");

                do{
                    imo = entrada5.nextInt();
                    if(imo < 1 && imo > 3){
                        System.out.print("Imovel invalido! Deve ser 1 (Casa), 2(Apartamento) ou 3(Chacara)\n");
                        System.out.print("Digite novamente: ");

                    }
                } while(imo < 1 && imo > 3); 

                Vector <Imovel> auxIm = Func.imovelUnico(dados_imoveis, imo);

                for (Imovel aux : auxIm){
                    if(aux instanceof Casa){

                        Casa temp = (Casa) aux;

                        System.out.printf("%.2f", temp.getValor());
                        System.out.print("----- \n");
                        System.out.print("CASA\n");
                        System.out.printf("Andares: %d\n", temp.getAndares());

                        System.out.print("Sala de Jantar: ");
                        if(temp.getSala_jantar()){
                            System.out.print("SIM!!\n\n");
                        }

                        else{
                            System.out.print("NÃO!!\n\n");
                        }
                    }

                    else if(aux instanceof Apartamento){

                        Apartamento temp = (Apartamento) aux;
                        System.out.printf("%.2f", temp.getValor());
                        System.out.print("----- \n");
                        System.out.print("APARTAMENTO\n");
                        System.out.printf("Andar: %d\n",  temp.getAndar());
                        System.out.printf("Taxa de Condominio: %.2f\n",  temp.getTaxa_condominio());

                        System.out.print("Elevador: ");
                        if(temp.getElevador()){
                            System.out.print("SIM!!\n");
                        }

                        else {
                            System.out.print("NÃO!!\n");
                        }

                        System.out.print("Sacada: ");
                        if(temp.getSacada()){
                            System.out.print("SIM!!\n\n");
                        }

                        else {
                            System.out.print("NÃO!!\n\n");
                        }

                        System.out.print("----- \n");
                    }

                    else if(aux instanceof Chacara){

                        Chacara temp = (Chacara) aux;
                        System.out.printf("%.2f", temp.getValor());
                        System.out.print("----- \n");
                        System.out.print("CHACARA\n");
                        
                        System.out.print("Salão de festa: ");
                        if(temp.getSalao_festa()){
                            System.out.print("SIM!!\n");
                        }

                        else{
                            System.out.print("NÃO!!\n");
                        }

                        System.out.print("Salão de jogos: ");
                        if(temp.getSalao_jogos()){
                            System.out.print("SIM!!\n");
                        }

                        else{
                            System.out.print("NÃO!!\n");
                        }

                        System.out.print("Campo de Futebol: ");
                        if(temp.getCampo_futebol()){
                            System.out.print("SIM!!\n");
                        }

                        else{
                            System.out.print("NÃO!!\n");
                        }

                        System.out.print("Churrasqueira: ");
                        if(temp.getChurrasqueira()){
                            System.out.print("SIM!!\n");
                        }

                        else{
                            System.out.print("NÃO!!\n");
                        }

                        System.out.print("Piscina: ");
                        if(temp.getPiscina()){
                            System.out.print("SIM!!\n\n");
                        }

                        else{
                            System.out.print("NÃO!!\n\n");
                        }

                        System.out.print("----- \n");
                    }
                }

                entrada5.close();
                break;
            }

            /*Parte 6 - Dada uma cidade, criar uma funcao que retorne uma unica colecao com todos os imoveis (casa,
            apartamento e chacara) que estejam localizados na cidade especificada. Os imoveis deverao ser exibidos
            no main em ordem decrescente em relacao ao seu valor. */
            case 6:{
                Scanner entrada5 = new Scanner(System.in);
                String cidade;

                System.out.print("Digite o nome de uma cidade: ");

                cidade = entrada5.nextLine();

                Vector<Imovel> auxCity =  Func.cidadeImoveis(dados_imoveis, cidade);

                if(auxCity.isEmpty()){

                    System.out.print("CIDADE NÃO EXISTENTE\n");
                    break;
                }

                for(Imovel elem : auxCity){

                    System.out.println(elem);
                }

                entrada5.close();
                
                break;
            }

            /*Parte 7 - Dado o nome de um proprietario, criar uma funcao que retorna um iterador para cada tipo de imovel 
            apontando para o elemento encontrado. No main deve ser mostrado se o imovel foi encontrado e os 
            dados do mesmo para cada um dos tipos de imovel (mostrar os dados comuns e especıficos do imovel 
            conforme o item a). */
            case 7:{
                Scanner entrada6 = new Scanner(System.in);
                String prop;

                System.out.print("Digite um proprietario para saber se ele tem algum imóvel: ");
                prop = entrada6.nextLine();

                Vector <Imovel> vetordeProp = Func.retornaPropries(dados_imoveis, prop);

                if (vetordeProp.isEmpty()){
                    System.out.println("Proprietario sem Imoveis");
                    break;
                }

                Iterator <Imovel> iterador = vetordeProp.iterator();

                while (iterador.hasNext()){

                    System.out.println(iterador.next());
                } 

                entrada6.close();
                
                break;
            }

            /*Criar uma funcao que recebe uma unica colecao de imoveis de todos os tipos e que mostre no terminal 
            ou salve em um arquivo (saida.txt) todos os tipos de imoveis. Mostrar os dados comuns e especificos do
            imovel conforme o item a). Um argumento passado para a funcao define qual sera a saida. Nesse caso, é
            necessario downcasting.
            */
            case 8:{


                break;
            }
        }

        entrada1.close();
    }
}
  