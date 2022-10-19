/**
 * @file demo.c
 * @author ajheck
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>

#include "hamming.h"

int main(void) {
    char str[1024];
    char encoded_data[2048];
    int i;
    int len;
    
    printf("Enter a word to encode: ");
    scanf("%s", str);
    len = strlen(str);

    len = lhc_encode(str, len, encoded_data, 2048);

    printf("The encoded string:\r\n");
    for(i = 0; i < len; ++i) {
        printf("0x%02x%02x (\"%c\")\r\n", (uint8_t)encoded_data[2*i], (uint8_t)encoded_data[2*i + 1], str[i]);
    }
}