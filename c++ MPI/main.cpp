#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <mpi.h>
#define LARGO 5015751


using namespace std;
vector<int> obtenerPuntajes(std::string linea);

struct datos{
    std::string rut;
    unsigned int ranking;
    unsigned int nem;
    unsigned int matematica;
    unsigned int lenguaje;
    unsigned int ciencias;
    unsigned int historia;
};

struct puntajes{
    float promedio;
    float desviacion;
    float mediana;
    float moda;
};

int contador=0;
datos prueba;
puntajes NEM, RANKING, MATEMATICA, LENGUAJE, CIENCIA, HISTORIA;
float prom;
float des;
float med;
float mod;


int *listaNEM = new int [5015751];
int *listaRAN = new int [5015751];
int *listaMAT = new int [5015751];
int *listaLEN = new int [5015751];
int *listaCIE = new int [5015751];
int *listaHIS = new int [5015751];


void ordenar(int x[], int n) //Metodo de ordenamiento seleccion
{
    int i, j, aux;
    for(i=1; i<n; i++){
        j=i-1;
        aux=x[i];
        while((j>-1)&&(aux<x[j])){
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=aux;
    }
}

void desmedmod(int x[], int n, puntajes p){ // calculo de, desviacion estandar, media y moda
    float prome = p.promedio;
    float acumulador = 0; // El acumulador es La sumatoria de (Xi - Xpromedio) al cuadrado
    int aux2; 
    int cont = 0, contmoda = 0, xmoda=0, aux=0;
    for(int i=0; i<n; i++){
        acumulador = acumulador + ((x[i] - prome)*(x[i] - prome));
        if(x[i]!=aux || i+1 == n){
            if(i+1 ==n){
                cont++;
            }
            if(cont > contmoda){
                contmoda = cont;
                xmoda = i-1;
            }
            aux = x[i];
            cont = 0;
        }
        cont = cont + 1;
    }
    des = sqrt(acumulador/n); 
    aux2= n/2; //Para obtener la posición intermedia del arreglo
    med = x[aux2];
    mod = x[xmoda];
}

void promedio(unsigned int suma){ //calcula el promedio
    prom = suma /(float)contador;
} 

void imprimir()
{
    std::cout<<"===Nem==="<<std::endl;
    std::cout<<"Promedio: "<<NEM.promedio<<std::endl;
    std::cout<<"Desviacion estandar: "<<NEM.desviacion<<std::endl;
    std::cout<<"Moda: "<<NEM.moda<<std::endl;
    std::cout<<"Mediana: "<<NEM.mediana<<std::endl;
    std::cout<<"===Ranking==="<<std::endl;
    std::cout<<"Promedio: "<<RANKING.promedio<<std::endl;
    std::cout<<"Desviacion estandar: "<<RANKING.desviacion<<std::endl;
    std::cout<<"Moda: "<<RANKING.moda<<std::endl;
    std::cout<<"Mediana: "<<RANKING.mediana<<std::endl;
    std::cout<<"===Matematica==="<<std::endl;
    std::cout<<"Promedio: "<<MATEMATICA.promedio<<std::endl;
    std::cout<<"Desviacion estandar: "<<MATEMATICA.desviacion<<std::endl;
    std::cout<<"Moda: "<<MATEMATICA.moda<<std::endl;
    std::cout<<"Mediana: "<<MATEMATICA.mediana<<std::endl;
    std::cout<<"===Lenguaje==="<<std::endl;
    std::cout<<"Promedio: "<<LENGUAJE.promedio<<std::endl;
    std::cout<<"Desviacion estandar: "<<LENGUAJE.desviacion<<std::endl;
    std::cout<<"Moda: "<<LENGUAJE.moda<<std::endl;
    std::cout<<"Mediana: "<<LENGUAJE.mediana<<std::endl;
    std::cout<<"===Ciencias==="<<std::endl;
    std::cout<<"Promedio: "<<CIENCIA.promedio<<std::endl;
    std::cout<<"Desviacion estandar: "<<CIENCIA.desviacion<<std::endl;
    std::cout<<"Moda: "<<CIENCIA.moda<<std::endl;
    std::cout<<"Mediana: "<<CIENCIA.mediana<<std::endl;
    std::cout<<"===Historia==="<<std::endl;
    std::cout<<"Promedio: "<<HISTORIA.promedio<<std::endl;
    std::cout<<"Desviacion estandar: "<<HISTORIA.desviacion<<std::endl;
    std::cout<<"Moda: "<<HISTORIA.moda<<std::endl;
    std::cout<<"Mediana: "<<HISTORIA.mediana<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout << std::endl << "===Integrantes===" << std::endl;
    std::cout << "Sebastián Garrido Valenzuela" << std::endl;
    std::cout << "Ramiro Uribe Garrido" << std::endl;
    std::cout << "Javier Gálvez González" << std::endl;
}



void generarresultado(){
    int a=0, ne=0, ra=0, ma=0, le=0, ci=0, hi=0;
    ifstream  lectura; 
    lectura.open("puntajes.csv",ios::in);
    if(!lectura.is_open()){
        std::cout <<"El archivo puntajes.csv no existe en la ruta" <<std::endl;
        return ;
    }
    for(std::string linea; std::getline(lectura,linea); ){
        a++;
        std::stringstream registro (linea);
        std::string dato;
        for(int columna = 0; std::getline(registro, dato, ';'); columna++){
            switch (columna){
            case 1:
                contador++;
                prueba.nem = prueba.nem + std::stoi(dato);
                listaNEM[ne]=std::stoi(dato);
                ne++;
                break;
            case 2:
                prueba.ranking = prueba.ranking + std::stoi(dato);
                listaRAN[ra]=std::stoi(dato);
                ra++;
                break;
            case 3:
                prueba.matematica = prueba.matematica + std::stoi(dato);
                listaMAT[ma]=std::stoi(dato);
                ma++;
                break;
            case 4:
                prueba.lenguaje = prueba.lenguaje + std::stof(dato);
                listaLEN[le]=std::stoi(dato);
                le++;
                break;
            case 5:
                prueba.ciencias = prueba.ciencias + std::stoi(dato);
                listaCIE[ci]=std::stoi(dato);
                ci++;
                break;
            case 6:
                prueba.historia = prueba.historia + std::stoi(dato);
                listaHIS[hi]=std::stoi(dato);
                hi++;
            break;
            }

        }
        /*if(a==5){ //sirve para limitar la cantiddad de filas leidas del archivo
            break;
        }*/
    }
    lectura.close();
    promedio(prueba.nem);
    NEM.promedio = prom;
    promedio(prueba.ranking);
    RANKING.promedio = prom;
    promedio(prueba.matematica);
    MATEMATICA.promedio = prom;
    promedio(prueba.lenguaje);
    LENGUAJE.promedio = prom;
    promedio(prueba.ciencias);
    CIENCIA.promedio = prom;
    promedio(prueba.historia);
    HISTORIA.promedio = prom;
    
    ordenar(listaNEM, contador);
    ordenar(listaRAN, contador);
    ordenar(listaMAT, contador);
    ordenar(listaLEN, contador);
    ordenar(listaCIE, contador);
    ordenar(listaHIS, contador);
    

    desmedmod(listaNEM, contador, NEM);
    NEM.desviacion = des;
    NEM.mediana = med;
    NEM.moda = mod;
    desmedmod(listaRAN, contador, RANKING);
    RANKING.desviacion = des;
    RANKING.mediana = med;
    RANKING.moda = mod;
    desmedmod(listaMAT, contador, MATEMATICA);
    MATEMATICA.desviacion = des;
    MATEMATICA.mediana = med;
    MATEMATICA.moda = mod;
    desmedmod(listaLEN, contador, LENGUAJE);
    LENGUAJE.desviacion = des;
    LENGUAJE.mediana = med;
    LENGUAJE.moda = mod;
    desmedmod(listaCIE, contador, CIENCIA);
    CIENCIA.desviacion = des;
    CIENCIA.mediana = med;
    CIENCIA.moda = mod;
    desmedmod(listaHIS, contador, HISTORIA);
    HISTORIA.desviacion = des;
    HISTORIA.mediana = med;
    HISTORIA.moda = mod;
    
    imprimir();
}

//Funcion main
int main(int argc, char** argv) {
    int mi_rango; //rango del proceso
    int procesadores; // numero de procesos
    int maestro = 0; // Procesador maestro
    int escritor = 1; // Procesador escritor
    int tag = 0; // etiqueta del mensaje
    MPI_Status estado; // devuelve estado al recibir
    
    std::string parar("STOP"); //Este string se usara para detener los hilos paralelos

    if (argc > 1) {
     
        MPI_Init(&argc, &argv); // Se comienza las llamadas a MPI

        
        MPI_Comm_rank(MPI_COMM_WORLD, &mi_rango); // Se obtiene el rango del proceso

//Tras obtener el número de procesos que estan ejecutando en el programa 

        MPI_Comm_size(MPI_COMM_WORLD, &procesadores);

        if (procesadores < 3) {
            fprintf(stderr, "\nSe requiere al menos 3 procesadores para ejecutar el programa\n");
            return EXIT_FAILURE;
        }
        if (mi_rango == 0) {
            //Proceso maestro

            std::string ruta(argv[1]);
            std::ifstream entrada(ruta);
            if (entrada) {
                 // Estrategia:
                 //El procesador 0 como maestro (lee y distribuye)
                 //El procesador 1 como escritor (recibe los promedios y escribe en disco)
                 // Otros procesadores para realizar calculos de funciones
                int procesador = 2;
                for (std::string lectura; getline(entrada, lectura);) {
                        std::stringstream registro (lectura);
                        std::string dato;
                    for(int columna = 0; std::getline(registro, dato, ';'); columna++){
                        int procesador = 2;
                        if (!dato.empty()) {
                            switch(columna){
                                case 1:
                                    // Usa length +1 para que la marca /0 se transmita //
                                    MPI_Send((char *) dato.c_str(), dato.length() + 1, MPI_CHAR, procesador, tag, MPI_COMM_WORLD);
                                    break;
                                case 2:
                                    if (procesador +1 >= procesadores) {
                                        procesador = 2;
                                    }
                                    MPI_Send((char *) dato.c_str(), dato.length() + 1, MPI_CHAR, procesador +1, tag, MPI_COMM_WORLD);
                                    break;
                                case 3:
                                    if (procesador +2>= procesadores) {
                                        procesador = 2;
                                    }                                   
                                    MPI_Send((char *) dato.c_str(), dato.length() + 1, MPI_CHAR, procesador +2, tag, MPI_COMM_WORLD);
                                    break;
                                case 4:
                                    if (procesador +3>= procesadores) {
                                        procesador = 2;
                                    }                                    
                                    MPI_Send((char *) dato.c_str(), dato.length() + 1, MPI_CHAR, procesador +3, tag, MPI_COMM_WORLD);
                                    break;
                                case 5:
                                    if (procesador +4>= procesadores) {
                                        procesador = 2;
                                    }  
                                    MPI_Send((char *) dato.c_str(), dato.length() + 1, MPI_CHAR, procesador +4, tag, MPI_COMM_WORLD);
                                    break;
                                case 6:
                                    if (procesador +5 >= procesadores) {
                                        procesador = 2;
                                    }  
                                    MPI_Send((char *) dato.c_str(), dato.length() + 1, MPI_CHAR, procesador +5, tag, MPI_COMM_WORLD);
                                    break;
                            }
                        }
                    }
                }
                std::cout << std::endl;

                for (procesador = 2; procesador < procesadores; procesador++) {
                    MPI_Send((char *) parar.c_str(), parar.length() + 1, MPI_CHAR, procesador, tag, MPI_COMM_WORLD);
                }

                entrada.close();
            }
        } /*else if (mi_rango == 1) {

            // Este procesador recibe los datos para procesarlo         
            
            bool procesados[procesadores];
            for (int i = 0; i < procesadores; i++) {
                procesados[i] = true;
            }
            procesados[0] = false;
            procesados[1] = false;

            while (isAnyOk(procesados, procesadores)) {
                for (int procesador = 2; procesador < procesadores; procesador++) {
                    if (procesados[procesador]) {
                        char* escritura = (char *) calloc(LARGO, sizeof (char));
                        MPI_Recv(escritura, LARGO, MPI_CHAR, procesador, tag, MPI_COMM_WORLD, &estado);
                        std::string texto(escritura);
                        if (parar.compare(texto) == 0 || texto.empty()) {
                            procesados[procesador] = false;
                        } else {
                            salida << texto << std::endl;
                        }
                        free(escritura);
                    }
                }
            }
            salida.close();
        } */
        else {
            /* Obtengo el mensajes */
            while (true) {
                char* mensaje = (char *) calloc(LARGO, sizeof (char));
                MPI_Recv(mensaje, LARGO, MPI_CHAR, maestro, tag, MPI_COMM_WORLD, &estado);
                std::string fila(mensaje);
                if (parar.compare(fila) == 0 || fila.empty()) {
                    // No hay datos, se debe salir del loop
                    MPI_Send((char *) parar.c_str(), parar.length() + 1, MPI_CHAR, escritor, tag, MPI_COMM_WORLD);
                    break;
                } 
                /*else {
                    vector<int> puntajes = obtenerPuntajes(fila);
                    //std::cout<< puntajes<<endl; //no funciona
                    /*if (puntajes.size() >= 6) {
                        int rut = puntajes.at(0);
                        int nem = puntajes.at(1);
                        int ranking = puntajes.at(2);
                        int matematica = puntajes.at(3);
                        int lenguaje = puntajes.at(4);
                        int ciencias = puntajes.at(5);
                        int historia = puntajes.at(6);

                        double promedio = (nem + ranking + matematica + lenguaje + ciencias + historia) / 6.0;
                        std::string fila;
                        fila = std::to_string(rut) + ";" + to_string(promedio);

                        MPI_Send((char *) fila.c_str(), fila.length() + 1, MPI_CHAR, escritor, tag, MPI_COMM_WORLD);
                    }*/
                }
                //free(mensaje);
            }


        }

        /* Termina con MPI. Recordemos que después de 
         * esta llamada no podemos llamar a funciones 
         * MPI, ni siquiera de nuevo a MPI_Init 
         */
        MPI_Finalize();

    
    return EXIT_SUCCESS;
}
    /*std::cout << "Taller 3: C++ secuencial" << std::endl;
    generarresultado();
    delete [] listaNEM;
    delete [] listaRAN;
    delete [] listaMAT;
    delete [] listaLEN;
    delete [] listaCIE;
    delete [] listaHIS;
    return EXIT_SUCCESS;*/
