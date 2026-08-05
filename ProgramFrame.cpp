#include "ProgramFrame.h"

#include <iostream>
#include <limits>

ProgramFrame::~ProgramFrame() = default;

void ProgramFrame::startMessage(std::ostream& os) const {
    os << "Nhap du lieu.\n";
}

void ProgramFrame::errorMessage(std::ostream& os) const {
    os << "Du lieu khong hop le, nhap lai.\n";
}

bool ProgramFrame::askContinue(
    std::istream& is,
    std::ostream& os
) const {
    os << "Ban co muon tiep tuc (c/k): ";

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