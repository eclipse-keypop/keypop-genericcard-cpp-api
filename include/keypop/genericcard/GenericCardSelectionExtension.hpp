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

#include "keypop/reader/selection/spi/CardSelectionExtension.hpp"

namespace keypop {
namespace genericcard {

using keypop::reader::selection::spi::CardSelectionExtension;

/**
 * Extends the CardSelectionExtension interface of the "Keypop Reader
 * API" to provide means to add successful status word.
 *
 * @since 1.0.0
 */
class GenericCardSelectionExtension : public CardSelectionExtension {
public:
    /**
     * Adds a status word to the list of those that should be considered
     * successful for the Select Application APDU.
     *
     * <p>Note: initially, the list contains the standard successful status
     * word 9000h.
     *
     * @param statusWord A positive int &le;  FFFFh.
     * @return The current instance.
     * @since 1.0.0
     */
    virtual GenericCardSelectionExtension&
    addSuccessfulStatusWord(int statusWord)
        = 0;
};

} /* namespace genericcard */
} /* namespace keypop */
