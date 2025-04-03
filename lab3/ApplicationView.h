#ifndef KLAB3_APPLICATIONVIEW_H
#define KLAB3_APPLICATIONVIEW_H

#include "../../Classes/Application/Application.h"

namespace Prog3 {

    class ApplicationView {
    public:
        static void printMainMenu();
        static void printDescriptorMenu();
        static void getUserInput(std::shared_ptr<Descriptor>& element);
        static void getUserInput(std::string& userInput);
        static void getUserInput(std::shared_ptr<MemoryCell>& cell);
        static void getUserInput(std::shared_ptr<MemoryVector>& vector);
        static void getUserInput(std::shared_ptr<MemoryMatrix>& matrix);
        static void getUserInput(std::size_t& row, std::size_t& col);
        static void getUserInput(int& num);
    };

}
#endif //KLAB3_APPLICATIONVIEW_H
