# Notes on C++

**Resources**:
- [Beginning C++ Programming PDF](https://notalentgeek.github.io/note/note/project/project-independent/pi-brp-beginning-c-programming/document/20170807-1504-cet-1-book-and-source-1.pdf)
- [LLVM Documentation](https://releases.llvm.org/18.1.8/docs/)
- [Clang Documentation](https://clang.llvm.org/docs/UsersManual.html#generating-a-pch-file)

## Operators

1. The **Arrow** operator `->`
    - This operator is used to access members (attributes or methods) of a reference.

2. The **Put** operator `<<` 
     1. With Streams
        - Passes input to the `operator <<` function of an object.
    2. With Integers
        - e.g. `x << y` shifts `x` by `y` number of bits (i.e. multiply `x` by 2^y). 

3. The **Scope Resolution** operator `::`
    - Allows access of objects declared in particular namespaces.
    - e.g.  `std::cout` accesses the `cout` stream object (an instance of the ostream class) of the *standard* namespace.

4. The **Pound** operator `#`

## Libraries

- **Function Prototype**s are essentially function signatures, placed in header files, that allow for the compiler (and linter) to verify that a function is called correctly. 

### Static Library
- The `.lib` extension is used on Windows.

### Dynamic Link Libraries
- The `.dll` extension is used for Windows.

### Standard Library
Found in the **include directory** provided by a C++ compiler/toolkit.
Often seperatred into folders by CPU type.

1. The **bin** Directory
    - Executables such as the compiler and linker.

2. The **include** Directory
    - Header files for the C Runtime Library and the C++ Standard Library

3. The **lib** Directory
    - The static link library files for the C Runtime Library and the C++ Standard Library.

## Compiler (General)
### Preprocessor
- Runs before compilation.
- Locates and inserts header files.
- Subsitutes macros and defined constants.
- NOTE: It possible to examine the preprocessor's output (e.g. using a command line flag).
#### Preprocessor Directives
1. Macros
    1. The **Include** Directives
        - e.g. `#include "x.hpp"`
        - Copys the content of the header file `x` into the current file at the specified point, resulting in the 
        included content being compiled too. 
        - The variation `#include <x>` indicates to the compiler that it should search the standard directories used to store header files, and does not require a suffix such as `.hpp` or `h`.
    2. The **Define** Directives
        - e.g. `#define EXAMPLE 4` will instruct the preprocessor to replace any instances of the `EXAMPLE` symbol with the value `4` (does not replace symbols such as `EXAMPLE1`).
        - e.g. `#define MESSAGE(c, v) for (int i=1; i<c; ++i) std::cout << v[i] << std::endl;` instructrs the preprocessor to replaces all instances of `MESSAGE(x, y)`, where `x` and `y` are arbitray symbols with the specified statement(s), and substitutes the parameters passed to MESSAGE into the statement(s) respectively. Importantly, the macro is NOT a function.
2. File Inclusion
3. Conditional Compilation
4. Other
    1. The **Pragma** Directives
        - e.g. `#pragma once` instructs the preprocessor to only process this file one time (by adding it to a list of files that it has already processed). This is reduces processing time, compared to **conditional compilation** which still requires the file to be processed. 

## Compiler (Clang)

- ?? clang-tags (may be used to find definitions of symbols).

### Compiler Options (Clang)
1. Only compile (no linking) `-c`.
2. Define a symbol `'-D'`.
3. Include a precompiled header `-include-pch <filename.pch>`
