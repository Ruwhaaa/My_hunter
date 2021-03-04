/*
** EPITECH PROJECT, 2017
** score.c
** File description:
** pasting the score
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void cause1(struct global *gb, struct init *in)
{
	if (sfEvtMouseButtonReleased) {
		in->score++;
		in->position.x = -90;
		in->position.y = rand() % 500;
		sfMusic_play(gb->music);
		sfSprite_setPosition(gb->sprite2, in->position);
	}
}

void cause2(struct global *gb, struct init *in)
{
	if (sfEvtMouseButtonReleased) {
		sfMusic_play(gb->music2);
		in->hearth--;
	}
}

void screen_score()
{
	my_putstr("Game Over, Try Again...\n");
}
