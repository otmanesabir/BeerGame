# The Beer Game

## Description

The beer distribution game (also known as the beer game) is a type of gamification that is used to experience typical coordination problems of a supply chain process. It reflects a role-play simulation where several participants play with each other.

## What still needs to be done?

Link all UI elements and add multiplayer functionality. 

## File Structure
    .
    ├── beergame                # root directory
    │   ├── docs                # documentation
    │   ├── build               # build directory
    │   ├── include             # header/declaration files
    │   ├── src                 # source/implementation files
    │   ├── tst                 # testcase files
    │   └── ...                 # .gitignore/CMakeLists.txt/README.md


## Dependencies

| Dependancy | Download | Documentation |
| :---------: | :-----: | :-----------: |
| **QT** | [`Link`](https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5) | [`Link`](https://doc.qt.io) |
| **CMake** | [`Link`](https://cmake.org/download/) | [`Link`](https://cmake.org/documentation/) |
| **Google Test** | [`Link`](https://github.com/google/googletest) | [`Link`](https://github.com/google/googletest/blob/master/googletest/docs/prim…) |
| **Doxygen** | [`Link`](http://www.doxygen.nl/download.html) | [`Link`](http://www.doxygen.nl) |

## Deploying

```bash
git clone https://github.com/otmanesabir/BeerGame.git
cd build
cmake ..
make
./beergame
./beergame-tests
./beergame-server
./beergame-client
```

#### DEBUG

When doing a `DEBUG` build the project is set up to not optimize the generated code, and to tell the compiler to add debug information (which includes information about functions, variables, and other information needed for debugging).

```bash
git clone https://github.com/otmanesabir/BeerGame.git
cd build
cmake ..
make debug
make debug-test
```

#### RELEASE

A `RELEASE` build on the other hand have higher level of optimization, and no debug information is saved.
```bash
git clone https://github.com/otmanesabir/BeerGame.git
cd build
cmake ..
make release
make release-test
```
