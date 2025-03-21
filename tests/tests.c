/*
** EPITECH PROJECT, 2025
** test
** File description:
** test
*/

#include "include/unit_test.h"
#include <dlfcn.h>

int (*my_strlen)(const char *str) = NULL;
char *(*my_strchr)(const char *str, int c) = NULL;
char *(*my_strrchr)(const char *str, int c) = NULL;
void *(*my_memset)(void *ptr, int value, size_t num) = NULL;
void *(*my_memcpy)(void *dest, const void *src, size_t num) = NULL;
int (*my_strcmp)(const char *str1, const char *str2) = NULL;
void *(*my_memmove)(void *dest, const void *src, size_t num) = NULL;
int (*my_strncmp)(const char *str1, const char *str2, size_t num) = NULL;
int (*my_strcasecmp)(const char *str1, const char *str2) = NULL;
char *(*my_strstr)(const char *str1, const char *str2) = NULL;
char *(*my_strpbrk)(const char *str1, const char *str2) = NULL;
size_t (*my_strcspn)(const char *str1, const char *str2) = NULL;

void *handle = NULL;

void load_lib(void)
{
    handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle) {
        cr_assert_fail("dlopen failed: %s\n", dlerror());
    }
    my_strlen = dlsym(handle, "strlen");
    my_strchr = dlsym(handle, "strchr");
    my_strrchr = dlsym(handle, "strrchr");
    my_memset = dlsym(handle, "memset");
    my_memcpy = dlsym(handle, "memcpy");
    my_strcmp = dlsym(handle, "strcmp");
    my_memmove = dlsym(handle, "memmove");
    my_strncmp = dlsym(handle, "strncmp");
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_strstr = dlsym(handle, "strstr");
    my_strpbrk = dlsym(handle, "strpbrk");
    my_strcspn = dlsym(handle, "strcspn");
}

void unload_lib(void)
{
    dlclose(handle);
}

Test(my_strlen, tests_my_strlen, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_strlen, NULL);
    cr_assert_eq(my_strlen("Hello"), strlen("Hello"));
    cr_assert_eq(my_strlen(""), strlen(""));
    cr_assert_eq(my_strlen("Hello World"), strlen("Hello World"));
    cr_assert_eq(my_strlen("Hello\0World"), strlen("Hello\0World"));

    char large_string[1001];
    memset(large_string, 'a', 1000);
    large_string[1000] = '\0';
    cr_assert_eq(my_strlen(large_string), strlen(large_string));

    cr_assert_eq(my_strlen("a"), strlen("a"));
    cr_assert_eq(my_strlen("\n"), strlen("\n"));

    cr_assert_eq(my_strlen("\n\t\r"), strlen("\n\t\r"));

    char string_with_nulls[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cr_assert_eq(my_strlen(string_with_nulls), strlen(string_with_nulls));

    string_with_nulls[2] = '\0';
    cr_assert_eq(my_strlen(string_with_nulls), strlen(string_with_nulls));
}

Test(my_strchr, tests_my_strchr, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_strchr, NULL);
    char *str = "Hello";
    cr_assert_eq(my_strchr(str, 'H'), strchr(str, 'H'));
    cr_assert_eq(my_strchr(str, 'e'), strchr(str, 'e'));
    cr_assert_eq(my_strchr(str, 'l'), strchr(str, 'l'));
    cr_assert_eq(my_strchr(str, 'o'), strchr(str, 'o'));
    cr_assert_eq(my_strchr(str, 'z'), strchr(str, 'z'));
    cr_assert_eq(my_strchr(str, '\0'), strchr(str, '\0'));

    cr_assert_eq(my_strchr("a", 'a'), strchr("a", 'a'));
    cr_assert_eq(my_strchr("\n\t\r", '\n'), strchr("\n\t\r", '\n'));

    char *multi_occurrences = "Hello, World! Hello, Universe!";
    cr_assert_eq(my_strchr(multi_occurrences, 'o'), strchr(multi_occurrences, 'o'));

    cr_assert_eq(my_strchr("Hello", 'H'), strchr("Hello", 'H'));

    cr_assert_eq(my_strchr("Hello", '\0'), strchr("Hello", '\0'));
    cr_assert_eq(my_strchr("Hello", 'x'), strchr("Hello", 'x'));
    cr_assert_eq(my_strchr("", 'a'), strchr("", 'a'));
    cr_assert_eq(my_strchr("", '\0'), strchr("", '\0'));

    cr_assert_eq(my_strchr("Test\0String", '\0'), strchr("Test\0String", '\0'));
}

