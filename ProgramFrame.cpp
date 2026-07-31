#include "ProgramFrame.h"

#include <iostream>
#include <limits>

ProgramFrame::~ProgramFrame() = default;

void ProgramFrame::startMessage(std::ostream& os) const {
    os << "Hãy nhập dữ liệu.\n";
}

void ProgramFrame::errorMessage(std::ostream& os) const {
    os << "Dữ liệu không hợp lệ. Vui lòng nhập lại.\n";
}

bool ProgramFrame::askContinue(
    std::istream& is,
    std::ostream& os
) const {
    os << "Bạn có muốn tiếp tục với cùng kiểu dữ liệu và thuật toán không? (c/k): ";

    char choice;
    is >> choice;

    is.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );

    return choice == 'c' || choice == 'C';
}

void ProgramFrame::run(
    std::istream& is,
    std::ostream& os
) {
    while (true) {
        startMessage(os);

        Input(is);

        if (!Check()) {
            errorMessage(os);

            is.clear();

            is.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            continue;
        }

        Process();

        Output(os);

        if (!askContinue(is, os)) {
            break;
        }
    }
}
