# Informe Proyecto I - CI5437

Elaborado por:
Yerimar Manzo - 14-10611
Jorge Correia - 14-10254

## Representaciones en PSVN

### N-Puzzle

Para representar los estados en PSVN de los N-Puzzles se definió el dominio "tile", compuesto por las siguientes constantes: para el 15-Puzzle son los números del intervalo $[1,14]$ y para el 24-Puzzle el intervalo $[1,24]$, y para ambos casos el espacio en blanco, representado por una letra "b".

Un estado es un vector de largo 16 o 25, donde cada componente es una constante de las mecionadas anteriormente, sin repetición, de la forma: $c_1 c_2 c_3 c_4 ... c_n$.

Para la función de transición, se consideran los movimientos: arriba, abajo, izquierda y derecha del espacio en blanco "b". Es posible que de acuerdo a la ubicación del $b$, no sea posible hacer todos los movimientos.

Se consideran dos estados objetivo:

1) Cuando el espacio en blanco "b" está al inicio le siguen todos los números ordenados de forma ascendente.
2) Cuando todos los números ordenados de forma ascendente anteceden al blanco "b".

### Cubo de Rubik 3x3x3

Para representar el cubo de Rubik se utilizó el generador ya incluido con PSVN para generar los estados. Se tiene un dominio con seis colores escritos en inglés: red, green, blue, yellow, orange, white. La cantidad de variables en total es de 48, por lo que el vector de estados es de largo 48.

Se consideran las 6 caras del cubo con U (upper), F (front), R (right), B (back), L (left) y D (down). Cada cara tiene 9 posiciones en ella, pero como la posición del medio es fija sólo hay 8 variables por cara, de esta forma hay en total 48 variables.

Las variables de estado se componen de 2 o 3 letras, la primera dice la cara que se está "mirando", la segunda indica la posición la localización de un lado. Por ejemplo, FU es Front Upper, es decir, el cuadro superior al central. FR es Front Right, es decir, el cuadro a la derecha del central. Para los cuadros en las esquinas, se añade la tercera letra, por ejemplo FUR es el cuadro de la esquina superior derecha.

Además, el nombre de la variable indica qué posibles movimientos les afecta, en este caso Front, Up y Right.

Cada cara posee tres movimientos, un giro de 180 grados, un giro de 90 grados en el sentido de las agujas del reloj y un giro en 90 grados en sentido opuesto a las agujas del reloj.

Finalmente, este problema solo tiene un estado objetivo que es los cuadros de cada  caras del cubo sean únicamente del color del cuadro central.

### TopSpin

TopSpin es un juego que consiste en tener un arreglo circular de $n$ números, los cuales están conectados a una rotonda, similar a la que usan los ferrocarriles para dar una vuelta de 180 grados, con el objetivo de rotar $k$ números, para poder ordenar todo el arreglo.

En este caso, TopSpin tiene $n$ variables de estado, una para cada posición y el valor es el número en cuestión ubicado dentro de esa variable. Cualesquiera 4 posiciones adyacentes pueden ser rotadas, de forma que si se tiene los números 0,1,2,3 al rotar queden 3,2,1,0.

La cantidad de estados objetivo es igual a $n$. Se consideraron los TopSpin con $n=12$, $n=14$ y $n=17$, y $k=4$

### Torres de Hanoi

El problema de las Torres de Hanoi consiste en que hay P astas y D discos y cada uno de diferente tamaño. En cada estado, cada disco está exactamente en un asta y en cada asta los discos están ordenados de mayor a menor de abajo hacia arrba. La acción de mover un disco consiste en que debe moverse el disco que esté en el tope, y debe moverse al tope de otra asta, cumpliendo la restricción de que el disco a ser movido sea menor que el disco que se encuentre en el asta al cual se mueve.

Se consideraron las Torres de Hanoi de $D=12$, $D=14$ y $D=18$ discos con $P=4$.

En total el número de variables de estado es igual a $D \times P$, mientras que el dominio se compone de 0 y 1, donde significa que el disco está o no está en esa posición. La transición es mover un disco de un asta a la otra, y sólo se tiene un estado objetivo.

## Especificaciones de las pruebas

### Especificaciones de hardware de los equipos

- Ubuntu 22.04 LTS, Intel Core i7-9750H @ 2.60GHz, 16GB de RAM
- Windows Subsystem for Linux con Ubuntu 22.04, Intel Core i5-11400F @ 2.60GHz, 16GB de RAM

