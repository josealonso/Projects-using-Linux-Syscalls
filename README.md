Projects-using-Linux-Syscalls
=============================

In this repository, there will be small projects, most of them required for the Operating System Course 
at my University (http://www.uah.es).

                        B A S I C  I P C
                        
Files: prac7.h, escritor.c, lector.c, makefile_ipc.

Description: Two cyclic processes are going to be created. One is called the writter and the other one
is the reader. Both processes will use a syncronyzation mechanism, to avoid simultaneous accesses to 
the same data. The writer process will try to write the data input from the keyboard onto a shared memory area.
Then, the reader process will transform those data into uppercase letters. When the user enters the "Z" letter, 
the writer will finish its task and will launch the reader process, so that the data stored on the shared memory
area will be read. To finish, the reader will write the transformed data on the screen. Then, the cycle will be 
repeated until the user exits from the program, by pressing Ctrl^C. 

To guarantee that the reader will not be executed until the writer finishes, two binaries semaphores are used, one per process. The writer is the parent process, since it is the first one to be executed, and the reader is the child process. Therefore, in the beginning the parent semaphore has a value of one (open access), while the child semaphore has a value of zero (blocked access). Each process, right before executing itself, decrements its semaphore value. And right before finishing its execution, each process increments its semaphore value, allowing the execution of the other process.
 

To compile this project, type:

make -f makefile_ipc

And the executables called lector and escritor will be created. Run the escritor executable and that's all.

                         TODO

- Declare the shmem area only once.
- Make the comments Doxygen-friendly.
- Translate everything into English.
- Use a nameless pipe (the mknod syscall) to communicate both processes in a more elegant way.