Test(my_strrchr, tests_my_strrchr, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_strrchr, NULL);
    char *str = "Hello";
    cr_assert_eq(my_strrchr(str, 'H'), strrchr(str, 'H'));
    cr_assert_eq(my_strrchr(str, 'e'), strrchr(str, 'e'));
    cr_assert_eq(my_strrchr(str, 'l'), strrchr(str, 'l'));
    cr_assert_eq(my_strrchr(str, 'o'), strrchr(str, 'o'));
    cr_assert_eq(my_strrchr(str, 'z'), strrchr(str, 'z'));
    cr_assert_eq(my_strrchr(str, '\0'), strrchr(str, '\0'));

    char *repeated_chars = "Hello, World! Hello, Universe!";
    cr_assert_eq(my_strrchr(repeated_chars, 'o'), strrchr(repeated_chars, 'o'));
    cr_assert_eq(my_strrchr(repeated_chars, 'l'), strrchr(repeated_chars, 'l'));

    char *special_chars = "Hello\nWorld\t!";
    cr_assert_eq(my_strrchr(special_chars, '\n'), strrchr(special_chars, '\n'));
    cr_assert_eq(my_strrchr(special_chars, '\t'), strrchr(special_chars, '\t'));

    cr_assert_eq(my_strrchr("a", 'a'), strrchr("a", 'a'));
    cr_assert_eq(my_strrchr("", '\0'), strrchr("", '\0'));

    cr_assert_eq(my_strrchr("Hello", 'x'), strrchr("Hello", 'x'));
    cr_assert_eq(my_strrchr("Hello", 255), strrchr("Hello", 255));

    cr_assert_eq(my_strrchr("aHelloa", 'a'), strrchr("aHelloa", 'a'));

    cr_assert_eq(my_strrchr("Hello\0World", '\0'), strrchr("Hello\0World", '\0'));

    char *edge_case_str = "Hello\0World";
    cr_assert_eq(my_strrchr(edge_case_str, 'W'), strrchr(edge_case_str, 'W'));
}

Test(my_memset, tests_my_memset, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_memset, NULL);
    char *str1 = malloc(6);
    char *str2 = malloc(6);
    cr_assert_eq(my_memset(str1, 'a', 5), memset(str1, 'a', 5));
    my_memset(str1, 'a', 5);
    for (int i = 0; i < 5; i++)
        cr_assert_eq(str1[i], 'a');
    my_memset(str1, 'b', 5);
    for (int i = 0; i < 5; i++)
        cr_assert_eq(str1[i], 'b');
    my_memset(str1, 'c', 0);
    for (int i = 0; i < 5; i++)
        cr_assert_eq(str1[i], 'b');
}

Test(my_memcpy, tests_my_memcpy, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_memcpy, NULL);
    char *str1 = malloc(6);
    char *str2 = malloc(6);
    memset(str1, '\0', 6);
    memset(str2, '\0', 6);
    str1[0] = 'H';
    str1[1] = 'e';
    str1[2] = 'l';
    str1[3] = 'l';
    str1[4] = 'o';
    my_memcpy(str2, str1, 5);
    cr_assert_str_eq(str2, "Hello");
    memset(str2, '\0', 6);
    my_memcpy(str2, str1, 3);
    cr_assert_str_eq(str2, "Hel");
    memset(str2, '\0', 6);
    my_memcpy(str2, str1, 0);
    cr_assert_str_eq(str2, "");
    memset(str2, '\0', 6);
    my_memcpy(str2, str1, 6);
    cr_assert_str_eq(str2, "Hello");
}

