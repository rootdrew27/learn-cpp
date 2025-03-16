#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;
const int block_length = 16;
const int half_block_length = block_length / 2; // implicit conversion rounds down

int read_bytes(ifstream& stm)
{
    if (stm.eof()) {return -1;}
    ios_base::fmtflags flags = cout.flags();
    cout << hex;

    string line;
    line += "|";
    for (int i = 0; i < block_length; ++i)
    {
        unsigned char c = stm.get();
        if (stm.eof())
            break;
        if (half_block_length == i) {cout << " ";} // additionall space printed when half block size is reached.
        cout << setw(2) << setfill('0');
        cout << static_cast<short>(c) << " ";
        if (isprint(c) == 0) {line += '.';} // '.' is a placeholder for non-printable chars
        else {line += c;}
    }
    line += "|";
    string padding = " ";
    if (line.length() < block_length)
    {
        padding += string(3 * (block_length - line.length()), ' '); // multiply by 3 because each hex char takes 3 characters (including the space)
    }
    cout << padding;
    cout << line << endl;

    cout.setf(flags);
    return line.length();
}

void usage(const char* msg) // using const on a pointer prevents the memory it points to from being changed.
{
    cout << endl;
    cout << "filedump <filename> <num_blocks>" << endl;
    cout << "   - <filename> (required) is the name of the file to dump" << endl;
    cout << "   - <num_blocks> (optional) is the number of blocks to dump" << endl;
    if (nullptr == msg) {return;}
    else {cout << endl << "Error: " << msg << endl << endl;}
}

int main(int argc, char* argv[])
{
    // read in two parameters: file name and num of lines to print
    if (argc < 2)
    {
        usage("Not enough parameters.");
        return 1;
    }
    if (argc > 3)
    {
        usage("Too many parameters");
        return 1;
    }

    string filename = argv[1];
    int blocks = 1;
    if (argc == 3)
    {
        istringstream ss(argv[2]);
        ss >> blocks; // by default, getting from an istringstream will get until whitespace. 
        if (ss.fail() || blocks <= 0)
        {
            usage("Second parameter must be a positive integer.");
            return 1;
        }
    }

    ifstream file(filename, ios::binary); // open in binary mode to ignore '/r' chars
    if (!file.good())
    {
        usage("First parameter must be a valid file!");
        return 1;
    }

    // print out hex and character versions of input file, block by block.
    while (blocks-- && read_bytes(file) != -1);
    file.close();
    cout << endl;

}