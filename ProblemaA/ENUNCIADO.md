# Problema A - La etapa reina

Las carreras de ultradistancia, conocidas popularmente como *ultras*, son uno de
los grandes fenómenos del atletismo amateur. En cada etapa, los corredores se
enfrentan a decenas (a veces cientos) de kilómetros de un tirón, frecuentemente
por terreno de montaña, midiéndose contra el reloj y contra sí mismos.

Estamos organizando una nueva *ultra* por etapas que se disputará en alta montaña
y queremos diseñar la etapa reina: ese tramo legendario del recorrido que
decidirá la clasificación general y del que se hablará durante años. Tenemos un
sendero ya trazado y bien señalizado, del que conocemos la altitud en cada uno de
sus puntos kilométricos consecutivos. La etapa reina será un tramo contiguo de
este sendero, de un punto kilométrico a otro pasando por todos los intermedios.

Como es la etapa estrella, queremos que sea lo más larga posible: cuantos más
kilómetros, más sufrimiento, más mérito, más prestigio. Pero todo tiene un
límite: si la etapa tiene demasiado desnivel, ni los corredores de élite van a
terminarla, y eso es muy mala publicidad. Por seguridad y por reputación, hemos
decidido que dentro de la etapa la diferencia entre el punto más alto y el más
bajo no podrá superar cierta cantidad de metros. Sabemos que con esa cota
cualquiera de nuestros corredores la podrá completar.

Dadas las altitudes del sendero, ¿cuál es el mayor número de puntos kilométricos
consecutivos que podemos incluir en la etapa reina sin que el desnivel supere el
límite fijado?

## Entrada

La entrada está formada por una serie de casos de prueba. En la primera línea
aparece el número $T$ de casos que aparecerán a continuación ($0 \le T \le 1000$).

Cada caso comienza con una línea con dos enteros $N$ y $D$, donde $N$ es el número
de puntos kilométricos del sendero ($1 \le N \le 10^6$) y $D$ el desnivel máximo
permitido en metros ($0 \le D \le 10^6$). A continuación aparece una línea con $N$
enteros entre 0 y $10^6$, las altitudes en metros del sendero en sus $N$ puntos
kilométricos consecutivos, en el orden en el que se recorren. La suma de los
valores de $N$ de todos los casos no excederá $10^6$.

## Salida

Para cada caso de prueba se escribirá una línea con un único número: el mayor
número de puntos kilométricos consecutivos del sendero cuya diferencia entre la
altitud máxima y la mínima no excede $D$ metros.

## Ejemplos

### Entrada de ejemplo
```
3
8 3
14 12 13 15 16 14 17 19
6 0
1000 1000 999 1000 1000 1000
5 100
1050 1030 1080 1060 1040
```

### Salida de ejemplo
```
4
3
5
```