Test(my_strcmp, tests_my_strcmp, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_strcmp, NULL);
    cr_assert_eq(my_strcmp("Hello", "Hello"), strcmp("Hello", "Hello"));
    cr_assert_eq(my_strcmp("Hello", "HelloWorld"), strcmp("Hello", "HelloWorld"));
    cr_assert_eq(my_strcmp("Hello", "Bonjour"), strcmp("Hello", "Bonjour"));
    cr_assert_eq(my_strcmp("Hello", "Helloo"), strcmp("Hello", "Helloo"));
    cr_assert_eq(my_strcmp("Hello", "Helloo"), strcmp("Hello", "Helloo"));
    cr_assert_eq(my_strcmp("", ""), strcmp("", ""));
    cr_assert_eq(my_strcmp("Hello", ""), strcmp("Hello", ""));
    cr_assert_eq(my_strcmp("", "Hello"), strcmp("", "Hello"));
    cr_assert_eq(my_strcmp("Hello\0World", "Hello\0World"), strcmp("Hello\0World", "Hello\0World"));
}

Test(my_memmove, basic, .init = load_lib, .fini = unload_lib, .timeout = 1)
{
	char *test = strdup("test");
	char *test2 = strdup("test");
	char *copy = strdup("copy");
	char *copy2 = strdup("copy");

	cr_assert(!strcmp(memmove(test, copy, 4), my_memmove(test2, copy2, 4)));
}

Test(my_memmove, empty_string, .init = load_lib, .fini = unload_lib, .timeout = 1)
{
	char *test = strdup("hello there u");
	char *test2 = strdup("");

	cr_assert(my_memmove(test, test2, 1) == test);
}

Test(my_memmove, empty_string2, .init = load_lib, .fini = unload_lib, .timeout = 1)
{
	char *test = strdup("");
	char *test2 = strdup("hello there u");

	cr_assert(my_memmove(test, test2, 1) == test);
}

Test(my_memmove, full_null, .init = load_lib, .fini = unload_lib, .timeout = 1)
{
	char *test = strdup("");
	char *test2 = strdup("");

	cr_assert(my_memmove(test, test2, 1) == test);
}

// Test(my_memmove, tests_my_memmove, .init = load_lib, .fini = unload_lib, .timeout = 1) {
//     // cr_assert_neq(my_memmove, NULL);
//     // char *str1 = malloc(6);
//     // char *str2 = malloc(6);
//     // memset(str1, '\0', 6);
//     // memset(str2, '\0', 6);
//     // str1[0] = 'H';
//     // str1[1] = 'e';
//     // str1[2] = 'l';
//     // str1[3] = 'l';
//     // str1[4] = 'o';
//     // my_memmove(str2, str1, 5);
//     // cr_assert_str_eq(str2, "Hello");
//     // memset(str2, '\0', 6);
//     // my_memmove(str2, str1, 3);
//     // cr_assert_str_eq(str2, "Hel");
//     // memset(str2, '\0', 6);
//     // my_memmove(str2, str1, 0);
//     // cr_assert_str_eq(str2, "");
//     // memset(str2, '\0', 6);
//     // my_memmove(str2, str1, 6);
//     // cr_assert_str_eq(str2, "Hello");

//     // my_memmove(str2, str2, 6);
//     // cr_assert_str_eq(str2, "Hello");
//     // cr_assert_eq(my_memmove(str2, str2, 0), memmove(str2, str2, 0));
//     // cr_assert_eq(my_memmove(str2, str2, 6), memmove(str2, str2, 6));
//     // cr_assert_eq(my_memmove(str2, str2, 3), memmove(str2, str2, 3));
//     // cr_assert_eq(my_memmove(str2, str2, 1), memmove(str2, str2, 1));
//     // cr_assert_eq(my_memmove(str2, str2, 2), memmove(str2, str2, 2));
//     // char *str3 = malloc(6);
//     // char *str4 = malloc(6);
//     // memset(str3, '\0', 6);
//     // memset(str4, '\0', 6);
//     // str3[0] = 'H';
//     // str3[1] = 'e';
//     // str3[2] = 'l';
//     // str3[3] = 'l';
//     // str3[4] = 'o';
//     // my_memmove(str4, str3, 5);
//     // cr_assert_str_eq(str4, "Hello");
// }

