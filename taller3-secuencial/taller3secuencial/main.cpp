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
    unsigned float promedio;
    unsigned float desviacion;
    unsigned float mediana;
    unsigned float moda;
};


int contador=0;
datos prueba;
puntajes NEM, RANKING, MATEMATICA, LENGUAJE, CIENCIA, HISTORIA;
float prom;


void ordenar(vector x, int n)
{
    int aux;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            if(x[j+1] < x[j]){
                aux = x[j];
                x[j] = x[j+1];
                x[j+1] = aux;
            }
        }
    }
}

void desmedmod(vector x, int n, puntajes p)
{
    float prome = p.promedio;
    float acumulador = 0, aux; // El acumulador es La sumatoria de (Xi - Xpromedio) al cuadrado, y el otro para dividir por n aplicar raiz cuadrada
    int contador = 0, contmoda = 0, aux2; //Primero es el contador y otro es el contador de una moda
    float xmoda= 0, x2 = 0; //Para obtener el puntaje en moda
    for(int i=0; i<n; i++)
    {
        acumulador = acumulador + ((x[i] - prome)*(x[i] - prome));
        if(x[i+1] =! x2) //En caso de que la posicion siguiente es distinto a la actual
        {
            contador++;
            if(contador > contmoda){ //Se verifica si el contador es mayor la de moda
                xmoda = x2;
                contmoda = contador;
                
            }
            if(x[i+1]!=NULL){
                acumulador = acumulador + ((x[i+1] - prome)*(x[i+1] - prome));
            }
            x2 = x[i+1]; //Se reinicia para contar el dato que se encuentre actualmente
            contador = 0;
            i++;         
        }
        contador++;
    }
    aux = sqrt(acumulador/n); 
    aux2 = n/2; //Para obtener la posición intermedia del arreglo
    p.desviacion = aux;
    p.mediana = x[aux2];
    p.moda = xmoda;
}

void promedio(unsigned int suma, puntajes p){
    prom = suma /(float)contador;
    p.promedio = prom;
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
    int a=0;
    ifstream  lectura; 
    lectura.open("puntajes.csv",ios::in);
    for(std::string linea; std::getline(lectura,linea); ){
        a++;
        std::stringstream registro (linea);
        std::string dato;
        for(int columna = 0; std::getline(registro, dato, ';'); columna++){
            switch (columna){
            case 0:
                //std::cout << dato << "  rut" << std::endl;
                //prueba.rut = dato;
                break;
            case 1:
                //fpromedio(dato, prueba.nem);
                contador++;
                prueba.nem = prueba.nem + std::stof(dato);
                break;
            case 2:
                //contadorR++;
                //std::cout << dato << "  ranking" << std::endl;
                prueba.ranking = prueba.ranking + std::stof(dato);
                break;
            case 3:
                //contadorM++;
                //std::cout << dato << "  matematica" << std::endl;
                prueba.matematica = prueba.matematica + std::stof(dato);
                break;
            case 4:
                //contadorL++;
                //std::cout << dato << "  lenguaje" << std::endl;
                prueba.lenguaje = prueba.lenguaje + std::stof(dato);
                break;
            case 5:
                //contadorC++;
                //std::cout << dato << "  historia" << std::endl;
                prueba.ciencias = prueba.ciencias + std::stof(dato);
                break;
            case 6:
                //contadorH++;
                //std::cout << dato << "  ciencia" << std::endl;
                prueba.historia = prueba.historia + std::stof(dato);
            break;
            }

        }
        /*if(a==4){
            break;
        }*/
    }
    promedio(prueba.nem, NEM);
    promedio(prueba.ranking, RANKING);
    promedio(prueba.matematica, MATEMATICA);
    promedio(prueba.lenguaje, LENGUAJE);
    promedio(prueba.ciencias, CIENCIA);
    promedio(prueba.historia, HISTORIA);
    
    imprimir();
}

//Funcion main
int main(int argc, char** argv) {
    std::cout << "Taller 3: C++ secuencial" << std::endl;
    generarresultado();
    return EXIT_SUCCESS;
    
}