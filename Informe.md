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

### TopSpin 14-4 A* 005
|Profundidad|Nodos|
|----|----|
20|1960
17|2842
20|1498
20|2142
20|2212
20|1344
20|1666
20|2464
20|2604
20|2436

### TopSpin 14-4 A* 010
|Profundidad|Nodos|
|----|----|
54|10295768
56|13468602
41|325080
59|5450102
57|8741964
55|9017092
56|15018500
27|3906
40|222880
42|178864

### TopSpin 14-4 A* 015
|Profundidad|Nodos|
|----|----|
57|2294838
68|289206918
57|29010184
66|45274208
73|227520468
58|4421550
47|3737286
60|16438128
72|259576702
59|7377174

### TopSpin 14-4 A* 2000
|Profundidad|Nodos|
|----|----|
71|243711342
68|159107550
70|140958734
76|243291272
70|264782420
67|52916416
68|149942016
76|359033248
75|312826402
73|396477130

### TopSpin 12-4 IDA* 005
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
8 4 5 10 9 7 0 1 2 3 6 11  |  -1  |  2215340877  |  300
8 4 3 2 9 5 6 10 1 0 7 11  |  34  |  903801435   | 125.61
0 1 2 9 4 5 7 8 3 6 10 11  |  -1  |  2195655507  |  300
8 7 1 0 4 5 6 9 2 3 10 11  |  -1  |  2188998501  |  300
0 10 9 2 1 6 7 3 4 5 8 11  |  -1  |  2176093874  |  300
8 3 2 10 9 4 1 7 6 5 0 11  |  24  |  544064  |  0.0765326
7 6 9 8 0 2 10 1 5 4 3 11  |  32  |  193575185  |  27.1501
1 5 4 3 2 0 8 10 9 7 6 11  |  14  |  8672  |  0.00121527
0 1 5 3 8 7 6 4 10 9 2 11  |  14  |  91451  |  0.0129368
0 7 6 2 1 8 5 10 9 3 4 11  |  -1  |  2135406650  |  300

### TopSpin 12-4 IDA* 010
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
3 4 5 10 6 0 2 8 7 9 1 11  |  -1  |  2268743251  |  300
9 8 7 2 3 4 5 6 10 1 0 11  |  22  |  71886  |  0.0115824
4 8 1 9 10 0 3 5 6 7 2 11  |  -1  |  2260593599  |  300
0 10 9 8 7 5 2 1 4 3 6 11  |  -1  |  2236972587  |  300
8 9 2 6 0 5 4 10 7 3 1 11  |  -1  |  2263246351  |  300
8 1 2 7 3 0 5 4 9 10 6 11  |  18  |  48985  |  0.00744687
3 2 5 4 0 8 9 1 6 7 10 11  |  -1  |  2135082517  |  300
4 3 2 7 6 5 0 9 1 10 8 11  |  22  |  3084  |  0.000429376
1 3 10 9 7 8 2 6 5 4 0 11  |  26  |  155040 |  0.0246054
1 9 8 7 0 6 10 5 3 4 2 11  |  29  |  167244  |  0.0253239

### TopSpin 12-4 IDA* 015
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
5 4 0 9 1 8 6 10 2 3 7 11  |  -1  |  2160101433  |  300
8 3 1 6 10 9 4 7 5 2 0 11  |  22  |  23847  |  0.00315765
5 1 8 6 3 2 0 4 7 10 9 11  |  -1  |  2142865922  |  300
1 3 7 2 4 0 8 10 6 5 9 11  |  -1  |  2136640131  |  300
5 1 6 0 7 3 8 10 4 2 9 11  |  -1  |  2164481889  |  300
0 6 5 1 2 9 4 8 3 7 10 11  |  -1  |  2150983503  |  300
9 10 8 3 4 1 2 5 0 6 7 11  |  18  |  244778  |  0.0377491
6 2 4 0 8 3 10 9 7 5 1 11  |  -1  |  2055895767   | 300
4 10 9 2 6 8 0 1 5 3 7 11  |  20  |  130938 |  0.0180987
10 7 0 2 1 6 4 5 8 9 3 11  |  16  |  32117  |  0.00470829

