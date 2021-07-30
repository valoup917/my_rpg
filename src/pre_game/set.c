/*
** EPITECH PROJECT, 2021
** set.c
** File description:
** set everything
*/

#include "my.h"

struct image fill_struct(char *path, int x, int y)
{
    image_t fill;
    sfVector2f pos = {x, y};

    fill.text = sfTexture_createFromFile(path, NULL);
    fill.sprite = sfSprite_create();
    fill.Rect = (sfIntRect){0, 0, 804, 1135};
    fill.clock = sfClock_create();
    sfSprite_setTexture(fill.sprite, fill.text, sfFalse);
    sfSprite_setPosition(fill.sprite, pos);
    return fill;
}

void music(enti_t *enti)
{
    enti->song.volume = 40;
    enti->song.music = sfMusic_createFromFile("assets/song.ogg");
    sfMusic_setLoop(enti->song.music, sfTrue);
    sfMusic_setVolume(enti->song.music, enti->song.volume);
    sfMusic_play(enti->song.music);
}

void set_txt(enti_t *enti)
{
    enti->pause_scrolling.vect = (sfVector2f){-1920, - 1080};
    enti->pause_scrolling.sprite = sfSprite_create();
    enti->pause_scrolling.text = sfTexture_createFromFile("assets/rpgg.png", NULL);
    sfTexture_setRepeated(enti->pause_scrolling.text, sfTrue);
    sfSprite_setTexture(enti->pause_scrolling.sprite, enti-> pause_scrolling.text, sfTrue);
    sfSprite_setTextureRect(enti->pause_scrolling.sprite, (sfIntRect){0, 0, 10000, 10000});
}

select_t fill_selection(void)
{
    select_t select;

    select.sprite = sfSprite_create();
    select.texture = sfTexture_createFromFile("assets/menu_assets/select.jpg", NULL);
    sfSprite_setTexture(select.sprite, select.texture, sfFalse);
    select.selection = 0;

    return select;
}

struct enti initialize(enti_t enti)
{
    enti.menu_bg = fill_struct("assets/menu_assets/menu_backround.jpeg", 0, 0);
    enti.menu_start = fill_struct("assets/menu_assets/start1.png", 1220, 300);
    enti.menu_quit = fill_struct("assets/menu_assets/exit1.png", 100, 300);
    enti.menu_info = fill_struct("assets/menu_assets/man1.png", 1620, 800);
    enti.menu_settings = fill_struct("assets/menu_assets/settings1.png", 100, 800);
    enti.man_bg = fill_struct("assets/menu_assets/man_background.jpeg", 0, 0);
    enti.man_exit = fill_struct("assets/menu_assets/m_exit1.png", 10, 800);
    enti.game_bg = fill_struct("assets/kono.png", 0, 0);
    enti.menu_map = fill_struct("assets/menu_assets/map1.png", 100, 540);

    enti.pause_resume = fill_struct("assets/menu_assets/resume1.png", 680, 540);
    enti.pause_menu = fill_struct("assets/menu_assets/home1.png", 680, 140);
    enti.pause_quit = fill_struct("assets/menu_assets/close1.png", 1650, 800);

    enti.settings_bg = fill_struct("assets/menu_assets/menu_backround.jpeg", 0, 0);
    enti.settings_volume10 = fill_struct("assets/menu_assets/10vol.png", 1400, 140);
    enti.settings_volume50 = fill_struct("assets/menu_assets/50vol.png", 1400, 340);
    enti.settings_volume100 = fill_struct("assets/menu_assets/100vol.png", 1400, 540);
    enti.settings_mute = fill_struct("assets/menu_assets/mute1.png", 100, 100);
    enti.settings_exit = fill_struct("assets/menu_assets/back1.png", 890, 800);

    enti.menu_map_img = fill_struct("assets/menu_assets/menu_map.png", 0, 0);
    enti.menu_map_exit = fill_struct("assets/menu_assets/back1.png", 100, 100);

    enti.game = setup_game();

    music(&enti);

    enti.inventory = struct_creation_inventory();

    enti.select = fill_selection();

    enti.finished = set_cutscene("assets/cutscene/thumbs-up.jpg", 1, finished_txt());
    enti.start_battle = set_cutscene("assets/cutscene/village.png", 2, enemyarrive_txt());

    enti.mouse.x = 0;
    enti.mouse.y = 0;

    set_txt(&enti);
    return (enti);
}
