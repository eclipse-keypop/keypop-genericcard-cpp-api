/******************************************************************************
 * Copyright (c) 2026 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * See the NOTICE file(s) distributed with this work for additional           *
 * information regarding copyright ownership.                                 *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT                                        *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "keypop/reader/transaction/spi/CardTransactionManager.hpp"

namespace keypop {
namespace genericcard {

/**
 * Provides basic methods to prepare and process APDU exchange with a card.
 *
 * @since 1.0.0
 */
class CardTransactionManager
: public keypop::reader::transaction::spi::CardTransactionManager<
      CardTransactionManager> {
public:
    /**
     *
     */
    virtual ~CardTransactionManager() = default;

    /**
     * Prepares an APDU to be transmitted the next time
     * processCommands(keypop::reader::ChannelControl) is invoked.
     *
     * @param apduCommand A not empty hexadecimal string containing a raw APDU
     * command.
     * @return This instance.
     * @since 1.0.0
     */
    virtual CardTransactionManager&
    prepareApdu(const std::string& apduCommand)
        = 0;

    /**
     * Prepares an APDU to be transmitted the next time
     * processCommands(keypop::reader::ChannelControl) is invoked.
     *
     * @param apduCommand A not empty byte arrays containing raw APDU
     * commands.
     * @return This instance.
     * @since 1.0.0
     */
    virtual CardTransactionManager&
    prepareApdu(const std::vector<std::uint8_t>& apduCommand)
        = 0;

    /**
     * Prepares an APDU to be transmitted the next time
     * processCommands(keypop::reader::ChannelControl) is invoked.
     *
     * @param cla The class byte.
     * @param ins The instruction byte.
     * @param p1 The P1 parameter.
     * @param p2 The P2 parameter.
     * @param dataIn The APDU data, empty if there is no data.
     * @param le The expected output length, 0 if the output length is
     * unspecified..
     * @return This instance.
     * @since 1.0.0
     */
    virtual CardTransactionManager& prepareApdu(
        const std::uint8_t cla,
        const std::uint8_t ins,
        const std::uint8_t p1,
        const std::uint8_t p2,
        const std::vector<std::uint8_t>& dataIn,
        const std::uint8_t le)
        = 0;

    /**
     * Prepares an APDU to be transmitted the next time
     * processCommands(keypop::reader::ChannelControl) is invoked.
     *
     * @param cla The class byte.
     * @param ins The instruction byte.
     * @param p1 The P1 parameter.
     * @param p2 The P2 parameter.
     * @param dataIn The APDU data, empty if there is no data.
     * @return This instance.
     * @since 1.0.0
     */
    virtual CardTransactionManager& prepareApdu(
        const std::uint8_t cla,
        const std::uint8_t ins,
        const std::uint8_t p1,
        const std::uint8_t p2,
        const std::vector<std::uint8_t>& dataIn)
        = 0;

    /**
     * Returns the list of responses corresponding to the commands executed by
     * the last call to
     * processCommands(keypop::reader::ChannelControl), represented as byte
     * arrays.
     *
     * <p>Each element in the returned list represents the response of one
     * command, in the same order as the commands were prepared. The returned
     * list is never null. <br>
     * This method does not alter the internal state of the manager: the list
     * of responses remains available for later calls until
     * processCommands(keypop::reader::ChannelControl) is invoked
     * again, at which point it is replaced by the new set of responses.
     *
     * @return A not-null list of byte arrays representing the command
     * responses, in the same order as the commands were sent.
     * @since 1.0.0
     */
    virtual const std::vector<std::vector<std::uint8_t>>
    getResponsesAsByteArrays()
        = 0;

    /**
     * Returns the list of responses corresponding to the commands executed by
     * the last call to
     * processCommands(keypop::reader::ChannelControl), represented as
     * hexadecimal strings.
     *
     * <p>Each element in the returned list represents the response of one
     * command, in the same order as the commands were prepared. The returned
     * list is never null. <br>
     * This method does not alter the internal state of the manager: the list
     * of responses remains available for later calls until
     * processCommands(keypop::reader::ChannelControl) is invoked
     * again, at which point it is replaced by the new set of responses.
     *
     * @return A not-null list of hexadecimal strings representing the command
     * responses, in the same order as the commands were sent.
     * @since 1.0.0
     */
    virtual const std::vector<std::string> getResponsesAsHexStrings() = 0;
};

} /* namespace genericcard */
} /* namespace keypop */
