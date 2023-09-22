#include "Array.h"

int main() {
    
    int data[] = {1, 2, 3, 4, 5};
    Array<int, 5> myArray(data);

    // Test various functions
    std::cout << "Size of myArray: " << myArray.size() << std::endl;
    std::cout << "Is myArray empty? " << (myArray.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Front element: " << myArray.front() << std::endl;
    std::cout << "Back element: " << myArray.back() << std::endl;

    // Test operator[], at(), and fill()
    std::cout << "Element at index 2: " << myArray[2] << std::endl;
    std::cout << "Element at index 3 (using at()): " << *myArray.at(3) << std::endl;
    
    myArray.fill(10);
    std::cout << "After fill(10): ";
    for (size_t i = 0; i < myArray.size(); i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // Test swap
    int data2[] = {6, 7, 8, 9, 10};
    Array<int, 5> anotherArray(data2);

    std::cout << "Before swap - myArray: ";
    for (size_t i = 0; i < myArray.size(); i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Before swap - anotherArray: ";
    for (size_t i = 0; i < anotherArray.size(); i++) {
        std::cout << anotherArray[i] << " ";
    }
    std::cout << std::endl;

    myArray.swap(anotherArray);

    std::cout << "After swap - myArray: ";
    for (size_t i = 0; i < myArray.size(); i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After swap - anotherArray: ";
    for (size_t i = 0; i < anotherArray.size(); i++) {
        std::cout << anotherArray[i] << " ";
    }
    std::cout << std::endl;

    // Test fusion
    Array<int, 5> resultArray = myArray.fusion(anotherArray);

    std::cout << "After fusion: ";
    for (size_t i = 0; i < resultArray.size(); i++) {
        std::cout << resultArray[i] << " ";
    }
    std::cout << std::endl;
}