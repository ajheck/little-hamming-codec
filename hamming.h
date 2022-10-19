/**
 * @file hamming.h
 * @author ajheck
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef HAMMING_H
#define HAMMING_H

#include <stdint.h>

/**
 * @brief Encode the lower 4 bits of a byte
 * 
 * @param n the nibble to be encoded
 * @return uint8_t the encoded value
 */
uint8_t lhc_encode_nibble(uint8_t n);

/**
 * @brief Encode one byte into 16 bits
 * 
 * @param b the byte to be encoded
 * @return uint16_t the encoded value; bits 0-7 encode the lower half of b, and bits 8-15 encode the upper half
 */
uint16_t lhc_encode_byte(uint8_t b);

/**
 * @brief Encode a buffer of data
 * 
 * @param data The data to be encoded
 * @param data_len The length of data in bytes
 * @param output The output buffer to write the encoded data
 * @param output_len The length of output in bytes; must be at least 2
 * @return int -1 on invalid param; otherwise the number of bytes encoded from data, which is also half the length of the encoded data in output
 */
int lhc_encode(const uint8_t data[], int data_len, uint8_t output[], int output_len);

#endif