## Árboles de Búsqueda

Para generar los árboles de búsqueda se utilizó el algoritmo Breadth First Search (BFS), tomando en consideración las recomendaciones dadas en clase. El algoritmo tiene dos variaciones, una realiza poda parcial de duplicados usando el API de PSVN y otra no realiza la poda de duplicados.

Dado que este algoritmo realiza un consumo de RAM excesivo, la ejecución se detiene  por el propio sistema operativo cuando la RAM usada llega al 100%.

Los resultados son los siguientes:

### Sin pruning

#### 15-Puzzle

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 2 |
1 | 2 | 3 |
2 | 6 | 3 |
3 | 18 | 3,222 |
4 | 58 | 3,207 |
5 | 186 | 3,237 |
6 | 602 | 3,233 |
7 | 1946 | 3,236 |
8 | 6298 | 3,236 |
9 | 20378 | 3,236 |
10 | 65946 | 3,236 |
11 | 213402 | 3,236 |
12 | 690586 | 3,236 |
13 | 2234778 | 3,236 |
14 | 7231898 | 3,236 |
15 | 23402906 | 3,236 |
16 | 75733402 | 3,236 |

#### 24-Puzzle

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 2.000
1 | 2 | 3.000
2 | 6 | 3.000
3 | 18 | 3.389
4 | 61 | 3.164
5 | 193 | 3.523
6 | 680 | 3.165
7 | 2152 | 3.558
8 | 7656 | 3.139
9 | 24035 | 3.564
10 | 85666 | 3.118
11 | 267120 | 3.564
12 | 952086 | 3.104
13 | 2955395 | 3.563
14 | 10530665 | 3.095
15 | 32597517 | 3.562
16 | 116120864 | 3.090

#### Torres de Hanoi 4-12

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 3.000
1 | 3 | 5.000
2 | 15 | 5.000
3 | 75 | 5.240
4 | 393 | 5.366
5 | 2109 | 5.447
6 | 11487 | 5.517
7 | 63375 | 5.566
8 | 352755 | 5.608
9 | 1978341 | 5.642
10 | 11161197 | 5.670

#### Torres de Hanoi 4-14

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 3.000
1 | 3 | 5.000
2 | 15 | 5.000
3 | 75 | 5.240
4 | 393 | 5.366
5 | 2109 | 5.447
6 | 11487 | 5.517
7 | 63375 | 5.566
8 | 352755 | 5.608
9 | 1978341 | 5.642
10 | 11161197 | 5.670

#### Torres de Hanoi 4-18

|Profundidad|Nodos|Branching Factor|
|----|----|----|
|0 | 1 | 3.000|
1 | 3 | 5.000|
2 | 15 | 5.000
3 | 75 | 5.240
4 | 393 | 5.366
5 | 2109 | 5.447
6 | 11487 | 5.517
7 | 63375 | 5.566
8 | 352755 | 5.608
9 | 1978341 | 5.642
10 | 11161197 | 5.670

#### TopSpin 12-4

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 12.000
1 | 12 | 12.000
2 | 144 | 12.000
3 | 1728 | 12.000
4 | 20736 | 12.000
5 | 248832 | 12.000
6 | 2985984 | 12.000
7 | 35831808 | 12.000

#### TopSpin 14-4

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 14.000
1 | 14 | 14.000
2 | 196 | 14.000
3 | 2744 | 14.000
4 | 38416 | 14.000
5 | 537824 | 14.000
6 | 7529536 | 14.000

#### TopSpin 17-4

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 17.000
1 | 17 | 17.000
2 | 289 | 17.000
3 | 4913 | 17.000
4 | 83521 | 17.000
5 | 1419857 | 17.000
6 | 24137569 | 17.000

#### Rubik 3x3x3

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 18.000 
1 | 18 | 18.000 
2 | 324 | 18.000 
3 | 5832 | 18.000 
4 | 104976 | 18.000 
5 | 1889568 | 18.000


### Con pruning