Test(my_strncmp, tests_my_strncmp, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_strncmp, NULL);
    cr_assert_eq(my_strncmp("Hello", "Hello", 5), strncmp("Hello", "Hello", 5));
    cr_assert_eq(my_strncmp("Hello", "Hello", 3), strncmp("Hello", "Hello", 3));
    cr_assert_eq(my_strncmp("Hello", "Hello", 0), strncmp("Hello", "Hello", 0));
    cr_assert_eq(my_strncmp("Hello", "Hello", 6), strncmp("Hello", "Hello", 6));
    cr_assert_eq(my_strncmp("Hello", "Bonjour", 0), strncmp("Hello", "Bonjour", 0));
    cr_assert_eq(my_strncmp("Hello", "Bonjour", 3), strncmp("Hello", "Bonjour", 3));

    cr_assert_eq(my_strncmp("Hello", "HelloWorld", 5), strncmp("Hello", "HelloWorld", 5));
    cr_assert_eq(my_strncmp("Hello", "HelloWorld", 10), strncmp("Hello", "HelloWorld", 10));

    cr_assert_eq(my_strncmp("Hello", "Hell", 4), strncmp("Hello", "Hell", 4));
    cr_assert_eq(my_strncmp("Hello", "Hell", 5), strncmp("Hello", "Hell", 5));

    cr_assert_eq(my_strncmp("Hello", "Helloooo", 7), strncmp("Hello", "Helloooo", 7));

    cr_assert_eq(my_strncmp("hello", "Hello", 5), strncmp("hello", "Hello", 5));

    cr_assert_eq(my_strncmp("HeLlo", "Hello", 5), strncmp("HeLlo", "Hello", 5));

    cr_assert_eq(my_strncmp("Hello!", "Hello!", 6), strncmp("Hello!", "Hello!", 6));
    cr_assert_eq(my_strncmp("Hello!", "Hello", 6), strncmp("Hello!", "Hello", 6));

    cr_assert_eq(my_strncmp("Hello World", "Hello World", 11), strncmp("Hello World", "Hello World", 11));
    cr_assert_eq(my_strncmp("Hello World", "Hello  World", 11), strncmp("Hello World", "Hello  World", 11));

    cr_assert_eq(my_strncmp("", "", 0), strncmp("", "", 0));
    cr_assert_eq(my_strncmp("", "Hello", 0), strncmp("", "Hello", 0));

    cr_assert_eq(my_strncmp("Hello\0World", "Hello\0World", 11), strncmp("Hello\0World", "Hello\0World", 11));
    cr_assert_eq(my_strncmp("Hello\0World", "Hello\0Universe", 11), strncmp("Hello\0World", "Hello\0Universe", 11));

    cr_assert_eq(my_strncmp("HelloWorld", "HelloUniverse", 5), strncmp("HelloWorld", "HelloUniverse", 5));

    cr_assert_eq(my_strncmp("hello", "HELLO", 5), strncmp("hello", "HELLO", 5));

    cr_assert_eq(my_strncmp("Hi", "Hello", 5), strncmp("Hi", "Hello", 5));

    cr_assert_eq(my_strncmp("Hello World!", "Hello World?", 12), strncmp("Hello World!", "Hello World?", 12));

    cr_assert_eq(my_strncmp("Hello123", "Hello456", 5), strncmp("Hello123", "Hello456", 5));

    cr_assert(my_strncmp("b", "a", 1) > 0);
    cr_assert(my_strncmp("a", "b", 1) < 0);
    cr_assert_eq(my_strncmp("a", "a", 1), 0);

    cr_assert_eq(my_strncmp("", "Hello", 5), strncmp("", "Hello", 5));
    cr_assert_eq(my_strncmp("Hello", "", 5), strncmp("Hello", "", 5));

    cr_assert_eq(my_strncmp("abcdef", "ghijkl", 0), strncmp("abcdef", "ghijkl", 0));

    cr_assert_eq(my_strncmp("Hello\0World", "Hello\0Universe", 12), strncmp("Hello\0World", "Hello\0Universe", 12));
}

