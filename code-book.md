- [Contest](#contest)
- [Data Structures](#data-structures)
- [Numerical](#numerical)
- [Number Theory](#number-theory)
- [Combinatorial](#combinatorial)
- [Graph](#graph)
  - [Maximum Flow and Minimum Cut](#maximum-flow-and-minimum-cut)
- [Strings](#strings)
- [Various](#various)
- [Geometry](#geometry)
- [Misc](#misc)
  - [Installing C++ Compiler for Windows](#installing-c-compiler-for-windows)

# Contest

# Data Structures

# Numerical

# Number Theory

# Combinatorial

# Graph

## Maximum Flow and Minimum Cut

Resources:

- https://youtu.be/M6cm8UeeziI (Dinic's Algorithm explanation by WilliamFiset, very easy to understand)
- https://cses.fi/book/book.pdf#page=191 (Contains good examples of how flows can be used in different problems, such as Path Covers, Node Covers, Maximum Matchings, Antichains, etc)

Problems:

- https://cses.fi/problemset/task/1694
- https://cses.fi/problemset/task/1709 (Solution is explained here: https://usaco.guide/adv/min-cut?lang=cpp)
- For more problems, see https://usaco.guide/adv/max-flow?lang=cpp.

# Strings

# Various

# Geometry

# Misc

## Installing C++ Compiler for Windows

Follow the steps from https://www.msys2.org/.

Download the installer.

Install MSYS2 in C:\msys64

Open MSYS2 from Start, it will open a terminal. Run the following commands -
1. pacman -Syu
2. pacman -Su
3. pacman -S mingw-w64-x86_64-toolchain

Add C:\msys64\mingw64\bin to PATH (search Environment Variables on Start to open)

Check if mingw is installed or not by typing "g++ --version" and "gdb --version" in the command prompt.

Helpful resources -
- https://code.visualstudio.com/docs/cpp/config-mingw
- https://www.msys2.org/
- https://www.devdungeon.com/content/install-gcc-compiler-windows-msys2-cc