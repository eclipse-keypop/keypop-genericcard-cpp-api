/******************************************************************************
 * Copyright (c) 2026 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#include <regex>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

/* Keypop Generic Card */
#include "keypop/genericcard/GenericCardApiProperties.hpp"

using keypop::genericcard::GenericCardApiProperties_VERSION;

TEST(GenericCardApiPropertiesTest, versionIsCorrectlyWritten) {
    const std::string& apiVersion = GenericCardApiProperties_VERSION;
    const std::regex r("\\d+\\.\\d+");

    ASSERT_TRUE(std::regex_match(apiVersion, r));
}
