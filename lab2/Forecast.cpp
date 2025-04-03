#include "Forecast.h"
#include "Weather.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

namespace Prog2 {

	Forecast::Forecast() {
		msize = 1;
		array = new Weather[msize];
		//array = nullptr;
		csize = 0;
	}

	Forecast::Forecast(Weather* arr, int number) {
		if (number < 0) {
			throw std::invalid_argument("invalid number");
		}
		msize = 1;
		csize = number;
		while (msize < csize) msize *= 2;
		array = new Weather [msize];
		if (arr != nullptr) for (auto i = 0; i < number; ++i) array[i] = arr[i];
		else array = nullptr;
	}

	Forecast::Forecast(Weather daily_forecats, int number) {
		if (number < 0) {
			throw std::invalid_argument("invalid number");
		}
		msize = 1;
		csize = number;
		while (msize < csize) msize *= 2;
		array = new Weather[msize];
		for (auto i = 0; i < number; ++i) array[i] = daily_forecats;
	}



	Forecast& Forecast::operator += (Weather& add) {
		if (csize == msize) {
			msize *= 2;
			Weather* new_arr = new Weather[msize];
			std::copy(array, array+csize, new_arr);
			delete[]array;
			array = new_arr;
		}
		++csize;
		array[csize - 1] = add;
		return *this;
	}

	Weather& Forecast::operator[] (int num) {
		if (num < 0 || num >= csize) {
			throw std::invalid_argument("invalid number");
		}
		return array[num];
	}

	Forecast& Forecast::del_by_idx(int num) {
		if (num < 0 || num >= csize) {
			throw std::invalid_argument("invalid number");
		}
		for (auto i = num; i < csize-1; ++i)
		{
			array[i] = array[i + 1];
		}
		--csize;
		return *this;
	}

	Weather& Forecast::find_coldest(Date begin, Date end) {
		Weather first, second;
		int min = 99999, num;
		first.setD(begin);
		second.setD(end);
		if (first == second || second < first) {
			throw std::invalid_argument("invalid dates");
		}
		for (auto i = 0; i < csize; ++i) {
			if (array[i] < second && first < array[i]) {
				if (array[i].medium_temp() <= min) {
					num = i;
					min = array[i].medium_temp();
				}
			}
		}
		return array[num];
	}

	int dif(Weather first, Weather sec) {
		int sum = (first.getD().year - sec.getD().year) * 365;
		sum += (first.getD().month - sec.getD().month) * 30;
		sum += first.getD().day - sec.getD().day;
		return sum;
	}

	Weather& Forecast::find_sunny_day(Date now) {
		Weather today;
		today.setD(now);
		int min = 99999, num = -1;
		for (auto i = 0; i < csize; ++i) {
			if (today < array[i] && array[i].getP() == sunny) {
				if (dif(array[i], today) <= min) {
					min = dif(array[i], today);
					num = i;
				}
			}
		}
		if (num == -1) {
			throw std::invalid_argument("no sunny days");
		}
		return array[num];
	}

	void Forecast::delete_all_mistaken() {
		for (auto i = 0; i < csize; ++i) {
			if (!array[i].check()) this->del_by_idx(i);
		}
	}

	void Forecast::unite_all() {
		for (auto i = 0; i < csize; ++i) {
			for (auto j = i+1; j < csize; ++j) {
				if (array[i] == array[j]) {
					array[i] += array[j];
					this->del_by_idx(j);
					j--;
				}
			}
		}
	}

	bool how_to_sort(Weather first, Weather second) {
		if (first == second) return true;
		else if (first < second) return true;
		else return false;
	}

	void Forecast::sort() {
		std::sort(array, array + csize, how_to_sort);
	}

	Forecast& Forecast::get_sorted_arr(Date begin, Date end) {
		Weather first, second;
		Forecast res;
		first.setD(begin);
		second.setD(end);
		if (first == second || second < first) {
			throw std::invalid_argument("invalid dates");
		}
		for (auto i = 0; i < csize; ++i) {
			if (array[i] < second && first < array[i]) {
				res += array[i];
			}
		}
		res.sort();
		std::cout << res << std::endl;
		return res;
	}

	int Forecast::get_csize() {
		return csize;
	}

	Forecast& Forecast::set_csize(int num) {
		this->csize = num;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, Forecast& forecast) {
		for (auto i = 0; i < forecast.csize; ++i)
			os << "#" << i+1 << ": " << forecast[i] << std::endl;
		return os;
	}

	Forecast::~Forecast() {
		delete[] array;
	}

	Forecast& Forecast::operator=(const Forecast& other) {
		Weather* res = new Weather[other.msize];
		delete[] array;
		std::copy(other.array, other.array + other.csize, res);
		array = res;
		csize = other.csize;
		msize = other.msize;
		return *this;
	}

	Forecast& Forecast::operator=(Forecast&& other) {
		delete[] array;
		csize = std::exchange(other.csize, 0);
		msize = std::exchange(other.msize, 0);
		array = std::exchange(other.array, nullptr);
		return *this;
	}
}