#include <iostream>
#include "RingBuffer.h"

using namespace std;

int main(int argc, char *argv[])
{
    RingBuffer rb(10);

    unsigned char output[10] = {0,};
    unsigned char input[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    for(int i = 0; i < 10; i++) {
        rb.Write(&input[i], 1);
    }

    rb.Read(output, 2);
    cout << "Read Data : " << output << endl;

    rb.Read(output, 3);
    cout << "Read Data : " << output << endl;

    rb.UpdateReadPos(2);
    rb.Write(&input[4], 1);
    rb.Read(output, 10);
    cout <<"Read Data : " << output << endl;
    return 0;
}
