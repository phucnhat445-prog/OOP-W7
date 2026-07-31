#pragma once
#include "SortArray.h"

template <typename T>
class SelectionS : public SortArray<T> {
protected:
    void doSort() override {
        int n = this->array.size();

        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (this->array[j] < this->array[minIdx])
                    minIdx = j;
            }
            if (minIdx != i)
                std::swap(this->array[i], this->array[minIdx]);
        }
    }

public:
    SelectionS(const std::vector<T>& arr) : SortArray<T>(arr) {}
    virtual ~SelectionS() = default;
};
