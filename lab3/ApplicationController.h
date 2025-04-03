#ifndef KLAB3_APPLICATIONCONTROLLER_H
#define KLAB3_APPLICATIONCONTROLLER_H

#include "../ApplicationModel/ApplicationModel.h"
#include "../ApplicationView/ApplicationView.h"

namespace Prog3 {

    class ApplicationController {
    private:
        ApplicationModel model;

    public:
        void handleMainMenu();
    };

}

#endif //KLAB3_APPLICATIONCONTROLLER_H
