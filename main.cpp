#include <iostream>
#include "Forecast.h"
#include "Weather.h"
#include <string>
#include <time.h>
#include <format>
#include <vector>
#include "dialog.h"

using namespace Prog2;

int main() {
    int param;
    Forecast full;
    Weather daily;
    while (1) {
        std::cout << "1. Add daily forecast\n2. Delete daily forecast\n3. Find coldest daily forecast\n4. Find sunny daily forecast\n5. Delete all daily forecasts with mistake\n6. Unite daily forecasts\n7. Sort\n8. Sort the chosen period\n9. Output\n0. End prog\n"
            << std::endl;
        param = getNum<int>(0, 9);
        switch (param) {
        case 1:
            d_add(full, daily);
            break;
        case 2:
            d_del(full);
            break;
        case 3:
            d_coldest(full, daily);
            break;
        case 4:
            d_sunny(full, daily);
            break;
        case 5:
            if (full.get_csize() == 0) break;
            full.delete_all_mistaken();
            break;
        case 6:
            if (full.get_csize() == 0) break;
            full.unite_all();
            break;
        case 7:
            if (full.get_csize() == 0) break;
            full.sort();
            break;
        case 8:
            d_sort(full);
            break;
        case 9:
            std::cout << full << std::endl;
            break;
        case 0:
            return 0;
        default:
            if (std::cin.eof()) {
                return 0;
            }
            std::cout << "Wrong option" << std::endl;
            break;
        }
    }
    return 0;
}
