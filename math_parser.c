#include "computer.h"

char    *quad_reduce(char *str){
    //struct table *t = create_hash_table(10);
    str += str_len(str);
    bool is_neg = false;
    while (*(--str)){
        //check if current char is a positive or negative delimeter
        int i = 0;
        while ((*(str-i) != '-' || *(str-i) != '+' || (*str != '=')) && *(str - i))
            i++;
        if (*(str - i) == '-'){
            is_neg = true;
        }
        else if (*(str - i) == '+'){
            is_neg = false;
        }
        
        char *term = (char *)malloc(sizeof(char) * (i + 1));
        for (int j = 0; j < i + 1; j++){
            printf("%c", *(str - i + j));
            term[j] = *(str - i + j);
        }
        term[i] = '\0';
        for (int j = 0; term[j] != '\0'; j++){
            printf("%c", term[j]);
        }
        write(1, "\n", 1);
        str--;
    }
    return NULL;
}