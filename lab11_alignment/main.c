// Text alignment by template

#include "alignment.h"

int main(int argc, char** argv)
{
    //Чтение
    char** text;
    int* len_words;

    int size_text = 0, size_arr = 10;
    
    FILE *ifp = fopen(argv[1], "r");
    read(&text, &len_words, &size_text, &size_arr, ifp);
    fclose(ifp);

    //Образец
    int left, right;   
    
    FILE *pattern_fp = fopen(argv[2], "r");
    analysis(&left, &right, pattern_fp);
    fclose(pattern_fp);

    //Преобразование и вывод
    FILE *ofp = fopen(argv[3], "w");

    alignmented_write(text, len_words, size_text, left, right, ofp);

    fclose(ofp);

    for (int i = 0; i < size_arr; i++)
        free(text[i]);
    free(text);
    free(len_words);

    return 0;
}

