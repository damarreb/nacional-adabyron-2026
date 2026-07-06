# Problema H - Las luces de la verbena

Llega el verano y, con él, las verbenas de barrio. Durante unos días la rutina se
toma vacaciones: las plazas se engalanan con banderines de papel, suenan los
organillos, huele a churros y a flores, y los vecinos sacan las sillas a la calle
para no perderse el baile. Pero si hay algo que de verdad anuncia la fiesta, algo
que se ve desde el final de cada calle antes incluso de oír la música, son las
luces: sobre las cabezas de los vecinos cuelgan guirnaldas de bombillas que, al
caer la tarde, encienden la plaza y le dan a la noche ese aire de fiesta que todos
esperan el año entero.

Este año nos han encargado iluminar la plaza mayor, y la idea es vestirla por
completo: la guirnalda recorre todo el perímetro saltando de farola en farola hasta
volver al punto de partida, cerrándose en un anillo de $N$ bombillas que se pueden
encender o apagar una a una. El problema es que la instalación viene de muchas
verbenas atrás y no conviene tentar a la suerte: si demasiadas bombillas seguidas
permanecen encendidas, el cable se calienta en exceso y salta el diferencial,
dejando la plaza a oscuras en plena fiesta. Para evitar el disgusto, el
electricista ha sido tajante: en ningún tramo del anillo puede haber más de $K$
bombillas encendidas consecutivas.

A la comisión de fiestas le ha entrado el gusanillo de la duda. Podrían encender la
guirnalda de cualquier manera que respete el cableado, pero antes de decidirse les
pica la curiosidad por saber cuántas posibilidades tienen realmente sobre la mesa:
si son cuatro combinaciones o si son tantas que no acabarían de probarlas en lo que
queda de verano.

## Entrada

La entrada está formada por una serie de casos de prueba. En la primera línea
aparece el número $T$ de casos que aparecerán a continuación ($0 \le T \le 2000$).

Cada caso ocupa una línea con dos enteros $N$ y $K$, donde $N$ es el número de
bombillas de la guirnalda ($1 \le N \le 10^6$) y $K$ el máximo número de bombillas
encendidas consecutivas que admite el anillo ($0 \le K \le N$). La suma de los
valores de $N$ de todos los casos no excederá $10^6$.

## Salida

Por cada caso de prueba se escribirá una línea con el número de formas distintas en
las que se puede iluminar la guirnalda sin sobrecargar el cableado. Como el número
puede ser enorme, se dará su resto módulo $10^9 + 7$.

Cada bombilla cuelga de un punto fijo y bien identificado del recorrido, así que lo
que cuenta es qué bombilla concreta está encendida y cuál apagada: dos
iluminaciones son la misma forma solo si coinciden bombilla a bombilla. En
particular, una misma disposición girada alrededor de la plaza ilumina puntos
distintos y cuenta, por tanto, como una forma diferente.

## Ejemplos

### Entrada de ejemplo
```
5
4 1
3 3
6 2
1 1
4 0
```

### Salida de ejemplo
```
7
8
39
2
1
```
