/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include <fossil/pizza/framework.h>

#include "fossil/code/app.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define the test suite and add test cases
FOSSIL_SUITE(c_this_suite);

// Setup function for the test suite
FOSSIL_SETUP(c_this_suite)
{
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_this_suite)
{
    // Teardown code here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test: Only system info
FOSSIL_TEST(c_test_this_system)
{
    int rc = fossil_squid_this(true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only architecture info
FOSSIL_TEST(c_test_this_arch)
{
    int rc = fossil_squid_this(false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only memory info
FOSSIL_TEST(c_test_this_memory)
{
    int rc = fossil_squid_this(false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only endianness info
FOSSIL_TEST(c_test_this_endianness)
{
    int rc = fossil_squid_this(false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only power info
FOSSIL_TEST(c_test_this_power)
{
    int rc = fossil_squid_this(false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only cpu info
FOSSIL_TEST(c_test_this_cpu)
{
    int rc = fossil_squid_this(false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only gpu info
FOSSIL_TEST(c_test_this_gpu)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only storage info
FOSSIL_TEST(c_test_this_storage)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only environment info
FOSSIL_TEST(c_test_this_env)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only virtualization info
FOSSIL_TEST(c_test_this_virtualization)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only uptime info
FOSSIL_TEST(c_test_this_uptime)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only network info
FOSSIL_TEST(c_test_this_network)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only process info
FOSSIL_TEST(c_test_this_process)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only limits info
FOSSIL_TEST(c_test_this_limits)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only time info
FOSSIL_TEST(c_test_this_time)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only hardware info
FOSSIL_TEST(c_test_this_hardware)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only display info
FOSSIL_TEST(c_test_this_display)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: All info (all = true)
FOSSIL_TEST(c_test_this_all)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: All info in JSON format
FOSSIL_TEST(c_test_this_all_json)
{
    int rc = fossil_squid_this(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_this_tests)
{
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_system);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_arch);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_memory);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_endianness);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_power);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_cpu);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_gpu);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_storage);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_env);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_virtualization);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_uptime);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_network);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_process);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_limits);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_time);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_hardware);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_display);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_all);
    FOSSIL_TEST_ADD(c_this_suite, c_test_this_all_json);

    FOSSIL_TEST_REGISTER(c_this_suite);
}
