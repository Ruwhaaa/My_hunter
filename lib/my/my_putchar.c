/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** putchar
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}
