#ifndef KLAB3_MEMORYCELL_H
#define KLAB3_MEMORYCELL_H

#include "../Descriptor/Descriptor.h"

namespace Prog3 {

    /**
     * @brief Class representing a memory cell.
     * @details Inherits from the Descriptor base class.
     */
    class MemoryCell : public Descriptor {
    private:
        int data; /**< Integer data stored in the memory cell. */

    public:
        /**
         * @brief Default constructor.
         */
        MemoryCell();

        /**
         * @brief Parameterized constructor with an integer value.
         * @param num The integer value to initialize the memory cell with.
         */
        explicit MemoryCell(int num);

        /**
         * @brief Parameterized constructor with an integer value and definition state.
         * @param num The integer value to initialize the memory cell with.
         * @param definition The definition state of the memory cell.
         */
        MemoryCell(int num, bool definition);

        /**
         * @brief Copy constructor.
         * @param other The MemoryCell object to be copied.
         */
        MemoryCell(const MemoryCell& other);

        /**
         * @brief Move constructor.
         * @param other The MemoryCell object to be moved.
         */
        MemoryCell(MemoryCell&& other) noexcept;

        /**
         * @brief Copy assignment operator.
         * @param other The MemoryCell object to be copied.
         * @return Reference to the assigned MemoryCell object.
         */
        MemoryCell& operator=(const MemoryCell& other);

        /**
         * @brief Move assignment operator.
         * @param other The MemoryCell object to be moved.
         * @return Reference to the assigned MemoryCell object.
         */
        MemoryCell& operator=(MemoryCell&& other) noexcept;

        /**
         * @brief Getter for the type of the descriptor.
         * @return The type of the descriptor (CELL).
         */
        [[nodiscard]] DescriptorType getType() const override;

        /**
         * @brief Getter for the information about the memory cell.
         * @return Information about the memory cell.
         */
        [[nodiscard]] std::string getDescriptorInfo() const override;

        /**
         * @brief Getter for the definition state of the memory cell.
         * @return True if the memory cell is defined, false otherwise.
         */
        [[nodiscard]] bool getDefinition() const;

        /**
         * @brief Getter for the data stored in the memory cell.
         * @return The integer data stored in the memory cell.
         */
        [[nodiscard]] int getData() const;

        /**
         * @brief Getter for the size of the memory cell descriptor.
         * @return The size of the memory cell descriptor.
         */
        [[nodiscard]] std::size_t getDescriptorSize() const override;

        /**
         * @brief Setter for the definition state of the memory cell.
         * @param defined The definition state to be set.
         */
        void setDefinition(bool defined);

        /**
         * @brief Setter for setting the memory cell as defined.
         * @details Overrides the setDefined method from the base class.
         */
        void setDefined() override;

        /**
         * @brief Method to change the definition state of the memory cell.
         */
        void changeDefinition();

        /**
         * @brief Setter for changing the data stored in the memory cell.
         * @param newData The new data to be set in the memory cell.
         */
        void setData(int newData);

    };

}

#endif //KLAB3_MEMORYCELL_H
