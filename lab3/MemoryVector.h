#ifndef KLAB3_MEMOTYVECTOR_H
#define KLAB3_MEMOTYVECTOR_H

#include "../MemoryCell/MemoryCell.h"
#include <vector>
#include <memory>
#include <sstream>

namespace Prog3 {

    /**
     * @brief Class representing a memory vector.
     * @details Inherits from the Descriptor base class.
     */
    class MemoryVector : public Descriptor {
    private:
        std::shared_ptr<std::vector<std::shared_ptr<MemoryCell>>> data; /**< Shared pointer to a vector of shared pointers to MemoryCell objects. */
        std::size_t maxSize; /**< Maximum size of the memory vector. */

        /**
         * @brief Private method to check if all elements in the vector are defined.
         * @return True if all elements are defined, false otherwise.
         */
        [[nodiscard]] bool checkDefined() const;

    public:
        /**
         * @brief Explicit constructor with maximum size.
         * @param maxSize The maximum size of the memory vector.
         */
        explicit MemoryVector(int maxSize);

        /**
         * @brief Parameterized constructor with a memory cell and maximum size.
         * @param cell The memory cell to initialize the vector with.
         * @param maxSize The maximum size of the memory vector.
         */
        MemoryVector(std::shared_ptr<MemoryCell> cell, std::size_t maxSize);

        /**
         * @brief Deleted copy constructor.
         * @details Copy constructor is deleted to prevent unintended copying.
         */
        MemoryVector(const MemoryVector& other) = delete;

        /**
         * @brief Move constructor.
         * @param other The MemoryVector object to be moved.
         */
        MemoryVector(MemoryVector&& other) noexcept;

        /**
         * @brief Deleted copy assignment operator.
         * @details Copy assignment operator is deleted to prevent unintended copying.
         */
        MemoryVector& operator=(const MemoryVector& other) = delete;

        /**
         * @brief Move assignment operator.
         * @param other The MemoryVector object to be moved.
         * @return Reference to the assigned MemoryVector object.
         */
        MemoryVector& operator=(MemoryVector&& other) noexcept;

        /**
         * @brief Getter for the type of the descriptor.
         * @return The type of the descriptor (VECTOR).
         */
        [[nodiscard]] DescriptorType getType() const override;

        /**
         * @brief Getter for the information about the memory vector.
         * @return Information about the memory vector.
         */
        [[nodiscard]] std::string getDescriptorInfo() const override;

        /**
         * @brief Getter for the size of the memory vector.
         * @return The size of the memory vector.
         */
        [[nodiscard]] std::size_t size() const;

        /**
         * @brief Getter for the maximum size of the memory vector.
         * @return The maximum size of the memory vector.
         */
        [[nodiscard]] std::size_t getMaxSize() const;

        /**
         * @brief Getter for the definition state of the memory vector.
         * @return True if the memory vector is defined, false otherwise.
         */
        [[nodiscard]] bool getDefinition() const;

        /**
         * @brief Getter for the size of the memory vector descriptor.
         * @return The size of the memory vector descriptor.
         */
        [[nodiscard]] std::size_t getDescriptorSize() const override;

        /**
         * @brief Setter for setting the maximum size of the memory vector.
         */
        void setMaxSize();

        /**
         * @brief Setter for changing the definition state of a specified element in the vector.
         * @param index The index of the element to set as defined.
         */
        void setData(int index);

        /**
         * @brief Setter for setting the memory vector as defined.
         */
        void setDefined() override;

        /**
         * @brief Method to add a memory cell to the end of the vector.
         * @param cell The memory cell to be added.
         */
        void push_back(std::shared_ptr<MemoryCell> cell);

        /**
         * @brief Getter for the data stored in a specified element of the vector.
         * @param index The index of the element to retrieve the data from.
         * @return The data stored in the specified element.
         */
        [[nodiscard]] int getData(int index) const;

        /**
         * @brief Overloaded subscript operator to access a specified element in the vector.
         * @param i The index of the element to access.
         * @return Reference to the specified element.
         */
        [[nodiscard]] std::shared_ptr<MemoryCell>& operator[](int i);

        /**
         * @brief Overloaded const subscript operator to access a specified element in the vector.
         * @param i The index of the element to access.
         * @return Const reference to the specified element.
         */
        [[nodiscard]] const std::shared_ptr<MemoryCell>& operator[](int i) const;

    };

}

#endif //KLAB3_MEMOTYVECTOR_H
