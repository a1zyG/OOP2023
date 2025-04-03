#pragma once
#include "Forecast.h"
#include "Weather.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace Prog2;

template<class T>
T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
    T a;
    while (true) {
        std::cin >> a;
        if (std::cin.eof())
            throw std::runtime_error("Failed to read number: EOF");
        else if (std::cin.bad()) 
            throw std::runtime_error("Failed to read number: ");
        else if (std::cin.fail() || a < min || a > max) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You are wrong; repeat please!" << std::endl;
        }
        else 
            return a;
    }
}

void d_add(Forecast& full, Weather& daily) {
    std::cout << "Enter date, 3 temperatures, osadki, phenom: ";
    try {
        std::cin >> daily;
        full += (daily);
    }
    catch (...) {
        std::cout << "You entered invalid arguments" << std::endl;
    }
}

void d_del(Forecast& full) {
    if (full.get_csize() == 0) {
        std::cout << "No elements" << std::endl;
        return;
    }
    std::cout << "Enter element's index: ";
    int i = getNum<int>(0, full.get_csize() - 1);
    full.del_by_idx(i);
}

void d_coldest(Forecast& full, Weather& daily) {
    if (full.get_csize() == 0) {
        std::cout << "No elements" << std::endl;
        return;
    }
    Date first, sec;
    std::cout << "Enter the period: ";
    first.day = getNum<int>(1, 31);
    first.month = getNum<int>(1, 12);
    first.year = getNum<int>(1);
    sec.day = getNum<int>(1, 31);
    sec.month = getNum<int>(1, 12);
    sec.year = getNum<int>(1);
    daily = full.find_coldest(first, sec);
    std::cout << "Result: " << std::endl;
    std::cout << daily << std::endl;
}

void d_sunny(Forecast& full, Weather& daily) {
    if (full.get_csize() == 0) {
        std::cout << "No elements" << std::endl;
        return;
    }
    Date first;
    std::cout << "Enter today's date: ";
    first.day = getNum<int>(1, 31);
    first.month = getNum<int>(1, 12);
    first.year = getNum<int>(1);
    try {
        daily = full.find_sunny_day(first);
    }
    catch (...) {
        std::cout << "No sunny days" << std::endl;
        return;
    }
    std::cout << "Result: " << std::endl;
    std::cout << daily << std::endl;
}

void d_sort(Forecast& full) {
    if (full.get_csize() == 0) {
        std::cout << "No elements" << std::endl;
        return;
    }
    Date first, sec;
    std::cout << "Enter the period: ";
    first.day = getNum<int>(1, 31);
    first.month = getNum<int>(1, 12);
    first.year = getNum<int>(1);
    sec.day = getNum<int>(1, 31);
    sec.month = getNum<int>(1, 12);
    sec.year = getNum<int>(1);
    full.get_sorted_arr(first, sec);
}