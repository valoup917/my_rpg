/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** menu
*/

#include <stdlib.h>
#include "my.h"

void game_loop(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        check_menu_choice(enti, window);
        draw_menu(enti, window);
    }
}

void event(enti_t *enti, sfRenderWindow *window, sfEvent *evt)
{
    if (evt->type == sfEvtClosed) {
        sfRenderWindow_close(window);
        exit(0);
    }
    if (evt->type == sfEvtMouseButtonPressed)
        enti->mouse = sfMouse_getPositionRenderWindow(window);
}

void selection(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        draw_selection(enti, window);
        if (enti->mouse.x > 180  && enti->mouse.x < 300
        && enti->mouse.y > 410 && enti->mouse.y < 530) {
            enti->menu_map.i = 1;
            enti->select.selection = 1;
            start_game(enti, window);
        } if (enti->mouse.x > 480  && enti->mouse.x < 600
        && enti->mouse.y > 650 && enti->mouse.y < 770) {
            enti->menu_map.i = 1;
            enti->select.selection = 2;
            start_game(enti, window);
        }
    }
}

void check_menu_choice(enti_t *enti, sfRenderWindow *window)
{
    if (enti->mouse.x > sfSprite_getPosition(enti->menu_start.sprite).x
    && enti->mouse.x < sfSprite_getPosition(enti->menu_start.sprite).x + 600
    && enti->mouse.y > sfSprite_getPosition(enti->menu_start.sprite).y &&
    enti->mouse.y < sfSprite_getPosition(enti->menu_start.sprite).y + 200)
    {
        if (!enti->select.selection)
            selection(enti, window);
        else
            start_game(enti, window);
    }
    if (enti->mouse.x > sfSprite_getPosition(enti->menu_quit.sprite).x
    && enti->mouse.x < sfSprite_getPosition(enti->menu_quit.sprite).x + 600
    && enti->mouse.y > sfSprite_getPosition(enti->menu_quit.sprite).y &&
    enti->mouse.y < sfSprite_getPosition(enti->menu_quit.sprite).y + 200)
    {
        sfRenderWindow_close(window);
    }
    if (enti->mouse.x > sfSprite_getPosition(enti->menu_info.sprite).x
    && enti->mouse.x < sfSprite_getPosition(enti->menu_info.sprite).x + 200
    && enti->mouse.y > sfSprite_getPosition(enti->menu_info.sprite).y &&
    enti->mouse.y < sfSprite_getPosition(enti->menu_info.sprite).y + 200)
    {
        man_page(enti, window);
    }
    if (enti->mouse.x > sfSprite_getPosition(enti->menu_settings.sprite).x
    && enti->mouse.x < sfSprite_getPosition(enti->menu_settings.sprite).x + 200
    && enti->mouse.y > sfSprite_getPosition(enti->menu_settings.sprite).y &&
    enti->mouse.y < sfSprite_getPosition(enti->menu_settings.sprite).y + 200)
    {
        settings_page(enti, window);
    }
}

void settings_page(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;
    while (sfRenderWindow_isOpen(window)) {
        draw_settings(enti, window);
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->settings_exit.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->settings_exit.sprite).x + 200
        && enti->mouse.y > sfSprite_getPosition(enti->settings_exit.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->settings_exit.sprite).y + 200) {
            game_loop(enti, window);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->settings_volume10.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->settings_volume10.sprite).x + 300
        && enti->mouse.y > sfSprite_getPosition(enti->settings_volume10.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->settings_volume10.sprite).y + 100) {
            enti->song.volume = 10;
            sfMusic_setVolume(enti->song.music, enti->song.volume);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->settings_volume50.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->settings_volume50.sprite).x + 300
        && enti->mouse.y > sfSprite_getPosition(enti->settings_volume50.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->settings_volume50.sprite).y + 100) {
            enti->song.volume = 30;
            sfMusic_setVolume(enti->song.music, enti->song.volume);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->settings_volume100.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->settings_volume100.sprite).x + 300
        && enti->mouse.y > sfSprite_getPosition(enti->settings_volume100.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->settings_volume100.sprite).y + 100) {
            enti->song.volume = 100;
            sfMusic_setVolume(enti->song.music, enti->song.volume);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->settings_mute.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->settings_mute.sprite).x + 200
        && enti->mouse.y > sfSprite_getPosition(enti->settings_mute.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->settings_mute.sprite).y + 200) {
            enti->song.mute = enti->song.mute + 1;
            play_music(enti);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->menu_map.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->menu_map.sprite).x + 200
        && enti->mouse.y > sfSprite_getPosition(enti->menu_map.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->menu_map.sprite).y + 200)
        {
            map_page(enti, window);
        }
    }
}

void man_page(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;
    while (sfRenderWindow_isOpen(window)) {
        draw_info(enti, window);
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->menu_info.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->menu_info.sprite).x + 200
        && enti->mouse.y > sfSprite_getPosition(enti->menu_info.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->menu_info.sprite).y + 200)
        {
            draw_info(enti, window);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->man_exit.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->man_exit.sprite).x + 200
        && enti->mouse.y > sfSprite_getPosition(enti->man_exit.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->man_exit.sprite).y + 200)
        {
            game_loop(enti, window);
        }
    }
}

void pause_window(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;
    while (sfRenderWindow_isOpen(window)) {
        draw_pause(enti, window);
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->pause_resume.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->pause_resume.sprite).x +
        600 && enti->mouse.y > sfSprite_getPosition(enti->pause_resume.sprite).y
        && enti->mouse.y < sfSprite_getPosition(enti->pause_resume.sprite).y + 200)
        {
            return;
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->pause_menu.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->pause_menu.sprite).x + 600
        && enti->mouse.y > sfSprite_getPosition(enti->pause_menu.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->pause_menu.sprite).y + 200)
        {
            enti->menu_map.i = 2;
            game_loop(enti, window);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->pause_quit.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->pause_quit.sprite).x + 200
        && enti->mouse.y > sfSprite_getPosition(enti->pause_quit.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->pause_quit.sprite).y + 200)
        {
            sfRenderWindow_close(window);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->menu_map.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->menu_map.sprite).x + 200
        && enti->mouse.y > sfSprite_getPosition(enti->menu_map.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->menu_map.sprite).y + 200)
        {
            map_page(enti, window);
        }
    }
}

void map_page(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;
    while (sfRenderWindow_isOpen(window)) {
        draw_map_menu(enti, window);
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        if (enti->mouse.x > sfSprite_getPosition(enti->menu_map_exit.sprite).x
        && enti->mouse.x < sfSprite_getPosition(enti->menu_map_exit.sprite).x + 200
        && enti->mouse.y > sfSprite_getPosition(enti->menu_map_exit.sprite).y &&
        enti->mouse.y < sfSprite_getPosition(enti->menu_map_exit.sprite).y + 200)
        {
            if (enti->menu_map.i == 1)
                pause_window(enti, window);
            else
                settings_page(enti, window);
        }
    }
}