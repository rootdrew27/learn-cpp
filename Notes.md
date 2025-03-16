# Notes on C++

**Resources**:
- [Beginning C++ Programming PDF](https://notalentgeek.github.io/note/note/project/project-independent/pi-brp-beginning-c-programming/document/20170807-1504-cet-1-book-and-source-1.pdf)
- [Embedded Systems Programming](https://elhacker.info/manuales/OReilly%204%20GB%20Collection/O%27Reilly%20-%20Programming%20Embedded%20Systems%20in%20C%20and%20C++.pdf)
- [LLVM Documentation](https://releases.llvm.org/18.1.8/docs/)
- [Clang Documentation](https://clang.llvm.org/docs/UsersManual.html#generating-a-pch-file)
- 

## Operators

- Operator precedence tables (along with associativity) should be referenced.
- Remember that C++ frequently uses operator overloading!

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
    - Denotes a preprocessing directive.

5. The **Increment** and **Decrement** operators `++` and `--`
    - There are two versions for each operator, prefix and postfix.
    1. Prefix: `a = ++b;` increments `b` and assigns the result to `a`.
    2. Postfix: `a = b++;` assigns the value of `b` to `a` and then increments `b`.
    - When used on pointers, the address is incremented by the size of the pointer type (e.g. 32 bits for an 32 bit integer).

6. The **Comma** operator `,`

7. The **Assignment** operator `=`

8. The **Angle Brackets** operator `<>`
    1. Parameterize
        - A class that is parameterized allows parameters to be passed during declaration, e.g. `bitset<64> my_bitset(value)` where `my_bitset()` is a call to the class's constructor. 

## Useful keywords

1. Constant
    - In the statement `const int a = 5;`, the `const` keyword tells the compiler to check the usage of `a` throughout its scope, ensuring that its value is unchanged.
2. Constant Expression
    - In the statement `constexpr int myFunc(int i){return i+1};`, the `constexpr` keyword indicates that calls to `myFunc`, with a known value for the parameter, should be elevated at compile time. If the parameter's value is unknown at compile time, the function will execute as normal during runtime.
3. Enumerations
    - A group of named constants which aid in restricting/enforcing a variable's value and increase code readability.
    - The statement `enum browser {chrome, firefox, safari};` automatically assigns integers to each of the names, allowing for later usage: `browser default = chrome;`.
    - The enum type may also be specified: `enum browser : char {chrome, firefox, safari};`, saving memory in this case.
    - Scoping can be required with, for example, `enum class browser {chrome, firefox, safari};`
4. Using Statement
    1. With Namespace
        - The statement, `using namespace example;` allows the use of members in the example namespace without fully-qualified names.
    2. With Namespace Member
        - The statement `using std::cout` enables the use of `cout` without specifying the FQN.

5. Static
    - Variables labeled as static, e.g. `static int value` will have memory allocated on program start, regardless of scope (typically only global file variables are allocated on start).
    - Variables declared with `static` at the file level will only be accessible within the file.
    - Within functions, the static keyword enables *state*, meaning that each call of the function will utilize whatever value is currently assigned to the variable, though the variable is still only accessible within the function. 


## Namespaces

- Allows the use of *fully-qualified names* with the scope **resolution operator**, e.g. `std::cout`.
- Namespaces decorate collections of types, functions, and variables: 
```
namespace my_namespace
{
  bool myFunc(); // func declaration
  int myFunc2() {} // func definition
  int myVar = 1;
  class myClass() {}
}
```
All of the members are now accessible via the namespace.
- Namespaces can be nested, and using the `inline` keyword on a nested namespace will allow access to it through the parent's name.
- A particular namespace may be defined in multiple places.\
- Namespaces may contain the `include` directive, enabling access to any symbols specified in the included header file.

## Storage Classes

- A storage class indicates the lifetime, linkage, and memory location of a variable.
1. Static
    - Used at the file level, the `static` keyword internally links the symbol so that it may only be accessed within the file.
    - Used in a function, the `static` keyword sets the lifetime of the variable to be the same as the programs.
2. External
    - The `extern` keyword indicates that a symbol may be used in other files (often used in header files).
3. Thread Local
    - Use of `thread_local` means that the variable has the same lifetime as the thread.

## Type Aliases

- As types become more cumbersome to read/write (such as nested parameterized types) type aliasing is useful:
```
vector<tuple<string, int>> people;

// or 

typedef tuple<string, int> name_year_t;
vector<name_year_t> people;

```
- The `typedef` keyword also increases read/writeability in due to clearer meaning of what the variable represents (in this example, a name and a year).
- Often better than using the `define` macro as type checking is performed.

## Aggregated Types

1. Structures
    - The `struct` keyword may be used to associate variables.
    - Structs members can be initialized through the `.` operator, a constructor, or `{}`.
    - Can be nested.
    - **Alignment** is 

## Alignment
    - TODO: Review alignment if working with devices on a low level.

## Scope

- Code blocks, `{ }` define a scope, and variables declared within them are only accessible within them, barring unique circumstances such as the use of `static` or in namespaces.

- Variables can be *externally linked*, e.g. `extern int my_var;` which indicates to the compiler that the variable is accessible in other files. This is in contrast to *internal linkage*, which means that a symbol may only be used in the current translation unit (i.e. current file being compiled). 

## Type Conversion (Type Casting)
    - Promotion : when a smaller type is promoted to a larger type (no data loss can occur).
    - Narrowing: when a larger type is converted to a smaller type (potential for the loss of data).
    - The compiler will perform promotions when necessary to avoid errors (it assumes you know what you are doing), as no data is lost.
    - The compiler will often issue warning when narrowing, as data could be lost.
    - Note: Use explicit conversions and document the code when relying on implicit conversions.

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

- Operators have precedence (e.g. the `+` operator has a greater precedence than the `=` operator).

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

- Clang version>=5 fully supports C++17 [source](https://clang.llvm.org/cxx_status.html)

- ??Clang uses the Standard Library headers (and CLR) of gcc/g++. Thus, clang must find a version of gcc on the machine. Use `clang++ -v` to see the GCC installation that is in use and ensure that the respective g++ version is installed on the machine, e.g. `apt install g++-<version_num>`

- ?? clang-tags (may be used to find definitions of symbols).

### Compiler Options (Clang)
1. Only compile (no linking) `-c`.
2. Define a symbol `'-D'`.
3. Include a precompiled header `-include-pch <filename.pch>`


## Important Terms

1. Fully-Qualified Name (FQN)
2. 