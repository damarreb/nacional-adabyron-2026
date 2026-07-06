# Problema G - La rondalla de Pontemiñá

En Pontemiñá, como en tantos pueblos de Galicia, la rondalla es el corazón del
lugar. Una rondalla es una agrupación de música popular —bandurrias, laúdes,
guitarras, panderetas y muchas voces— en la que cabe todo el vecindario, de los
niños a los más mayores, repartidos por instrumento: los gaiteiros, los de
bandurria, las pandereteiras... Más que tocar, es la razón para juntarse cada
semana, lo que mantiene unidas a las familias y a las generaciones.

El gran día es el concurso. Cuando llega el invierno, las rondallas de los pueblos
de la comarca se miden en un certamen que llena el recinto toda la tarde, y cada
pueblo quiere dejar su nombre bien alto. Por eso lo preparan al milímetro: el
jurado lo valora todo y, sobre el escenario, el tiempo está tasado —cada rondalla
tiene unos minutos exactos, ni uno más—, de modo que cada gesto de la coreografía
cuenta.

Este año, don Amaro, el director de la rondalla de Pontemiñá, ha preparado una
coreografía muy vistosa. Cada cuadrilla forma una *fila*, y sus componentes deben
acabar colocados *por altura*, del más bajito al más alto. Pero al empezar están
desordenados. Para colocarlos, don Amaro va cantando intercambios: cuando grita dos
posiciones $(a, b)$, los componentes que ocupan esas posiciones de la fila se
cambian de sitio.

Lo bonito es que no todas las cuadrillas hacen lo mismo a la vez. Mientras canta,
don Amaro va señalando con la batuta a unas cuadrillas u otras, y solo las
cuadrillas señaladas ejecutan ese intercambio; las demás se quedan quietas. El
público ve una sola batuta, pero cada cuadrilla, que partía de un orden distinto,
recorre su propio camino hasta quedar formada.

Como el tiempo está tasado, don Amaro no puede dar más de 2500 órdenes en total.
Ayúdale a decidir la secuencia de órdenes —cada una con sus dos posiciones y las
cuadrillas a las que señala— para que, al terminar, todas las cuadrillas queden
colocadas por altura.

## Entrada

La primera línea contiene el número de casos de prueba $T$ ($0 \le T \le 1000$). A
continuación se describen los $T$ casos.

Cada caso comienza con una línea con dos enteros $n$ y $k$ ($1 \le n, k \le 200$):
el número de componentes de cada cuadrilla y el número de cuadrillas. Cada una de
las $k$ líneas siguientes describe una cuadrilla mediante una permutación de
$1, \ldots, n$: el $j$-ésimo número es la altura relativa del componente que ocupa
la posición $j$ de la fila al empezar (1 es el más bajito y $n$ el más alto). Una
cuadrilla queda colocada por altura cuando en cada posición $j$ se encuentra el
componente de altura $j$.

La suma de $n \cdot k$ de todos los casos de una misma entrada no superará $10^5$.

## Salida

Para cada caso de prueba se escribirá lo siguiente. La primera línea contendrá $m$,
el número de órdenes que da don Amaro ($0 \le m \le 2500$). Cada una de las $m$
líneas siguientes describirá una orden con:

- dos enteros $a$ y $b$ ($1 \le a, b \le n$, $a \ne b$): las dos posiciones de la
  fila que se intercambian;
- un entero $c$ ($1 \le c \le k$), seguido de $c$ enteros distintos entre 1 y $k$:
  las cuadrillas a las que don Amaro señala con la batuta en esa orden.

Las órdenes se ejecutan en el orden en que se escriben. Si hay varias soluciones
válidas, se aceptará cualquiera.

## Ejemplos

### Entrada de ejemplo
```
2
4 2
3 4 1 2
3 2 4 1
2 1
2 1
```

### Salida de ejemplo
```
3
1 3 2 1 2
2 4 1 1
1 4 1 2
1
1 2 1 1
```

## Notas

En el primer caso, don Amaro da tres órdenes. En la primera intercambia las
posiciones 1 y 3 señalando a las dos cuadrillas. En la segunda intercambia las
posiciones 2 y 4 solo en la cuadrilla 1. En la tercera intercambia las posiciones 1
y 4 solo en la cuadrilla 2. Al terminar, las dos filas quedan ordenadas:
$1, 2, 3, 4$.

En el segundo caso hay una sola cuadrilla con dos componentes en orden inverso;
basta una orden que intercambie las dos posiciones señalando a esa cuadrilla.
