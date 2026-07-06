# Problema K - Turismo de musicales

Broadway es uno de los grandes símbolos culturales de la ciudad de Nueva York y el
lugar de referencia para los amantes del teatro musical. Cada año, millones de
personas visitan sus teatros atraídas por producciones que se han convertido en
clásicos. Entre los musicales que triunfan esta temporada se encuentran *Cats*, *El
Rey León* y *Hadestown*, tres espectáculos que hacen las delicias de los turistas.

Los empresarios han observado que, cuando se representan varios de estos
espectáculos el mismo día, el público se reparte entre ellos y las salas no se
llenan tanto como desearían. Para evitar esto, han tomado una decisión muy sencilla:
cada día se representa uno y solo uno de estos tres musicales. Así, algunos días se
puede disfrutar de *Cats*, otros de *El Rey León* y otros de *Hadestown*.

Soy un gran aficionado a los musicales y he decidido viajar a Broadway para ver los
tres espectáculos. Sin embargo, quiero gastar lo mínimo posible en alojamiento para
poder destinar una mayor parte de mi presupuesto a comprar mejores entradas. Por
ello, mi objetivo es que la estancia sea lo más corta posible, pero que aun así me
permita asistir a una representación de cada uno de los tres musicales.

Afortunadamente, conozco de antemano qué musical se representará cada día de la
próxima temporada. ¿Cuál es el número mínimo de días consecutivos que debo
permanecer en Broadway para poder ver los tres musicales, sin importar el orden en
que los vea?

## Entrada

La entrada contiene varios casos de prueba; cada uno de ellos ocupa dos líneas. La
primera línea contiene el número de días $N$ de los que consta la temporada de
musicales ($1 \le N \le 3 \cdot 10^5$). La segunda línea contiene una secuencia de
$N$ letras separadas por espacios, e indica qué musical se representa en cada uno de
los días de la temporada, desde el inicio hasta el fin de esta. La letra `C` indica
*Cats*, la letra `R` indica *El Rey León* y la letra `H` indica *Hadestown*.

La entrada finaliza con una temporada de 0 días, caso que no se procesa.

## Salida

Para cada caso de prueba se escribirá una línea con el número mínimo de días que
tengo que estar en Broadway para poder asistir a los tres musicales. Si no es
posible ver los tres musicales aun estando allí durante toda la temporada, se
escribirá una línea con el texto `NO SE PUEDE`.

## Ejemplos

### Entrada de ejemplo
```
5
R C H R H
4
H R R C
3
H H R
0
```

### Salida de ejemplo
```
3
4
NO SE PUEDE
```
