#include "weight.h"

void Weight::set_type(Type type) {
    if (_type == type) return;

    double grams = _weight;
    if (_type == kg) {
        grams = _weight * 1000.;
    }
    if (_type == lb) {
        grams = _weight / 0.0022046;
    }
    if (_type == oz) {
        grams = _weight / 0.035274;
    }

    if (type == g) {
        _weight = grams;
    }
    if (type == kg) {
        _weight = grams * 0.001;
    }
    if (type == lb) {
        _weight = grams * 0.0022046;
    }
    if (type == oz) {
        _weight = grams * 0.035274;
    }

    _type = type;
}

void Weight::set_weight(double weight) {
    if (weight < 0) {
        throw std::invalid_argument(
            "Weight cannot be negative");
    }
    _weight = weight;
}

double Weight::get_weight() const {
    return _weight;
}

Weight::Type Weight::get_type() const {
    return _type;
}

Weight::Type Weight::define_uon(const char* str, bool& uon) {
    if(strcmp(str, "lb") == 0) {
        uon = true;
        return lb;
    }
    if(strcmp(str, "kg") == 0) {
        uon = true;
        return kg;
    }
    if(strcmp(str, "g") == 0) {
        uon = true;
        return g;
    }
    if(strcmp(str, "oz") == 0) {
        uon = true;
        return oz;
    }
    uon = false;
    return kg;
}

void Weight::print() {
    if(_type == Weight::lb) {
        std::cout <<
            "Pound = "
                  <<
            _weight;
    }
    if(_type == Weight::kg) {
        std::cout <<
            "Kilogram = "
                  <<
            _weight;
    }
    if(_type == Weight::g) {
        std::cout <<
            "Gram = "
                  <<
            _weight;
    }
    if(_type == Weight::oz) {
        std::cout <<
            "Ounce = "
                  <<
            _weight;
    }
}