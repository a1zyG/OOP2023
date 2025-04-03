#ifndef KLAB3_MEMORYMATRIX_H
#define KLAB3_MEMORYMATRIX_H

#include "../MemoryCell/MemoryCell.h"
#include <vector>
#include <memory>
#include <sstream>

namespace Prog3 {

    /**
     * @brief Class representing a memory matrix.
     * @details Inherits from the Descriptor base class.
     */
    class MemoryMatrix : public Descriptor {
    private:
        std::shared_ptr<std::vector<std::vector<std::shared_ptr<MemoryCell>>>> data; /**< Shared pointer to a vector of vectors of shared pointers to MemoryCell objects. */
        std::size_t rows; /**< Number of rows in the memory matrix. */
        std::size_t cols; /**< Number of columns in the memory matrix. */

        /**
         * @brief Private method to check if all elements in the matrix are defined.
         * @return True if all elements are defined, false otherwise.
         */
        [[nodiscard]] bool checkDefined() const;

    public:
        /**
         * @brief Constructor with specified number of rows and columns.
         * @param rows Number of rows in the memory matrix.
         * @param cols Number of columns in the memory matrix.
         */
        MemoryMatrix(std::size_t rows, std::size_t cols);

        /**
         * @brief Deleted copy constructor.
         * @details Copy constructor is deleted to prevent unintended copying.
         */
        MemoryMatrix(const MemoryMatrix& other) = delete;

        /**
         * @brief Move constructor.
         * @param other The MemoryMatrix object to be moved.
         */
        MemoryMatrix(MemoryMatrix&& other) noexcept;

        /**
         * @brief Deleted copy assignment operator.
         * @details Copy assignment operator is deleted to prevent unintended copying.
         */
        MemoryMatrix& operator=(const MemoryMatrix& other) = delete;

        /**
         * @brief Move assignment operator.
         * @param other The MemoryMatrix object to be moved.
         * @return Reference to the assigned MemoryMatrix object.
         */
        MemoryMatrix& operator=(MemoryMatrix&& other) noexcept;

        /**
         * @brief Getter for the type of the descriptor.
         * @return The type of the descriptor (MATRIX).
         */
        [[nodiscard]] DescriptorType getType() const override;

        /**
         * @brief Getter for the information about the memory matrix.
         * @return Information about the memory matrix.
         */
        [[nodiscard]] std::string getDescriptorInfo() const override;

        /**
         * @brief Getter for the number of rows in the memory matrix.
         * @return The number of rows in the memory matrix.
         */
        [[nodiscard]] std::size_t numRows() const;

        /**
         * @brief Getter for the number of columns in the memory matrix.
         * @return The number of columns in the memory matrix.
         */
        [[nodiscard]] std::size_t numCols() const;

        /**
         * @brief Getter for the definition state of the memory matrix.
         * @return True if the memory matrix is defined, false otherwise.
         */
        [[nodiscard]] bool getDefinition() const;

        /**
         * @brief Getter for the size of the memory matrix descriptor.
         * @return The size of the memory matrix descriptor.
         */
        [[nodiscard]] std::size_t getDescriptorSize() const override;

        /**
         * @brief Setter for setting the memory matrix as defined.
         */
        void setDefined() override;

        /**
         * @brief Setter for changing the definition state of a specified element in the matrix.
         * @param row The row index of the element to set as defined.
         * @param col The column index of the element to set as defined.
         */
        void setData(std::size_t row, std::size_t col, int num);

        /**
         * @brief Getter for the data stored in a specified element of the matrix.
         * @param row The row index of the element to retrieve the data from.
         * @param col The column index of the element to retrieve the data from.
         * @return The data stored in the specified element.
         */
        [[nodiscard]] int getData(std::size_t row, std::size_t col) const;

        /**
         * @brief Overloaded function call operator to access a specified element in the matrix.
         * @param row The row index of the element to access.
         * @param col The column index of the element to access.
         * @return Reference to the specified element.
         */
        [[nodiscard]] std::shared_ptr<MemoryCell>& operator()(std::size_t row, std::size_t col);

        /**
         * @brief Overloaded const function call operator to access a specified element in the matrix.
         * @param row The row index of the element to access.
         * @param col The column index of the element to access.
         * @return Const reference to the specified element.
         */
        [[nodiscard]] const std::shared_ptr<MemoryCell>& operator()(std::size_t row, std::size_t col) const;

    };

}

#endif //KLAB3_MEMORYMATRIX_H
