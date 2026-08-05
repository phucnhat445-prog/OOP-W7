#pragma once
#include "SortArray.h"
#include <utility> 

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
    InterchangeS(const std::vector<T>& arr = std::vector<T>()) : SortArray<T>(arr) {}
    virtual ~InterchangeS() = default;

    std::string name() const override {
        return "Interchange Sort";
    }
};