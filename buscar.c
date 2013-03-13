
/* BUSCAR.C */

# include "buscar.h"

int ContarCaracteres (int descriptor, char *caracter)
{
	int iNum, iContador=0;
	char acLetra[1];
	
/* Allocating memory dynamically is not needed, because only one character is read at a time */
	
	while((iNum=read(descriptor, acLetra, 1))!=0) // O indicates end of file.
	{
        if (*acLetra==*caracter)
	    iContador++;  // The number of ocurrences of the chosen character is incremented by one.
      }
	return iContador;
}

