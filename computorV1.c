#include "computor.h"

void            simplify(char *str){
        char *args[] = {"*", "/", "+", "-", "^", "X", ".", NULL};
        char **terms = half_split(str);
        char **left_delim = ft_split(terms[0], args);
        char **right_delim = ft_split(terms[1], args);
        
        free(terms);

        HashTable *ht = ht_create(103);
        //TODO: Create own strcat implementation
        //Capture terms inside of hashmap
        for (int i = 0; left_delim[i] != NULL; i++){
                if (left_delim[i][0] == 'X'){
                        if (i > 1 && left_delim[i - 2][0] >= '0' && left_delim[i - 2][0] <= '9'){
                                if (ht_get(ht, left_delim[i])){
                                        if (i > 2 && left_delim[i - 3])
                                                ht_put(ht, left_delim[i], strcat(left_delim[i - 3], left_delim[i - 2]));
                                        else
                                                ht_put(ht, left_delim[i], left_delim[i - 2]);
                                }
                                else{
                                        if (i > 2 && left_delim[i - 3])
                                                ht_put(ht, left_delim[i], strcat(left_delim[i - 3], left_delim[i - 2]));
                                        else
                                                ht_put(ht, left_delim[i], left_delim[i - 2]);
                                }
                        }
                        else{
                                if (ht_get(ht, left_delim[i]))
                                        ht_put(ht, left_delim[i], "1");
                                else
                                        ht_put(ht, left_delim[i], "1");
                        }
                }
        }
        ht_print(ht);

        for (int i = 0; right_delim[i] != NULL; i++){
                if (right_delim[i][0] == 'X'){
                        if (i > 1 && right_delim[i - 2][0] >= '0' && right_delim[i - 2][0] <= '9'){
                                if (ht_get(ht, right_delim[i])){
                                        if (i > 2 && right_delim[i - 3])
                                                ht_put(ht, right_delim[i], strcat(right_delim[i - 3], right_delim[i - 2]));
                                        else
                                                ht_put(ht, right_delim[i], right_delim[i - 2]);
                                }
                                else{
                                        if (i > 2 && right_delim[i - 3])
                                                ht_put(ht, right_delim[i], strcat(right_delim[i - 3], right_delim[i - 2]));
                                        else
                                                ht_put(ht, right_delim[i], right_delim[i - 2]);
                                }
                        }
                        else{
                                if (ht_get(ht, right_delim[i]))
                                        ht_put(ht, right_delim[i], "1");
                                else
                                        ht_put(ht, right_delim[i], "1");
                        }
                }
        }
        ht_free(ht);
}

int main(int argc, char **argv)
{
    if (argc == 2){
        simplify(argv[1]);
    }
}