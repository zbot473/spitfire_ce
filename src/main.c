#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <debug.h>

#include <graphx.h>
#include <keypadc.h>
#include "gfx/sprites.h"

void setup();
void updatePlayer();
void updateEnemies();
void updateBullets();
void drawMenu();
void drawSprites();

gfx_sprite_t *player, *bomb, *title, *subtitle, *wrench;
gfx_sprite_t *enemies[7];
int dimensions[7][2] = {
    {enemy_1_width, enemy_1_height},
    {enemy_2_width, enemy_2_height},
    {enemy_3_width, enemy_3_height},
    {enemy_4_width, enemy_4_height},
    {enemy_5_width, enemy_5_height},
    {enemy_6_width, enemy_6_height},
    {enemy_7_width, enemy_7_height}};
uint8_t *enemiesCompressed[6] = {
    enemy_1_compressed,
    enemy_2_compressed,
    enemy_3_compressed,
    enemy_4_compressed,
    enemy_5_compressed,
    enemy_6_compressed};
uint8_t *bulletsCompressed[3] = {
    bullet_1_compressed,
    bullet_2_compressed,
    bullet_3_compressed};
typedef struct
{
    bool active;
    int x;
    int y;
} bullet_t;
bullet_t bulletLocations[100];
typedef struct
{
    bool active;
    int type;
    int health;
    int x;
    int y;
} enemy_t;
enemy_t enemyLocations[40];
gfx_sprite_t *bullets[3];
bool isPlaying = true;
bool inGame = false;
bool inMenu = true;
bool invincible = false;
int score = 0, lives = 3;

int i;

void setup()
{
    player = gfx_MallocSprite(player_width, player_height); //allocate memory by pixel dimensions
    zx7_Decompress(player, player_compressed);              //decompress sprite
    bomb = gfx_MallocSprite(bomb_width, bomb_height);
    zx7_Decompress(bomb, bomb_compressed);
    title = gfx_MallocSprite(255, 85);
    zx7_Decompress(title, title_compressed);
    subtitle = gfx_MallocSprite(subtitle_width, subtitle_height);
    zx7_Decompress(subtitle, subtitle_compressed);
    wrench = gfx_MallocSprite(wrench_width, wrench_height);
    zx7_Decompress(wrench, wrench_compressed);
    for (i = 0; i < 7; i++)
    {
        enemies[i] = gfx_MallocSprite(dimensions[i][0], dimensions[i][1]);
        zx7_Decompress(enemies[i], enemiesCompressed[i]);
    }
    for (i = 0; i < 3; i++)
    {
        bullets[i] = gfx_MallocSprite(16, 7);
        zx7_Decompress(bullets[i], bulletsCompressed[i]);
    }

    gfx_Begin();                                        //begin graphics
    gfx_SetPalette(sprites_pal, sizeof_sprites_pal, 0); //set graphics palette
    gfx_SetDrawBuffer();                                //start to buffer graphics for visual quality
    gfx_SetTextFGColor(4);                              //white text
    gfx_SetColor(3);
}
bool right; //key bools
bool left;
bool up;
bool down;
kb_key_t arrows; //arrow keys
int x = 0, y = 103;
int invincibleDelay;
void updatePlayer()
{
    if (invincible){
        invincibleDelay++;
        if (invincibleDelay==40){
            invincible = false;
            invincibleDelay = false;
        }
    }
    arrows = kb_Data[7];       //kb data bit 7 has arrows, among other stuff
    right = arrows & kb_Right; //check if right key pressed
    left = arrows & kb_Left;
    down = arrows & kb_Down;
    up = arrows & kb_Up;
    if (arrows)
    {
        if (right)
        {
            x += 3;
        }
        if (left)
        {
            x -= 3;
        }
        if (down)
        {
            y += 3;
        }
        if (up)
        {
            y -= 3;
        }
    }
    if (x < 0)
    {
        x += 3;
    }
    if (y < 0)
    {
        y += 3;
    }
    if (x > 256)
    {
        x -= 3;
    }
    if (y > 183)
    {
        y -= 3;
    }
}

bool canShoot = true; //don't shoot during this time
int delayTick = 0;    //frame interval
void updateBullets()
{
    if (delayTick == 10)
    {
        canShoot = true; //now we can shoot
        delayTick = 0;   //reset frame interval
    }
    delayTick++;
    if (kb_Data[1] == kb_2nd && canShoot)
    {
        for (i = 0; i < 100; i++)
        {
            if (!bulletLocations[i].active) //if it isn't in use, skip
            {
                bulletLocations[i].x = x + 64; //move to end of player
                bulletLocations[i].y = y + 9;  //x to player x, offset by around half
                bulletLocations[i].active = true;
                canShoot = false; //turn off shooting
                break;            // we don't need to waste time iterating, so break.
            }
        }
    }
    for (i = 0; i < 100; i++)
    {
        if (bulletLocations[i].active)
        {
            bulletLocations[i].x += 5;      //move bullet
            if (bulletLocations[i].x > 304) //bullet would be offscreen, so don't draw it
            {
                bulletLocations[i].active = false;
            }
        }
    }
}

