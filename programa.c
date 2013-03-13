/* PROGRAMA.C
  This is the main module */

# include "buscar.h"

int main(int argc, char *argv[])
{
  void proper_usage_message()
  {
    printf ("The executable, called \"busqueda\", has to be invocated with only two parameters, like this:\n");
    printf ("\t ./busqueda FileName Letter_To_Be_Searched\n\n");
  }

  int iDescriptor1, iRepeticiones;
        
  system ("clear");
  if (argc != 3)
  {
    proper_usage_message();
    return -1;
  }
       
  if (argc>3)
  {
    printf("ERROR: too many parameters\n");
    proper_usage_message();
    return -1;
  }
       
else
  {  
    if ((iDescriptor1=open(argv[1], O_RDONLY)) == -1)
    {
      perror ("\nError opening the file");
      return -1;
    }       
    else        
    {
      iRepeticiones=ContarCaracteres(iDescriptor1, argv[2]);    
      close(iDescriptor1); 
      printf ("\n\n\n\n\n\n\n\n\n\n\n");
      printf ("The number of ocurrences of the %c character inside the %s file is: %i\n\n", *argv[2], argv[1], iRepeticiones);
      return 1;
    } 
  } 
}

