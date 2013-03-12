 /* El fichero ejecutable LECTOR es usado en el proceso hijo de 
    "escritor.c". 
    Este programa convierte a mayúsculas los datos almacenados en
    el área de memoria compartida. Después, muestra por pantalla 
    el resultado de la conversión */

# include "prac7.h"

int main (int argc, char *argv [])
{
  //pid_t pid;
  key_t llave;
  int segmento, semaforo;
  //int valorH, valorP;
  char *memoria = NULL;  // Si lo declaro como una tabla, no compila.
  int i = 0;
  struct sembuf OpSemaforo;

  /* Creación de una llave */  
  llave = ftok ( "escritor.c", 'A');
  
  /* Petición de una zona de memoria compartida */
  segmento = shmget ( llave, MAX * sizeof (char), IPC_CREAT | 0600); 

  /* Asocia la zona de memoria compartida a nuestro espacio
     de direcciones virtuales */
  memoria = shmat ( segmento, 0, 0);

  /* Petición de dos semáforos */
  semaforo = semget ( llave, 2, IPC_CREAT | 0666 );

  /* No hace falta inicializar otra vez los semáforos, porque 
     ya lo ha hecho el padre */

  while (1)
  {
  
     /* Cierra el semáforo del hijo */
       OpSemaforo.sem_num = SEM_HIJO;
       OpSemaforo.sem_op = -1;
       OpSemaforo.sem_flg = 0;
       semop (semaforo, &OpSemaforo, 1);

  fflush (stdin);
  i = 0;  
  while (*(memoria+i) != '\0') 
  {
    putchar ( toupper ( *(memoria+i) ) );
    i++;
  }
  
              /* Abre el semáforo del padre */
       OpSemaforo.sem_num = SEM_PADRE;
       OpSemaforo.sem_op = 1;
       semop (semaforo, &OpSemaforo, 1);
  }

  return 0;
  
}

