#include <iostream>
#include <ctime>

using namespace std;

int daysBetweenDates(const string& date1, const string& date2) {
    tm tm1 = {}, tm2 = {};
    strptime(date1.c_str(), "%Y-%m-%d", &tm1);
    strptime(date2.c_str(), "%Y-%m-%d", &tm2);

    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);

    const int secondsPerDay = 60 * 60 * 24;
    return difftime(time2, time1) / secondsPerDay;
}

int main() {
    string date1 = "2023-08-01";
    string date2 = "2024-08-01";
    cout << "Days between dates: " << daysBetweenDates(date1, date2) << endl;
    return 0;
}