Test(my_strcasecmp, tests_my_strcasecmp, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_strcasecmp, NULL);
    cr_assert_eq(my_strcasecmp("Hello", "Hello"), strcasecmp("Hello", "Hello"));
    cr_assert_eq(my_strcasecmp("Hello", "HelloWorld"), strcasecmp("Hello", "HelloWorld"));
    cr_assert_eq(my_strcasecmp("Hello", "Bonjour"), strcasecmp("Hello", "Bonjour"));
    cr_assert_eq(my_strcasecmp("Hello", "Helloo"), strcasecmp("Hello", "Helloo"));
    cr_assert_eq(my_strcasecmp("Hello", "Helloo"), strcasecmp("Hello", "Helloo"));
    cr_assert_eq(my_strcasecmp("", ""), strcasecmp("", ""));

    cr_assert_eq(my_strcasecmp("Hello", "hello"), strcasecmp("Hello", "hello"));
    cr_assert_eq(my_strcasecmp("Hello World", "hello world"), strcasecmp("Hello World", "hello world"));
    cr_assert_eq(my_strcasecmp("hello world", "Hello World"), strcasecmp("hello world", "Hello World"));
    cr_assert_eq(my_strcasecmp("Hello World", "Hello World"), strcasecmp("Hello World", "Hello World"));
    cr_assert_eq(my_strcasecmp("hello world", "hello world"), strcasecmp("hello world", "hello world"));
    cr_assert_eq(my_strcasecmp("Hello World", "hello"), strcasecmp("Hello World", "hello"));
    cr_assert_eq(my_strcasecmp("hello", "Hello World"), strcasecmp("hello", "Hello World"));
    cr_assert_eq(my_strcasecmp("Hello World", "hello"), strcasecmp("Hello World", "hello"));
    cr_assert_eq(my_strcasecmp("hello", "Hello"), strcasecmp("hello", "Hello"));
    cr_assert_eq(my_strcasecmp("hello", "hello"), strcasecmp("hello", "hello"));

    // cr_assert_eq(my_strcasecmp("Hello", ""), strcasecmp("Hello", ""));
    // cr_assert_eq(my_strcasecmp("", "Hello"), strcasecmp("", "Hello"));
    // cr_assert_eq(my_strcasecmp("Hello", ""), strcasecmp("Hello", ""));
    // cr_assert_eq(my_strcasecmp("", "Hello"), strcasecmp("", "Hello"));
    cr_assert_eq(my_strcasecmp("Hello\0World", "Hello\0World"), strcasecmp("Hello\0World", "Hello\0World"));

    for (int i = 'A'; i <= 'Z'; ++i) {
        char lower_case[2] = {i + 32, '\0'};
        char upper_case[2] = {i, '\0'};
        cr_assert_eq(my_strcasecmp(lower_case, upper_case), strcasecmp(lower_case, upper_case));
    }

    cr_assert_eq(my_strcasecmp("Hello", "H"), strcasecmp("Hello", "H"));
    cr_assert_eq(my_strcasecmp("H", "Hello"), strcasecmp("H", "Hello"));

    cr_assert_eq(my_strcasecmp("12345", "12345"), strcasecmp("12345", "12345"));
    cr_assert_eq(my_strcasecmp("!@#$%", "!@#$%"), strcasecmp("!@#$%", "!@#$%"));
    cr_assert_eq(my_strcasecmp("hello\tworld", "HELLO\tWORLD"), strcasecmp("hello\tworld", "HELLO\tWORLD"));

    cr_assert_eq(my_strcasecmp("Hello\0World", "HELLO\0WORLD"), strcasecmp("Hello\0World", "HELLO\0WORLD"));
    cr_assert_eq(my_strcasecmp("Hello\0A", "HELLO\0B"), strcasecmp("Hello\0A", "HELLO\0B"));


    cr_assert_eq(my_strcasecmp("aBcDeF", "AbCdEf"), strcasecmp("aBcDeF", "AbCdEf"));
    cr_assert_eq(my_strcasecmp("ZzZz", "zZzZ"), strcasecmp("ZzZz", "zZzZ"));
}

