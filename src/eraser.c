/*
** EPITECH PROJECT, 2017
** eraser.c
** File description:
** eraser
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void clean_sprite(struct global *gb)
{
	sfRenderWindow_clear(gb->window, sfBlack);
	sfRenderWindow_drawSprite(gb->window, gb->sprite, NULL);
	sfRenderWindow_drawSprite(gb->window, gb->sprite2, NULL);
	sfRenderWindow_display(gb->window);
}

void clean_all(struct global *gb, struct init *in)
{
	sfSprite_destroy(gb->sprite);
	sfSprite_destroy(gb->sprite2);
	sfTexture_destroy(gb->texture);
	sfTexture_destroy(gb->texture2);
	sfMusic_destroy(gb->music);
	sfMusic_destroy(gb->music2);
	sfRenderWindow_destroy(gb->window);
	free(gb);
	free(in);
}
