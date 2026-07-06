# Problema M - Hogueras de San Juan

Dicen en el pueblo que la noche de San Juan no se mide en horas, sino en hogueras.
En cuanto el sol se rinde tras el mar, el paseo marítimo empieza a poblarse de
fuegos: unos pequeños y tímidos, otros enormes, levantados con muebles viejos y
promesas de quemar lo malo del año. Y entre el chisporroteo y el olor a sardina,
todo el mundo busca su sitio: ni tan cerca que se chamusque uno, ni tan lejos que
pase frío.

El paseo es completamente recto y está dividido en $N$ parcelas numeradas de 1 a
$N$ de un extremo al otro. En algunas de ellas los vecinos han prendido una
hoguera, y conforme avanza la noche surge la pregunta de siempre: ¿dónde se está
mejor?

Porque una hoguera no calienta solo su propia parcela. Una hoguera de *intensidad*
$c$ caldea con $c$ grados la parcela donde arde, con $c - 1$ grados las dos parcelas
contiguas, con $c - 2$ las que están a distancia 2, y así perdiendo un grado por
cada parcela que uno se aleja del fuego, hasta que el calor se desvanece en la
brisa. Dicho en números, una hoguera de intensidad $c$ situada en la parcela $p$
aporta a la parcela $q$ un calor de $\max(0,\ c - |q - p|)$ grados.

Cuando a una misma parcela le llega calor de varias hogueras (o tiene su propia
hoguera además del calor que le llega de las vecinas), los grados *se suman*. El
calor que se escapa más allá de los extremos del paseo (parcelas anteriores a la 1 o
posteriores a la $N$) simplemente se pierde en la noche.

Encendidas ya todas las hogueras, ayuda a los vecinos a saber cuánto calor se
disfruta en cada parcela del paseo, para que cada cual encuentre su sitio antes de
que empiecen los saltos.

## Entrada

La entrada está formada por varios casos de prueba. En la primera línea aparece el
número $T$ de casos que se mostrarán a continuación ($0 \le T \le 5000$).

Cada caso de prueba comienza con una línea con dos números, el número de parcelas
$N$ del paseo ($1 \le N \le 10^6$) y el número de hogueras $H$ ($1 \le H \le N$). A
continuación aparecen $H$ líneas, cada una con dos números $p$ y $c$, indicando que
en la parcela $p$ ($1 \le p \le N$) se ha encendido una hoguera de intensidad $c$
($1 \le c \le 10^5$). En cada parcela hay encendida, como mucho, una hoguera.

La suma de los valores de $N$ de todos los casos no supera $10^6$.

## Salida

Para cada caso de prueba se escribirá una línea con $N$ números separados por
espacios: el calor total que llega a cada una de las parcelas $1, 2, \ldots, N$, en
ese orden.

## Ejemplos

### Entrada de ejemplo
```
2
8 2
3 4
6 3
6 2
2 4
5 2
```

### Salida de ejemplo
```
2 3 4 4 4 4 2 1
3 4 3 3 3 1
```
