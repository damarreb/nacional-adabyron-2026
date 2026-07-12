# Introducción a la solución

Un pulpo de tres tentáculos escala una pared plana con $N$ agarres (puntos del
plano). Su cuerpo es un punto libre y cada tentáculo llega hasta una distancia
$L$. Empieza sujeto a los tres primeros agarres y hay que decidir si puede
llegar a tocar el agarre final, sabiendo que en cada movimiento recoloca un
tentáculo manteniendo los otros dos, y que **una única vez** puede hacer un
*estiramiento*: alargar un tentáculo hasta $2L$, quedarse colgando solo de él
y reengancharse después a otro agarre.

La solución tiene dos mitades bien separadas: un problema de alcanzabilidad
en un grafo (¿qué configuraciones puede visitar el pulpo?) y un problema de
geometría (¿cuándo es válido cada movimiento?). Conviene resolverlas por
ese orden.

# Modelando al pulpo: el cuerpo no importa

Lo primero es quitarse de encima el cuerpo del pulpo. Un movimiento ordinario
que termina con los tentáculos en los agarres $B$, $C$ y $D$ es válido si
existe *alguna* posición del cuerpo a distancia $\le L$ de los tres a la vez;
es decir, si los tres *discos* de radio $L$ centrados en $B$, $C$ y $D$ tienen
algún punto en común.

No hace falta comprobar que el cuerpo pueda *llegar* hasta esa posición.
Mientras el pulpo mantiene dos tentáculos sujetos a $B$ y $C$, su cuerpo puede
situarse en cualquier punto de la intersección de los discos de $B$ y $C$ (una
*lente*). Esa lente es una región **convexa**, así que el cuerpo puede
deslizarse de cualquier posición válida a cualquier otra sin soltar nada. Por
tanto no hace falta rastrear dónde está el cuerpo: basta saber qué agarres
están sujetos.

El estado del pulpo parece entonces ser el trío de agarres que sujeta. Eso ya
daría un algoritmo correcto (un BFS sobre tríos), pero se puede afinar más.

# La observación clave: el estado es un par

En cada movimiento ordinario hay dos tentáculos que no se mueven. Llamemos
*par pivote* a sus dos agarres. La observación es que el tercer tentáculo no
aporta información: esté donde esté, puede levantarse y recolocarse en
cualquier agarre $D$ que forme trío compatible con el pivote. Así que el
estado que merece la pena recordar es el **par** de agarres que el pulpo
mantiene sujetos, sabiendo que el tercer tentáculo está disponible.

Las transiciones salen solas. Si el pulpo dispone del par $\{B, C\}$ y el trío
$\{B, C, D\}$ es compatible (los tres discos comparten un punto), puede posar
el tercer tentáculo en $D$. En ese instante sujeta los tres agarres, así que a
partir de ahí puede usar como pivote cualquiera de los pares $\{B, D\}$ y
$\{C, D\}$ (además del propio $\{B, C\}$).

Cualquier secuencia real de movimientos es una secuencia de tríos donde cada
trío comparte un par con el siguiente: ese par compartido es exactamente el
pivote del movimiento. Recorrer pares con la regla anterior reproduce todas
esas secuencias, y a la inversa, cada camino entre pares se realiza con
movimientos legales. Un **BFS sobre pares** computa por tanto todo lo
alcanzable:

- Estados iniciales: los tres pares del trío de partida (el enunciado
  garantiza que es compatible).
- Desde $\{B, C\}$, para cada agarre $D$ con trío $\{B, C, D\}$ compatible,
  se descubren los pares $\{B, D\}$ y $\{C, D\}$.
- El agarre final queda tocado en cuanto es un $D$ válido de algún movimiento.

Hay $O(N^2)$ pares y cada uno prueba $N$ destinos, así que el BFS cuesta
$O(N^3)$ comprobaciones geométricas. Con $N \le 200$ y suma de $N$ acotada por
$1000$, es más que suficiente.

# El estiramiento y el reenganche

El estiramiento solo puede usarse una vez, lo que parte la búsqueda en dos
fases idénticas con una transición especial en medio:

1. **Fase 1**: BFS sobre pares desde el trío inicial, solo movimientos
   ordinarios.