#### 15-Puzzle

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 2.000 
1 | 2 | 2.000 
2 | 4 | 2.500 
3 | 10 | 2.400 
4 | 24 | 2.250 
5 | 54 | 2.000 
6 | 108 | 2.019 
7 | 218 | 2.165 
8 | 472 | 2.182 
9 | 1030 | 2.140 
10 | 2204 | 2.117 
11 | 4666 | 2.117 
12 | 9880 | 2.130 
13 | 21046 | 2.137 
14 | 44972 | 2.133 
15 | 95930 | 2.129 
16 | 204216 | 2.129 
17 | 434694 | 2.130 
18 | 925980 | 2.131 
19 | 1973338 | 2.131 
20 | 4204856 | 2.130 
21 | 8957558 | 2.130 
22 | 19080940 | 2.130 
23 | 40648730 | 2.130 
24 | 86600984 | 2.130 
25 | 184499846 | 2.130

#### 24-Puzzle

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 2.000 
1 | 2 | 2.000 
2 | 4 | 3.000 
3 | 12 | 2.833 
4 | 34 | 2.618 
5 | 89 | 3.034 
6 | 270 | 2.585 
7 | 698 | 2.974 
8 | 2076 | 2.623 
9 | 5446 | 2.937 
10 | 15996 | 2.632 
11 | 42101 | 2.919 
12 | 122880 | 2.634 
13 | 323633 | 2.909 
14 | 941445 | 2.633 
15 | 2478859 | 2.903 
16 | 7195597 | 2.632 
17 | 18936360 | 2.898 
18 | 54886250 | 2.630

#### Torres de Hanoi 4-12

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 3.000 
1 | 3 | 5.000 
2 | 15 | 5.000 
3 | 75 | 4.840 
4 | 363 | 5.149 
5 | 1869 | 5.087 
6 | 9507 | 5.269 
7 | 50091 | 5.227 
8 | 261843 | 5.333 
9 | 1396293 | 5.316 
10 | 7422543 | 5.381 
11 | 39937575 | 5.376

#### Torres de Hanoi 4-14

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 3.000 
1 | 3 | 5.000 
2 | 15 | 5.000 
3 | 75 | 4.840 
4 | 363 | 5.149 
5 | 1869 | 5.087 
6 | 9507 | 5.269 
7 | 50091 | 5.227 
8 | 261843 | 5.333 
9 | 1396293 | 5.316 
10 | 7422543 | 5.381

#### Torres de Hanoi 4-18

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 3.000 
1 | 3 | 5.000 
2 | 15 | 5.000 
3 | 75 | 4.840 
4 | 363 | 5.149 
5 | 1869 | 5.087 
6 | 9507 | 5.269 
7 | 50091 | 5.227 
8 | 261843 | 5.333 
9 | 1396293 | 5.316 
10 | 7422543 | 5.381

#### TopSpin 12-4

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 12.000 
1 | 12 | 8.500 
2 | 102 | 7.961 
3 | 812 | 7.884 
4 | 6402 | 7.874 
5 | 50412 | 7.873 
6 | 396902 | 7.873 
7 | 3124812 | 7.873 
8 | 24601602 | 7.873

#### TopSpin 14-4

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 14.000 
1 | 14 | 9.500 
2 | 133 | 8.632 
3 | 1148 | 8.459 
4 | 9711 | 8.430 
5 | 81864 | 8.426 
6 | 689800 | 8.426 
7 | 5812144 | 8.426 
8 | 48972249 | 8.426

#### TopSpin 17-4

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 17.000 
1 | 17 | 11.000 
2 | 187 | 9.610 
3 | 1797 | 9.250 
4 | 16622 | 9.175 
5 | 152503 | 9.167 
6 | 1398011 | 9.169 
7 | 12819040 | 9.171

#### Rubik 3x3x3

|Profundidad|Nodos|Branching Factor|
|----|----|----|
0 | 1 | 18.000 
1 | 18 | 13.500 
2 | 243 | 13.333 
3 | 3240 | 13.350 
4 | 43254 | 13.348 
5 | 577368 | 13.348 
6 | 7706988 | 13.348


### Comentarios

Tal como se esperaba, la cantidad de nodos disminuye con el pruning además que se logra explorar un poco más profundo el grafo de búsqueda. Las Torres de Hanoi arrojan


## Heurísticas

Para este proyecto se usaron los algoritmos de búsqueda informados A* e IDA*, los cuales usan heurísticas para mejorar su comportamiento. Las heurísticas usadas fueron PDBs aditivas, el máximo de varias PDB y distancia Manhattan.

Para cada problema se tienen las siguientes heurísticas:

