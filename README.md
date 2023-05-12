# pamsi 1

 2022/2023

Zadanie 1 -   kolejka 

## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: cmake, gnuplot, doxygen + dot (in graphviz library)

Example:

``` bash
> mkdir build && cd build
> cmake .. #### options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make     #### compilation
> ./main   #### main() from app
> make fulltest #### compile & run tests with full decription
> make doc       #### Generate html documentation
```

Things to remember during upgrading project to new task:

* changes to CMakeLists.txt in the main folder with new files added, i.e.:

```cpp
// --------------------------------------------------------------------------------
//                         Locate files (change as needed).
// --------------------------------------------------------------------------------
set(SOURCES          // All .cpp files in src/
    src/.cpp
  
    
     // etc.
)
set(TESTFILES        // All .cpp files in tests/
    
    test_file.cpp
     // etc.
)
set(LIBRARY_NAME zadX)  // Default name for the library built from src/*.cpp (change if you wish)
```

* changes to tests/CMakeLists.txt (in tests subfolder) with new files added, i.e.:

```cpp
# List all files containing tests. (Change as needed)
set(TESTFILES        // All .cpp files in tests/
    main.cpp
    test_file.cpp
     // etc.
)
```

The `main.cpp` in the folder `tests` is needed. Only there we define `#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN`.

The main loop of the program is in the `app` folder.
