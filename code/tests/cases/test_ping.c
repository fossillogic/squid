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
FOSSIL_SUITE(c_ping_suite);

// Setup function
FOSSIL_SETUP(c_ping_suite)
{
    // Setup code (if any)
}

// Teardown function
FOSSIL_TEARDOWN(c_ping_suite)
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

// Test: Basic IPv4 ping
FOSSIL_TEST(c_test_ping_ipv4)
{
    int rc = fossil_squid_ping("127.0.0.1", 4, 1000, 3000, true, false, 80, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Basic IPv6 ping
FOSSIL_TEST(c_test_ping_ipv6)
{
    int rc = fossil_squid_ping("::1", 4, 1000, 3000, false, true, 80, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: TCP ping on custom port
FOSSIL_TEST(c_test_ping_tcp_port)
{
    int rc = fossil_squid_ping("127.0.0.1", 2, 500, 1000, true, false, 8080, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Stats only output
FOSSIL_TEST(c_test_ping_stats_only)
{
    int rc = fossil_squid_ping("127.0.0.1", 3, 1000, 2000, true, false, 80, true, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Flood mode
FOSSIL_TEST(c_test_ping_flood)
{
    int rc = fossil_squid_ping("127.0.0.1", 5, 10, 1000, true, false, 80, false, true, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: JSON output
FOSSIL_TEST(c_test_ping_json)
{
    int rc = fossil_squid_ping("127.0.0.1", 4, 1000, 3000, true, false, 80, false, false, true);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: IPv4 and IPv6 both set (defaults to IPv4)
FOSSIL_TEST(c_test_ping_ipv4_ipv6)
{
    int rc = fossil_squid_ping("127.0.0.1", 3, 1000, 2000, true, true, 80, false, false, false);
    ASSUME_ITS_EQUAL_I32(0, rc);
}

// Test: Invalid host (should fail)
FOSSIL_TEST(c_test_ping_invalid_host)
{
    int rc = fossil_squid_ping("invalid.host.local", 2, 1000, 1000, true, false, 80, false, false, false);
    ASSUME_ITS_NOT_EQUAL_I32(0, rc);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_ping_tests)
{
    FOSSIL_TEST_ADD(c_ping_suite, c_test_ping_ipv4);
    FOSSIL_TEST_ADD(c_ping_suite, c_test_ping_ipv6);
    FOSSIL_TEST_ADD(c_ping_suite, c_test_ping_tcp_port);
    FOSSIL_TEST_ADD(c_ping_suite, c_test_ping_stats_only);
    FOSSIL_TEST_ADD(c_ping_suite, c_test_ping_flood);
    FOSSIL_TEST_ADD(c_ping_suite, c_test_ping_json);
    FOSSIL_TEST_ADD(c_ping_suite, c_test_ping_ipv4_ipv6);
    FOSSIL_TEST_ADD(c_ping_suite, c_test_ping_invalid_host);

    FOSSIL_TEST_REGISTER(c_ping_suite);
}
