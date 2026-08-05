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
        os << "\nKieu du lieu: " << typeName << '\n';

        if (algorithm != nullptr) {
            os << "Thuat toan dang su dung: "
                << algorithm->name()
                << '\n';
        }
        else {
            os << "Chua co thuat toan sap xep.\n";
        }

        os << "Nhap so luong phan tu n, sau do nhap n phan tu.\n";
        os << inputHint << '\n';
        os << "Du lieu cua ban: ";
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
        os << "Mang sau khi sort: ";

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
