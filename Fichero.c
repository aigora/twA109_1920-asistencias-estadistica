#include <stdio.h>
#include <stdlib.h>

FILE * crear_fichero (void);

int main(void)
{
  FILE *mifichero;

   mifichero = crear_fichero();

  return 0;
}

FILE * crear_fichero (void)
{
  FILE *mifichero;
  int cierre;

  mifichero = fopen ("Arduino.txt","w"); //Destructiva 
  if (mifichero==NULL)
    printf ("Error no se ha podido abrir el fichero\n");
  else
  {
     cierre = fclose (mifichero);

     if (cierre == EOF);
	    // Acciones asociadas a la imposibilidad de cerrar el fichero.
     else;
        // Acciones asociadas una vez cerrado el fichero
  }
  return mifichero;
}
