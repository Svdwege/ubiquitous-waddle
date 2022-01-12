# Build management: compiling C programs

## QtCreator IDE

Select the HelloWorld.pro file and QtCreator will show the opened project: overview of .pro file and code files.

## Visual Studio Code IDE

Start VS Code and open code directory. VS Code will show the contents of the opened project directory.

### * Using .pro file for creating Makefile

Open a Bash terminal in VS Code: **\<Ctrl>\<`>**

```bash
cd <code directory>
qmake
make
```

Run **HelloWorld**:

```bash
./HelloWorld
```

### * Using the already available Makefile2

The name Makefile2 is used for preventing the overwriting of Makefile by the **qmake** command.

Open a Bash terminal in VS Code: **\<Ctrl>\<`>**

```bash
cd <code directory>
make -f Makefile2
```

Run **HelloWorld2**:

```bash
./HelloWorld2
```
