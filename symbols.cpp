//
// Created by Paul SOUTEYRAT & Alexandre MARTIN on 21/01/2022.
//

#include "symbols.h"

void Symbol::Display() const {
    cout << "    ";
    switch (ident) {
        case 0:
            cout << "OPEN_PAR";
            break;
        case 1:
            cout << "CLOSE_PAR";
            break;
        case 2:
            cout << "PLUS";
            break;
        case 3:
            cout << "MULTIPLICATION";
            break;
        case 4:
            cout << "INT";
            break;
        case 5:
            cout << "END";
            break;
        case 6:
            cout << "ERROR";
            break;
        case 7:
            cout << "EXPR";
            break;
    }
}

__attribute__((unused)) void SymbolWithValue::Display() {
    Symbol::Display();
    cout << "(" << value << ")";
}
