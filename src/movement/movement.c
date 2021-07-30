/*
** EPITECH PROJECT, 2021
** movement
** File description:
** .
*/

#include <stdlib.h>
#include <my.h>

void free_all(perso_t *perso)
{
    sfSprite_destroy(perso->s_perso);
    sfTexture_destroy(perso->image->t_perso);
    sfClock_destroy(perso->clock);
    free(perso);
}

void move_boy(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && seconds > 0.04)
        sfClock_restart(perso->clock), move_right(perso);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && seconds > 0.04)
        sfClock_restart(perso->clock), move_left(perso);
    if (sfKeyboard_isKeyPressed(sfKeyUp) && seconds > 0.04)
        sfClock_restart(perso->clock), move_up(perso);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && seconds > 0.04)
        sfClock_restart(perso->clock), move_down(perso);
    if (sfKeyboard_isKeyPressed(sfKeyA) && seconds > 0.04)
            sprint(perso);
}

void move_rect_gright(perso_t *perso)
{
    if (perso->image->direction != 3) {
        sfTexture_destroy(perso->image->t_perso);
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/sakura_right.png", NULL);
        sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
        perso->image->direction = 3;
    }
    if (perso->image->rect.left >= 336) {
        perso->image->rect.left = 0;
    }
    else
        perso->image->rect.left += 48;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
}

void move_rect_gleft(perso_t *perso)
{
    if (perso->image->direction != 4) {
        sfTexture_destroy(perso->image->t_perso);
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/sakura_left.png", NULL);
        sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
        perso->image->direction = 4;
    }
    if (perso->image->rect.left >= 336) {
        perso->image->rect.left = 0;
    }
    else
        perso->image->rect.left += 48;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
}

void move_rect_gup(perso_t *perso)
{
    if (perso->image->direction != 1) {
        sfTexture_destroy(perso->image->t_perso);
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/sakura_up.png", NULL);
        sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
        perso->image->direction = 1;
    }
    if (perso->image->rect.left >= 336) {
        perso->image->rect.left = 0;
    }
    else
        perso->image->rect.left += 48;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
}

void move_rect_gdown(perso_t *perso)
{
    if (perso->image->direction != 2) {
        sfTexture_destroy(perso->image->t_perso);
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/sakura_down.png", NULL);
        sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
        perso->image->direction = 2;
    }
    if (perso->image->rect.left >= 336) {
        perso->image->rect.left = 0;
    }
    else
        perso->image->rect.left += 48;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
}

void move_gright(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;

    perso->pos.x += 8;
    sfSprite_setPosition(perso->s_perso, perso->pos);
    if (seconds > 0.000001)
        move_rect_gright(perso);
}

void move_gleft(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;

    perso->pos.x -= 8;
    sfSprite_setPosition(perso->s_perso, perso->pos);
    if (seconds > 0.000001)
        move_rect_gleft(perso);
}

void move_gup(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;

    perso->pos.y -= 8;
    sfSprite_setPosition(perso->s_perso, perso->pos);
    if (seconds > 0.000001)
        move_rect_gup(perso);
}

void move_gdown(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;

    perso->pos.y += 8;
    sfSprite_setPosition(perso->s_perso, perso->pos);
    if (seconds > 0.000001)
        move_rect_gdown(perso);
}

void move_girl(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && seconds > 0.04)
        sfClock_restart(perso->clock), move_gright(perso);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && seconds > 0.04)
        sfClock_restart(perso->clock), move_gleft(perso);
    if (sfKeyboard_isKeyPressed(sfKeyUp) && seconds > 0.04)
        sfClock_restart(perso->clock), move_gup(perso);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && seconds > 0.04)
        sfClock_restart(perso->clock), move_gdown(perso);
    if (sfKeyboard_isKeyPressed(sfKeyA) && seconds > 0.04)
            sprint(perso);
}