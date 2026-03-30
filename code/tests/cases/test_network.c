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
FOSSIL_SUITE(c_network_suite);

// Setup function for the test suite
FOSSIL_SETUP(c_network_suite)
{
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_network_suite)
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

FOSSIL_TEST(c_test_network_init_shutdown)
{
    // Should initialize and shutdown networking subsystem successfully
    int result_init = fossil_squid_network(true, false, NULL, NULL, -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL, false, false, -1, NULL, -1, false, 0, -1);
    int result_shutdown = fossil_squid_network(false, true, NULL, NULL, -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL, false, false, -1, NULL, -1, false, 0, -1);
    ASSUME_ITS_EQUAL_I32(0, result_init);
    ASSUME_ITS_EQUAL_I32(0, result_shutdown);
}

FOSSIL_TEST(c_test_network_create_close_socket)
{
    // Should create and close a TCP/IPv4 socket successfully
    int sock_id = fossil_squid_network(
        false, false,
        "fossil.net.socket.type.tcp", "fossil.net.family.ipv4",
        -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL,
        false, false, -1, NULL, -1, false, 0, -1);
    ASSUME_TRUE(sock_id >= 0);
    int result_close = fossil_squid_network(
        false, false,
        NULL, NULL,
        sock_id, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL,
        false, false, -1, NULL, -1, false, 0, -1);
    ASSUME_ITS_EQUAL_I32(0, result_close);
}

FOSSIL_TEST(c_test_network_set_blocking)
{
    // Should set blocking mode on a socket
    int sock_id = fossil_squid_network(
        false, false,
        "fossil.net.socket.type.tcp", "fossil.net.family.ipv4",
        -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL,
        false, false, -1, NULL, -1, false, 0, -1);
    ASSUME_TRUE(sock_id >= 0);
    int result_block = fossil_squid_network(
        false, false,
        NULL, NULL,
        -1, sock_id, true, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL,
        false, false, -1, NULL, -1, false, 0, -1);
    ASSUME_ITS_EQUAL_I32(0, result_block);
    fossil_squid_network(
        false, false,
        NULL, NULL,
        sock_id, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL,
        false, false, -1, NULL, -1, false, 0, -1); // cleanup
}

FOSSIL_TEST(c_test_network_address_parse)
{
    // Should parse a valid IP address and port
    int result = fossil_squid_network(false, false, NULL, NULL, -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, "127.0.0.1", 8080, -1, NULL, false, false, -1, NULL, -1, false, 0, -1);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(c_test_network_resolve_hostname)
{
    // Should resolve a valid hostname
    int result = fossil_squid_network(false, false, NULL, NULL, -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, "localhost", false, false, -1, NULL, -1, false, 0, -1);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(c_test_network_hostname)
{
    // Should get the local hostname
    int result = fossil_squid_network(false, false, NULL, NULL, -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL, true, false, -1, NULL, -1, false, 0, -1);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(c_test_network_mac_get)
{
    // Should get the primary MAC address
    int result = fossil_squid_network(false, false, NULL, NULL, -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL, false, true, -1, NULL, -1, false, 0, -1);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(c_test_network_sleep)
{
    // Should sleep for a short period (10 ms)
    int result = fossil_squid_network(false, false, NULL, NULL, -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL, false, false, -1, NULL, -1, false, 0, 10);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(c_test_network_error_last)
{
    // Should get last socket error (even if none)
    int result = fossil_squid_network(false, false, NULL, NULL, -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL, false, false, -1, NULL, -1, true, 0, -1);
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST(c_test_network_error_string)
{
    // Should describe an error code (simulate with "network.unreachable")
    int result = fossil_squid_network(false, false, NULL, NULL, -1, -1, false, -1, NULL, -1, -1, -1, -1, -1, -1, NULL, -1, -1, NULL, -1, -1, NULL, -1, NULL, false, false, -1, NULL, -1, false, (int)"network.unreachable", -1);
    ASSUME_NOT_EQUAL_I32(0, result);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_network_tests)
{
    FOSSIL_TEST_ADD(c_network_suite, c_test_network_init_shutdown);
    FOSSIL_TEST_ADD(c_network_suite, c_test_network_create_close_socket);
    FOSSIL_TEST_ADD(c_network_suite, c_test_network_set_blocking);
    FOSSIL_TEST_ADD(c_network_suite, c_test_network_address_parse);
    FOSSIL_TEST_ADD(c_network_suite, c_test_network_resolve_hostname);
    FOSSIL_TEST_ADD(c_network_suite, c_test_network_hostname);
    FOSSIL_TEST_ADD(c_network_suite, c_test_network_mac_get);
    FOSSIL_TEST_ADD(c_network_suite, c_test_network_sleep);
    FOSSIL_TEST_ADD(c_network_suite, c_test_network_error_last);
    FOSSIL_TEST_ADD(c_network_suite, c_test_network_error_string);

    FOSSIL_TEST_REGISTER(c_network_suite);
}
