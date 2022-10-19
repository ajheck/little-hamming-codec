/**
 * @file hamming.c
 * @author ajheck
 * @brief
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "hamming.h"

int8_t encoder_lut[] = {
    0b10001000, /* 0x88 */
    0b10000111, /* 0x87 */
    0b10111011, /* 0xBB */
    0b10110100, /* 0xB4 */
    0b11011101, /* 0xDD */
    0b11010010, /* 0xD2 */
    0b11101110, /* 0xEE */
    0b11100001, /* 0xE1 */
    0b00011110, /* 0x1E */
    0b00010001, /* 0x11 */
    0b00101101, /* 0x2D */
    0b00100010, /* 0x22 */
    0b01001011, /* 0x4B */
    0b01000100, /* 0x44 */
    0b01111000, /* 0x78 */
    0b01110111, /* 0x77 */
};

#define ENCODE_LOWER_NIBBLE(n) (encoder_lut[(n) & 0x0F])
#define ENCODE_UPPER_NIBBLE(n) (encoder_lut[((n) & 0xF0 ) >> 4 ])

inline uint8_t lhc_encode_nibble(uint8_t n)
{
    return ENCODE_LOWER_NIBBLE(n);
}

inline uint16_t lhc_encode_byte(uint8_t b)
{
    return ( ENCODE_UPPER_NIBBLE(b) << 8 ) | ENCODE_LOWER_NIBBLE(b);
}

int lhc_encode(const uint8_t data[], int data_len, uint8_t output[], int output_len)
{
    int i;
    int j;

    if ( NULL == data || NULL == output || data_len < 1 || output_len < 2 ) {
        return -1;
    }

    for(i = 0, j = -1; i < data_len && output_len > 0; ++i, output_len -= 2) {
        output[++j] = ENCODE_UPPER_NIBBLE(data[i]);
        output[++j] = ENCODE_LOWER_NIBBLE(data[i]);
    }

    return i;
}