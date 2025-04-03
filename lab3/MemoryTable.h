#ifndef KLAB3_MEMORYTABLE_H
#define KLAB3_MEMORYTABLE_H

#include <iostream>
#include <map>
#include <algorithm>
#include <future>
#include <numeric>

#include "../MemoryCell/MemoryCell.h"
#include "../MemoryVector/MemoryVector.h"
#include "../MemoryMatrix/MemoryMatrix.h"

namespace Prog3 {

    /**
     * @brief Class representing a memory table to store descriptors.
     */
    class MemoryTable {
    private:
        std::map<std::string, std::shared_ptr<Descriptor>> table; /**< Map to store identifiers and corresponding descriptors. */

    public:
        /**
         * @brief Insert a new element into the memory table.
         * @param identifier The identifier of the element.
         * @param descriptor The descriptor associated with the element.
         */
        void insertElement(const std::string &identifier, std::shared_ptr<Descriptor> descriptor);

        /**
         * @brief Find an element in the memory table based on its identifier.
         * @param identifier The identifier of the element to find.
         * @return Shared pointer to the descriptor associated with the element, or nullptr if not found.
         */
        std::shared_ptr<Descriptor> findElement(const std::string &identifier) const;

        /**
         * @brief Remove an element from the memory table based on its identifier.
         * @param identifier The identifier of the element to remove.
         */
        void removeElement(const std::string &identifier);

        /**
         * @brief Show the contents of the memory table.
         */
        void showTable() const;

        /**
         * @brief Compute the total size of all descriptors in the memory table.
         * @return The total size of all descriptors in the memory table.
         */
        std::size_t computeTotalSize() const;
    };

}

#endif //KLAB3_MEMORYTABLE_H
