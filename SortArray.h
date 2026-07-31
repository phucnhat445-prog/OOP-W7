#pragma once
#include <iostream>
#include <vector>
#include <chrono>

template <typename T>
class SortArray {
protected:
    std::vector<T> array;

    virtual void doSort() = 0;

public:
    SortArray(const std::vector<T>& arr) : array(arr) {}
    virtual ~SortArray() = default;

    void runTest() {
        std::cout << "Truoc khi sap xep: ";
        printArray();

        auto start = std::chrono::high_resolution_clock::now();
        doSort();
        auto end = std::chrono::high_resolution_clock::now();

        std::cout << "Sau khi sap xep:   ";
        printArray();

        std::chrono::duration<double, std::milli> duration = end - start;
        std::cout << "Thoi gian chay: " << duration.count() << " ms\n\n";
    }

    void printArray() const {
        for (const auto& item : array) {
            std::cout << item << " ";
        }
        std::cout << "\n";
    }
};