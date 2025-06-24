# Sample libdl usage

`libdl` is a standard Unix library that provides functions for dynamic loading of shared libraries at runtime. It allows programs to load, access, and use symbols (such as functions or variables) from shared libraries without linking them at compile time.

In this repo, I demonstrated a simple usage of `libdl`.

## foo library

foo library consists of two simple functions. One with C linkage (no mangling), the other with C++ linkage.

On linux, compile the library using the following command:

```bash
gcc -shared foo.cpp -o libfoo.so
```

## foo_user application

This application makes use of the compiled shared library from previous step, looks for the symbols at runtime, and calls those functions. On linux, compile the application using the following command:

```bash
g++ -ldl foo_user.cpp
```
