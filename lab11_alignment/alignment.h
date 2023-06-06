#ifndef _ALIGNMENT_H_
#define _ALIGNMENT_H_

#include <stdio.h>
#include <climits>
#include <malloc.h>

void read(char*** text, int** len_words, int* size_text, int* size_arr, FILE *fp);
void analysis(int* left, int* right, FILE *fp);
void alignmented_write(char** text, int* len_words, int size_text, int left, int right, FILE *fp);

#endif
