# Proyecto N°2 – Simulación de Auto-Home de un Brazo Robótico  

**Integrantes:** Sebastian Palacios, Javiera Vega, Hugo Nuñez, Jordan Porras.

El proyecto simula la rutina de auto-home de un brazo robótico con 4 eslabones. 
Cada eslabón comienza en una posición aleatoria (dentro del rango de 0 a 360) 
y el programa hace que sus coordenadas X e Y disminuyan hasta llegar a 0, 
que es la posición de origen.

---

## Requisitos previos

Para compilar y ejecutar el programa, solo necesitas tener instalado un compilador de C, por ejemplo GCC.

---

## Compilación y ejecución

Sigue estos pasos desde la terminal o consola:

1. Compilar el archivo principal:
   ```bash
   gcc ejercicio.c -o ejercicio
   ```

2. Ejecutar el programa:
   ```bash
   ./ejercicio
   ```

Si usas Windows, el ejecutable se llamará `ejercicio.exe` y lo ejecutas con:
   ```bash
   ejercicio.exe
   ```

---

## Explicación del código

El programa está dividido en partes claras para que sea fácil de entender.

### 1. Estructura del eslabón (`Eslabon`)

Se define una estructura que guarda la información de cada eslabón:

- `id`: número identificador (1, 2, 3 o 4).
- `x`: posición en el eje X (tipo flotante).
- `y`: posición en el eje Y (tipo flotante).

### 2. Generación de posiciones iniciales (`generarPosicion`)

Esta función recibe dos punteros (uno para X y otro para Y) y les asigna un valor aleatorio entre 0 y 360. 
Se usa la función `rand()` con el operador `% 361` para asegurar que el número quede dentro del rango permitido.

### 3. Simulación del auto-home (`autoHome`)

Esta función recibe un eslabón por referencia (usando un puntero) y modifica sus posiciones. 
Dentro de un ciclo `while`, va restando 1 a X y a Y mientras sean mayores que 0. 
Cuando ambas coordenadas llegan a 0, la función retorna `true` para indicar que el eslabón terminó su proceso.

### 4. Función principal (`main`)

Aquí ocurre todo el flujo del programa:

- Se definen las 4 estructuras con los nombres `id1`, `id2`, `id3` e `id4`, tal como lo pide la tarea.
- Se llama a `generarPosicion` para cada una de ellas.
- Se imprimen las posiciones iniciales en pantalla.
- Se llama a `autoHome` para cada eslabón y se guarda el resultado (verdadero o falso).
- Finalmente, se muestran los mensajes de término para cada eslabón y el mensaje global cuando todos han terminado correctamente.

---

## Ejemplo de salida

Al ejecutar el programa, verás algo parecido a esto:

```
=====================================
POSICIONES INICIALES DE LOS ESLABONES
=====================================
Eslabon 1 -> X = 240, Y = 150
Eslabon 2 -> X = 80, Y = 300
Eslabon 3 -> X = 360, Y = 45
Eslabon 4 -> X = 10, Y = 200

=====================================
INICIO DEL PROCESO AUTO-HOME
=====================================

Iniciando Auto-Home del Eslabon 1
Posicion inicial: X = 240, Y = 150
Eslabon 1 -> X = 239, Y = 149
...
Eslabon 1 -> X = 0, Y = 0

Eslabon 1 terminado
Eslabon 2 terminado
Eslabon 3 terminado
Eslabon 4 terminado
Todos los eslabones realizaron auto-home correctamente.
```
