# Problema C - Las tablas de Ockham Park

> *Del diario particular de Charles Babbage.*
> *Londres, octubre de 1852.*

Hoy he recibido carta de Ada. La letra, antaño firme y resuelta, se encoge ahora
hasta volverse casi indescifrable; mas el ingenio que la dicta sigue siendo el de
siempre. Los médicos, escribe, le conceden a lo sumo unas semanas. Y en cuanto
ella cierre los ojos, su madre, Lady Byron —que jamás disimuló cuánto aborrece los
versos del padre y las matemáticas de la hija— hará registrar Ockham Park de cabo
a rabo y arrojará a la lumbre cuanto papel comprometedor halle a su paso: cartas
mías, anotaciones marginales a las *Notes* —aquellas notas suyas a la memoria de
Menabrea sobre el Motor Analítico, donde Ada explicó al mundo, con más claridad
que yo mismo, cuanto la máquina sería capaz de obrar—, esbozos de programas para
máquinas que aún no existen. Todo cuanto hemos urdido juntos durante años se
perderá en una sola tarde de hogueras.

Ada no piensa permitirlo. Ha confiado a una doncella leal un inventario minucioso
de los objetos que, durante años, ha ido escondiendo por los distintos rincones de
la casa, y que ella irá rescatando uno a uno. Mi cometido es bien humilde: poseo
el plano de Ockham Park, dibujado por la propia Ada, y he de servir de guía a la
doncella en su búsqueda de cada uno de estos objetos.

Mas hay una dificultad, y no menor. El suelo de madera de Ockham Park está viejo y
descuidado y muchas son las tablas que crujen escandalosamente al pisarlas. La
señora tiene el oído fino. Por cada zona del suelo crujiente que la doncella deba
atravesar, mayor será el riesgo de ser descubierta. Habré, pues, de calcular para
cada objeto del inventario el menor número de zonas crujientes que la doncella
habrá de atravesar desde el lugar en que se halle hasta donde el objeto yace
oculto. Tarea es esta que, de hacerse a mano, me llevaría noches enteras; mas
dispongo, por fortuna, del Motor Analítico, y a él habré de encomendarle el
cálculo.

## Entrada

La entrada está formada por una serie de casos de prueba. En la primera línea
aparece el número $T$ de casos que aparecerán a continuación ($0 \le T \le 1000$).

Cada caso comienza con una línea con dos enteros $C$ y $F$ ($1 \le C, F \le 1000$),
el ancho y la altura del plano. A continuación vienen $F$ líneas con $C$
caracteres cada una, conteniendo el plano de Ockham Park. Cada celda contiene uno
de los siguientes caracteres: `#`, un muro infranqueable; `.`, suelo firme por el
que la doncella camina sin hacer ruido; `*`, suelo crujiente que delata a quien lo
pisa. Toda la cuadrícula se halla rodeada por un borde de muro. Dos celdas
crujientes pertenecen a la misma *zona crujiente* si es posible ir de una a otra
avanzando paso a paso en horizontal o en vertical, pisando siempre celdas
crujientes. La mansión nunca contiene más de 200 zonas crujientes distintas.

Tras el plano sigue una línea con un entero $Q$ ($1 \le Q \le 10^4$), el número de
objetos del inventario. Las posiciones en el plano se indican mediante un par
$(x, y)$, donde $x$ es la columna (entre 1 y $C$, contando desde la izquierda) e
$y$ la fila (entre 1 y $F$, contando desde arriba). Las $Q$ líneas siguientes
contienen cuatro enteros cada una: $x_1\ y_1\ x_2\ y_2$, las coordenadas de la
posición en que se halla la doncella y las del objeto que ha de rescatar en ese
turno. Se garantiza que ambas posiciones corresponden a celdas de suelo firme
(`.`) distintas entre sí.

Sumando sobre todos los casos de un mismo fichero de entrada, la suma de
$C \cdot F$ no excede $5 \cdot 10^6$.

## Salida

Por cada caso de prueba se escribirán $Q$ líneas, una por objeto del inventario,
con el menor número de *zonas crujientes* que la doncella habrá de atravesar para
alcanzarlo desde su posición.

Si no existe camino que las una, se escribirá `-1` para denotar que aquel objeto
se halla, por desventura, fuera del alcance de la doncella. Tras las $Q$ líneas de
respuestas se escribirá una línea con tres guiones (`---`) a modo de separador,
también después del último caso.

## Ejemplos

### Entrada de ejemplo
```
2
22 8
######################
#.**....##.....***...#
#......**.......**...#
########**########...#
#....##..*..**....#..#
#***##......**.....#.#
#****.......#.......##
######################
3
2 2 17 6
9 6 14 3
2 2 3 5
14 6
##############
#......#.....#
#.****.#.....#
#.****.#.....#
#......#.....#
##############
2
2 2 7 5
11 3 2 2
```

### Salida de ejemplo
```
2
1
2
---
0
-1
---
```
