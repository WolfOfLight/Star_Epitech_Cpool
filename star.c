/*
** EPITECH PROJECT, 2024
** Star_Epitech_Cpool
** File description:
** star
*/
#include <stdio.h>
double pow10(int pow)
{
    double r = 1;
    for(double i = 0; i < pow; i++) {
        r *= 10;
    }
    return r;
}

int intAt(int index, char *str)
{
    char c = str[index];
    return (c - '0');
}

int strToInt(char *str, int size, int negativ)
{
    long result = 0;
    if(size > 10) return 0;
    for(int i = 0; i < size; i++) {
        result += pow10(size - i - 1) * intAt(i, str);
    }
    if(negativ == 1) result *= (-1);
    
    if(result > 2147483647 || result < -2147483648) return 0;
    return (int)result;
}

int my_getnbr(char const *str)
{
    int start = 0;
    while(str[start] < 48 || str[start] > 57) start++;
    int end = start + 1;
    while(str[end] >= 48 && str[end] <= 57) end++;
    int negativ = 0;
    if(start != 0 && str[start - 1] == '-') negativ = 1;
    
    char numStr[end - start];
    int j = 0;
    for(int i = start; i < end; i++) {
        numStr[j] = str[i];
        j++;
    }
    return strToInt(numStr, j, negativ);
}

void star(unsigned int size)
{
    int spaces = ((size * 4) - 1);
    int tmpspaces = spaces;
    
    printf("%d", spaces);
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2){
        i = my_getnbr(av[1]);
        star(i);
    }
    return 0;
}
