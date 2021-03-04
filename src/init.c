/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** initialisation of the structure function
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int init(struct global *gb, struct init *in)
{
	in->rect.top = 0;
	in->rect.left = 0;
	in->rect.width = 110;
	in->rect.height = 110;
	sfSprite_setTextureRect(gb->sprite2, in->rect);
	in->offset.x = 5;
	in->offset.y = 0;
	in->position.x = 0;
	in->position.y = 0;
	in->scale.x = 1;
	in->scale.y = 1;
	in->mark = 1;
	in->score = 0;
	in->mouse_pos.x = 0;
	in->mouse_pos.y = 0;
	in->hearth = 3;
	return (0);
}
