#include <iostream>
#include <string>

using namespace std; // The python equivalent is importanting a module named std.

void usage()
{
    cout << endl;
    cout << "User error:" << endl;
    cout << "calc.exe requires the format: arg1 op arg2" << endl;
    cout << "- arg1 and arg2 are numeric arguments" << endl;
    cout << "- op is an operator: +, -, /, *" << endl;
    cout << "- NOTE: the * operator must be entered as \\*" << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    // verify correct number of args
    if (argc != 4)
    {
        usage();
        return 1;
    }

    // validate operator length 
    string opArg = argv[2];
    if (opArg.length() > 1)
    {
        cout << "The operator (op) argument must be a single character" << endl;
        usage();
        return 1;
    }

    // get operator as char and args as floats
    char op = opArg.at(0);
    double arg1 = atof(argv[1]);
    double arg2 = atof(argv[3]);
    double result = 0;

    // switch block to determine the operation to perform. Invalid operators are handled by default case.
    switch(op)
    {
        case '+':
            result = arg1 + arg2;
            break;
            
        case '-':
            result = arg1 - arg2;
            break;

        case '*':
            result = arg1 * arg2;
            break;
        case '/':
            if (arg2 == 0) {
                cout << endl << "Cannot divide by zero!" << endl;
                return 1;
            }
            result = arg1 / arg2;
            break;

        default:
            cout << endl << "The operator (" << op << ") is invalid." << endl;
            return 1;     
    }

    // print result
    cout << endl;
    cout << argv[1] << " " << argv[2] << " " << argv[3];
    cout << " = " << result << endl << endl;
}

