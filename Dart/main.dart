import 'dart:io';
import 'dart:math';
import 'dart:convert';
import 'dart:async';

double promedionem;  //NEM
double desviacionnem;
double mediananem;
double modanem;

double promedioran; //RANKING
double desviacionran;
double medianaran;
double modaran;

double promediomat; //MATEMATICA
double desviacionmat;
double medianamat;
double modamat;

double promediolen;  //LENGUAJE
double desviacionlen;
double medianalen;
double modalen;

double promediocie;  //CIENCIA
double desviacioncie;
double medianacie;
double modacie;

double promediohis; //HISTORIA
double desviacionhis;
double medianahis;
double modahis;

void imprimir(){
  print("===NEM===");
  print("Promedio: ${promedionem}");
  print("Desviación estandar: ${desviacionnem}");
  print("Moda: ${modanem}");
  print("Mediana: ${mediananem}");

  print("===RANKING===");
  print("Promedio: ${promedioran}");
  print("Desviación estandar: ${desviacionran}");
  print("Moda: ${modaran}");
  print("Mediana: ${medianaran}");

  print("===Matematica===");
  print("Promedio: ${promediomat}");
  print("Desviación estandar: ${desviacionmat}");
  print("Moda: ${modamat}");
  print("Mediana: ${medianamat}");

  print("===Lenguaje===");
  print("Promedio: ${promediolen}");
  print("Desviación estandar: ${desviacionlen}");
  print("Moda: ${modalen}");
  print("Mediana: ${medianalen}");

  print("===Ciencia===");
  print("Promedio: ${promediocie}");
  print("Desviación estandar: ${desviacioncie}");
  print("Moda: ${modacie}");
  print("Mediana: ${medianacie}");

  print("===Historia===");
  print("Promedio: ${promediohis}");
  print("Desviación estandar: ${desviacionhis}");
  print("Moda: ${modahis}");
  print("Mediana: ${medianahis}\n");

  print("==Integrantes===");
  print("Sebastián Garrido Valenzuela");
  print("Ramiro Uribe Garrido");
  print("Javier Gálvez Gonzalez");
}

int truncar(numero)
{
  double multiplier = 0.5;
  return (numero-multiplier).toInt();
}

double promedios(List hola)
{
  double suma=0;
  double promedio;
  for(int i=0;i<hola.length;i++)
  {
    suma=suma+hola[i];
  }
  promedio=suma/hola.length;
  return promedio;

}

double desviacion(List hola)
{
  double suma=0;
  double promedio=promedios(hola);
  for(int i=0;i<hola.length;i++)
  {
    suma=suma+(pow(hola[i]-promedio,2));
  }
  double aux=suma/hola.length;
  double desviacion_final=pow(aux,0.5);   
 
  return desviacion_final;
  
}

double moda(List x){
  x.sort();
  int cont=0;
  int contmoda=0;
  int xmoda=0;
  double aux=0;
  double moda;
  for (int i=0;i<x.length;i++)
  {
    if(x[i]!=aux || i+1==x.length)
    {
      if(i+1==x.length)
      {
        cont++;
      }
      if(cont>contmoda)
      {
        contmoda=cont;
        xmoda=i-1;
      }
      aux= x[i];
      cont=0;
    }
    cont=cont+1;

  }
  moda= x[xmoda];
  return moda;
  
}

double mediana(List hola)
{
  hola.sort();
  double aux=hola.length/2;
  double aux2=(hola.length/2)+1;
  int largo=hola.length;
  int aux1=truncar(aux);
  int aux3=truncar(aux2);
  double mediana;
  if(largo%2==0)
  {
    mediana=(hola[aux1]+hola[aux3])/2;
  }
  else
  {
    mediana=hola[aux1];
  }
  return mediana;
}

void llenar(File hola)
{
  for(int i=0;i<10;i++)
  {
    hola.writeAsStringSync("${i};${i};${i};${i};${i};${i};${i}\r\n", mode:APPEND);
  }
}
void crearPuntajes(File puntajes){
  print("Se estan creando los puntajes ... Espere un momento por favor");
  Random random = new Random();   
  for (var i = 0; i <=14; i++) {   //Ciclo en el cual se crearan los puntajes
    int NEM = 475 + random.nextInt(276);
    int RKN = 475 + random.nextInt(276);
    int MAT = 475 + random.nextInt(276);
    int LEN = 475 + random.nextInt(276);
    int CIE = 475 + random.nextInt(276);
    int HIS = 475 + random.nextInt(276);
    puntajes.writeAsStringSync("${i};${NEM};${RKN};${MAT};${LEN};${CIE};${HIS}\r\n", mode:APPEND); //Escritura sobre el archivo puntajes
    
    
  }
  print("Se han creado los puntajes");
}
void calculos()
{
  List<double> mate=new List();
  List<double> len=new List();
  List<double> cien=new List();
  List<double> his=new List();
  List<double> nemu=new List();
  List<double> rank=new List();
  int contador = 0;
  var documento = new File('puntajes.csv');   //Aqui se lee el archivo
  Stream<List<int>> inputStream = documento.openRead(1);
  inputStream
    .transform(utf8.decoder)       // Decode bytes to UTF-8.
    .transform(new LineSplitter()) // Convert stream to individual lines.
    .listen((String linea) {        // Process results
        var separar = linea.split(";");
        double nem = double.parse(separar[1]);
        double ranking = double.parse(separar[2]);
        double matematica = double.parse(separar[3]);
        double lenguaje = double.parse(separar[4]);
        double ciencia = double.parse(separar[5]);
        double historia = double.parse(separar[6]);
        nemu.add(nem);
        rank.add(ranking);
        mate.add(matematica);
        len.add(lenguaje);
        cien.add(ciencia);
        his.add(historia);
        contador = contador + 1;
        if(contador == 5015751){ //Total 5015751 filas del archivo.csv
          // Calculos de promedios
          promedionem = promedios(nemu);
          promedioran = promedios(rank);
          promediomat = promedios(mate);
          promediolen = promedios(len);
          promediocie = promedios(cien);
          promediohis = promedios(his);
          //Calculos de desviaciones estandares
          desviacionnem = desviacion(nemu);
          desviacionran = desviacion(rank);
          desviacionmat = desviacion(mate);
          desviacionlen = desviacion(len);
          desviacioncie = desviacion(cien);
          desviacionhis = desviacion(his);
          //Calculos de moda
          modanem = moda(nemu);
          modaran = moda(rank);
          modamat = moda(mate);
          modalen = moda(len);
          modacie = moda(cien);
          modahis = moda(his);
          //Calculos de mediana
          mediananem = mediana(nemu);
          medianaran = mediana(rank);
          medianamat = mediana(mate);
          medianalen = mediana(len);
          medianacie = mediana(cien);
          medianahis = mediana(his);
          //Imprimir resultados
          imprimir();
        }
    },
    onDone: () { print('File is now closed.'); },
    onError: (e) { print(e.toString()); });     // Process results.
  print(nemu);

}
void main()
{
 // File llenado= new File("archivo.csv");
 // File calculo= new File("calculo.csv");
 // crearPuntajes( );
  print("Taller 3: Dart \n");
  calculos();
  
}