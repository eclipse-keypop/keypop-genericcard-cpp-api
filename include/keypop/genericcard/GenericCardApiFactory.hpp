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

#include <memory>

#include "keypop/genericcard/CardTransactionManager.hpp"
#include "keypop/genericcard/GenericCardSelectionExtension.hpp"
#include "keypop/reader/CardReader.hpp"
#include "keypop/reader/selection/spi/SmartCard.hpp"

namespace keypop {
namespace genericcard {

using keypop::reader::CardReader;
using keypop::reader::selection::spi::SmartCard;

/**
 * Generic Card API Factory.
 *
 * @since 1.0.0
 */
class GenericCardApiFactory {
public:
    /**
     *
     */
    virtual ~GenericCardApiFactory() = default;

    /**
     * Creates a new instance of GenericCardSelectionExtension.
     *
     * @return A not null reference
     * @since 1.0.0
     */
    virtual std::unique_ptr<GenericCardSelectionExtension>
    createGenericCardSelectionExtension()
        = 0;

    /**
     * Creates an instance of CardTransactionManager.
     *
     * @param reader The reader through which the card communicates.
     * @param card The initial card data provided by the selection process.
     * @return A not null reference.
     * @since 1.0.0
     */
    virtual std::unique_ptr<CardTransactionManager> createCardTransaction(
        const std::shared_ptr<CardReader>& reader,
        const std::shared_ptr<SmartCard>& card)
        = 0;
};

} /* namespace genericcard */
} /* namespace keypop */