### TopSpin 12-4 IDA* 2000
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
0 7 3 5 4 9 10 8 6 1 2 11  |  -1  |  2202009055  |  300
6 7 4 3 5 2 1 0 9 8 10 11  |  -1  |  2167347630  |  300
8 5 7 4 9 1 0 2 3 10 6 11  |  -1  |  2167454927  |  300
10 1 5 4 3 0 8 9 7 6 2 11  |  25  |  24662  |  0.00333433
10 4 1 0 2 8 6 5 9 7 3 11  |  18  |  122503  |  0.0187688
9 0 7 10 4 8 2 6 1 3 5 11  |  -1  |  2112029515  |  300
3 0 6 7 8 1 5 4 10 2 9 11  |  -1  |  2102532331  |  300
7 5 4 8 6 10 3 9 1 0 2 11  |  22  |  112415  |  0.0147303
9 6 10 3 1 7 4 0 8 5 2 11  |  -1  |  2143081034  | 300
5 8 3 2 6 10 0 9 7 1 4 11  |  -1  |  2085533149  |  300

### TopSpin 12-4 IDA* 2000000
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
7 5 2 9 4 8 0 10 6 1 3 11  |  -1  |  2208635602 |   300
6 2 7 4 1 10 0 9 8 3 5 11  |  18  |  6211  |  0.000912331
6 7 0 3 10 4 8 9 5 1 2 11  |  -1  |  2196286837   | 300
8 10 6 3 1 2 4 7 0 5 9 11  |  25  |  280003  |  0.0379907
9 7 2 1 10 6 8 0 4 5 3 11  |  15  |  487329  |  0.0662718
3 10 4 2 7 5 6 9 0 1 8 11  |  -1  |  2103919994  |  300
10 0 5 4 1 9 8 7 3 6 2 11  |  21  |  88690  |  0.0123203
2 3 7 10 6 0 5 9 1 8 4 11  |  -1  |  2082628463  |  300
1 5 6 4 10 0 9 8 7 2 3 11  |  17  |  28014  |  0.00340198
9 7 0 10 4 6 5 8 2 3 1 11  |  -1  |  2172857038   | 300

### TopSpin 14-4 IDA* 005
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
12 7 1 2 3 11 10 5 4 8 9 6 0 13  |  29  |  67152  |  0.00871492
8 7 6 9 12 11 0 10 1 2 3 4 5 13  |  29  |  108063 |   0.0133315
10 9 2 12 4 3 1 11 5 6 7 8 0 13  |  19  |  61478  |  0.00759691
6 7 3 8 4 5 0 10 9 12 11 1 2 13  |  -1  |  2489679773  |  300
0 1 5 10 9 2 6 4 3 8 7 11 12 13  |  -1  |  2358686703  |  300
0 7 1 11 12 8 5 4 3 2 6 10 9 13  |  -1  |  2392563382  |  300
5 6 2 1 4 8 9 10 11 12 0 7 3 13  |  24  |  2047958  |  0.288676
6 11 0 1 2 3 4 7 8 12 5 10 9 13  |  -1  |  2580767514  |  300
9 8 11 1 2 3 10 6 5 4 0 7 12 13  |  -1  |  2607487880  |  300
3 4 1 0 5 6 7 10 11 12 8 9 2 13  |  15  |  25139  |  0.0028037

### TopSpin 14-4 IDA* 010
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
9 7 1 0 3 4 5 10 2 6 12 8 11 13  |  22  |  32355  |  0.00365812
4 5 6 3 10 11 1 7 8 9 2 12 0 13  |  -1  |  2281146113  |  300
4 9 10 1 5 8 11 12 2 3 7 6 0 13  |  -1  |  2281738686  |  300
9 5 3 11 10 6 0 4 7 1 2 12 8 13  |  21  |  2802516  |  0.348602
4 10 2 5 6 7 0 12 11 9 3 8 1 13  |  -1  |  2276897626  |  300
9 6 11 3 1 0 12 7 8 2 10 5 4 13  |  22  |  4943984  |  0.669785
7 3 8 1 4 5 6 12 10 0 2 11 9 13  |  -1  |  2414919533  |  300
0 7 6 5 4 8 9 1 10 2 3 12 11 13  |  29  |  284313  |  0.0323382
9 12 11 0 7 1 2 3 8 6 5 4 10 13  |  -1  |  2378262691   | 300
7 2 0 3 4 8 1 6 5 9 10 12 11 13  |  -1  |  2490716690  |  300

