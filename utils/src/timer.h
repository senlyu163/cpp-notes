//
// Created by sen on 11/10/20.
//

#ifndef CPP_NOTES_TIMER_H
#define CPP_NOTES_TIMER_H

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <sys/time.h>
#endif

#include <chrono>
#include <stdio.h>

// get now timestamp in ms
#ifdef _WIN32
double get_current_time() {
    LARGE_INTEGER freq;
    LARGE_INTEGER pc;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&pc);

    return pc.QuadPart * 1000.0 / freq.QuadPart;
}
#else
double get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, nullptr);

    return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
}
#endif

class TimeCounter {
public:
    using microseconds = std::chrono::microseconds;
    using system_clock = std::chrono::system_clock;
    using time_point = decltype(system_clock::now());

    TimeCounter () {
        m_start = system_clock::now();
    }

    ~TimeCounter() {
        m_end = system_clock::now();
        m_duration = std::chrono::duration_cast<microseconds>(m_end - m_start);

        float time = m_duration.count() / 1000.0;
        printf("Duration: %.3lf ms\n", time);
    }

private:
    time_point m_start;
    time_point m_end;
    microseconds m_duration;
};


#endif //CPP_NOTES_TIMER_H
