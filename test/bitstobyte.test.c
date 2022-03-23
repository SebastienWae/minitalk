#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <limits.h>

#include <bits.h>

static void bitstobyte_0(void **state) {
    (void) state;

    char    bits[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	assert_int_equal(bitstobyte(bits), 0);
}

static void bitstobyte_1(void **state) {
    (void) state;

    char    bits[8] = {0, 0, 0, 0, 0, 0, 0, 1};

	assert_int_equal(bitstobyte(bits), 1);
}

static void bitstobyte_minus_1(void **state) {
    (void) state;

    char    bits[8] = {1, 1, 1, 1, 1, 1, 1, 1};

	assert_int_equal(bitstobyte(bits), -1);
}

static void bitstobyte_min(void **state) {
    (void) state;

    char    bits[8] = {1, 0, 0, 0, 0, 0, 0, 0};

	assert_int_equal(bitstobyte(bits), CHAR_MIN);
}

static void bitstobyte_max(void **state) {
    (void) state;

    char    bits[8] = {0, 1, 1, 1, 1, 1, 1, 1};

	assert_int_equal(bitstobyte(bits), CHAR_MAX);
}

int main(void) {
    const struct CMUnitTest bitstobyte[] = {
        cmocka_unit_test(bitstobyte_0),
        cmocka_unit_test(bitstobyte_1),
        cmocka_unit_test(bitstobyte_minus_1),
        cmocka_unit_test(bitstobyte_min),
        cmocka_unit_test(bitstobyte_max),
    };
    return cmocka_run_group_tests(bitstobyte, NULL, NULL);
}
