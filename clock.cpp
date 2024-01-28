#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;
using namespace chrono;
using namespace this_thread;
int main()
{
    time_t now = time(0);
    tm *currentTime = localtime(&now);
    int h = currentTime->tm_hour;
    int m = currentTime->tm_min;
    int s = currentTime->tm_sec;
    while (true)
    {
        cout << h << ":" << m << ":" << s << endl;
        sleep_for(seconds(1));
        s++;
        if (s == 60)
        {
            s = 0;
            m++;
            if (m == 60)
            {
                m = 0;
                h++;
                if (h == 24)
                {
                    h = 0;
                }
            }
        }
    }
    return 0;
}