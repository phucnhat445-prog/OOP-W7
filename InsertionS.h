#pragma once
#include "SortArray.h"

template <typename T>
class InsertionS : public SortArray<T> {
protected:
    void doSort() override {
        int n = this->array.size();

        for (int i = 1; i < n; i++) {
            // Lay phan tu hien tai can chen vao phan da sap xep
            T key = this->array[i];
            int j = i - 1;

            // Dich phan tu lon hon key sang phai 1 vi tri
            while (j >= 0 && this->array[j] > key) {
                this->array[j + 1] = this->array[j];
                j--;
            }

            // Dat key vao vi tri dung
            this->array[j + 1] = key;
        }
    }

public:
    InsertionS(const std::vector<T>& arr) : SortArray<T>(arr) {}
    virtual ~InsertionS() = default;
};
