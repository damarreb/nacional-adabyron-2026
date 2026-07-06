# Problema J - Calle Angostura

La calle Angostura es una estrecha vía de un solo carril que conecta varios puntos
de la isla Atascaria. Como es tan estrechita, el mismo carril debe utilizarse para
circular en ambos sentidos. No hay ninguna separación física entre coches que van
en direcciones opuestas.

A lo largo de esta peculiar vía hay varias incorporaciones distribuidas en
distintos puntos. Los coches pueden acceder a la calle por cualquiera de ellas y
abandonarla por otra diferente, recorriendo el tramo comprendido entre ambas. Cada
coche circula a una velocidad constante, que puede ser distinta a la del resto de
coches.

Los gobernantes de Atascaria no se creen que una calle tan estrecha pueda tener
tanto tráfico, así que un día instalaron cámaras en varios puntos y empezaron a
registrar la actividad de todos los coches que utilizan la calle. Para cada uno de
ellos apuntaron la incorporación por la que entraba, la incorporación por la que
salía y los instantes exactos en los que realizaba ambas acciones.

Como era de esperar, la convivencia de todos estos coches podía dar lugar a
situaciones problemáticas. Si dos coches que circulan en sentidos opuestos llegan a
coincidir en el mismo punto de la calle al mismo tiempo, uno de ellos tendría que
dar marcha atrás para evitar una colisión. Por otro lado, si un coche alcanza a
otro que circula delante de él en el mismo sentido, el coche más rápido tendría que
reducir su velocidad para mantener una distancia de seguridad.

Ninguna de estas situaciones es deseable. A partir de la información disponible
sobre los movimientos de todos los coches que utilizan la calle Angostura a lo
largo del día, ¿es posible determinar si en algún momento se producirá alguna de
ellas?

## Entrada

La entrada consta de varios casos de prueba. Cada caso de prueba comienza con un
número $N$ que indica el número de coches registrados a lo largo del día
($1 \le N \le 10^5$). Después vienen $N$ líneas, cada una de ellas con cuatro
números enteros (entre 0 y $3 \cdot 10^5$) que describen el trayecto de un coche.
Los primeros dos números indican respectivamente el punto kilométrico y la hora en
el que el coche se incorpora a la calle Angostura. Los siguientes dos números
indican el punto kilométrico y la hora en el que el coche abandona la calle. Los
puntos kilométricos están medidos sobre el inicio de la calle, y las horas se
representan mediante números que indican cuántos minutos han transcurrido desde el
inicio del registro del tráfico en la calle. Para cada coche, los puntos
kilométricos de entrada y de salida son siempre distintos, y la hora de salida
siempre es estrictamente mayor que la hora de entrada.

La entrada finaliza con un caso de prueba con 0 coches, que no se procesa.

## Salida

Para cada caso de prueba se escribirá una línea con el texto `SI` si en algún
momento del día habrá dos coches que coincidan en el mismo punto de la vía al mismo
tiempo o `NO` en caso contrario. También se considera que dos coches coinciden si,
justo en el momento en que uno de ellos se incorpora a la vía en un punto
determinado, el otro se encuentra entrando, saliendo, o transitando por ese mismo
punto al mismo tiempo.

## Ejemplos

### Entrada de ejemplo
```
2
1 1 2 2
1 2 2 3
2
1 1 4 2
3 1 2 3
2
1 1 3 4
1 2 3 3
3
4 1 3 2
1 1 2 2
2 2 4 3
0
```

### Salida de ejemplo
```
NO
SI
SI
SI
```
