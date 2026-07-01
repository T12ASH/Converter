#include "temperature.h"

void Temperature::set_type(Type type) {
    if (_type == type) return;

    double celsius = _temperature;
    if (_type == F) {
        celsius = (_temperature - 32) * 5. / 9.;
    }
    if (_type == K) {
        celsius = _temperature - 273.15;
    }

    if (type == C) {
        _temperature = celsius;
    }
    if (type == F) {
        _temperature = celsius * 9. / 5. + 32;
    }
    if (type == K) {
        _temperature = celsius + 273.15;
    }

    _type = type;
}

void Temperature::set_value(double temperature) {
    if ((temperature < -273.15) && (_type == C)) {
        throw std::invalid_argument(
            "Celsius cannot be lesser than -273.15");
    } else if ((temperature < -459.67) && (_type == F)) {
        throw std::invalid_argument(
            "Fahrenheit cannot be lesser than -459.67");
    } else if ((temperature < 0) && (_type == K)) {
        throw std::invalid_argument(
            "Kelvin cannot be negative");
    }
    _temperature = temperature;
}

double Temperature::get_value() const {
    return _temperature;
}

Temperature::Type Temperature::get_type() const {
    return _type;
}

Temperature::Type Temperature::define_uon(const char* str, bool& uon) {
    if(strcmp(str, "C") == 0) {
        uon = true;
        return Temperature::C;
    }
    if(strcmp(str, "F") == 0) {
        uon = true;
        return Temperature::F;
    }
    if(strcmp(str, "K") == 0) {
        uon = true;
        return Temperature::K;
    }
    uon = false;
    return Temperature::C;
}

void Temperature::print() {
    if(_type == Temperature::F) {
        std::cout <<
            "Fahrenheit = "
                  <<
            _temperature;
    }
    if(_type == Temperature::C) {
        std::cout <<
            "Celsius = "
                  <<
            _temperature;
    }
    if(_type == Temperature::K) {
        std::cout <<
            "Kelvin = "
                  <<
            _temperature;
    }
}