- 15-Puzzle: se usó distancia Manhattan y tres PDBs aditivas con un total de 524.160 estados.
- 24-Puzzle: se planteó usar PDBs aditivas. Las PDBs no pudieron llegar a ser construidas por limitación de recursos. Una PDB llegó a 23.092.751 estados, y las otras dos a 5.862.457 estados y 19.589.656 estados.
- Torres de Hanoi: las PDB para las Torres de Hanoi seleccionan el máximo entre cuatro PDB. Se generaron un total de 2 PDB para cada caso.
  - 12-4 se tienen 2 PDBs con 4096 estados.
  - 14-4: 2 PDBs, dos con 16384 estados.
  - 18-4: 2 PDBs con 262.144 estados.
- Top Spin: con TopSpin se generaron 3 PDB para cada caso. 
  - 12-4: una con 11880, otra con 655280 casos y 11880 casos.
  - 14-4: una de 24024 estados, otra de 17.297.280 y otra de 240240 estados.
  - 17-4: una con 57120 estados, otra con 8910720 estados y una que no pudo ser generada.
- Rubik: no fue posible generar los PDB de Rubik.
## Resultados de las ejecuciones

Se ejecutaron los algoritmos A* e IDA* y se obtuvieron los siguientes resultados:

### Hanoi 4-12 A* 005
|Profundidad|Nodos|
|----|----|
9|47
2|5
5|11
9|42
2|5
5|11
9|47
2|5
9|44
5|11


### Hanoi 4-12 A* 010
|Profundidad|Nodos|
|----|----|
5|11
20|185
2|5
2|5
9|42
2|5
14|98
14|87
14|87
14|98

### Hanoi 4-12 A* 015
|Profundidad|Nodos|
|----|----|
9|44
20|183
5|11
5|11
14|98
14|87
9|44
5|11
20|177
14|98

### Hanoi 4-12 A* 2000
|Profundidad|Nodos|
|----|----|
225|255445
445|10813796
351|2698219
364|2476355
343|3117106
469|15384095
182|117599
515|17232062
259|595639
129|22892

### Hanoi 4-12 IDA* 005
|Profundidad|Nodos|
|----|----|
48|89
40|1
42|15
44|176
42|1
44|65
48|89
38|1
44|17
44|73

### Hanoi 4-12 IDA* 010
|Profundidad|Nodos|
|----|----|
44|65
47|8190
42|1
40|1
43|102
38|1
50|2480
45|84
48|36093
44|77 

### Hanoi 4-12 IDA* 015
|Profundidad|Nodos|
|----|----|
43|107
52|10467
42|40
46|19
46|85
49|171292
44|17
42|40
54|6643527
50|2480

El caso de Hanoi 4-12 con A* e IDA* no pudo ser generado por dar el error "stack smashing detected".

### TopSpin 12-4 A* 005
|Profundidad|Nodos|
|----|----|
20|1680
19|2352
20|1788
19|1680
18|2508
20|1764
20|1920
20|1740
20|1728
20|2256

### TopSpin 12-4 A* 010
|Profundidad|Nodos|
|----|----|
48|4800024
14|324
36|276720
35|326160
38|139776
34|434940
14|324
38|386916
39|105108
40|297408

### TopSpin 12-4 A* 015
|Profundidad|Nodos|
|----|----|
36|240828
37|292404
41|454704
52|3144048
53|13859232
36|336192
44|2142156
50|4235856
45|1483932
37|389148

### TopSpin 12-4 A* 2000
|Profundidad|Nodos|
|----|----|
40|617244
33|77820
43|2916432
41|1545144
44|1127616
57|19374696
33|47544
43|379644
51|4864020
47|1587408

El caso de TopSpin 12-4 con IDA* no pudo ser ejecutado por el error "stack smashing detected".

## Conclusiones

Gracias a la eliminación de duplicados, se observó una menor cantidad de nodos además que el factor de ramificación de los árboles de búsqueda se redujeron en comparativa a cuando no hay eliminación de duplicaods. 

El desempeño del algoritmo A* es mejor para ciertos casos que el algoritmo de IDA*. Hubo varias ejecuciones donde no se pudo realizar completamnete debido a que IDA* demoraba más, pero otras donde A* sí podía hacer la ejecución.

Los tiempos de ejecución en varios casos fueron de pocos segundos, como son Hanoi 