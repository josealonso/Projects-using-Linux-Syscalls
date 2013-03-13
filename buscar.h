/* BUSCAR.H */

#ifndef __BUSCAR__H
#define __BUSCAR__H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int ContarCaracteres (int descriptor, char *caracter);
/*
 This program returns the number of ocurrences of the "caracter" character 
 inside the file asocciated with the "descriptor" file descriptor.
*/

#endif

