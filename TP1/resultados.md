#1.
gcc -g -Wall -pedantic-errors -std=c2x -o prog  main.c tabla.c conversion.c
#2.
$ gcc -g -Wall -pedantic-errors -std=c2x -o prog  main.c tabla.c conversion.c
tabla.c: In function 'generarTabla':
tabla.c:18:51: error: implicit declaration of function 'convertir' [-Wimplicit-function-declaration]
   18 |         printf("|    %.3f|     %.3f| \n",inicio+i,convertir(inicio+i));
      |                                                   ^~~
tabla.c:18:35: warning: format '%f' expects argument of type 'double', but argument 3 has type 'int' [-Wformat=]
   18 |         printf("|    %.3f|     %.3f| \n",inicio+i,convertir(inicio+i));
      |                                ~^               ~~~~~
      |                                   |               |
      |                                   double          int
      |                                %.3d
tabla.c: In function 'generarTablaConIncremento':
tabla.c:29:35: warning: format '%f' expects argument of type 'double', but argument 3 has type 'int' [-Wformat=]
   29 |         printf("|    %.3f|     %.3f| \n",inicio,convertir(inicio));
      |                                ~^             ~~~~~
      |                                   |             |
      |                                   double        int
      |                                %.3d

Explicacion:
El error es causado en los llamados a la funcion convertir, ya que se esta llamando a una funcion la cual no esta declarada. Porque dejamos de incluir convercion.h, donde se realizaba dicha declaración.
En este caso estamos hablando de un error de compilación ya que falla al convertir el codigo fuente en codigo objeto.
El warning se genera porque por defecto c asume que las funciones con un tipo no declarado son int y la función printf espera un doble. 


#3.
$ gcc -g -Wall -pedantic-errors -std=c2x -o prog  main.c conversion.c
C:/TDM-GCC-64/bin/../lib/gcc/x86_64-w64-mingw32/10.3.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\Usuario\AppData\Local\Temp\ccm2W1xS.o: in function main':
D:\Materias\Sintaxis y Semantica\Trabajos\SslGrupo12\TP1/main.c:5: undefined reference to generarTabla'
C:/TDM-GCC-64/bin/../lib/gcc/x86_64-w64-mingw32/10.3.0/../../../../x86_64-w64-mingw32/bin/ld.exe: D:\Materias\Sintaxis y Semantica\Trabajos\SslGrupo12\TP1/main.c:8: undefined reference to `generarTablaConIncremento'
collect2.exe: error: ld returned 1 exit status

Explicacion:
El error es causado porque generarTabla y generarTablaConIncremento estan declarados, pero no definidos. Esto es porque main.c incluye tabla.h pero no compilamos tabla.c por lo que el codigo de la función no esta. En este caso el fallo se produce en el linker.

#4.
gcc -E conversion.c -o conversion.is