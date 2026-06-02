#include <iostream>
#include <algorithm>
#include <optional>

template<typename Type>
Type& findMax(Type arr[],const uint8_t size) {
    Type max = arr[0];

    for (uint8_t i = 0 ; i< size;i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

template<typename Type>
Type& findMax(Type arr[5][10]) {
    Type max = arr[0][0];

    for (uint8_t i = 0; i < 5; i++)
    {
        for (uint8_t j = 0; j < 10; j++)
        {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }

    return max;
}

template<typename Type>
std::optional<uint8_t> findValue(Type arr[],const uint8_t size,Type value,uint8_t idx = 0) {

    if (idx >= size)
       return std::nullopt;

    if (arr[idx] == value) {
        return idx;
    }

    return findValue(arr,size,value,idx + 1);
}

int main() {
    srand(time(NULL));
    //задание 1.1
    {
        const uint8_t size = 10;
        uint8_t arr[size] = {};

        std::cout << "array: " ;
        for (uint8_t i = 0 ;i<size;i++) {
            arr[i] = rand() % 255;
            std::cout << static_cast<short>(arr[i]) << ' ';
        }

        auto max = findMax(arr,size);

        std::cout << "\nmax value: " << static_cast<short>(max) << std::endl;
    }
    //задание 1.2
   {
       constexpr uint8_t rows =5,cols = 10;
       uint8_t arr[rows][cols];

        std::cout << "\narray: " ;
       for (uint8_t i = 0 ; i < rows;i++) {
           for (uint8_t j = 0 ; j < cols;j++) {
               arr[i][j] = rand() % 255;
               std::cout << static_cast<short>(arr[i][j]) << ' ';
           }
           std::cout << std::endl;
       }

        auto max = findMax(arr);

        std::cout << "\nmax value: " << static_cast<short>(max) << std::endl;
   }

    //задание 2
    {
        const uint8_t size = 12;
        uint8_t arr[size] = {};

        std::cout << "\narray: ";

        for (uint8_t i = 0;i<size;i++) {
            arr[i] = rand()% 255;
            std::cout << static_cast<short>(arr[i]) << ' ';
        }

        std::cout << std::endl;

        int value = 0;
        std::cout << "enter value: ";
        std::cin >> value;
        std::cout << std::endl;

        auto position = findValue(arr,size,static_cast<uint8_t>(value));

        if (position != std::nullopt)
            printf("pos of value %d = %d",value,(short)position.value());
        else
            printf("value %d not found",value);

    }
}