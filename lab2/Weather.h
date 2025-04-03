
#pragma once
#include <string>
#include <cmath>

namespace Prog2 {
    struct Date {
        int year;
        int month;
        int day;
    };
    enum Phenom
    {
        sunny=1, cloudy=2, rainy=3, snowy=4
    };
    class Weather {
    private:
        Date date;
        int temp_morning;
        int temp_day;
        int temp_evening;
        Phenom phenom;
        int osadki;
    public:
        Weather(Date date, int temp_morning, int temp_day, int temp_evening, Phenom phenom, int osadki);
        Weather(Date date, int temp, int osadki);
        Weather();
        // сеттеры (setter)
        Weather& setD(Date date);
        Weather& setT_morning(int temp_morning);
        Weather& setT_day(int temp_day);
        Weather& setT_evening(int temp_evening);
        Weather& setP(Phenom phenom);
        Weather& setO(int osadki);

        Date getD();
        Phenom getP();
        int getT_morning();
        int getT_day();
        int getT_evening();
        int getO();

        void print();
        bool operator == (const Weather&);
        bool operator < (const Weather&);
        Weather& operator += (Weather& add);
        friend std::ostream& operator << (std::ostream& os, const Weather& qur);
        friend std::istream& operator>>(std::istream& is, Weather& qur);

        int medium_temp();
        bool check();
    };
}
