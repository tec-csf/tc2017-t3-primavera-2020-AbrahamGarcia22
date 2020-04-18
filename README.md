# Tarea *[3]*. *[Técnicas de diseño de algoritmos*

---

##### Integrantes:
1. *[Abraham Garcia Del Corral]* - *[A01023256]* - *[CSF]*


---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

*Multiplicacion de matrices*

Para resolver este problema se utilizó el método ávido.
Debido a que la cantidad de operaciones aumentan de manera cuadrática dependiendo de las dimensiones, hacerlo de forma recursiva es muy tardado. Por lo tanto lo mejor es guardar en una tabla las soluciones para después utilizarlas.
La matriz tendrá guardado el resultado más optimo para su posición en especifica
Como tal la matriz representa el numero de particiones desde desde i hasta j.Asi, la matriz se llena por diagonales, siendo la diagonal central 0 y la parte derecha contendrá las particiones y sus resultados. Cada casilla depende de las particiones en las que se puede dividir.Debido a esto, la solucion general va a estar en la esquina superior derecha de la matriz, donde tenemos todas las posibles particiones y cual de estas es la suma minima de multiplicaciones escalares.
Complejidad n^2 (numero de matrices por numero de matrices)

*Ciclos hamiltonianos*

Este problema se resolvio de la forma vuelta atrás.
La solucion se obtiene recorriendo de manera profunda el grafo dado, explorando todas las posibles soluciones que se tienen.
El ciclo se cumple si siempre y cuando este sea convexo. El ciclo se cumple si se visita cada uno de los nodos solamente una vez. Por lo tantio si nos ayudamos de una estructura como un arreglo para ir guardando los vertices que ya visitamos, podemos recorrer las opciones válidas. Esta lista será la solucion final, cuando termine el algoritmo. Si en un dado caso, un camino no funcionó, se regresa a al vértice anterior para explorar otro vertice y se elimina el vertice fallido de la estructura.
Si todos los vertices de la estructura fueron validos y el ultimo se conecta con el primero, ese camino será la solución. El coste si el grafo es ponderado, se evalua cuando los vertices son válidos,si se insertan, tambien se añade su coste, en el caso de que se tenga que eliminar, también se resta dicho coste.
La complejidad de este algoritmo puede variar dependiendo de los grafos, si son ponderados, si son dirigidos etc. En su mayoria el peor de los casos de este algoritmo con este método es factorial


### 2.1 Pasos a seguir para utilizar la aplicación

clonar el repositorio en la terminal
git clone https://github.com/tec-csf/tc2017-t3-primavera-2020-AbrahamGarcia22

compilar el problema matrices:
g++ sources/main.cpp -std=c++17

Correr el programa:
./a.out < examples/test.txt

Compilar el problema hamiltoniano
g++ sources/main.cpp -std=c++17

Correr el programa
./a.out



## 3. Referencias

*[Guerequeta,R. (1998). Técnicas de Diseño de Algoritmos . Malaga: Servicio de Publicaciones de la Universidad de Málaga.
   s.a. (s.f). Programacion dinamica. 15/04/2020, de monografias Sitio web: https://www.monografias.com/trabajos107/programacion-dinamica-optimizacion/programacion-dinamica-optimizacion2.shtml*
