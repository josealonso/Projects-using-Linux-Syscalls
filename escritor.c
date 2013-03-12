/* ESCRITOR.C: Programa para la práctica 7
   Escribe en un bloque de memoria compartida los datos
   leídos desde teclado. Cuando el usuario pulsa 'q',
   el escritor lanza al proceso LECTOR para que éste
   lea del bloque de memoria compartida. */

# include "prac7.h"
  
int main (int argc, char *argv[])  
{
  pid_t pid;
  key_t llave;
  int segmento, semaforo;
  // int valorH, valorP;
  char *memoria;  // Si lo declaro como una tabla, no compila.
  // int j, i = 0;
  int i = 0;
  struct sembuf OpSemaforo;

  /* Crea una llave */  
  llave = ftok ( "escritor.c", 'A');
  
  /* Pide una zona de memoria compartida */
  segmento = shmget ( llave, MAX * sizeof (char), IPC_CREAT | 0600); 

  /* Asocia la zona de memoria compartida a nuestro espacio
     de direcciones virtuales */
  memoria = shmat ( segmento, 0, 0);

  /* Pide dos semáforos */
  semaforo = semget ( llave, 2, IPC_CREAT | 0666 );

  /* Inicializa los semáforos. El del padre está abierto (vale 1),
     mientras que el del hijo está cerrado (vale 0).
     Ambos son semáforos binarios. */
  semctl (semaforo, SEM_PADRE, SETVAL, 1);
  semctl (semaforo, SEM_HIJO, SETVAL, 0);

  system ("clear");
  if ((pid = fork()) == -1)
    {
    perror ("\nError:");
    exit (-1);
    }

/************************ Proceso hijo *************************/
  else if (pid == 0)
    {     
          /* execl ("./lector", (char *) NULL );   warning: not enough variable arguments to fit a sentinel [-Wformat] */
       execl ("./lector", "lector", (char *) NULL ); /* Da paso al lector */
    }
    
/************************ Proceso padre *************************/
  else
    { 
       while (1)
       {
       OpSemaforo.sem_flg = 0;

       /* Cierra el semáforo del padre */
       OpSemaforo.sem_num = SEM_PADRE;
       OpSemaforo.sem_op = -1;
       semop (semaforo, &OpSemaforo, 1);

       printf ("\nEscriba el texto que desea convertir a mayúsculas:\n");
       printf ("Para acabar, pulse la tecla de fin de línea y luego la Z \n\n\n\n");

       fflush (stdin);// IMPRESCINDIBLE. Si no lo pones,no sale del while
      
    /* Lee un carácter del teclado y lo guarda en mem. compartida  */
       while ( ( *(memoria+i) = getchar () ) != 'Z') 
       {
         i++;
       }

       *(memoria+i) = '\0';
       i = 0;
       fflush (stdout);
       fflush (stdin);
      
       /* Abre el semáforo del hijo */
       OpSemaforo.sem_num = SEM_HIJO;
       OpSemaforo.sem_op = 1;
       semop (semaforo, &OpSemaforo, 1);

       } /* Llave del "while" */

   } /* Llave del proceso padre */     

  return 0;
}  
    

