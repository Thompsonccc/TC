#include <iostream>
#include "./fir.h"

#define M 100

int main()
{
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Test started." << std::endl;

    data_t impulse[M] = {1, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    coef_t coefficient[N] =
        {-13, -6, 1, 9, 18, 26, 30, 29, 23,
         10, -8, -32, -55, -75, -86, -82, -62, -25,
         26, 84, 140, 182, 200, 183, 129, 40, -75,
         -202, -317, -398, -424, -377, -254, -58, 187, 452,
         693, 863, 915, 812, 532, 69, -558, -1309, -2128,
         -2942, -3676, -4261, -4637, 32767, -4637, -4261, -3676, -2942,
         -2128, -1309, -558, 69, 532, 812, 915, 863, 693,
         452, 187, -58, -254, -377, -424, -398, -317, -202,
         -75, 40, 129, 183, 200, 182, 140, 84, 26,
         -25, -62, -82, -86, -75, -55, -32, -8, 10,
         23, 29, 30, 26, 18, 9, 1, -6, -13};

    data_t ground_truth[M] =
        {-13, -6, 1, 9, 18, 26, 30, 29, 23,
         10, -8, -32, -55, -75, -86, -82, -62, -25,
         26, 84, 140, 182, 200, 183, 129, 40, -75,
         -202, -317, -398, -424, -377, -254, -58, 187, 452,
         693, 863, 915, 812, 532, 69, -558, -1309, -2128,
         -2942, -3676, -4261, -4637, 32767, -4637, -4261, -3676, -2942,
         -2128, -1309, -558, 69, 532, 812, 915, 863, 693,
         452, 187, -58, -254, -377, -424, -398, -317, -202,
         -75, 40, 129, 183, 200, 182, 140, 84, 26,
         -25, -62, -82, -86, -75, -55, -32, -8, 10,
         23, 29, 30, 26, 18, 9, 1, -6, -13, -13};

    data_t result[M];

    fir_wrap(result, impulse, M, coefficient);

    for (int i = 0; i < M; i++)
    {
        std::cout << result[i] << std::endl;
        if (result[i] != ground_truth[i])
        {
            std::cout << "Test failed." << std::endl;
            return -1;
        }
    }

    std::cout << "Test passed." << std::endl;
    std::cout << "Test finished." << std::endl;
    std::cout << "-------------------------------" << std::endl;

    return 0;
}
