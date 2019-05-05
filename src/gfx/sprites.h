// convpng v7.0
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __sprites__
#define __sprites__
#include <stdint.h>

#define sprites_transparent_color_index 0

#define bomb_width 8
#define bomb_height 8
#define bomb_size 66
extern uint8_t bomb_compressed[43];
#define bullet_1_width 16
#define bullet_1_height 7
#define bullet_1_size 114
extern uint8_t bullet_1_compressed[39];
#define bullet_2_width 16
#define bullet_2_height 7
#define bullet_2_size 114
extern uint8_t bullet_2_compressed[37];
#define bullet_3_width 16
#define bullet_3_height 7
#define bullet_3_size 114
extern uint8_t bullet_3_compressed[38];
#define enemy_1_width 41
#define enemy_1_height 15
#define enemy_1_size 617
extern uint8_t enemy_1_compressed[174];
#define enemy_2_width 55
#define enemy_2_height 25
#define enemy_2_size 1377
extern uint8_t enemy_2_compressed[355];
#define enemy_3_width 65
#define enemy_3_height 18
#define enemy_3_size 1172
extern uint8_t enemy_3_compressed[344];
#define enemy_4_width 56
#define enemy_4_height 22
#define enemy_4_size 1234
extern uint8_t enemy_4_compressed[308];
#define enemy_5_width 93
#define enemy_5_height 19
#define enemy_5_size 1769
extern uint8_t enemy_5_compressed[375];
#define enemy_6_width 129
#define enemy_6_height 26
#define enemy_6_size 3356
extern uint8_t enemy_6_compressed[678];
#define enemy_7_width 58
#define enemy_7_height 29
#define enemy_7_size 1684
extern uint8_t enemy_7_compressed[288];
#define player_width 64
#define player_height 17
#define player_size 1090
extern uint8_t player_compressed[341];
#define subtitle_width 107
#define subtitle_height 14
#define subtitle_size 1500
extern uint8_t subtitle_compressed[147];
#define title_width 255
#define title_height 85
#define title_size 21677
extern uint8_t title_compressed[2692];
#define wrench_width 32
#define wrench_height 32
#define wrench_size 1026
extern uint8_t wrench_compressed[61];
#define sizeof_sprites_pal 512
extern uint16_t sprites_pal[256];

#endif
