// ──────────────────────────────────────────────────
// Problem  : 166. Fraction to Recurring Decimal
// Difficulty: Medium
// Tags     : Hash Table, Math, String
// Link     : https://leetcode.com/problems/fraction-to-recurring-decimal/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9140000 (beats 79%)
// Language : c
// Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
        char* res = (char*)malloc(2 * sizeof(char));
        strcpy(res, "0");
        return res;
    }

    char* result = (char*)malloc(10005 * sizeof(char));
    int pos = 0;

    if ((numerator < 0) ^ (denominator < 0)) {
        result[pos++] = '-';
    }

    long long num = labs((long long)numerator);
    long long den = labs((long long)denominator);

    pos += sprintf(result + pos, "%lld", num / den);

    long long rem = num % den;
    if (rem == 0) {
        return result;
    }

    result[pos++] = '.';

    long long rems[10005];
    int indices[10005];
    int rem_count = 0;

    while (rem != 0) {
        for (int i = 0; i < rem_count; i++) {
            if (rems[i] == rem) {
                int start_idx = indices[i];
                memmove(result + start_idx + 1, result + start_idx, pos - start_idx);
                result[start_idx] = '(';
                pos++;
                result[pos++] = ')';
                result[pos] = '\0';
                return result;
            }
        }

        rems[rem_count] = rem;
        indices[rem_count] = pos;
        rem_count++;

        rem *= 10;
        result[pos++] = (rem / den) + '0';
        rem %= den;
    }

    result[pos] = '\0';
    return result;
}

