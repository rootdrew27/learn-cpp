#include <iostream>
#ifdef DEBUG
#define MESSAGE(c, v)\
for (int i=1; i<c; ++i) std::cout << v[i] << std::endl;
#else
#define MESSAGE(c, v) //removes instances of message
#endif
// Despite declaring 'int' as a return type, the main function (the name is chosen conventionally) will return 0 if a return statement is unspecified.
int main(int argc, char *argv[])
{
    MESSAGE(argc, argv);
    std::cout << "Invoked with: " << argv[0] << std::endl;
    std::cout << __FILE__ << std::endl;
}

// Main Block 1
// {
//     std::cout << "Number of arguments:" << argc << std::endl;
//     for (int i=0; i<argc; ++i)
//     {
//         std::cout << argv[i] << std::endl;
//     }
// }