### TopSpin 14-4 IDA* 015
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
11 9 0 6 7 8 2 10 5 1 3 4 12 13  |  29  |  163958   | 0.0199658
4 5 2 10 1 11 0 3 8 7 9 12 6 13  |  22  |  2923468  |  0.36215
3 7 8 6 9 0 4 11 12 5 2 1 10 13  |  -1  |  2231976923  |  300
4 10 5 11 3 6 7 8 2 0 12 1 9 13  |  18  |  1242079  |  0.140926
8 5 10 0 6 2 1 4 12 11 9 7 3 13  |  25  |  406014  |  0.0482118
1 11 7 3 2 9 5 6 12 8 0 4 10 13  |  16  |  53962  |  0.00591413
2 1 0 7 4 9 8 3 10 12 11 5 6 13  |  -1  |  2333329561  |  300
1 9 8 3 12 4 5 6 0 7 2 10 11 13  |  25  |  93021  |  0.0108269
11 7 8 9 2 6 10 5 12 3 0 4 1 13  |  26  |  652597  |  0.0780024
6 0 7 9 5 12 2 3 1 8 11 10 4 13  |  -1  |  2436311370  |  300

### TopSpin 14-4 IDA* 2000
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
7 5 8 0 12 4 10 11 6 2 1 3 9 13  |  26  |  1962057  |  0.217297
10 5 9 3 2 6 1 8 11 7 4 12 0 13  |  -1  |  2479456173  |  300
3 7 12 5 1 10 4 9 11 2 8 0 6 13  |  20  |  7464006  |  0.88428
2 12 5 4 6 10 0 8 3 1 11 7 9 13  |  19  |  1714988  |  0.216738
12 9 4 7 3 11 8 5 1 6 10 2 0 13  |  22  |  774573  |  0.100237
9 4 11 12 5 8 6 10 0 2 3 1 7 13  |  -1  |  2487201263  |  300
3 9 11 8 0 7 12 5 1 2 4 10 6 13  |  -1  |  2459960238  |  300
11 3 6 10 12 8 2 7 1 9 0 5 4 13  |  -1  |  2434931590  |  300
9 5 7 6 2 12 1 3 11 4 10 8 0 13  |  -1  |  2375503060  |  300
3 9 2 6 0 7 10 4 5 12 1 8 11 13  |  21  |  3055507  |  0.347491

### TopSpin 14-4 IDA* 2000000
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
2 1 11 8 12 4 3 7 6 5 0 10 9 13  |  -1  |  2565976594  |  300
6 10 12 5 4 8 7 0 9 3 1 11 2 13  |  22  |  724541 |   0.0932792
8 11 0 2 4 1 12 6 9 3 5 7 10 13  |  -1  |  2326968803   | 300
3 6 11 8 5 12 7 0 9 1 4 2 10 13  |  -1  |  2390954066   | 300
5 7 12 6 0 3 9 8 1 2 10 4 11 13  |  -1  |  2318438437   | 300
7 4 12 11 0 3 8 9 2 6 1 10 5 13  |  -1  |  2210181431   | 300
3 6 12 2 8 1 7 5 9 0 4 11 10 13  |  -1  |  2056800217   | 300
2 1 7 6 4 0 11 5 8 9 12 10 3 13  |  21  |  490748  |  0.0592035
10 11 3 2 5 9 8 7 12 6 0 4 1 13  |  17  |  148373  |  0.0175595
0 11 9 12 8 7 4 1 2 5 3 10 6 13  |  28  |  11105605|    1.39365

### TopSpin 17-4 IDA* 005
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
4 5 6 7 8 9 10 11 12 15 3 0 13 14 2 1 16  |  31  |  5523816   | 0.568318
12 11 10 0 13 14 15 1 2 3 4 7 8 9 5 6 16  |  46  |  58896388  |  5.62278
0 1 4 5 9 8 11 10 6 14 13 12 7 15 2 3 16  |  29  |  17444881  |  1.55434
15 3 2 1 14 4 5 10 11 7 6 13 12 8 9 0 16  |  37  |  2733057   | 0.269652
9 8 14 15 13 12 10 0 1 2 3 4 5 6 7 11 16  |  33  |  13403968  |  1.50332
15 14 1 0 2 3 4 5 10 11 7 6 9 8 12 13 16  |  31  |  6501832   | 0.595066
15 14 1 0 2 3 4 5 6 7 8 9 10 11 12 13 16  |  30  |  3247210   | 0.335195
0 3 4 5 6 7 8 9 2 13 14 10 1 11 12 15 16  |  25  |  148602    |0.0160829
0 1 2 3 8 6 5 4 13 14 7 9 10 12 11 15 16  |  25  |  21483694  |  2.02884
3 7 6 5 10 9 8 4 14 13 12 11 0 1 2 15 16  |  29  |  5036227   | 0.474041


