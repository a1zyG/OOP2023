#include "Weather.h"
#include <stdexcept>
#include <iostream>

using namespace std;
namespace Prog2 {
    Weather::Weather(Date _date, int _temp_morning, int _temp_day, int _temp_evening, Phenom _phenom, int _osadki)
    {
        date = _date;
        if (date.year <= 0 || date.month <= 0 || date.month > 12 || date.day <= 0 || date.day >= 31) {
            throw invalid_argument("invalid date");
        }
        temp_morning = _temp_morning;
        if (temp_morning < -273)
            throw invalid_argument("invalid temperature");
        temp_day = _temp_day;
        if (temp_day < -273)
            throw invalid_argument("invalid temperature");
        temp_evening = _temp_evening;
        if (temp_evening < -273)
            throw invalid_argument("invalid temperature");
        phenom = _phenom;
        osadki = _osadki;
        if (osadki > 1500)
            throw invalid_argument("invalid value of osadki");
    }
    Weather::Weather(Date _date, int _temp, int _osadki)
    {
        date = _date;
        temp_morning = _temp;
        temp_evening = _temp;
        temp_day = _temp;
        osadki = _osadki;
        if ((date.month == 1 || date.month == 2 || date.month == 12) && osadki > 0 && _temp < 0)
            phenom = Phenom::snowy;
        if (osadki == 0) {
            if (date.month == 9 || date.month == 10 || date.month == 11)
                phenom = Phenom::cloudy;
            else
                phenom = Phenom::sunny;
        }
        if ((date.month != 1 || date.month != 2 || date.month != 12) && osadki > 0 && _temp > 0)
            phenom = Phenom::rainy;
    }

    Weather::Weather() {
        date.day = 1;
        date.month = 1;
        date.year = 1;
        temp_morning = 0;
        temp_evening = 0;
        temp_day = 0;
        osadki = 0;
        phenom = sunny;
    }

    Date Weather::getD() {
        return date;
    }
    Phenom Weather::getP() {
        return phenom;
    }
    int Weather::getT_morning() {

        return temp_morning;
    }
    int Weather::getT_day() {

        return temp_day;
    }
    int Weather::getT_evening() {

        return temp_evening;
    }
    int Weather::getO() {

        return osadki;
    }

    Weather& Weather::setD(Date _date) {
        this->date = _date;
        return *this;
    }
    Weather& Weather::setP(Phenom _phenom) {
        this->phenom = _phenom;
        return *this;
    }
    Weather& Weather::setT_morning(int _temp_morning) {
        this->temp_morning = _temp_morning;
        return *this;
    }
    Weather& Weather::setT_day(int _temp_day) {
        this->temp_day = _temp_day;
        return *this;
    }
    Weather& Weather::setT_evening(int _temp_evening) {
        this->temp_evening = _temp_evening;
        return *this;
    }
    Weather& Weather::setO(int _osadki) {
        this->osadki = _osadki;
        return *this;
    }

    int Weather::medium_temp() {
        return (temp_morning + temp_day + temp_evening) / 3;

    }

    bool Weather::check() {
        if ((phenom == Phenom::sunny || phenom == Phenom::cloudy) && osadki != 0)
            return false;
        if ((temp_morning > 0 || temp_day > 0 || temp_evening > 0) && phenom == Phenom::snowy)
            return false;
        if (temp_morning > 60 || temp_day > 60 || temp_evening > 60 || temp_morning < -100 || temp_day < -100 || temp_evening < -100)
            return false;
        return true;
    }
    bool Weather::operator ==(const Weather& w) {
        if (date.year == w.date.year && date.month == w.date.month && date.day == w.date.day)
            return true;
        else return false;
    }

    bool Weather::operator <(const Weather& w) {
        if (w.date.year < date.year)
            return false;
        else if (w.date.year == date.year) {
            if (w.date.month < date.month)
                return false;
            else if (w.date.month == date.month) {
                if (w.date.day < date.day)
                    return false;
                else
                    return true;

            }
            else
                return true;
        }
        else
            return true;
    }

    Weather& Weather::operator += (Weather& add) {
        setO((add.osadki + osadki) / 2);
        setT_day((add.temp_day + temp_day) / 2);
        setT_evening((add.temp_evening + temp_evening) / 2);
        setT_morning((add.temp_morning + temp_morning) / 2);
        if (phenom == sunny) setP(add.phenom);
        else if (phenom == cloudy && add.phenom != sunny) setP(add.phenom);
        else if (phenom == rainy && add.phenom == snowy) setP(add.phenom);
        return *this;
    }

    std::istream& operator>>(std::istream& is, Weather& qur) {
        int mor, day1, eve, osad, day2, mon, year, phenom;
        is >> day2 >> mon >> year >> mor >> day1 >> eve >> osad >> phenom;
        if (osad >= 0 && day2 >= 1 && day2 <= 31 && mon <= 12 && mon >= 1 && year >= 0 && phenom <= 4 && phenom > 0) {
            Date q;
            q.day = day2;
            q.month = mon;
            q.year = year;
            qur.setD(q);
            qur.setT_morning(mor);
            qur.setT_day(day1);
            qur.setT_evening(eve);
            qur.setO(osad);
            qur.setP((Phenom)phenom);
        }
        else {
            throw invalid_argument("invalid arguments");
        }
        return is;
    }

    std::ostream& operator<<(std::ostream& os, const Weather& qur) {
        os << qur.date.day << " " << qur.date.month << " " << qur.date.year << " " << qur.temp_morning << " " << 
            qur.temp_day << " " << qur.temp_evening << " " << qur.osadki << " " << qur.phenom;
        return os;
    }

    void Weather::print() {
        cout << "data: " << date.year << "." << date.month << "." << date.day << endl;
        cout << "temp_morning =" << temp_morning << " " << "day temperature =" << temp_day << " " << "evening temperature =" << temp_evening << endl;
        cout << "osadki = " << osadki << endl;
        cout << "phenom = " << phenom << endl;
        cout << endl;

    }

}