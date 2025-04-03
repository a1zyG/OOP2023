#include "MemoryMatrix.h"

namespace Prog3 {

    MemoryMatrix::MemoryMatrix(std::size_t rows, std::size_t cols) : Descriptor(true), rows(rows), cols(cols) {
        data = std::make_shared<std::vector<std::vector<std::shared_ptr<MemoryCell>>>>(rows, std::vector<std::shared_ptr<MemoryCell>>(cols, std::make_shared<MemoryCell>()));
    }

    MemoryMatrix::MemoryMatrix(MemoryMatrix&& other) noexcept : Descriptor(other.IsDefined), data(std::move(other.data)), rows(other.rows), cols(other.cols) {
        other.IsDefined = false;
        other.rows = 0;
        other.cols = 0;
    }

    MemoryMatrix& MemoryMatrix::operator=(MemoryMatrix&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
            rows = other.rows;
            cols = other.cols;
            IsDefined = other.IsDefined;
            other.IsDefined = false;
            other.rows = 0;
            other.cols = 0;
        }
        return *this;
    }

    Descriptor::DescriptorType MemoryMatrix::getType() const {
        return DescriptorType::MATRIX;
    }

    [[nodiscard]] std::size_t MemoryMatrix::getDescriptorSize() const {
        return rows * cols * sizeof(int);
    }

    std::string MemoryMatrix::getDescriptorInfo() const {
        std::stringstream ss;
        ss <<  "Memory Matrix: Rows - " + std::to_string(numRows()) + ", Cols - " + std::to_string(numCols()) +
               ", Defined - " + (getDefinition() ? "true\n" : "false\n");
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                ss << (*data)[i][j] -> getData() + ((*data)[i][j] -> getDefinition() ? "y " : "n ");
            }
            ss << std::endl;
        }
        return ss.str();
    }

    std::size_t MemoryMatrix::numRows() const {
        return rows;
    }

    std::size_t MemoryMatrix::numCols() const {
        return cols;
    }

    bool MemoryMatrix::getDefinition() const {
        if(data != nullptr) return checkDefined();
        else throw std::runtime_error("Matrix was moved");
    }

    bool MemoryMatrix::checkDefined() const {
        for (const auto& row : *data) {
            for (const auto& cell : row) {
                if (!cell->getDefinition()) {
                    return false;
                }
            }
        }
        return true;
    }

    void MemoryMatrix::setData(std::size_t row, std::size_t col, int num) {
        if (row >= 0 && row < numRows() && col >= 0 && col < numCols()) {
            (*data)[row][col]->setDefinition(true);
            (*data)[row][col]->setData(num);
            IsDefined = checkDefined();
        } else {
            throw std::invalid_argument("Invalid row or column index");
        }
    }

    int MemoryMatrix::getData(std::size_t row, std::size_t col) const {
        if (row >= 0 && row < numRows() && col >= 0 && col < numCols()) {
            return (*data)[row][col]->getData();
        }
        throw std::invalid_argument("Invalid row or column index");
    }

    std::shared_ptr<MemoryCell>& MemoryMatrix::operator()(std::size_t row, std::size_t col) {
        if (row >= 0 && row < numRows() && col >= 0 && col < numCols()) {
            return (*data)[row][col];
        }
        throw std::invalid_argument("Invalid row or column index");
    }

    const std::shared_ptr<MemoryCell>& MemoryMatrix::operator()(std::size_t row, std::size_t col) const {
        if (row >= 0 && row < numRows() && col >= 0 && col < numCols()) {
            return (*data)[row][col];
        }
        throw std::invalid_argument("Invalid row or column index");
    }

    void MemoryMatrix::setDefined(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                (*data)[i][j] -> setDefined();
            }
        }
        IsDefined = true;
    }
}