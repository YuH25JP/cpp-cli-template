# C++ cli template

## Features

- CMake setup
- Separated dirs for libraries(`include/`) and cli(`cli/`) source files
- [p-ranav/argpare](https://github.com/p-ranav/argparse) is used for cli parser
- Out-of-the-box support for OpenMP and [Eigen](https://libeigen.gitlab.io/)
- Support header only libraries

## How to use

In the project root directory, run the following commands:
```sh
cmake -S . -B build
cmake --build build
```

These commands create `build` directory in which executables are placed.
