# Introducción a la solución
El problema consiste en encontrar la longitud de la ventana de días más pequeña
necesaria para poder ver los 3 shows. Formalmente, dada la lista de shows
$s_1,...,s_N$, en la que $s_i$ denota la letra del show realizado el día
$i$-ésimo ($s_i \in \{C,R,H\}$), se pide encontrar la mínima longitud entre las
sublistas que contienen al menos un $C$, un $R$ y un $H$ (más adelante nos
referiremos a una sublista como válida si cumple esta última condición).

# La idea: una ventana deslizante

La estrategia es mantener una *ventana*: un rango de días consecutivos $[l, r]$
(con ambos extremos incluidos) sobre el que llevamos la cuenta de cuántas veces
aparece cada musical dentro de él. La ventana es, en todo momento, un candidato
a sublista, y la iremos *deslizando* de izquierda a derecha a lo largo de la
temporada para examinar los candidatos que nos importan.

Arrancamos con la ventana más pequeña posible: un único día, el primero
($l = r = 0$). A partir de ahí avanzamos el extremo derecho $r$ de uno en uno
hasta el final de la temporada y, tras cada avance, ajustamos el extremo
izquierdo. En concreto, en cada paso:

1. **Crecemos por la derecha:** incorporamos el día $r$ a la ventana e
   incrementamos en uno la cuenta de su musical.
2. **Encogemos por la izquierda:** mientras expulsar el día del extremo
   izquierdo, $s_l$, deje la ventana *todavía válida* (es decir, mientras siga
   conteniendo los tres musicales), avanzamos $l$ y descontamos ese día. Nos
   detenemos justo antes de eliminar la última aparición de algún musical.

Después de estos dos pasos, si la ventana es válida, su longitud $r - l + 1$ es
un candidato a la respuesta. La solución final es el mínimo de esas longitudes
sobre todos los extremos derechos. Si al recorrer toda la temporada la ventana
no llega a ser válida en ningún momento, es que falta algún musical y la
respuesta es *NO SE PUEDE*.

## ¿Cuándo es válida la ventana?

Para saber si la ventana contiene los tres musicales no hace falta recorrerla:
basta llevar, además de las cuentas por musical, un contador de *cuántos
musicales distintos* tienen ahora mismo cuenta positiva. Cuando un musical pasa
de $0$ a $1$ apariciones al entrar por la derecha, ese contador sube; la ventana
es válida exactamente cuando vale $3$. Como al encoger nunca eliminamos la
última aparición de un musical, el encogimiento no lo baja de $3$.

## Por qué encoger no pierde la solución

Fijémonos en un extremo derecho $r$ cualquiera. Entre todas las sublistas
válidas que terminan en el día $r$, la más corta es la que tiene el extremo
izquierdo *lo más a la derecha posible*. Y ese extremo izquierdo máximo es justo
donde se detiene nuestro encogimiento: paramos cuando $s_l$ es la única
aparición de su musical en la ventana, de modo que mover $l$ un paso más
rompería la validez. Por tanto, tras procesar el día $r$, la ventana $[l, r]$ es
exactamente la sublista válida más corta que acaba en $r$ (si es que existe
alguna).

Como consideramos todos los extremos derechos $r$, y para cada uno obtenemos la
mejor sublista válida que termina ahí, el mínimo global que calculamos es la
respuesta correcta.

## Algoritmo

1. Inicializar la ventana vacía: $l = 0$, las cuentas por musical a $0$, el
   contador de musicales distintos a $0$ y la respuesta `res` a un valor
   imposible, como `N+1` (ninguna sublista es tan larga).
2. Para cada `r` de `0` a `N-1`: incorporar el día `r` actualizando su cuenta y,
   si era nuevo en la ventana, el contador de distintos. Después, mientras el
   contador valga `3` y el día `l` esté repetido (cuenta mayor que `1`),
   descontarlo y avanzar `l`. Si el contador vale `3`, actualizar `res` con
   `r-l+1` si es menor.
