/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** struct + my
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#ifndef LIST_H_
#define LIST_H_

struct global
{
	sfRenderWindow *window;
	sfTexture *texture;
	sfTexture *texture2;
	sfSprite *sprite;
	sfSprite *sprite2;
	sfEvent event;
	float seconds;
	sfClock *clock;
	sfTime time;
	sfMusic *music;
	sfMusic *music2;
};

struct init
{
	sfIntRect rect;
	sfVector2f offset;
	sfVector2f position;
	sfVector2f scale;
	sfVector2i mouse_pos;
	int score;
	int mark;
	int hearth;
};

int my_putstr(char const *str);
void my_putchar(char c);
int process(struct global *gb, struct init *in);
void clean_sprite(struct global *gb);
void clean_all(struct global *gb, struct init *in);
int move_rect(struct global *gb, struct init *in);
int clock(struct global *gb, struct init *in);
int mouse(struct global *gb, struct init *in);
int move(struct global *gb, struct init *in);
int init(struct global *gb, struct init *in);
void cause1(struct global *gb, struct init *in);
void cause2(struct global *gb, struct init *in);
int mouse2(struct global *gb, struct init *in);
int error(struct global *gb, struct init *in);
void screen_score();
int initialisation_texture(struct global *gb, struct init *in);
int initialisation_music(struct global *gb, struct init *in);
int initialisation_sprite(struct global *gb, struct init *in);

#endif /* !LIST_H_ */
