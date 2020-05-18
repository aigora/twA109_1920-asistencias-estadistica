#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SerialPort.h"
#define MAX_DATA_LENGTH 255
// Funciones prototipo
void autoConnect(SerialPort *arduino,char*);
FILE * crear_fichero (void);
void leer_fichero (FILE *);

int main(void)
{
 //Arduino SerialPort object
 SerialPort *arduino;
 // Puerto serie en el que está Arduino
 char* portName = "\\\\.\\COM3";
 // Buffer para datos procedentes de Arduino
 char incomingData[MAX_DATA_LENGTH];

 // Crear estructura de datos del puerto serie
 arduino = (SerialPort *)malloc(sizeof(SerialPort));
 // Apertura del puerto serie
 Crear_Conexion(arduino,portName);
 autoConnect(arduino,incomingData);
}
void autoConnect(SerialPort *arduino,char *incomingData)
{
 int readResult;

// Espera la conexión con Arduino
 while (!isConnected(arduino))
 {
  Sleep(100);
  Crear_Conexion(arduino,arduino->portName);
 }
 //Comprueba si arduino está connectado
 if (isConnected(arduino))
 {
  printf ("Conectado con Arduino en el puerto %s\n",arduino->portName);
 }
 // Bucle de la aplicación
  while (isConnected(arduino))
  {
    readResult = readSerialPort(arduino,incomingData,
    MAX_DATA_LENGTH);
    if (readResult!=0)
       printf("%s - %d\n", incomingData,readResult);
       FILE *mifichero;
       mifichero = crear_fichero();//add
       leer_fichero (mifichero);//add
    Sleep(10);
  }
 if (!isConnected(arduino))
   printf ("Se ha perdido la conexión con Arduino\n");
}
void leer_fichero (FILE *mifichero)
{
  int n,i,cierre;
  mifichero = fopen ("datos.txt","r");
  
  if (mifichero==NULL)
    printf ("Error no se ha podido abrir el fichero\n");
  else
  {
     fscanf (mifichero,"%d",&n); 
     while (!feof(mifichero)) 
     {
       printf ("Acabo de leer=%d\n",n);
       fscanf (mifichero,"%d",&n);
     }
    cierre = fclose (mifichero);
    if (cierre == EOF)
        printf ("Problemas al cerrar\n");// Acciones asociadas a la imposibilidad de cerrar el fichero.
    else
        printf ("Todo ok\n");
         // Acciones asociadas una vez cerrado el fichero
  }
  return;
}

FILE * crear_fichero (void)
{
  FILE *mifichero;
  int i,cierre;

  mifichero = fopen ("datos.txt","w"); //Destructiva 
  if (mifichero==NULL)
    printf ("Error no se ha podido abrir el fichero\n");
  else
  {
     //acciones a realizar en el fichero ****************
     cierre = fclose (mifichero);
     if (cierre == EOF)
        printf ("Problemas al cerrar\n");// Acciones asociadas a la imposibilidad de cerrar el fichero.
    else
        printf ("Todo ok\n");
         // Acciones asociadas una vez cerrado el fichero
  }
  return mifichero;
}
