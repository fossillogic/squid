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

// Define the test suite
FOSSIL_SUITE(c_scan_suite);

// Setup function
FOSSIL_SETUP(c_scan_suite)
{
    // Setup code (if any)
}

// Teardown function
FOSSIL_TEARDOWN(c_scan_suite)
{
    // Teardown code (if any)
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test: Basic TCP scan on localhost
FOSSIL_TEST(c_test_scan_tcp)
{
    int rc = fossil_squid_scan("127.0.0.1", "80-82", 0, 1000, true, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Basic UDP scan on localhost
FOSSIL_TEST(c_test_scan_udp)
{
    int rc = fossil_squid_scan("127.0.0.1", "53", 0, 1000, false, true, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Scan top 5 common ports
FOSSIL_TEST(c_test_scan_top_n)
{
    int rc = fossil_squid_scan("127.0.0.1", NULL, 5, 1000, true, false, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Scan with service detection
FOSSIL_TEST(c_test_scan_service)
{
    int rc = fossil_squid_scan("127.0.0.1", "80-82", 0, 1000, true, false, true, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Scan with banner grabbing
FOSSIL_TEST(c_test_scan_banner)
{
    int rc = fossil_squid_scan("127.0.0.1", "80-82", 0, 1000, true, false, false, true, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Only open ports
FOSSIL_TEST(c_test_scan_open_only)
{
    int rc = fossil_squid_scan("127.0.0.1", "80-82", 0, 1000, true, false, false, false, true, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: JSON output
FOSSIL_TEST(c_test_scan_json)
{
    int rc = fossil_squid_scan("127.0.0.1", "80-82", 0, 1000, true, false, false, false, false, true);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: TCP + UDP combined scan
FOSSIL_TEST(c_test_scan_tcp_udp)
{
    int rc = fossil_squid_scan("127.0.0.1", "80-82,53", 0, 1000, true, true, false, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Invalid host should fail
FOSSIL_TEST(c_test_scan_invalid_host)
{
    int rc = fossil_squid_scan("invalid.host.local", "1-10", 0, 1000, true, false, false, false, false, false);
    ASSUME_ITS_NOT_EQUAL_I32(0, rc);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_scan_tests)
{
    FOSSIL_TEST_ADD(c_scan_suite, c_test_scan_tcp);
    FOSSIL_TEST_ADD(c_scan_suite, c_test_scan_udp);
    FOSSIL_TEST_ADD(c_scan_suite, c_test_scan_top_n);
    FOSSIL_TEST_ADD(c_scan_suite, c_test_scan_service);
    FOSSIL_TEST_ADD(c_scan_suite, c_test_scan_banner);
    FOSSIL_TEST_ADD(c_scan_suite, c_test_scan_open_only);
    FOSSIL_TEST_ADD(c_scan_suite, c_test_scan_json);
    FOSSIL_TEST_ADD(c_scan_suite, c_test_scan_tcp_udp);
    FOSSIL_TEST_ADD(c_scan_suite, c_test_scan_invalid_host);

    FOSSIL_TEST_REGISTER(c_scan_suite);
}
