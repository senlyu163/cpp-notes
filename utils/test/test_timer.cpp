//
// Created by sen on 11/10/20.
//
#include "../src/timer.h"

#include <thread>

int main () {
    double time_start = get_current_time();
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    double time_end = get_current_time();
    printf("Duration: %.3lf ms\n", time_end - time_start);

    {
        TimeCounter tc;
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
    }

    return 0;
}
