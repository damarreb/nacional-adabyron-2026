# Introducción a la solución

Nos dan las altitudes de los $N$ puntos de un sendero y un límite $D$, y nos
piden el mayor número de puntos **consecutivos** que podemos tomar de forma que
la diferencia entre la altitud máxima y la mínima de ese tramo no supere $D$.
Dicho de otro modo: buscar el subarreglo contiguo más largo cuyo *desnivel*
(máximo menos mínimo) sea $\le D$.

Como $D \ge 0$, un único punto siempre es un tramo válido (su desnivel es $0$),
así que la respuesta nunca baja de $1$.

# La observación clave

Todas las técnicas que veremos se apoyan en la misma propiedad: **si un tramo
es válido, cualquier subtramo suyo también lo es**. Al quitar puntos de los
extremos, el máximo sólo puede bajar y el mínimo sólo puede subir, de modo que
el desnivel nunca aumenta. Esta monotonía es la que hace que el problema tenga
soluciones eficientes: no necesitamos mirar los $O(N^2)$ tramos posibles.

El enfoque ingenuo de comprobar todos los pares (inicio, fin) y calcular su
desnivel es $O(N^2)$ (o peor). Con $N$ hasta $10^6$ y la suma de todos los $N$
hasta $10^6$, eso es inviable: necesitamos algo cercano a $O(N)$ o
$O(N \log N)$.

# Técnica 1: búsqueda binaria sobre la longitud

Definimos el predicado

$$P(L) = \text{«existe algún tramo de exactamente } L \text{ puntos con desnivel} \le D\text{»}.$$

Por la observación clave, $P$ es *monótono*: si hay un tramo válido de longitud
$L$, al recortarlo obtenemos uno válido de longitud $L-1$, luego
$P(L) \Rightarrow P(L-1)$. Existe por tanto un umbral: $P$ es cierto hasta una
cierta longitud máxima y falso a partir de ahí. Esa longitud máxima es justo la
respuesta, y la encontramos con **búsqueda binaria** sobre $L \in [1, N]$.

Lo único que necesitamos es ser capaces de evaluar $P(L)$ rápido. Hay que
recorrer todas las ventanas de tamaño fijo $L$ y comprobar si alguna tiene
desnivel $\le D$; es decir, calcular el máximo y el mínimo de cada ventana
deslizante de tamaño $L$. Eso se hace en $O(N)$ con dos *colas monótonas*
(_deques_): una que mantiene los candidatos a máximo en orden decreciente y otra
los candidatos a mínimo en orden creciente. Al avanzar la ventana, el frente
de cada cola da el máximo y el mínimo actuales.

Coste: $O(N)$ por evaluación de $P$, y $O(\log N)$ evaluaciones, total
$O(N \log N)$.

# Técnica 2: ventana deslizante con *multiset*

Podemos resolverlo con **dos punteros** de forma más directa. Mantenemos una
ventana $[l, r]$ y la idea es: para cada extremo derecho $r$, ¿cuál es el $l$
más pequeño que la mantiene válida?

Ese $l$ óptimo nunca retrocede al avanzar $r$. En efecto, si para un cierto
$r$ el menor inicio válido es $l$, al pasar a $r+1$ añadimos un punto que sólo
puede aumentar el desnivel; nunca podremos permitirnos un inicio más a la
izquierda que $l$. Por eso $l$ sólo avanza, y en total recorre el arreglo una
única vez.

El único ingrediente que falta es conocer el máximo y el mínimo de la ventana
en cada momento para saber si hay que encogerla. Un
[`multiset`](https://en.cppreference.com/w/cpp/container/multiset) lo resuelve
de forma cómoda: guarda las altitudes de la ventana ordenadas, con lo que
`*begin()` es el mínimo y `*rbegin()` el máximo. Al avanzar $r$ insertamos
$a[r]$; mientras el desnivel supere $D$, sacamos $a[l]$ y avanzamos $l$.

Como cada punto se inserta y se borra a lo sumo una vez, y cada operación del
`multiset` cuesta $O(\log N)$, el total es $O(N \log N)$.

Esta es, por su sencillez, la solución de referencia (`A.cpp`).

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [A.cpp](src/A.cpp) | Ventana deslizante con `multiset`, $O(N \log N)$. | :white_check_mark: |
| [A_binaria.cpp](src/A_binaria.cpp) | Búsqueda binaria sobre la longitud + colas monótonas, $O(N \log N)$. | :white_check_mark: |
