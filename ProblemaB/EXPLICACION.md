# Introducción a la solución

Este es un problema interactivo. Al otro lado hay un servicio de
autocompletado que esconde un diccionario de palabras (cadenas de minúsculas,
todas distintas, de longitud a lo sumo $L$). Nosotros solo podemos hacer una
cosa: mandar un prefijo `pre` y el servicio nos responde con las hasta $K$
palabras lexicográficamente menores que empiezan por ese prefijo. Si hay más
de $K$, el resto quedan ocultas. Nuestro objetivo es reconstruir el diccionario
completo usando como mucho $4 \cdot 10^4$ consultas por caso, sin saber a
priori el tamaño del diccionario.

La dificultad es el tope $K$: una única consulta nunca nos garantiza
haberlo visto todo. Si preguntamos por un prefijo y nos devuelve exactamente $K$
palabras, no sabemos si esas son todas o si hay más escondidas detrás.

# Cómo lidiar con el límite $K$

Fijémonos en qué significa cada respuesta a una consulta `? p`:

- Si el juez devuelve **menos de $K$** palabras, hemos visto todas las que
  empiezan por `p`. No hay ninguna oculta, porque el juez solo se calla palabras
  cuando hay más de $K$. Este es nuestro caso base: prefijo *resuelto*.
- Si devuelve **exactamente $K$**, tenemos las $K$ menores con prefijo `p`, pero
  puede haber más. Eso sí, sabemos algo muy útil: llamemos `last` a la mayor de
  esas $K$ palabras. Como son las $K$ *menores*, todas las palabras con
  prefijo `p` que sean $\le$ `last` son exactamente las que nos han devuelto.
  Lo único que puede faltar son palabras con prefijo `p` **estrictamente
  mayores que `last`**.

Esa segunda idea es la palanca: cada consulta que se "llena" ($K$ resultados)
nos deja completamente resuelta la parte $\le$ `last`, y reduce el problema a
buscar lo que haya por encima de `last`.

Definimos una función recursiva

$$\mathrm{collect}(p) = \text{«averiguar todas las palabras del diccionario que empiezan por } p\text{»}.$$

Llamando a $\mathrm{collect}(\varepsilon)$ con el prefijo vacío obtenemos el
diccionario entero. La función procede así:

1. Consultamos `? p`. Si vienen menos de $K$ palabras, las añadimos al resultado
   y **terminamos**: no hay nada más con ese prefijo.
2. Si vienen exactamente $K$, las añadimos igualmente y tomamos `last`, la mayor.
   Ya sabemos que todo lo $\le$ `last` está cubierto; nos falta encontrar las
   palabras con prefijo `p` que sean **mayores** que `last`.

¿Cómo son esas palabras que faltan? Toda palabra $x$ con prefijo `p` y
$x >$ `last` cae en uno de dos grupos, según dónde se separe de `last`:

- **Continuaciones de `last`.** Si `last` es un prefijo de $x$ (es decir, $x$ es
  `last` seguida de más letras), basta con volver a lanzar la recursión sobre
  ese prefijo más largo: $\mathrm{collect}(\texttt{last})$. La propia consulta
  `? last` devuelve `last` y sus continuaciones.
- **Desvíos de `last`.** Si $x$ no tiene a `last` como prefijo pero es mayor,
  entonces $x$ coincide con `last` hasta una cierta posición $j$ y en esa
  posición lleva una letra $c$ **mayor** que `last[j]`. Para capturarlas
  recorremos cada posición $j$ (desde $|p|$ en adelante) y cada letra
  $c >$ `last[j]`, y lanzamos $\mathrm{collect}(\texttt{last[0..j-1]} + c)$.

Estos dos grupos son **disjuntos** y, entre los dos, cubren exactamente las
palabras que quedaban por encima de `last`. Además, cada llamada recursiva usa
un prefijo *estrictamente más largo* que `p` (la palabra `last`, al ser distinta
de `p` pero empezar por `p`, es forzosamente más larga que `p`; y los desvíos
tienen longitud $j + 1 > |p|$). Por tanto la profundidad de la recursión está
acotada por la longitud máxima $L \le 8$.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [B.cpp](src/B.cpp) | Recursión por prefijos: consultar, y ante $K$ resultados descomponer en continuaciones y desvíos de la mayor palabra. | :white_check_mark: |