Test(my_strstr, tests_my_strstr, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_strstr, NULL);
    cr_assert_str_eq(my_strstr("hello world", "hello"), strstr("hello world", "hello"));
    cr_assert_str_eq(my_strstr("hello world", "world"), strstr("hello world", "world"));
    cr_assert_str_eq(my_strstr("hello beautiful world", "beautiful"), strstr("hello beautiful world", "beautiful"));
    cr_assert_str_eq(my_strstr("Hello World", "World"), strstr("Hello World", "World"));
    cr_assert_null(my_strstr("Hello World", "world"));
    cr_assert_str_eq(my_strstr("repeat repeat repeat", "repeat"), strstr("repeat repeat repeat", "repeat"));
    cr_assert_null(my_strstr("short", "longerneedle"));
    cr_assert_null(my_strstr("", "needle"));
    cr_assert_str_eq(my_strstr("haystack", ""), strstr("haystack", ""));
    cr_assert_str_eq(my_strstr("", ""), strstr("", ""));
}

Test(my_strpbrk, tests_my_strpbrk, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_strpbrk, NULL);
    cr_assert_str_eq(my_strpbrk("hello world", "hello"), strpbrk("hello world", "hello"));
    cr_assert_str_eq(my_strpbrk("hello world", "world"), strpbrk("hello world", "world"));
    cr_assert_str_eq(my_strpbrk("hello beautiful world", "beautiful"), strpbrk("hello beautiful world", "beautiful"));
    cr_assert_str_eq(my_strpbrk("Hello World", "World"), strpbrk("Hello World", "World"));
    cr_assert_str_eq(my_strpbrk("Hello World", "world"), strpbrk("Hello World", "world"));
    cr_assert_str_eq(my_strpbrk("repeat repeat repeat", "repeat"), strpbrk("repeat repeat repeat", "repeat"));

    cr_assert_str_eq(my_strpbrk("short", "longerneedle"), strpbrk("short", "longerneedle"));

    cr_assert_null(my_strpbrk("", "needle"));
    cr_assert_null(strpbrk("", "needle"));

    cr_assert_null(my_strpbrk("haystack", ""));
    cr_assert_null(strpbrk("haystack", ""));

    cr_assert_null(my_strpbrk("", ""));
    cr_assert_null(strpbrk("", ""));
}

Test(my_strcspn, tests_my_strcspn, .init = load_lib, .fini = unload_lib, .timeout = 1) {
    cr_assert_neq(my_strcspn, NULL);
    cr_assert_eq(my_strcspn("hello world", "hello"), strcspn("hello world", "hello"));
    cr_assert_eq(my_strcspn("hello world", "world"), strcspn("hello world", "world"));
    cr_assert_eq(my_strcspn("hello beautiful world", "beautiful"), strcspn("hello beautiful world", "beautiful"));
    cr_assert_eq(my_strcspn("Hello World", "World"), strcspn("Hello World", "World"));
    cr_assert_eq(my_strcspn("Hello World", "world"), strcspn("Hello World", "world"));
    cr_assert_eq(my_strcspn("repeat repeat repeat", "repeat"), strcspn("repeat repeat repeat", "repeat"));
    cr_assert_eq(my_strcspn("short", "longerneedle"), strcspn("short", "longerneedle"));
    cr_assert_eq(my_strcspn("", "needle"), strcspn("", "needle"));
    cr_assert_eq(my_strcspn("haystack", ""), strcspn("haystack", ""));
    cr_assert_eq(my_strcspn("", ""), strcspn("", ""));
}