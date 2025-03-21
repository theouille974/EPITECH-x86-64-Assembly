/*
** EPITECH PROJECT, 2025
** unit test
** File description:
** redirect the standard output and standard error for the test
*/

#include "include/unit_test.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// cr_assert_null                pointer                        Asserts that a pointer is NULL
// cr_assert_not_null	         pointer	                    Asserts that a pointer is not NULL.
// cr_assert_eq                  actual, expected	            Asserts that two values are equal.
// cr_assert_neq	             actual, expected	            Asserts that two values are not equal.
// cr_assert_str_eq	             actual_str, expected_str	    Asserts that two strings are equal.
// cr_assert_str_empty	         str	                        Asserts that a string is empty.
// cr_assert_stdout_eq_str       expected_str	                Asserts that the captured stdout matches an expected string.
// cr_assert_stderr_neq_str	     unexpected_str	                Asserts that the captured stderr does not match an unexpected string.
// cr_assert_file_contents_eq    filename, expected_contents	Asserts that the contents of a file match the expected contents.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