### TopSpin 17-4 IDA* 010
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
15 3 5 4 2 9 10 11 6 14 13 12 8 0 1 7 16  |  31  |  37822151 |   3.21571
2 3 13 11 0 4 5 6 7 8 9 10 14 15 12 1 16  |  36  |  24166048 |   2.7351
13 12 3 0 10 11 2 14 1 4 5 6 7 8 9 15 16  |  39  |  2118344  |  0.21662
9 8 12 13 14 15 2 1 0 5 11 3 7 6 4 10 16  |  42  |  26065882 |   2.61063
11 12 8 7 13 14 15 10 9 5 6 3 2 1 4 0 16  |  34  |  49404183 |   5.12538
10 2 12 5 6 7 8 11 0 9 14 15 1 13 3 4 16  |  28  |  3738031  |  0.398261
1 13 4 5 6 7 8 9 10 14 2 11 15 12 3 0 16  |  24  |  7014107  |  0.79969
8 0 1 2 3 4 5 13 15 7 10 11 9 6 14 12 16  |  29  |  9421427  |  0.854047
3 4 9 10 11 15 12 13 1 2 6 5 8 7 14 0 16  |  36  |  44356008 |   4.92379
0 1 3 4 9 5 2 7 6 10 11 12 13 15 14 8 16  |  12  |  272872   | 0.0274445

### TopSpin 17-4 IDA* 015
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
9 14 1 7 3 6 10 5 4 2 12 15 11 8 0 13 16  |  31  |  15791164 |   1.94618
13 12 11 1 14 2 3 10 9 7 6 8 4 15 5 0 16  |  28  |  1820007  |  0.171827
0 10 3 7 6 5 12 9 8 13 14 1 4 11 2 15 16  |  40  |  31343281 |   3.01045
9 10 13 12 2 3 11 1 14 15 7 6 5 4 8 0 16  |  32  |  10694019 |   1.01068
13 1 2 6 14 3 7 9 5 4 10 11 12 15 0 8 16  |  27  |  19204015 |   1.83449
13 6 5 0 2 1 12 11 3 15 8 7 9 10 14 4 16  |  29  |  8243471  |  0.795547
13 1 15 14 3 4 0 7 6 5 12 2 8 9 10 11 16  |  34  |  5739543  |  0.542904
6 7 12 10 9 14 2 15 8 0 1 11 13 5 4 3 16  |  37  |  2385297  |  0.217677
5 12 14 7 8 11 13 15 1 2 3 4 0 9 10 6 16  |  36  |  2127203  |  0.209792
1 14 2 4 0 5 6 7 8 9 10 3 13 12 11 15 16  |  23  |  837290   | 0.0677151

### TopSpin 17-4 IDA* 2000
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
9 0 1 11 4 10 7 5 14 2 3 13 8 6 15 12 16  |  33  |  20253366 |   2.11933
7 1 14 4 2 5 15 12 9 3 8 13 10 11 6 0 16  |  25  |  36488244 |   3.53879
7 10 4 14 9 3 1 5 0 11 13 2 8 6 12 15 16  |  37  |  8409554  |  0.845057
4 13 2 10 0 14 11 6 3 8 15 12 7 1 5 9 16  |  41  |  313793243|    26.3188
12 10 6 8 15 3 2 11 14 5 13 7 9 0 1 4 16  |  35  |  19147323 |   1.67763
3 13 4 12 14 5 10 11 1 9 6 8 15 0 7 2 16  |  29  |  8350396  |  0.834807
2 7 8 13 14 4 9 11 3 10 1 6 5 0 12 15 16  |  34  |  12387466 |   1.43001
1 9 0 8 2 12 3 11 6 4 15 13 7 10 14 5 16  |  32  |  1613310  |  0.180131
13 6 2 15 5 12 9 0 1 7 8 3 14 10 4 11 16  |  28  |  18259176 |   1.59389
2 9 11 13 0 1 5 3 4 12 14 15 8 6 10 7 16  |  36  |  4791057  |  0.502153

### TopSpin 12-4 IDA* 2000000
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
6 3 8 14 10 7 0 13 12 15 1 5 11 4 9 2 16  |  43  |  74770126  |  7.85146
5 3 6 9 10 8 14 12 11 4 2 0 7 15 1 13 16  |  36  |  7201767   | 0.639118
15 5 12 2 3 7 4 1 6 9 10 13 11 14 0 8 16  |  29  |  28976230  |  2.54077
10 7 1 4 11 12 0 13 8 9 5 15 6 3 2 14 16  |  37  |  25357854  |  2.39428
2 9 3 14 13 15 5 7 11 12 1 4 0 10 6 8 16  |  26  |  26366047  |  2.733
9 4 2 15 10 7 0 3 5 12 8 1 14 13 6 11 16  |  28  |  1119027   | 0.109498
15 2 13 6 1 4 8 0 11 7 14 9 12 5 10 3 16  |  35  |  26386981  |  2.54626
9 15 10 3 11 8 13 0 14 12 2 1 4 7 5 6 16  |  39  |  5318216   | 0.516143
8 11 12 0 14 7 2 10 4 13 6 15 3 1 5 9 16  |  45  |  16718518  |  1.7087
7 10 3 2 5 6 8 13 12 0 15 4 1 14 11 9 16  |  28  |  47468932  |  4.46058

