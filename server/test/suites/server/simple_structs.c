/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#include "simple_structs.h"

int get_sign_struct(struct MyStruct st) {
    if (st.a == 0) {
        return 0;
    }
    if (st.a < 0) {
        return -1;
    } else {
        return 1;
    }
}

int calculate_something(struct OneMoreStruct str) {
    if (str.a == 1 && str.b == 10754) {
        return 0;
    }
    if (str.c != 0 && str.a == 7 && str.b == 2020) {
        return 1;
    }
    if (str.c != 0) {
        return (int) str.c;
    }
    if ((long long) str.a > str.b) {
        return str.a;
    } else {
        return (int) str.b;
    }
}

char get_symbol_by_struct(struct StructWithChars st) {
    if (st.a == 'a') {
        return 'a';
    }
    if (st.c == 'c') {
        return 'c';
    }

    if (st.u == 'u') {
        return 'u';
    }

    if (st.b == 1) {
        return '1';
    }

    return '0';
}

signed char operate_with_inner_structs(struct MainStruct st) {
    if (st.x == 5 && st.y == 5 && st.inner.c == '5' &&
        st.inner.s == 5 && st.inner.ininner.l == 5 && st.inner.ininner.u == 5) {
        return '5';
    }

    if (st.x == 5 && st.y == 101 && st.inner.s == 15) {
        return st.inner.c;
    }

    if ((long long) st.inner.ininner.u == st.inner.ininner.l) {
        return 'e';
    }
    if ((long long) st.inner.ininner.u > st.inner.ininner.l) {
        return 'g';
    }

    return 'o';
}


struct MainStruct struct_as_return_type(int a) {
    if (a == 0) {
        struct MainStruct res = {{'0', {0, 0}, 0}, 0, 0};
        return res;
    }

    if (a == 1) {
        struct MainStruct res = {{'1', {1, 1}, 1}, 1, 1};
        return res;
    }

    struct MainStruct res = {{'2', {2, 2}, 2}, 2, 2};
    return res;
}
