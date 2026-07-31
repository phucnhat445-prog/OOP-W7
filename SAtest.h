#pragma once

#include "ProgramFrame.h"
#include "SortArray.h"

#include <cstddef>
#include <istream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

template <class T>
class SATest : public ProgramFrame {
private:
    SortArray<T>* algorithm;
    std::vector<T> data;
    std::string typeName;
    std::string inputHint;
    bool inputIsValid;

protected:
    void startMessage(std::ostream& os) const override {
        os << "\nKiểu dữ liệu: " << typeName << '\n';

        if (algorithm != nullptr) {
            os << "Thuật toán đang sử dụng: "
               << algorithm->name()
               << '\n';
        } else {
            os << "Chưa có thuật toán sắp xếp.\n";
        }

        os << "Nhập số lượng phần tử n, sau đó nhập lần lượt n phần tử.\n";
        os << inputHint << '\n';
        os << "Dữ liệu của bạn: ";
    }

    void Input(std::istream& is) override {
        data.clear();
        inputIsValid = false;

        int n;

        if (!(is >> n) || n <= 0) {
            return;
        }

        data.resize(static_cast<std::size_t>(n));

        for (int i = 0; i < n; ++i) {
            if (!(is >> data[static_cast<std::size_t>(i)])) {
                data.clear();
                return;
            }
        }

        inputIsValid = true;
    }

    bool Check() const override {
        return algorithm != nullptr
            && inputIsValid
            && !data.empty();
    }

    void Process() override {
        algorithm->Sort(data);
    }

    void Output(std::ostream& os) const override {
        os << "Mảng sau khi sắp xếp: ";

        for (const T& value : data) {
            os << value << ' ';
        }

        os << '\n';
    }

public:
    SATest(
        SortArray<T>* algorithm,
        std::string typeName,
        std::string inputHint
    )
        : algorithm(algorithm),
          typeName(std::move(typeName)),
          inputHint(std::move(inputHint)),
          inputIsValid(false) {
    }

    ~SATest() override {
        delete algorithm;
    }

    SATest(const SATest&) = delete;
    SATest& operator=(const SATest&) = delete;
};
