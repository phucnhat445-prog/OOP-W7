#pragma once
#include "SortArray.h"

template <typename T>
class InterchangeS : public SortArray<T> {
protected:
    void doSort() override {
        int n = this->array.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (this->array[j] < this->array[i])
                    std::swap(this->array[i], this->array[j]);
            }
        }
    }

public:
    InterchangeS(const std::vector<T>& arr) : SortArray<T>(arr) {}
    virtual ~InterchangeS() = default;
};
