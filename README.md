# se-05-team-19

## Milestones

* [X] Optimize imports.
* [x] Fixed forward declaration issues.
* [x] Integrate UniqueID Logic.
* [x] Integrate Custom Exception.
* [X] Create `DEBUG` and `RELEASE` modes. 
* [x] Add more comprehensive test cases.
* [x] Improve the UI.
* [x] Make the game multi-player using socket communication.
* [x] Improve the source code.



## File Structure
    .
    ├── se-05-team-19           # root directory
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

## Task distribution 

## Deploying

```bash
git clone https://github.com/iuliacornea99/se-04-team-01
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
git clone https://github.com/iuliacornea99/se-04-team-01
cd build
cmake ..
make debug
make debug-test
```

#### RELEASE

A `RELEASE` build on the other hand have higher level of optimization, and no debug information is saved.
```bash
git clone https://github.com/iuliacornea99/se-04-team-01
cd build
cmake ..
make release
make release-test
```

## References 

| Dependancy | Documentation |
| :---------: | :-----------: |
| **QT** | [`Link`](https://doc.qt.io) |
| **CMake** | [`Link`](https://cmake.org/documentation/) |
| **Google Test** | [`Link`](https://github.com/google/googletest/blob/master/googletest/docs/prim…) |
| **Doxygen** | [`Link`](http://www.doxygen.nl) |


## Contributors

* Tianyao Chen
* Otmane Sabir