### 15-Puzzle (Subconjunto de los ejemplos de benchmarks)
|Instancia|Profundidad|Nodos Generados|Distancia|
|----|----|----|----|
1 2 3 4 5 6 7 8 9 10 11 12 13 14 B 15  |  1  |  2  |  1.35e-06
1 2 3 4 5 6 7 8 9 10 11 12 B 14 15 13  |  19  |  18507  |  0.00241015
1 2 3 4 5 6 7 8 9 10 B 12 13 14 11 15  |  2  |  6  |  1.312e-06
6 12 11 3 13 7 9 15 2 14 8 10 4 1 5 B  |   -1  |  2382849704  |  300
12 8 14 6 11 4 7 B 5 1 10 15 3 13 9 2  |   -1  |  2377416234  |  300
14 3 9 1 15 8 4 5 11 7 10 13 B 2 12 6  |   -1  |  2416208171  |  300
10 9 3 11 B 13 2 14 5 6 4 7 8 15 1 12  |   -1  |  2471469414  |  300
7 3 14 13 4 1 10 8 5 12 9 11 2 15 6 B  |   -1  |  2419694581  |  300
11 4 2 7 1 B 10 15 6 9 14 8 3 13 5 12  |   -1  |  2370271345  |  300
5 7 3 12 15 13 14 8 B 10 9 6 1 4 2 11  |   -1  |  2438766416  |  300
14 1 8 15 2 6 B 3 9 12 10 13 4 7 5 11  |   -1  |  2478003083  |  300
13 14 6 12 4 5 1 B 9 3 10 2 15 11 8 7  |   -1  |  2513502569  |  300
9 8 B 2 15 1 4 14 3 10 7 5 11 13 6 12  |   -1  |  2478025572  |  300
12 15 2 6 1 14 4 8 5 3 7 B 10 13 9 11  |   -1  |  2376188023  |  300
12 8 15 13 1 B 5 4 6 3 2 11 9 7 14 10  |   -1  |  2372598981  |  300
14 10 9 4 13 6 5 8 2 12 7 B 1 3 11 15  |   -1  |  2343744288  |  300
14 3 5 15 11 6 13 9 B 10 2 12 4 1 7 8  |   -1  |  2442045724  |  300
6 11 7 8 13 2 5 4 1 10 3 9 14 B 12 15  |   -1  |  2386575031  |  300
1 6 12 14 3 2 15 8 4 5 13 9 B 7 11 10  |   -1  |  2391169878  |  300
12 6 B 4 7 3 15 1 13 9 8 11 2 14 5 10  |   -1  |  2421581227  |  300
8 1 7 12 11 B 10 5 9 15 6 13 14 2 3 4  |   -1  |  2365100878  |  300
9 B 4 10 1 14 15 3 12 6 5 7 11 13 8 2  |   -1  |  2485645061  |  300
11 5 1 14 4 12 10 B 2 7 13 3 9 15 6 8  |   -1  |  2469278626  |  300
8 13 10 9 11 3 15 6 B 1 2 14 12 5 4 7  |   -1  |  2474020793  |  300

### 24-Puzzle (Subconjunto de los ejemplos de benchmarks)
No se pudieron obtener resultados debido a la falta de recursos.

## Conclusiones
Es importante destacar que se agregó un timer que detiene la ejecución del problema actual luego de 5 minutos. Una vez que esto ocurre, pasa al siguiente problema. Esto se hizo con el fin de colocar un tiempo límite y poder conseguir datos con la mayor cantidad de ejercicios posibles, sin comprometer demasiado las pruebas.

Gracias a la eliminación de duplicados, se observó una menor cantidad de nodos además que el factor de ramificación de los árboles de búsqueda se redujeron en comparativa a cuando no hay eliminación de duplicaods. 

El desempeño del algoritmo A* es mejor para ciertos casos que el algoritmo de IDA*. Hubo varias ejecuciones donde no se pudo realizar completamnete debido a que IDA* demoraba más, pero otras donde A* sí podía hacer la ejecución.

Los tiempos de ejecución en varios casos fueron de pocos segundos, como son Hanoi.