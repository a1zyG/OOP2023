#ifndef KLAB3_DESCRIPTOR_H
#define KLAB3_DESCRIPTOR_H

#include<iostream>

namespace Prog3 {

    /**
     * @brief Base class for descriptors of variables, vectors, and matrices.
     */
    class Descriptor {
    public:
        /**
         * @brief Enumeration of descriptor types.
         */
        enum class DescriptorType {
            CELL,    /**< Descriptor for a simple variable. */
            VECTOR,  /**< Descriptor for a vector. */
            MATRIX   /**< Descriptor for a matrix. */
        };

        /**
         * @brief Virtual method to get the type of the descriptor.
         * @return The type of the descriptor.
         */
        [[nodiscard]] virtual DescriptorType getType() const = 0;

        /**
         * @brief Virtual method to get information about the descriptor.
         * @return Information about the descriptor.
         */
        [[nodiscard]] virtual std::string getDescriptorInfo() const = 0;

        /**
         * @brief Virtual method to get the size of the descriptor.
         * @return The size of the descriptor.
         */
        [[nodiscard]] virtual std::size_t getDescriptorSize() const = 0;

        /**
         * @brief Virtual method to set the defined state of the descriptor.
         */
        virtual void setDefined() = 0;

        /**
         * @brief Default constructor.
         */
        Descriptor() : IsDefined(false) {};

        /**
         * @brief Constructor with a definition parameter.
         * @param definition The definition state of the descriptor.
         */
        Descriptor(bool definition) : IsDefined(definition) {};

    protected:
        bool IsDefined;  /**< The definition state of the descriptor. */
    };

}

#endif //KLAB3_DESCRIPTOR_H
