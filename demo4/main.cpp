#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <bitset>
#include <string>
#include <cmath>

using namespace std;

void sizes_demo()
{
    cout << "Size of int8_t: " << sizeof(int8_t) << endl;
    cout << "Size of int16_t: " << sizeof(int16_t) << endl;
    cout << "Size of int32_t: " << sizeof(int32_t) << endl;
    cout << "Size of int64_t: " << sizeof(int64_t) << endl;
}

void bitmap_demo()
{
    unsigned long long every_other = 0xAAAA'AAAA'AAAA'AAAA;
    cout << hex << every_other << endl;

    // display as bitmap

    bitset<64> bs_every_other(every_other);
    cout << "Bitmap: " << bs_every_other << endl;

    bitset<64> bs_every_other_shifted(every_other>>1);
    cout << "Bitmap shifted: " << bs_every_other_shifted << endl;

    bs_every_other.set(0);
    cout << "Bitmap shifted with pos 1 set: " << bs_every_other << endl;
}

void endian_demo()
{
    unsigned short num = 0xff00;
    cout << hex << "Before Flip: " << num << endl;
    unsigned short converted_num = ((num & 0xff) << 8) | ((num & 0xff00) >> 8);
    cout << "Endian Flip: " << converted_num << endl;
}

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        cout << "Please enter a number. Valid names include: [1: sizes_demo, 2: bitmap_demo, 3: endian_demo] or any combination such as '31'." << endl;
        return 1;
    }
    if (argc > 3)
    {
        cout << "Please enter one string as input. Valid inputs are in the form X, XX, XXX, etc. where X is an integer in the range [1,3]" << endl;
        return 1;
    }

    string args = argv[1]; 
    
    for (int i = 0; i < args.length(); ++i)
    {
        switch (atoi(&args[i]))
        {
            case 1:
                sizes_demo();
                break;
            case 2:
                bitmap_demo();
                break;
            case 3:
                endian_demo();
                break;
        }
    }
    return 0;
}
