#include <iostream>

using namespace std;


struct FLOAT {
    float data;
    FLOAT(float f) : data(f) {}
};

//void foo(int) { cout << "int" << endl; }            // 4. Standard conversion : 데이터 손실이 발생하더라도 표준 타입끼리 암시적 변
//void foo(float) {cout << "float" << endl; }     // 1. Exactly Matching
//void foo(double) {cout << "double" << endl; }       // 3. Promotion : 데이터 손실이 없는 방향으로 암시적 변환
//void foo(FLOAT) { cout << "FLOAT" << endl; }          // 5. User Define conversion
void foo(...) { cout << "..." << endl; }            // 6. 가변인자

//template<typename T>
//void foo(T) { cout << "T" << endl; }                // 2. temmplate : 해당 타입의 함수를 생성한다.

int main(int argc, char *argv[])
{
    foo(3.4f);
    return 0;
}
