//
// Created by sen on 11/9/20.
//

#include <sys/time.h>
#include <iostream>

double get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
}

int main() {
    double start_time = get_current_time();
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 100000; ++j) {
        }
    }
    std::cout << "Time:" << get_current_time() - start_time << "ms" << std::endl;
    return 0;
}