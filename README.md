# Advanced C

## Intermediate level programming

The code examples are used for teaching C programming at an intermediate level.
The examples are compilable by a C99 compiler.

Each example is compilable using QtCreator by opening the related **.pro**
file. This will create the related **Makefile** file.  

Or compiling a Qt project by the command line, this also will create the related **Makefile** file:

    qmake
    
    make

To avoid the overwriting of a self-coded GNU Makefile by a QtCreator build step, we choose the name **Makefile2**.

Compiling a GNU make project and the related **Makefile2** for gcc compiling C99:

    make -f Makefile2

Some unit test code examples are available:

- Using the [Unity](http://www.throwtheswitch.org/unity/) unit test library.
**Unity** is written in 100% pure C code. It follows ANSI-C standards.
- Using the [Catch2](https://github.com/catchorg/Catch2) unit test library in a single header file.
**Catch2** is written in C++11.

## Debugging in Visual Studio Code: gdb

In every Makefile or Makefile2 the compiler flag *-g* is used. 
Some *gdb* launches are available in [launch.json](.vscode/launch.json).

## Book and excercises

Theory can be found in [AdvancedCv3.0.pdf](./AdvancedCv3.0.pdf), the code as used in the exercises can be found in [BookExampleCode](./BookExampleCode).

Lab exercis can be found in [LabExercisesADCv3.0.pdf](./LabExercisesADCv3.0.pdf), the code as used in the exercises can be found in [LabExercisesCode](./LabeExercisesCode).