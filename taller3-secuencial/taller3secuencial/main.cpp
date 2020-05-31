#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

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
        /*if(a==15){ //sirve para limitar la cantiddad de filas leidas del archivo
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
    std::cout << "Taller 3: C++ secuencial" << std::endl;
    generarresultado();
    delete [] listaNEM;
    delete [] listaRAN;
    delete [] listaMAT;
    delete [] listaLEN;
    delete [] listaCIE;
    delete [] listaHIS;
    return EXIT_SUCCESS;
}