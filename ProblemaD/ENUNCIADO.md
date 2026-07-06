# Problema D - El repartidor perezoso

Mario llevaba varias semanas buscando trabajo cuando, por fin, recibió una oferta
de una compañía de reparto emergente, la Increíble Compañía de Paquetes Curiosos
(ICPC). El proceso de selección consistió en una única pregunta: "¿Sabes
caminar?". Mario dijo que sí. Le dieron el trabajo.

Su primer encargo parecía sencillo: repartir varios paquetes en un mismo
vecindario. Sin embargo, al revisar los detalles, Mario descubrió que el barrio
era muy particular: consistía en una calle recta prácticamente infinita, con todas
las casas situadas en el mismo lado de la acera. Preguntó por la furgoneta. Le
dijeron que la empresa no tenía furgonetas. Preguntó por la bici. Le dijeron que
tampoco. Preguntó si al menos le pagarían el autobús. Le colgaron. Resignado a su
nueva vida como vehículo de reparto bípedo, Mario aceptó la situación y se puso
manos a la obra.

Por motivos de logística interna (una expresión que en la ICPC parece significar
"no preguntes"), los paquetes tienen un orden de reparto muy concreto, así que
Mario no puede alterar el orden de la lista que ha recibido. La central de reparto
se encuentra en la posición 0, y cada casa está situada en una posición entera de
la calle. Al comenzar la jornada, Mario parte desde la central, visita las casas
en el orden indicado y, al terminar, debe regresar de nuevo a la posición 0.

Al ver la distancia total que le esperaba, Mario decide llamar a su amigo. Este no
está especialmente ilusionado con la propuesta, pero tampoco quiere quedar mal,
así que llega a un acuerdo: se encargará de repartir exactamente uno de los
paquetes, ni más ni menos. Si su amigo se encarga de una casa, Mario elimina esa
visita de su recorrido y mantiene el orden relativo de todas las demás. Tu tarea es
determinar la mínima distancia total que Mario tendrá que caminar si elige de
forma óptima qué casa dejar en manos de su amigo.

## Entrada

La primera línea contiene un entero $T$ ($0 \le T \le 10^4$), el número de casos de
prueba. Cada caso de prueba consta de dos líneas. La primera contiene un entero
$N$ ($1 \le N \le 2 \cdot 10^5$), el número de entregas asignadas a Mario. La
segunda contiene $N$ enteros $a_1, a_2, \ldots, a_N$, donde $a_i$ representa la
posición de la casa correspondiente a la $i$-ésima entrega que debe realizar
($1 \le a_i \le 10^9$). Una misma posición puede aparecer varias veces, ya que
Mario podría tener que realizar varias entregas en la misma casa en distintos
momentos de la ruta. La suma de los valores de $N$ a lo largo de todos los casos
de prueba no supera $2 \cdot 10^5$. Además, se garantiza que la distancia total de
la ruta original de cada caso de prueba no supera $10^9$.

## Salida

Para cada caso de prueba se escribirá una línea con un único entero: la mínima
distancia total que deberá recorrer Mario si puede saltarse exactamente una de las
casas.

## Ejemplos

### Entrada de ejemplo
```
3
3
2 4 5
5
10 20 100 22 21
1
7
```

### Salida de ejemplo
```
8
44
0
```
