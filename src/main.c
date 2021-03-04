/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int main()
{
	struct global *gb = NULL;
	gb = malloc(sizeof(*gb));
	if (!gb)
		return (84);
	struct init *in = NULL;
	in = malloc(sizeof(*in));
	if (!in)
		return (84);
	sfVideoMode mode = {800, 600, 32};

	gb->clock = sfClock_create();
	gb->window = sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose, NULL);
	if (!gb->window)
		return (84);
	initialisation_texture(gb, in);
	return (0);
}

int initialisation_texture(struct global *gb, struct init *in)
{
	gb->texture = sfTexture_createFromFile("Assets/background.png", NULL);
	if (!gb->texture)
		return (84);
	gb->texture2 = sfTexture_createFromFile("Assets/spritesheet.png", NULL);
	if (!gb->texture2)
		return (84);
	initialisation_music(gb, in);
	return(0);
}

int initialisation_music(struct global *gb, struct init *in)
{
	gb->music = sfMusic_createFromFile("Assets/QUACK.WAV");
	if (!gb->music)
		return (84);
	gb->music2 = sfMusic_createFromFile("Assets/fail.wav");
	if (!gb->music2)
		return (84);
	initialisation_sprite(gb, in);
	return (0);
}

int initialisation_sprite(struct global *gb, struct init *in)
{
	gb->sprite = sfSprite_create();
	if (!gb->sprite)
		return (84);
	gb->sprite2 = sfSprite_create();
	if (!gb->sprite2)
		return (84);
	sfSprite_setTexture(gb->sprite, gb->texture, sfTrue);
	sfSprite_setTexture(gb->sprite2, gb->texture2, sfTrue);
	init(gb, in);
	process(gb, in);
	return (0);
}

int process(struct global *gb, struct init *in)
{
	sfRenderWindow_setFramerateLimit(gb->window, 60);
	while (sfRenderWindow_isOpen(gb->window)) {
		if (in->hearth == 0) {
			screen_score(in);
			break;
		}
		move(gb, in);
		while (sfRenderWindow_pollEvent(gb->window, &gb->event)) {
			if (gb->event.type == sfEvtMouseButtonPressed && in->mark == 1)
				mouse(gb, in);
			if (gb->event.type == sfEvtMouseButtonPressed && in->mark == 0)
				mouse2(gb, in);
			if (gb->event.type == sfEvtClosed)
				sfRenderWindow_close(gb->window);
		}
		clean_sprite(gb);
	}
	clean_all(gb, in);
	return (0);
}
