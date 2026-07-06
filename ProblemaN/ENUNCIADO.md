# Problema N - Examen tipo test

Después de muchos años dedicados a superar el Grado en la Universidad, Ángeles
Tudiante se está enfrentando por fin a su último examen. Si lo supera, podrá lanzar
el birrete al aire, irse a celebrarlo con sus compañeros y cerrar una etapa vital
que, según le han dicho muchos adultos, añorará más adelante.

Pero antes de echar las campanas al vuelo hay que aprobar. El examen es de tipo test
con un montón de preguntas que, por supuesto, no se sabe. ¡Si hubiera estudiado las
materias del Grado, llegar hasta aquí no habría tenido ningún mérito! Encima cada
pregunta respondida de forma incorrecta *resta* el valor de la mitad de una pregunta
acertada. Eso significa que si en total todas las preguntas valen 10 puntos, puede
sacar un 10, si las acierta todas, o un $-5$ si las falla todas. Naturalmente, puede
dejar preguntas sin contestar de modo que no se arriesga a perder puntos por ellas,
pero tampoco tendrá posibilidad de ganarlos. Para aprobar le basta con alcanzar al
menos la mitad de la puntuación máxima total.

Haciendo *ingeniería de examen*, todavía no ha contestado ninguna pregunta pero
tiene una estimación clara de la probabilidad que tiene de acertar cada una. Tiene
identificadas las que sí se sabe, que ha etiquetado con una probabilidad de acertar
de 1, y también aquellas en las que duda, y en qué grado. Es muy pesimista y algunas
las ha valorado con una probabilidad de acertar de 0, asumiendo que ponga lo que
ponga fallará, aunque sabe que incluso un dado aleatorio alguna vez acertaría.

## Entrada

Cada caso de prueba comienza con un número $N$ entre 1 y 100 indicando el número de
preguntas de las que consta el examen tipo test. A continuación vienen, en otra
línea, $N$ números entre 0 y 1 con como mucho tres decimales. Cada uno indica la
probabilidad que ha asignado Ángeles a acertar cada una de las preguntas del examen.

La entrada termina con un 0.

## Salida

Por cada caso de prueba se escribirá un número entre 0 y 1 que indique la máxima
probabilidad que tiene Ángeles de aprobar sabiendo que puede elegir qué preguntas
responde.

Se aceptará una respuesta si tiene un error absoluto o relativo de, como mucho,
$10^{-6}$.

## Ejemplos

### Entrada de ejemplo
```
4
0.5 0.0 0.5 0.0
3
0.0 1.0 0.5
3
1.0 1.0 0.0
5
0.9 0.75 0.5 0.25 0.125
0
```

### Salida de ejemplo
```
0.25
0.5
1
0.459375
```