2. **Estiramiento**: desde cualquier par $\{B, C\}$ alcanzado en la fase 1, el
   pulpo puede llegar con el tentáculo estirado a un agarre $E \notin \{B,C\}$
   si los discos $(B, L)$, $(C, L)$ y $(E, 2L)$ comparten un punto. Si
   $E$ es la meta, hemos terminado: tocarla durante el estiramiento cuenta.
3. **Reenganche**: tras el estiramiento el pulpo suelta $B$ y $C$ y cuelga
   solo de $E$, con el cuerpo libre en el disco $(E, 2L)$. Para recuperar una
   posición segura debe agarrar otro agarre $G \ne E$ con un tentáculo normal
   y recoger el estirado hasta longitud $\le L$. Eso exige acabar con ambos
   tentáculos a longitud $\le L$, es decir, $d(E, G) \le 2L$; y esa condición
   también basta, porque cualquier punto con ambas distancias $\le L$ está
   dentro del disco $(E, 2L)$ en el que el cuerpo se mueve libremente. Si $G$
   es la meta, también hemos terminado.
4. **Fase 2**: el pulpo queda sujeto al par $\{E, G\}$ con el tercer tentáculo
   libre. Todos esos pares son las semillas de un segundo BFS idéntico al
   primero.

$E$ puede ser un agarre que el pulpo ya usaba (incluso el que sujetaba el
propio tentáculo antes de estirarse), con la única condición de ser distinto de
$B$ y $C$. Esto importa, porque el estiramiento es la única manera de
"reorganizar" a qué pares se sujeta el pulpo, y a veces la jugada ganadora es
estirarse a un agarre ya conocido para reengancharse por el otro lado.

Nótese que en la fase 2 no hace falta reexplorar pares ya visitados en
la fase 1: su expansión ya se hizo entonces y no encontró la meta.

# La geometría: ¿cuándo comparten un punto tres discos?

Sólo falta resolver el problema geométrico. Todas las condiciones anteriores
son del mismo tipo: ¿tienen los discos $(A, r_A)$, $(B, r_B)$ y $(C, r_C)$ un
punto común? (Con radios $L, L, L$ en los movimientos ordinarios y $L, L, 2L$
en el estiramiento.)

Que los discos se corten **dos a dos es necesario pero no basta**: tres discos
pueden cortarse por parejas y dejar un "triángulo" vacío en medio. La
caracterización correcta es:

> La intersección de los tres discos es no vacía si y solo si se cortan dos a
> dos y, además, **o bien** el centro de un disco está dentro de los otros
> dos, **o bien** algún punto de corte de dos de las circunferencias cae
> dentro del tercer disco.

La idea de la prueba: si la intersección no es vacía, es una región convexa
cuya frontera se compone de arcos de las tres circunferencias. Si esa frontera
tiene alguna "esquina", la esquina es un punto de corte de dos circunferencias
que está dentro del tercer disco. Y si no tiene esquinas, la frontera es una
circunferencia completa: ese disco está contenido en los otros dos, y en
particular su centro lo está. El recíproco es inmediato (en ambos casos se
exhibe un punto común).

Esto da un algoritmo directo: comprobar los cortes dos a dos y los centros con
enteros, y calcular los puntos de corte de las circunferencias (que requieren
una raíz cuadrada) en coma flotante. Es lo que hace [E.cpp](src/E.cpp).

# Sobre la precisión

[E.cpp](src/E.cpp) decide en enteros todo lo que puede (cortes dos a dos,
centros dentro de discos, el signo del discriminante que dice si dos
circunferencias llegan a cortarse) y solo usa `double` para situar los puntos
de corte. El error de esos flotantes es del orden de $10^{-10}$, muchísimo
menor que el margen `EPS = 1e-4` con el que compara; para que fallara haría
falta un caso cuyo valor real distase del umbral menos de `EPS` sin ser
exactamente el umbral, algo que con coordenadas enteras acotadas por $10^4$ no
ocurre en la práctica.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [E.cpp](src/E.cpp) | BFS sobre pares pivote en dos fases (antes y después del estiramiento); intersección de tres discos por candidatos, con enteros salvo los puntos de corte (`double` + `EPS`). $O(N^3)$ por caso. | :x: |
