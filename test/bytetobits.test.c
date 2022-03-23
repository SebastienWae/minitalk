#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <limits.h>

#include <bits.h>

static void bytetobits_0(void **state) {
    (void) state;

	char	bits[8];
    char    expected[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    bytetobits(0, bits);
	assert_memory_equal(bits, expected, sizeof(char) * 8); 
}

static void bytetobits_1(void **state) {
    (void) state;

	char	bits[8];
    char    expected[8] = {0, 0, 0, 0, 0, 0, 0, 1};

    bytetobits(1, bits);
	assert_memory_equal(bits, expected, sizeof(char) * 8); 
}

static void bytetobits_minus_1(void **state) {
    (void) state;

	char	bits[8];
    char    expected[8] = {1, 1, 1, 1, 1, 1, 1, 1};

    bytetobits(-1, bits);
	assert_memory_equal(bits, expected, sizeof(char) * 8); 
}

static void bytetobits_min(void **state) {
    (void) state;

	char	bits[8];
    char    expected[8] = {1, 0, 0, 0, 0, 0, 0, 0};

    bytetobits(CHAR_MIN, bits);
	assert_memory_equal(bits, expected, sizeof(char) * 8); 
}

static void bytetobits_max(void **state) {
    (void) state;

	char	bits[8];
    char    expected[8] = {0, 1, 1, 1, 1, 1, 1, 1};

    bytetobits(CHAR_MAX, bits);
	assert_memory_equal(bits, expected, sizeof(char) * 8); 
}

static void bytetobits_umax(void **state) {
    (void) state;

	char	bits[8];
    char    expected[8] = {1, 1, 1, 1, 1, 1, 1, 1};

    bytetobits((char)UCHAR_MAX, bits);
	assert_memory_equal(bits, expected, sizeof(char) * 8); 
}

int main(void) {
    const struct CMUnitTest bytetobits_tests[] = {
        cmocka_unit_test(bytetobits_0),
        cmocka_unit_test(bytetobits_1),
        cmocka_unit_test(bytetobits_minus_1),
        cmocka_unit_test(bytetobits_min),
        cmocka_unit_test(bytetobits_max),
        cmocka_unit_test(bytetobits_umax),
    };
    return cmocka_run_group_tests(bytetobits_tests, NULL, NULL);
}
