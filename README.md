# cables-y-voltios

Guía de compilación — Linux y Windows

Esta guía explica cómo compilar el proyecto desde cero. El proyecto está desarrollado en C++ utilizando raylib.

1. Archivos del proyecto

Primero asegúrate de tener todos los archivos .cpp del proyecto en la misma carpeta:

proyecto/
├── main.cpp
├── code.cpp
├── dib.cpp
├── escri.cpp
├── menu.cpp
└── func.cpp

También deben estar disponibles los archivos .h que utiliza el proyecto.

⸻

Linux

2. Instalar las herramientas necesarias

En Ubuntu/Debian puedes instalar G++ y las dependencias necesarias con:

sudo apt update
sudo apt install g++ build-essential git

Comprueba que G++ esté instalado:

g++ --version

⸻

3. Instalar raylib

Descarga raylib desde su repositorio oficial:

https://github.com/raysan5/raylib

Puedes clonar el repositorio:

git clone https://github.com/raysan5/raylib.git

Entra en la carpeta:

cd raylib

Crea una carpeta de compilación:

mkdir build
cd build

Configura y compila raylib:

cmake ..
make

Después tendrás la librería compilada.

⸻

4. Compilar el proyecto

Vuelve a la carpeta de tu proyecto.

Si raylib está instalada, por ejemplo, en:

/home/usuario/raylib/

puedes compilar con:

g++ main.cpp code.cpp dib.cpp escri.cpp menu.cpp func.cpp \
-o programa \
-I/home/usuario/raylib/src \
-L/home/usuario/raylib/build/raylib \
-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

Si raylib está en otra ubicación

Debes cambiar:

-I/home/usuario/raylib/src

por la ubicación donde se encuentra raylib.h.

Y:

-L/home/usuario/raylib/build/raylib

por la carpeta donde se encuentra la librería compilada.

Por ejemplo:

-I/home/juan/raylib/src
-L/home/juan/raylib/build/raylib

⸻

5. Ejecutar el programa

Si la compilación terminó correctamente:

./programa

⸻

Windows

6. Instalar un compilador C++

Para compilar utilizando g++, instala MinGW-w64.

Una opción sencilla es utilizar W64Devkit, que proporciona GCC/G++ y un entorno de terminal preparado para Windows.

Después de instalarlo, abre su terminal y comprueba:

g++ --version

Si aparece la versión de G++, el compilador está funcionando.

⸻

7. Instalar raylib para Windows

Descarga una versión de raylib compatible con MinGW-w64.

Puedes obtener raylib desde:

https://github.com/raysan5/raylib

Necesitarás tener disponibles:

raylib.h
libraylib.a

Una estructura sencilla sería:

C:\raylib\
├── include\
│   └── raylib.h
└── lib\
    └── libraylib.a

⸻

8. Colocar el proyecto

Por ejemplo:

C:\proyecto\
├── main.cpp
├── code.cpp
├── dib.cpp
├── escri.cpp
├── menu.cpp
└── func.cpp

Abre la terminal en esa carpeta.

Puedes comprobar que estás en la carpeta correcta ejecutando:

ls

Deberías ver tus archivos .cpp.

⸻

9. Compilar en Windows

Ejecuta:

g++ main.cpp code.cpp dib.cpp escri.cpp menu.cpp func.cpp ^
-o programa.exe ^
-I"C:\raylib\include" ^
-L"C:\raylib\lib" ^
-lraylib -lopengl32 -lgdi32 -lwinmm

Si estás utilizando una terminal Bash, utiliza \ en lugar de ^:

g++ main.cpp code.cpp dib.cpp escri.cpp menu.cpp func.cpp \
-o programa.exe \
-I"C:\raylib\include" \
-L"C:\raylib\lib" \
-lraylib -lopengl32 -lgdi32 -lwinmm

⸻

10. Ejecutar en Windows

Si la compilación fue correcta:

./programa.exe

También puedes abrir programa.exe directamente desde el explorador de archivos.

⸻

Diferencias entre Linux y Windows

El código C++ del proyecto puede ser el mismo en ambos sistemas.

Lo que cambia principalmente es la forma de enlazar las librerías del sistema.

Linux

-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

Windows

-lraylib -lopengl32 -lgdi32 -lwinmm

No debes utilizar las librerías de Linux en Windows:

-lX11
-lpthread
-ldl
-lrt

y tampoco las librerías específicas de Windows en Linux.

⸻

Errores comunes

raylib.h: No such file or directory

Significa que G++ no encuentra los archivos de cabecera de raylib.

Comprueba que la ruta después de -I sea correcta:

-I"C:\raylib\include"

o:

-I/home/usuario/raylib/src

⸻

cannot find -lraylib

G++ no encuentra la librería compilada.

Comprueba la ruta después de -L.

Por ejemplo:

-L"C:\raylib\lib"

⸻

undefined reference

Normalmente significa que falta una librería durante el enlazado o que las librerías están en un orden incorrecto.

Primero comprueba que raylib esté correctamente instalada y que estés utilizando las librerías correspondientes a tu sistema operativo.

⸻

Resumen rápido

Linux

g++ main.cpp code.cpp dib.cpp escri.cpp menu.cpp func.cpp \
-o programa \
-I/RUTA/A/RAYLIB/src \
-L/RUTA/A/RAYLIB/build/raylib \
-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

Ejecutar:

./programa

Windows + MinGW-w64

g++ main.cpp code.cpp dib.cpp escri.cpp menu.cpp func.cpp ^
-o programa.exe ^
-I"C:\raylib\include" ^
-L"C:\raylib\lib" ^
-lraylib -lopengl32 -lgdi32 -lwinmm

Ejecutar:

./programa.exe

Importante: las rutas de raylib (-I y -L) son ejemplos. Cada usuario debe sustituirlas por las rutas donde tenga instalada raylib.