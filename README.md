Projects-using-Linux-Syscalls
=============================

In this repository, there will be small projects, most of them required for the Operating System Course 
at my University (http://www.uah.es).

                        B A S I C  I P C
                        
Files: prac7.h, escritor.c, lector.c, makefile_ipc.

Description:

To compile this project, type:

make -f makefile_ipc

And the executables called lector and escritor will be created. Run the escritor executable and that's all.

                         TODO

- Declare the shmem area only once.
- Make the comments Doxygen-friendly.
- Translate everything into English.
- Use a nameless pipe (the mknod syscall) to communicate both processes in a more elegant way.
