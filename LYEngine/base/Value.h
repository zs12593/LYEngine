#ifndef LYENGINE_VALUE_H
#define LYENGINE_VALUE_H

#include <string>

namespace ly {

#define VALUE_ARRAY(_t) static Value **toValueArray(_t* arr, int len) { \
                        if (len <= 0) return nullptr; \
                        Value **val = new Value*[10]; \
                        for (int i = 0; i < len; ++i) \
                            val[i] = new Value(arr[i]); \
                        return val; }

class Value {
private:
    bool _bool;
    char _char;
    short _short;
    int _int;
    long _long;
    long long _longLong;
    float _float;
    double _double;
    std::string _string;

public:
    bool get_bool() const { return _bool; }

    void set_bool(bool _bool) { Value::_bool = _bool; }

    char get_char() const { return _char; }

    void set_char(char _char) { Value::_char = _char; }

    short get_short() const { return _short; }

    void set_short(short _short) { Value::_short = _short; }

    int get_int() const { return _int; }

    void set_int(int _int) { Value::_int = _int; }

    long get_long() const { return _long; }

    void set_long(long _long) { Value::_long = _long; }

    long long int get_longLong() const { return _longLong; }

    void set_longLong(long long int _longLong) { Value::_longLong = _longLong; }

    float get_float() const { return _float; }

    void set_float(float _float) { Value::_float = _float; }

    double get_double() const { return _double; }

    void set_double(double _double) { Value::_double = _double; }

    const std::string &get_string() const { return _string; }

    void set_string(const std::string &_string) { Value::_string = _string; }

    VALUE_ARRAY(bool)

    VALUE_ARRAY(char)

    VALUE_ARRAY(short)

    VALUE_ARRAY(int)

    VALUE_ARRAY(long)

    VALUE_ARRAY(long long)

    VALUE_ARRAY(std::string)

    Value() { }

    Value(bool _bool) : _bool(_bool) { }

    Value(char _char) : _char(_char) { }

    Value(short _short) : _short(_short) { }

    Value(long _long) : _long(_long) { }

    Value(int _int) : _int(_int) { }

    Value(float _float) : _float(_float) { }

    Value(double _double) : _double(_double) { }

    Value(long long int _longLong) : _longLong(_longLong) { }

    Value(const std::string &_string) : _string(_string) { }
};

}


#endif //LYENGINE_VALUE_H