3. Al terminar, si `res` conserva su valor imposible, escribir *NO SE PUEDE*; en
   otro caso, escribir `res`.

## Coste asintótico

A lo largo de todo el recorrido, cada día entra en la ventana una vez (cuando
lo alcanza $r$) y sale de ella como mucho una vez (cuando lo rebasa $l$). El
número total de operaciones es lineal, $O(n)$.

# Alternativa: los últimos índices de cada musical

Hay otra forma de encontrar, para cada extremo derecho $r$, la sublista válida
más corta que termina en él, sin mantener una ventana explícita.

Para un $r$ fijo, entre las sublistas válidas que terminan en $r$ hay una única
más corta: fijado el extremo derecho, cada extremo izquierdo da una longitud
distinta, así que la más corta corresponde al mayor extremo izquierdo que aún
deja la sublista válida. Ese extremo izquierdo óptimo es

$$l = \min(lastC(r), lastR(r), lastH(r)),$$

donde $lastX(r)$ es el índice más grande, no mayor que $r$, en el que se
representa el musical $X$:

$$lastC(r) = \max\{i \le r : s_i = C\}$$

$$lastR(r) = \max\{i \le r : s_i = R\}$$

$$lastH(r) = \max\{i \le r : s_i = H\}$$

## Por qué ese es el extremo izquierdo óptimo

Primero, la sublista $s_l,\dots,s_r$ es válida:
- como $l \le lastC(r) \le r$, contiene al menos una letra $C$;
- como $l \le lastR(r) \le r$, contiene al menos una letra $R$;
- como $l \le lastH(r) \le r$, contiene al menos una letra $H$.

Y ningún extremo izquierdo mayor que $l$ deja la sublista válida. Supongamos, por
reducción al absurdo, que existe $l' \ge l+1$ que también da una sublista válida.
El valor $l$ es uno de los tres $last$; digamos que $l = lastC(r)$. Entonces
$l+1 > lastC(r)$, así que la sublista $s_{l+1},\dots,s_r$ ya no contiene ninguna
letra $C$, y por tanto tampoco la que empieza en $l' \ge l+1$: no serían válidas,
contradicción. El mismo razonamiento vale si $l$ es $lastR(r)$ o $lastH(r)$.

Por tanto $l$ es el mayor extremo izquierdo válido, es decir, el que da la
sublista válida más corta que termina en $r$. La respuesta es
$$\min_{r=1}^N\left(r - \min(lastC(r), lastR(r), lastH(r)) + 1\right),$$
tomada solo sobre los $r$ para los que los tres $last$ están definidos.

## Cálculo incremental (programación dinámica)

Solo queda obtener los tres $last$ para cada $r$, y eso se hace de un $r$ al
siguiente con una recurrencia inmediata:

$$lastC(r) = \begin{cases} r & \text{si } s_r = C \\ lastC(r-1) & \text{si } s_r \neq C \end{cases}$$

y de forma análoga para $lastR(r)$ y $lastH(r)$. Partimos del caso base

$$lastC(0) = lastR(0) = lastH(0) = -1,$$

donde $-1$ significa que ese musical todavía no ha aparecido (y por tanto aún no
hay sublista válida).

> [!NOTE]
> Como cada $last$ solo depende de su valor en $r-1$, no hace falta memorizar
> todo el histórico: basta guardar el último valor de cada uno.

El recorrido visita cada día una sola vez, así que también es $O(n)$.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [K_ventana.cpp](src/K_ventana.cpp) | Ad hoc, ventana deslizante con conteo, $O(n)$ | :white_check_mark: |
| [K_dp.cpp](src/K_dp.cpp) | Ad hoc, programación dinámica, $O(n)$ | :white_check_mark: |
| [K_dp.py](src/K_dp.py) | Ad hoc, programación dinámica, $O(n)$ | :white_check_mark: |
