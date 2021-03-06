//
// Created by pauls on 21/01/2022.
//

#include <iostream>
#include "state.h"

State::State(string name) {
    this->name = std::move(name);
}

void State::Transiting(__attribute__((unused)) Symbol *symbol) {
#if DEBUG
    cout << "Transiting through the state "
         << name
         << endl << "With symbol:"
         << endl;
    symbol->Display();
    cout << endl;
#endif
}

bool State0::Transition(Automaton &automaton, Symbol *symbol) {
    Transiting(symbol);
    switch (*symbol) {
        case EXPR:
            automaton.shift(symbol, new State1());
            break;
        case INT:
            automaton.shift(symbol, new State3());
            break;
        case OPEN_PAR:
            automaton.shift(symbol, new State2());
            break;
        default:
            delete (symbol);
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State1::Transition(Automaton &automaton, Symbol *symbol) {
    Transiting(symbol);
    switch (*symbol) {
        case PLUS:
            automaton.shift(symbol, new State4());
            break;
        case MULTIPLICATION:
            automaton.shift(symbol, new State5());
            break;
        case END:
            delete (symbol);
            return false;
        default:
            delete (symbol);
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State2::Transition(Automaton &automaton, Symbol *symbol) {
    Transiting(symbol);
    switch (*symbol) {
        case INT:
            automaton.shift(symbol, new State3());
            break;
        case OPEN_PAR:
            automaton.shift(symbol, new State2());
            break;
        case EXPR:
            automaton.shift(symbol, new State6());
            break;
        default:
            delete (symbol);
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State3::Transition(Automaton &automaton, Symbol *symbol) {
    Transiting(symbol);
    switch (*symbol) {
        case MULTIPLICATION:
        case CLOSE_PAR:
        case END:
        case PLUS:
            automaton.reduction(1, symbol);
            break;
        default:
            delete (symbol);
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State4::Transition(Automaton &automaton, Symbol *symbol) {
    Transiting(symbol);
    switch (*symbol) {
        case INT:
            automaton.shift(symbol, new State3());
            break;
        case OPEN_PAR:
            automaton.shift(symbol, new State2());
            break;
        case EXPR:
            automaton.shift(symbol, new State7());
            break;
        default:
            delete (symbol);
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State5::Transition(Automaton &automaton, Symbol *symbol) {
    Transiting(symbol);
    switch (*symbol) {
        case INT:
            automaton.shift(symbol, new State3());
            break;
        case OPEN_PAR:
            automaton.shift(symbol, new State2());
            break;
        case EXPR:
            automaton.shift(symbol, new State8());
            break;
        default:
            delete (symbol);
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State6::Transition(Automaton &automaton, Symbol *symbol) {
    Transiting(symbol);
    switch (*symbol) {
        case PLUS:
            automaton.shift(symbol, new State4());
            break;
        case MULTIPLICATION:
            automaton.shift(symbol, new State5());
            break;
        case CLOSE_PAR:
            automaton.shift(symbol, new State9());
            break;
        default:
            delete (symbol);
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State7::Transition(Automaton &automaton, Symbol *symbol) {
    Transiting(symbol);
    switch (*symbol) {
        case END:
        case CLOSE_PAR:
        case PLUS:
            automaton.reduction(3, symbol);
            break;
        case MULTIPLICATION:
            automaton.shift(symbol, new State5());
            break;
        default:
            delete (symbol);
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State8::Transition(Automaton &automaton, Symbol *symbol) {
    Transiting(symbol);
    switch (*symbol) {
        case CLOSE_PAR:
        case MULTIPLICATION:
        case END:
        case PLUS:
            automaton.reduction(3, symbol);
            break;
        default:
            delete (symbol);
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}

bool State9::Transition(Automaton &automaton, Symbol *symbol) {
    Transiting(symbol);
    switch (*symbol) {
        case CLOSE_PAR:
        case END:
        case MULTIPLICATION:
        case PLUS:
            automaton.reduction(3, symbol);
            break;
        default:
            delete (symbol);
            automaton.shift(new Error(), nullptr);
            return false;
    }
    return true;
}