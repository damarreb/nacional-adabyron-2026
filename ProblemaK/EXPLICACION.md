# Introducción a la solución
El problema consiste en encontrar la longitud de la ventana de días más pequeña necesaria para poder ver los 3 shows. Formalmente, dada la lista de shows $s_1,...,s_N$, en la que $s_i$ denota la letra del show realizado el día $i$-ésimo ($s_i \in \{C,R,H\}$), se pide encontrar la mínima longitud entre las sublistas que contienen al menos un $C$, un $R$ y un $H$ (más adelante nos referiremos a una sublista como válida si cumple esta última condición).

# Definiciones y observaciones 
Podemos definir $L(r)$ como la mínima longitud de la sublista válida que acaba en $c_r$. Se demuestra que esta sublista es única ya que, al fijar el extremo derecho (con valor $r$), para cada extremo izquierdo hay una longitud distinta (formalmente, ocurre porque la función de la longitud sobre el índice izquierdo, $f(l)=r-l+1$, es inyectiva).

También vamos a definir $lastC(r)$, $lastR(r)$ y $lastH(r)$ como el índice máximo cuya letra es $C$, $R$ o $H$, respectivamente, dentro de la ventana $c_1$,...,$c_r$. Las definiciones formales son las siguientes: 
$$lastC(r) = \max_{i=1}^r(i \text { si } c_i = C)$$
$$lastH(r) = \max_{i=1}^r(i \text { si } c_i = H)$$
$$lastR(r) = \max_{i=1}^r(i \text { si } c_i = R)$$

Se demuestra que el extremo izquierdo, $l$, que minimiza la longitud de la sublista válida para un extremo derecho fijo, $r$, es igual a:
$$l=min(lastC(r),lastH(r),lastR(r))$$

La demostración es la siguiente:

Primero, vamos a demostrar que la sublista $c_l,\dots,c_r$ es válida:
- como se cumple $l \leq lastC(r) \leq r$, hay al menos una letra $C$ en la sublista $c_l,\dots,c_r$.
- como se cumple $l \leq lastH(r) \leq r$, hay al menos una letra $H$ en la sublista $c_l,\dots,c_r$.
- como se cumple $l \leq lastR(r) \leq r$, hay al menos una letra $R$ en la sublista $c_l,\dots,c_r$.

De esta manera queda demostrado que la sublista contiene al menos una letra de cada tipo, y por tanto es válida.

Ahora, por reducción a lo absurdo, vamos a suponer que existe otro índice $l'$ que minimiza la longitud de la sublista válida:

Por un lado, de manera trivial, cualquier sublista que contenga otra sublista válida también es válida.
Por otro lado, si $l'$ minimiza la longitud de la sublista, entonces $l' > l$, así que $l' \geq l+1$.
Juntando las dos afirmaciones llegamos a que la sublista $c_{l+1},\dots,c_r$ es válida.

$l$ toma el valor de $lastC(r)$, $lastH(r)$ o $lastR(r)$. Suponiendo que $l=lastC(r)$, entonces $l+1 > lastC(r)$. Esto significa que la sublista $c_{l+1},\dots,c_r$ no contendría ninguna letra $C$, y por tanto no sería válida. De igual manera, se demostraría para $l=lastH(r)$ y $l=lastR(r)$.

Así llegamos a una contradicción de que no puede existir otro $l'$ que minimice la longitud de la sublista.

Por tanto nuestra solución es: $$\min_{r=1}^N\left(r-l+1\right)=\min_{r=1}^N\left(r-\min(lastC(r),lastH(r),lastR(r))+1\right)$$

# Programación dinámica
El problema se resume a obtener $lastC(r)$, $lastH(r)$ y $lastR(r)$ para cada $r \in \{1,\dots,N\}$.

Podemos usar una definición recursiva sobre el índice anterior para obtener el actual:
- $lastC(r) = \begin{cases} r & \text{si } c_r = C \\ lastC(r-1) & \text{si } c_r \neq C \end{cases}$
- $lastH(r) = \begin{cases} r & \text{si } c_r = H \\ lastH(r-1) & \text{si } c_r \neq H \end{cases}$
- $lastR(r) = \begin{cases} r & \text{si } c_r = R \\ lastR(r-1) & \text{si } c_r \neq R \end{cases}$

> [!NOTE]
> Como para calcular $lastC(r)$ solo es necesario conocer $lastC(r-1)$, no es necesario memorizar todos los valores, solamente el anterior. Lo mismo ocurre con $lastH(r)$ y $lastR(r)$.

Por otra parte, para manejar los estados inválidos, partimos del caso base $$lastC(0)=lastH(0)=lastR(0)=-1$$

El valor $-1$ nos indicará que todavía no ha aparecido ninguna letra de ese tipo, y por tanto no hay ninguna sublista válida.

# Algoritmo
El algoritmo consiste en los siguientes pasos:
1. Inicializar `lastC`, `lastH` y `lastR` al valor por defecto `-1`. También inicializar la respuesta `res` a un valor inválido por defecto, como `N+1` (todas las sublistas tienen longitud menor).
2. Iterar sobre `r` calculando los nuevos `lastC`, `lastH` y `lastR`, y actualizar `res` si se obtiene una longitud menor que la actual, siempre que exista una sublista válida.
3. Finalmente, si `res` sigue teniendo el valor inválido se muestra por pantalla *NO SE PUEDE*, si no se muestra el valor de `res`.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [K.cpp](src/K.cpp) | Ad hoc, programación dinámica, $O(n)$ | :white_check_mark: |
| [K.py](src/K.py) | Ad hoc, programación dinámica, $O(n)$| :white_check_mark: |