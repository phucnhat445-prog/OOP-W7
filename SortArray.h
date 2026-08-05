#pragma once
#include <iostream>
#include <vector>
#include <string>

template <typename T>
class SortArray {
protected:
    std::vector<T> array;

    virtual void doSort() = 0;

public:

    SortArray(const std::vector<T>& arr = std::vector<T>()) : array(arr) {}
    virtual ~SortArray() = default;

    virtual std::string name() const = 0;

    void Sort(std::vector<T>& inputData) {
        this->array = inputData;
        doSort();


        inputData = this->array;
    }

    void runTest() {
        std::cout << "Truoc khi sap xep: ";
        printArray();

        doSort();

        std::cout << "Sau khi sap xep:   ";
        printArray();
    }

    void printArray() const {
        for (const auto& item : array) {
            std::cout << item << " ";
        }
        std::cout << "\n";
    }
};