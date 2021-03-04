/*
** EPITECH PROJECT, 2017
** animation.c
** File description:
** animation
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int clock(struct global *gb, struct init *in)
{
	gb->time = sfClock_getElapsedTime(gb->clock);
	gb->seconds = gb->time.microseconds / 100000.0;
	if (gb->seconds > 5) {
		move_rect(gb, in);
		sfClock_restart(gb->clock);
	}
	return (0);
}

int move_rect(struct global *gb, struct init *in)
{
	if (in->rect.left != 220)
		in->rect.left += 110;
	else
		in->rect.left = 0;
	sfSprite_setTextureRect(gb->sprite2, in->rect);
	return (0);
}

int move(struct global *gb, struct init *in)
{
	in->position = sfSprite_getPosition(gb->sprite2);
	if (in->position.x >= 910 && in->mark == 1) {
		in->scale.x = -1;
		in->offset.x = -5;
		sfSprite_setScale(gb->sprite2, in->scale);
		if (in->scale.x == -1)
			in->mark = 0;
	}
	if (in->position.x <= -110 && in->mark == 0) {
		in->scale.x = 1;
		in->offset.x = 5;
		sfSprite_setScale(gb->sprite2, in->scale);
		if (in->scale.x == 1)
			in->mark = 1;
	}
	sfSprite_move(gb->sprite2, in->offset);
	clock(gb, in);
	return (0);
}

int mouse(struct global *gb, struct init *in)
{
	in->mouse_pos = sfMouse_getPositionRenderWindow(gb->window);

	if (in->mouse_pos.x >= 0 && in->mouse_pos.x <= 800
	    && in->mouse_pos.y >= 0 && in->mouse_pos.y <= 600) {
		if (in->mouse_pos.x >= in->position.x && in->mouse_pos.x <= in->position.x + 110
		    && in->mouse_pos.y >= in->position.y && in->mouse_pos.y <= in->position.y + 110) {
			cause1(gb, in);
		} else {
			cause2(gb, in);
		}
	}
	return (0);
}

int mouse2(struct global *gb, struct init *in)
{
	in->mouse_pos = sfMouse_getPositionRenderWindow(gb->window);

	if (in->mouse_pos.x >= 0 && in->mouse_pos.x <= 800
	    && in->mouse_pos.y >= 0 && in->mouse_pos.y <= 600) {
		if (in->mouse_pos.x <= in->position.x && in->mouse_pos.x <= in->position.x + 110
		    && in->mouse_pos.y >= in->position.y && in->mouse_pos.y <= in->position.y + 110) {
			cause1(gb, in);
		} else {
			cause2(gb, in);
		}
	}
	return (0);
}
