#include "alignment.h"

void read(char*** text, int** len_words, int* size_text, int* size_arr, FILE *fp)
{
    *len_words = (int*)malloc(*size_arr * sizeof(int));
    *text = (char**)malloc(*size_arr * sizeof(char*));

    char c;

    int wlen = 5;
    int cur = 0;

    *text[*size_text] = (char*)malloc(wlen * sizeof(char));

    while(1)
    {
        c = getc(fp);
        if (c == EOF)
            break;

        if (c == ' ' || c == '\n')
        {
            while ((c == ' ' || c == '\n') && !feof(fp))
            {
                c = getc(fp);
            }
            
            (*text)[*size_text][cur] = '\0';
            (*len_words)[*size_text] = cur;
            (*size_text)++;
            
            wlen = 5;
            cur = 0;
            
            if (*size_text == *size_arr)
            {
                *size_arr *= 2;
                *len_words = (int*)realloc(*len_words, *size_arr * sizeof(int));
                *text = (char**)realloc(*text, *size_arr * sizeof(char*));
            }
            (*text)[*size_text] = (char*)malloc(wlen * sizeof(char));
        }

        (*text)[*size_text][cur] = c;
        cur++;

        if (cur >= wlen - 1)
        {
            wlen *= 2;
            (*text)[*size_text] = (char*)realloc((*text)[*size_text], wlen * sizeof(char));
        }
    }
}

void analysis(int* left, int* right, FILE *fp)
{
    *left = INT_MAX, *right = 0;
    int min = 0, max = 0;
    char c;

    c = getc(fp);
    
    //Поиск левой и правой границ
    for (min = 0; c == ' ' && !feof(fp); min++)
        c = getc(fp);
    for (max = 0; c != '\n' && !feof(fp); max++)
        c = getc(fp);
    //Обновление границ
    *left = *left > min ? min : *left;
    *right = *right < max ? max : *right;

}

void alignmented_write(char** text, int* len_words, int size_text, int left, int right, FILE *fp)
{
    int cur = 0;
    int count = 0;
    int length = 0;
    int* spaces;

    //printf("%d %d\n", left, right);
    
    while (cur < size_text - 1)
    {
        for (count = 0; cur + count != size_text && count + length + len_words[cur + count] <= right; count++)
        {
            length += len_words[cur + count];
        }

        for (int i = 0; i < left; i++)
            fprintf(fp, " "); 

        if (count != 1)
        {
            int count_space = right - (count + length) + 1;
            spaces = (int*)calloc((count - 1), sizeof(int));
    
            for (int i = 0; count_space > 0; i = (i+1) % (count - 1))
            {
                spaces[i] += 1;
                count_space -= 1;
            }       

            for (int i = 0; i < count - 1; i++)
            {
                fprintf(fp, "%s ", text[cur + i]);
                while(spaces[i] > 0)
                {   
                    spaces[i] -= 1;
                    fprintf(fp, " ");
                }
            }
            fprintf(fp, "%s\n", text[cur + count - 1]);
            free(spaces);
        }
        else
        {
            fprintf(fp, "%s\n",text[cur]);
        }
        
        cur += count;
        length = 0;        
    

    }
}































