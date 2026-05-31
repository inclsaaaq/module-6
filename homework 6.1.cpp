#include <iostream>

namespace utils {
    int8_t makerand(int8_t max, int8_t min = 0);
    void checkMax(uint8_t& a,uint8_t& b,uint8_t& c);
    void printArr(auto arr[],const uint8_t size);
    void fillArr(auto arr[],const uint8_t size , int8_t max = 80, int8_t min = 0);
}

namespace exercise {
    void e1(uint8_t& a , uint8_t& b ,uint8_t& c);
    void e2(int8_t arr[],uint8_t size);
    void e3(uint8_t arr[],bool& s,const uint8_t& size);
    void e5(short arr[],const uint8_t& size);
}

int main() {
    srand(time(0));

    //e1
    {
        std::cout << "задание 1" << std::endl;
        uint8_t a = utils::makerand(100) ,
        b = utils::makerand(100) ,
        c = utils::makerand(100);

        exercise::e1(a,b,c);
        std::cout << std::endl;
    }

    //e2
    {
        std::cout << "задание 2" << std::endl;
        const int8_t size = 44;
        int8_t arr[size] = {};

        std::cout<< "массив: " ;
        utils::fillArr(arr,size,100,-50);
        utils::printArr(arr,size);
        std::cout << std::endl;
        exercise::e2(arr,size);
        std::cout << std::endl;
    }

    //e3
    {
     std::cout << "задание 3" << std::endl;
        bool s = false;
        const uint8_t size = 10;
        uint8_t arr[size] = {};

        std::cout << "как отсортировать? (1 = по убыванию , 0 = по возрастанию): ";
        std::cin >> s;
        std::cout << std::endl;

        std::cout << "без сортировки: ";

        utils::fillArr(arr,size);
        utils::printArr(arr,size);

        std::cout << std::endl;

        exercise::e3(arr,s,size);

        std::cout << "после сортировки: ";
        utils::printArr(arr,size);

        std::cout << std::endl;
    }

    //e5
    {
        std::cout << "\nзадание 5" << std::endl;
        const uint8_t size = 100;
        short arr[size] = {};

        std::cout << "массив до: ";
        for (uint8_t i = 0 ;i < size;i++) {
            arr[i] = utils::makerand(100);
            std::cout << static_cast<short>(arr[i]) << ' ';
        }
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "массив после: " << std::endl;;
        exercise::e5(arr,size);

        std::cout << std::endl;
    }
}

void exercise::e1(uint8_t& a , uint8_t& b ,uint8_t& c) {
    std::cout << "a , b , c: " << (short)a << ' ' << (short)b << ' ' << (short)c << std::endl;
    utils::checkMax(a,b,c);
}

void exercise::e2(int8_t arr[],const uint8_t size) {
    uint8_t cntd = 0; // додатнi
    uint8_t cntn = 0; // від'ємнi
    uint8_t cntv = 0; // нульовi

    for (uint8_t i = 0 ; i < size;i++ ) {
        if (arr[i] > 0)
            cntd++;
        if (arr[i] == 0)
            cntv++;
        if (arr[i] < 0)
            cntn++;
    }

    std::cout << "додатнi , від'ємнi , нульовi: " << (short)cntd << ' ' << (short)cntn << ' ' << (short)cntv << std::endl;
}

void exercise::e3(uint8_t arr[],bool& s,const uint8_t& size) {
    for (uint8_t i = 0;i < size -1;i++) {
        for (uint8_t j = 0; j < size - i - 1;j++) {
            if ((arr[j] > arr[j + 1]) != s)
                std::swap(arr[j],arr[j + 1]);
        }
    }
}

void exercise::e5(short arr[],const uint8_t& size) {
    for (uint8_t i = 0; i < size;i++) {
        std::cout << static_cast<short>(arr[i]) << ' ';
        if ((i +1) % 10 == 0)
            std::cout << std::endl;
    }

    unsigned short minval = 60000;
    uint8_t minpos = 0;

    for (uint8_t i = 0; i <= size - 10;i++) {
        short sum = 0;

        for (uint8_t j = i; j < i +10 ;j++) {
            sum += arr[j];
        }

        if (sum < minval) {
            minval = sum;
            minpos = i;
        }
    }

    std::cout << "минимальная сумма: " << minval << std::endl;
    std::cout << "позиция: " << static_cast<short>(minpos) << std::endl;
}

int8_t utils::makerand(int8_t max,int8_t min) {
    return min + rand() % (max - min + 1);
}

void utils::checkMax(uint8_t& a,uint8_t& b,uint8_t& c) {
    uint8_t max = a;
    uint8_t min = a;

    if (b > max)
        max = b;
    if (c > max)
        max = c;

    if (b < min)
        min = b;
    if (c < min)
        min = c;

    std::cout << "max = " << static_cast<short>(max) << std::endl;
    std::cout << "min  = " << static_cast<short>(min) << std::endl;
}

void utils::printArr(auto arr[],const uint8_t size) {
    for (uint8_t i = 0; i < size;i++)
        std::cout << static_cast<short>(arr[i]) << ' ';
}

void utils::fillArr(auto arr[],const uint8_t size , int8_t max, int8_t min) {
    for (uint8_t i = 0 ; i < size; i++) {
        arr[i] = utils::makerand(min,max);
    }
}