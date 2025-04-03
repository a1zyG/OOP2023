#pragma once

#include <string>
#include <cmath>
#include "Weather.h"

namespace Prog2 {
	class Forecast {
	private:
		Weather* array;
		int csize;
		int msize;
	public:
		Forecast();
		Forecast(Weather* arr, int number);
		Forecast(Weather daily_forecats, int number);
		Forecast& operator += (Weather& add);
		Weather& operator[] (int num);
		Forecast& del_by_idx(int num);
		Weather& find_coldest(Date begin, Date end);
		Weather& find_sunny_day(Date now);
		void delete_all_mistaken();
		void unite_all();
		void sort();
		Forecast& get_sorted_arr(Date begin, Date end);
		int get_csize();
		Forecast& set_csize(int num);
		~Forecast();
		Forecast& operator=(Forecast&& other);
		Forecast& operator=(const Forecast& other);

		friend std::ostream& operator<<(std::ostream& os, Forecast& forecast);
	};



}