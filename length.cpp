#include "length.h"

void Length::set_type(Type type) {
    if (_type == type) return;

    double meters = _length;
    if (_type == km) {
        meters = _length * 1000.;
    }
    if (_type == cm) {
        meters = _length * 0.01;
    }
    if (_type == mm) {
        meters = _length * 0.001;
    }

    if (type == m) {
        _length = meters;
    }
    if (type == km) {
        _length = meters * 0.001;
    }
    if (type == cm) {
        _length = meters * 100.;
    }
    if (type == mm) {
        _length = meters * 1000.;
    }

    _type = type;
}

void Length::set_length(double length) {
    if (length < 0) {
        throw std::invalid_argument(
            "Length cannot be negative");
    }
    _length = length;
}

double Length::get_length() const {
    return _length;
}

Length::Type Length::get_type() const {
    return _type;
}

Length::Type Length::define_uon(const char* str, bool& uon) {
    if(strcmp(str, "km") == 0) {
        uon = true;
        return Length::km;
    }
    if(strcmp(str, "m") == 0) {
        uon = true;
        return Length::m;
    }
    if(strcmp(str, "cm") == 0) {
        uon = true;
        return Length::cm;
    }
    if(strcmp(str, "mm") == 0) {
        uon = true;
        return Length::mm;
    }
    uon = false;
    return Length::m;
}

void Length::print() {
    if(_type == Length::m) {
        std::cout <<
            "Meters = "
                  <<
            _length;
    }
    if(_type == Length::km) {
        std::cout <<
            "Kilometers = "
                  <<
            _length;
    }
    if(_type == Length::cm) {
        std::cout <<
            "Centimeters = "
                  <<
            _length;
    }
    if(_type == Length::mm) {
        std::cout <<
            "Millimeters = "
                  <<
            _length;
    }
}