#include <iostream>
#include <string>
#include <limits>
#include "SATest.h"
#include "SelectionS.h"
#include "InsertionS.h"
#include "InterchangeS.h"
#include "Fraction.h"

using namespace std;

void clearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    while (true) {
        cout << "CHON KIEU DU LIEU:\n";
        cout << "1. So nguyen (Short)\n";
        cout << "2. Chuoi ky tu (String)\n";
        cout << "3. Phan so (Fraction)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Nhap lua chon: ";

        int typeChoice;
        if (!(cin >> typeChoice)) {
            clearInputStream();
            cout << "Loi: Vui long nhap so hop le!\n";
            continue;
        }

        if (typeChoice == 0) {
            cout << "Oi!\n";
            break;
        }

        if (typeChoice < 1 || typeChoice > 3) {
            cout << "Lua chon kieu du lieu khong hop le!\n";
            continue;
        }

        cout << "\nCHON THUAT TOAN SAP XEP:\n";
        cout << "1. Selection Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Interchange Sort\n";
        cout << "Nhap lua chon: ";

        int algoChoice;
        if (!(cin >> algoChoice)) {
            clearInputStream();
            cout << "Loi: Vui long nhap so hop le!\n";
            continue;
        }

        if (algoChoice < 1 || algoChoice > 3) {
            cout << "Lua chon thuat toan khong hop le!\n";
            continue;
        }

        cout << "\n--------------------------------------------\n";


        switch (typeChoice) {
        case 1: {
            SortArray<short>* algo = nullptr;
            if (algoChoice == 1) algo = new SelectionS<short>();
            else if (algoChoice == 2) algo = new InsertionS<short>();
            else if (algoChoice == 3) algo = new InterchangeS<short>();

            SATest<short> testShort(algo, "Short", "HD: Nhap so luong n. Sau do nhap n so nguyen.");
            testShort.run(cin, cout);
            break;
        }
        case 2: {
            SortArray<string>* algo = nullptr;
            if (algoChoice == 1) algo = new SelectionS<string>();
            else if (algoChoice == 2) algo = new InsertionS<string>();
            else if (algoChoice == 3) algo = new InterchangeS<string>();

            SATest<string> testString(algo, "String", "HD: Nhap so luong n. Sau do nhap n chuoi ky tu.");
            testString.run(cin, cout);
            break;
        }
        case 3: {
            SortArray<Fraction>* algo = nullptr;
            if (algoChoice == 1) algo = new SelectionS<Fraction>();
            else if (algoChoice == 2) algo = new InsertionS<Fraction>();
            else if (algoChoice == 3) algo = new InterchangeS<Fraction>();

            SATest<Fraction> testFraction(algo, "Fraction (Phan so)", "HD: Nhap so luong n. Voi moi phan so nhap: <tu so> <mau so>. VD: 1 2.");
            testFraction.run(cin, cout);
            break;
        }
        }
    }

    return 0;
}