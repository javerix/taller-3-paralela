#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

struct promedio{
    std::string rut;
    unsigned int ranking;
    unsigned int nem;
    unsigned int matematica;
    unsigned int lenguaje;
    unsigned int ciencias;
    unsigned int historia;
};
int contador=0;
promedio prueba;
float  prom;

void integrantes(){ //Integrantes del grupo
    std::cout << std::endl << "Integrantes:" << std::endl;
    std::cout << "Sebastián Garrido Valenzuela" << std::endl;
    std::cout << "Ramiro Uribe Garrido" << std::endl;
    std::cout << "Javier Gálvez González" << std::endl;
}   

float promedio(unsigned int suma, string nombre){
    prom = suma /(float)contador;
    std::cout<< "el promedio del "<< nombre<< " es: "<< prom<< std::endl;
    return prom;
} 


void generarprom(){
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
}

//Funcion main
int main(int argc, char** argv) {
    std::cout << "Taller 3: C++ secuencial" << std::endl;
    generarprom();
    std::cout<<prueba.nem<< " nem suma "<< contador<<" cantidad dde datos"<<endl;
    promedio(prueba.nem, "nem");
    std::cout<<prueba.ranking<< " ranking suma "<<endl;
    promedio(prueba.ranking, "ranking");
    std::cout<<prueba.matematica << " matematica suma "<<endl;
    promedio(prueba.matematica, "matematica");
    std::cout<<prueba.lenguaje << " lenguaje suma "<<endl;
    promedio(prueba.lenguaje, "lenguaje");
    std::cout<<prueba.ciencias<< " ciencias suma "<<endl;
    promedio(prueba.ciencias, "ciencia");
    std::cout<<prueba.historia<< " historia suma "<<endl;
    promedio(prueba.historia, "historia");
    integrantes();
    return EXIT_SUCCESS;
    
}