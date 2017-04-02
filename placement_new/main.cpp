#include <iostream>
#include <cstring>
using namespace std;

struct BLOCK {
    char file[256];
    int line;
    void* addr;
};

BLOCK mem[10000];
int count = 0;

void* operator new(size_t sz, char* file, int no) {
    void* p = malloc(sz);
    mem[count].addr = p;
    mem[count].line = no;
    strcpy(mem[count].file, file);
    ++count;
    return p;
}

void operator delete(void* p) {
    for(int i = 0; i < count; i++) {
        if(mem[i].addr == p) {
            mem[i] = mem[count-1];
            --count;
            free(p);
            break;
        }
    }
}

#define new new(__FILE__, __LINE__)

class _check_memory
{
public:
    ~_check_memory() {
        if(count == 0) {
            cout << "메모리 누수가 없습니다" << endl;
            return;
        }

        for(int i = 0; i < count; i++) {
            printf("%d : %s(%d), %p\n", i, mem[i].file, mem[i].line, mem[i].addr);
        }
    }
};

_check_memory _c;



int main(int argc, char *argv[])
{
    int* p1 = new int;
        cout << count << endl;
    int* p2 = new int;
        cout << count << endl;
    int* p3 = new int;
        cout << count << endl;
    delete p2;

    cout << count << endl;
    return 0;
}
