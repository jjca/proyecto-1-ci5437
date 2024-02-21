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

Para representar el cubo de Rubik

### Top-spin

### Torres de Hanoi 