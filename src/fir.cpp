#include "./fir.h"

void fir(data_t *y, data_t x, coef_t *c, data_t shift_reg[N])
{
#pragma HLS PIPELINE II=1
    acc_t acc = 0;
    shift_reg[0] = x;

    for (int i = N - 1; i > 0; i--)
    {
#pragma HLS UNROLL
        shift_reg[i] = shift_reg[i - 1];
        acc += shift_reg[i] * c[i];
    }

    *y = acc + x * c[0];
}

void fir_wrap(data_t *y, data_t *x, int len, coef_t *coef)
{
#pragma HLS INTERFACE m_axi port=coef offset=slave depth=99
#pragma HLS INTERFACE m_axi port=x offset=slave depth=100
#pragma HLS INTERFACE m_axi port=y offset=slave depth=100
#pragma HLS INTERFACE s_axilite port=len  bundle=CTRL
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL

    coef_t c[N];
    data_t shift_reg[N];

    for (int i = 0; i < N; i++)
    {
#pragma HLS PIPELINE II=1
        c[i] = coef[i];
    }

    for (int i = 0; i < len; i++)
    {
#pragma HLS PIPELINE II=1
        fir(&y[i], x[i], c, shift_reg);
    }
}
