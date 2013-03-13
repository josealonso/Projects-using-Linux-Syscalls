 /* PRAC7.H */

# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h> 
# include <ctype.h>     // includes the toupper function

# define SEM_PADRE 0
# define SEM_HIJO 1
# define MAX 1000


