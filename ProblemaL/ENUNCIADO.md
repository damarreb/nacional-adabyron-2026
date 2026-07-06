# Problema L - GolfBot 2

Shane tiene un canal de YouTube dedicado a robótica. Sus vídeos siempre presentan
proyectos de robótica tan complejos como innecesarios.

Por ejemplo, una creación de Shane ha sido hacer un palo para jugar al golf que
apunta solo. Lo único que hay que hacer es ajustar un dial que dice a qué distancia
quieres que llegue la pelota (entero, en centímetros), y el palo hace el resto. Esto
en realidad no es nuevo, la misma idea ya se había considerado en Oporto allá por
2014.

Por eso Shane se plantea una nueva vuelta de tuerca. Además de motorizar el palo ha
decidido motorizar el hoyo del campo de golf (!?), que también se moverá hacia la
pelota para garantizar el hoyo en un golpe.

Un ingeniero razonable querría minimizar la energía necesaria para operar sus
inventos. Sin embargo, Shane quiere *maximizar* la energía necesaria para hacer el
hoyo en uno. El espectáculo atrae más visitas.

El palo consume energía cada vez que se usa. El coste en milivatios de usar el palo
para hacer avanzar la pelota $i$ centímetros es $a_i$ ($0 \le i \le n$). La energía
que requiere el hoyo para retroceder $j$ centímetros es $b_j$ milivatios
($0 \le j \le m$). La pelota solo se puede mover de izquierda a derecha en una
recta, y el hoyo solo se puede mover por la misma recta de derecha a izquierda.
Adicionalmente, la energía que necesita el palo para funcionar es creciente, y su
coste marginal también lo es, es decir, cada centímetro adicional cuesta más que el
anterior. En otras palabras, $a_{i+2} - a_{i+1} \ge a_{i+1} - a_i$ para todo
$0 \le i \le n - 2$, y $a_i \le a_{i+1}$ para todo $0 \le i \le n - 1$. El hoyo
robot usa magia y no tiene por qué seguir estas reglas.

Para cada distancia inicial $k$ ($0 \le k \le n + m$) entre el hoyo y la pelota,
calcular la máxima energía necesaria para hacer un hoyo en un golpe (usando
simultáneamente el palo robot y el hoyo robot).

## Entrada

La entrada consta de varios casos de prueba y se procesa hasta el final del fichero.
Cada caso comienza con una línea con dos números enteros $n$ y $m$ con
$0 \le n, m \le 5 \cdot 10^5$. Las siguientes dos líneas tienen $n + 1$ y $m + 1$
enteros positivos respectivamente representando $a_0, \ldots, a_n$ y
$b_0, \ldots, b_m$. Se garantiza que $0 \le a_i, b_j \le 10^{18}$ para todo $i, j$ en
el rango. La suma de $n + m$ sobre todos los casos de prueba es a lo sumo
$5 \cdot 10^5$.

## Salida

Para cada caso de prueba se escribirá una línea con los valores $c_0, \ldots, c_{n+m}$
separados por espacios, donde $c_k$ es la máxima energía necesaria para completar
una distancia de $k$ centímetros en un golpe.

## Ejemplos

### Entrada de ejemplo
```
2 3
0 3 8
5 2 7 1
1 1
0 5
3 1
```

### Salida de ejemplo
```
5 8 13 10 15 9
3 8 6
```
