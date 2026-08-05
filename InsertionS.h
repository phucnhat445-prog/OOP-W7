#pragma once
#include "SortArray.h"

template <typename T>
class InsertionS : public SortArray<T> {
protected:
    void doSort() override {
        int n = this->array.size();
        for (int i = 1; i < n; i++) {
            T key = this->array[i];
            int j = i - 1;
            while (j >= 0 && this->array[j] > key) {
                this->array[j + 1] = this->array[j];
                j--;
            }
            this->array[j + 1] = key;
        }
    }

public:
    InsertionS(const std::vector<T>& arr = std::vector<T>()) : SortArray<T>(arr) {}
    virtual ~InsertionS() = default;

    std::string name() const override {
        return "Insertion Sort";
    }
};