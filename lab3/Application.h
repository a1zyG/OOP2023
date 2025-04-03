#ifndef KLAB3_APPLICATION_H
#define KLAB3_APPLICATION_H

#include <future>
#include <numeric>
#include <iostream>
#include "../MemoryTable/MemoryTable.h"

namespace Prog3 {

    /**
     * @brief Class representing an application with memory management functionality.
     */
    class Application {
    private:
        MemoryTable memoryTable; /**< Memory table to store descriptors. */

    public:
        /**
         * @brief Insert a new identifier into the memory table.
         * @param identifier The identifier to be inserted.
         */
        void insertIdentifier(const std::string &identifier);

        /**
         * @brief Insert a new memory cell into the vector in memory table.
         * @param  The identifier to be inserted.
         */
        void insertCellInVector(const std::string& identifier, std::shared_ptr<MemoryCell> cell);

        /**
         * @brief Insert a new memory cell into the matrix in memory table.
         * @param  The identifier to be inserted.
         */
        void insertCellInMatrix(const std::string& identifier, std::size_t row, std::size_t col, int data);

        /**
         * @brief Insert a new descriptor into the memory table.
         * @param identifier The identifier associated with the descriptor.
         * @param element The descriptor to be inserted.
         */
        void insertDescriptor(const std::string &identifier, std::shared_ptr<Descriptor> element);

        /**
         * @brief Define a variable by marking it as defined in the memory table.
         * @param identifier The identifier of the variable to be defined.
         */
        void defineVariable(const std::string &identifier);

        /**
         * @brief Exclude a variable from the memory table.
         * @param identifier The identifier of the variable to be excluded.
         */
        void excludeVariable(const std::string &identifier);

        /**
         * @brief Show short information about all identifiers in the memory table.
         */
        void showShortInfo() const;

        /**
         * @brief Compute the total size of all descriptors in the memory table.
         * @return The total size of all descriptors in the memory table.
         */
        [[nodiscard]] std::size_t computeTotalSize() const;
    };

}

#endif //KLAB3_APPLICATION_H