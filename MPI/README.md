# Integrantes
* *Deivyd Dario Parra Perilla - 2162916*
* *Juan Diego Atehortua Duque - 2182064*

## Busqueda Binaria

Este código implementa dos funciones clave: `bubble_sort` y `binary_search`. La función `bubble_sort` se encarga de ordenar una lista de números utilizando el algoritmo de burbuja. En este proceso, los elementos adyacentes se comparan y se intercambian si están en el orden incorrecto. Este ciclo de comparación y intercambio continúa hasta que la lista esté completamente ordenada de manera ascendente.

Por otro lado, la función `binary_search` realiza una búsqueda de un valor específico en una lista ordenada utilizando el algoritmo de búsqueda binaria. En este algoritmo, la lista se divide repetidamente por la mitad y se compara el valor buscado con el elemento en el medio. Dependiendo del resultado de esta comparación, la búsqueda se enfoca en la mitad superior o inferior de la lista. Este proceso se repite hasta que se encuentra el valor buscado o hasta que la lista se reduce a cero, lo que indica que el valor no está presente en la lista.

Los pasos para ejecutar el algoritmo son:

* *Pedir una reserva interactiva:*

```
srun -n 16 -N 2 --pty /bin/bash
```

* *Luego debemos hacer la carga del modulo que nos permitirá ejecutar el MPI:*
```
module load  devtools/mpi/openmpi/4.1.2
```

* *Compilamos el codigo usando:* 
```
mpicc -fopenmp binarySearch_MPI.c -o binarySearch_MPI
```
Aqui despues de -fopenmp agregamos respectivas etiquetas de compilacion, se usaron -O, -O1

* *Lo ejecutamos usando:*
```
mpirun -np 16 binarySearch_MPI
```
Tiempo tomado para ordenar la lista: 18.170000 seconds

* *Lo ejecutamos usando:*
```
mpirun -np 16 binarySearch_MPIoO
```
Tiempo tomado para ordenar la lista: 15.146700 seconds

* *Lo ejecutamos usando:* 
```
mpirun -np 16 binarySearch_MPIO1
```
Tiempo tomado para ordenar la lista: 16.139800 seconds

Los resultados muestran una perdida de rendimiento cuando se hace uso de la etiqueta "O1" si se compara con las demás en donde la "O" deja ver un mejor rendimiento.

## Postman Sort
Para realizar la paralelización de este algoritmo usando MPI, el proceso inicializa el arreglo y además inicia la primera fase del algoritmo, la cual implica ordenar los elementos en base al número de dígitos. 
A continuación, se comparten las variables necesarias para el algoritmo, como la longitud del arreglo (n), a través de una operación de broadcast.

Una vez que todas las variables necesarias están disponibles para todos los procesos, se procede a dividir equitativamente el arreglo entre el número de procesos. Esto se logra utilizando la función `MPI_Scatter`, la cual distribuye eficientemente el arreglo entre los procesos disponibles. Cada proceso ejecuta la segunda fase del algoritmo, la cual implica ordenar su parte correspondiente del arreglo. Una vez que cada proceso ha completado esta tarea, se recopilan los subarreglos ordenados utilizando `MPI_Gather`, lo que permite que el proceso raíz obtenga el arreglo completo y ordenado.

Para calcular el tiempo total de ejecución del algoritmo, se registra el tiempo del proceso que ha tardado más en ordenar su parte del arreglo. Este tiempo se utiliza como referencia para determinar el tiempo total de ejecución del algoritmo.

Los pasos para ejecutar el algoritmo son:

* *Pedir una reserva interactiva:*
```
srun -n 4 --pty /bin/bash
```

* *Luego cargamos el modulo de MPI:*
```
module load devtools/mpi/openmpi/4.1.2 
```

* *Compilamos el codigo usando:*
```
mpicc -fopenmp postmansort_mpi.c -o postmansort_mpi
```

[ddparrap@guane11 ParcialII]$ mpirun -np 4 ./postmansort_mpi
Work took 40.957892 seconds
[ddparrap@guane11 ParcialII]mpirun --mca btl_openib_allow_ib true -np 2 postmansort_mpi0
Work took 35.150583 seconds
[ddparrap@guane11 ParcialII]mpirun --mca btl_openib_allow_ib true -np 2 postmansort_mpi01
Work took 28.917649 seconds
