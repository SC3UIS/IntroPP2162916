El método de ordenamiento "Radix Sort", también conocido como algoritmo Postman, organiza los elementos de una lista según sus dígitos individuales. Es especialmente útil para ordenar números con una cantidad constante de dígitos.

Utilizaremos las herramientas proporcionadas en clase, como guane o guaneExa, para analizar los tiempos de ejecución de los procesos.

Para acceder al entorno, se debe utilizar el comando:

```
ssh guaneExa
```

Para compilar el código secuencial y medir los tiempos de ejecución con OpenMP, se debe ejecutar:

```
gcc -fopenmp postmansort.c -o postmansort
./postmansort
```
y
```
gcc -fopenmp omp_postmansort.c -o omp_postmansort
./omp_postmansort
```
![Parcial](https://github.com/0MonsieurChat0/Paralela/assets/100472763/6a09ec68-32e1-478b-bc30-a3c378b75934)

Posteriormente, se compara el tiempo de ejecución entre el código secuencial y el paralelizado.

**RESULTADOS DE LOS CÓDIGOS**



**Conclusión:**

El algoritmo Postman Sort(Radix Sort), implementado tanto en su versión secuencial como paralelizada, ha demostrado ser una herramienta eficaz para ordenar números basándose en sus dígitos individuales. Tras analizar los tiempos de ejecución, se observa que la versión paralelizada ofrece una mejora significativa en la velocidad de procesamiento en comparación con la versión secuencial. Esto resalta la importancia y eficiencia del procesamiento paralelo en tareas de ordenamiento, especialmente cuando se manejan conjuntos de datos extensos.