//never really bothered to make a function for this,
//but you need to play around with lists and callbacks
int spawnTick = 0;
int j;
void updateEnemies()
{
    if (spawnTick == 20)
    {
        if (randInt(0, 1) == 1)
        {
            for (i = 0; i < 40; i++)
            {
                if (!enemyLocations[i].active) //Same as before, function
                //isn't really needed, as it only makes code shorter. Exec time is same
                {
                    int type = randInt(0, 5);
                    enemyLocations[i].type = type;
                    enemyLocations[i].health = type + 1;
                    enemyLocations[i].x = 320 - dimensions[type][0];
                    enemyLocations[i].y = randInt(0, 200 - dimensions[type][1]);
                    enemyLocations[i].active = true;
                    break;
                }
            }
        }
        spawnTick = 0;
    }
    spawnTick++;
    for (i = 0; i < 40; i++)
    {
        if (enemyLocations[i].active)
        {
            enemyLocations[i].x -= 2;
            if (y - enemyLocations[i].y < 0)
            {
                enemyLocations[i].y--;
            }
            else
            {
                enemyLocations[i].y++;
            }
            if (enemyLocations[i].x < -dimensions[enemyLocations[i].type][0])
            {
                score -= enemyLocations[i].type * 1000;
                enemyLocations[i].active = false;
                continue;
            }
            if (!invincible && (x - 64 - enemyLocations[i].x) < 0 && (y - enemyLocations[i].y + ((int)round(dimensions[enemyLocations[i].type][1] / 2))) < 0)
            {
                lives--;
                invincible = true;
                for (j = 0; j < 100; j++)
                {
                    bulletLocations[i].active = false;
                }
                for (i = 0; i < 40; i++)
                {
                    enemyLocations[i].active = false;
                }
            }

            for (j = 0; j < 100; j++)
            {
                if (bulletLocations[j].active)
                {
                    if (abs(bulletLocations[j].x - 16 - enemyLocations[i].x) < 5 && abs((bulletLocations[j].y - 7) - (enemyLocations[i].y + ((int)round(dimensions[enemyLocations[i].type][1] / 2)))) < 5)
                    {
                        enemyLocations[i].health--;
                        break;
                    }
                    if (enemyLocations[i].health < 1)
                    {
                        score += enemyLocations[i].type * 1000;
                        enemyLocations[i].active = false;
                        bulletLocations[j].active = false;
                    }
                }
            }
        }
    }
}
int frame, frameTick = 0;
void drawSprites()
{
    if (frame == 5)
    {
        if (frameTick < 2)
        {
            frameTick++;
        }
        else
        {
            frameTick = 0;
        }
        frame = 0;
    }
    frame++;
    gfx_FillScreen(1);
    gfx_TransparentSprite_NoClip(player, x, y);
    for (i = 0; i < 100; i++)
    {
        if (bulletLocations[i].active)
        {
            gfx_TransparentSprite_NoClip(bullets[frameTick], bulletLocations[i].x, bulletLocations[i].y);
            //draw the bullet frame at the corrdinates
        }
    }
    for (i = 0; i < 40; i++)
    {
        if (enemyLocations[i].active)
        {
            gfx_TransparentSprite(enemies[enemyLocations[i].type], enemyLocations[i].x, enemyLocations[i].y);
            //draw the bullet frame at the corrdinates
        }
    }
    gfx_FillRectangle_NoClip(0, 200, 320, 40);
    gfx_PrintStringXY("Score: ", 20, 216);
    gfx_PrintInt(score, 8);
    gfx_TransparentSprite_NoClip(wrench, 288, 208);
    gfx_BlitBuffer();
}
bool option = true;
void drawMenu()
{
    gfx_FillScreen(129);
    gfx_TransparentSprite(title, 32, 40);      //Spitfire
    gfx_TransparentSprite(subtitle, 107, 145); //Air superiority
    if (option)
    {
        gfx_SetTextBGColor(5); //Highlighted
        gfx_PrintStringXY("Play", 100, 169);
        gfx_SetTextBGColor(255); //Reset
        gfx_PrintStringXY("Quit", 220 - gfx_GetStringWidth("Quit"), 169);
    }
    else
    {
        gfx_SetTextBGColor(255); //Reset
        gfx_PrintStringXY("Play", 100, 169);
        gfx_SetTextBGColor(5); //Highlighted
        gfx_PrintStringXY("Quit", 220 - gfx_GetStringWidth("Quit"), 169);
    }
    if (kb_Data[7] == kb_Left)
    {
        option = true;
    }
    else if (kb_Data[7] == kb_Right)
    {
        option = false;
    }
    if (kb_Data[6] == kb_Enter)
    {
        if (option)
        {
            inMenu = false;
            inGame = true;
        }
        else
        {
            inMenu = false;
            isPlaying = false;
        }
    }
    gfx_BlitBuffer();
}

void main()
{
    setup();
    while (isPlaying)
    {
        while (inMenu)
        {
            kb_Scan();
            drawMenu();
        }
        while (inGame)
        {
            kb_Scan();       //scan keyboard
            updateBullets(); //update bullets
            updatePlayer();  //update player
            updateEnemies(); //update enemies
            updateBullets(); //update bullets
            drawSprites();   //draw everything

            if (kb_Data[6] == kb_Clear)
            {
                inMenu = true;
                inGame = false;
                score = 0;
            }
        }
    }
    gfx_End();    //end graphics
    free(player); //free all ram
    free(bomb);
    free(title);
    free(subtitle);
    for (i = 0; i < 7; i++)
    {
        free(enemies[i]);
    }
    for (i = 0; i < 3; i++)
    {
        free(bullets[i]);
    }
    os_ClrHome();
}