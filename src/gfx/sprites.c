// convpng v7.0
#include <stdint.h>
#include "sprites.h"

uint16_t sprites_pal[256] = {
 0x7C1F,  // 00 :: rgb(255,0,255)
 0xC33D,  // 01 :: rgb(135,206,235)
 0x6E80,  // 02 :: rgb(224,160,0)
 0x0000,  // 03 :: rgb(0,0,0)
 0xFFFF,  // 04 :: rgb(255,255,255)
 0x28FF,  // 05 :: rgb(81,55,252)
 0x3E73,  // 06 :: rgb(123,155,154)
 0x1084,  // 07 :: rgb(32,32,32)
 0x9063,  // 08 :: rgb(35,29,23)
 0x4210,  // 09 :: rgb(128,128,128)
 0x7FFF,  // 10 :: rgb(255,252,252)
 0xFC42,  // 11 :: rgb(255,19,19)
 0x3189,  // 12 :: rgb(95,97,76)
 0x84C1,  // 13 :: rgb(8,52,8)
 0x7C21,  // 14 :: rgb(255,9,9)
 0x2927,  // 15 :: rgb(83,71,60)
 0x09A2,  // 16 :: rgb(16,105,16)
 0x0D0B,  // 17 :: rgb(24,66,92)
 0x4400,  // 18 :: rgb(140,0,1)
 0xA98D,  // 19 :: rgb(85,103,103)
 0x294A,  // 20 :: rgb(85,82,80)
 0x3DED,  // 21 :: rgb(120,121,103)
 0xFFDE,  // 22 :: rgb(255,245,245)
 0xEF7B,  // 23 :: rgb(224,224,224)
 0x99E6,  // 24 :: rgb(49,125,49)
 0x096D,  // 25 :: rgb(17,91,105)
 0x256A,  // 26 :: rgb(71,90,84)
 0x39CB,  // 27 :: rgb(112,113,94)
 0xFCA5,  // 28 :: rgb(255,43,43)
 0xFE73,  // 29 :: rgb(255,159,159)
 0x7E31,  // 30 :: rgb(255,136,136)
 0x7DEF,  // 31 :: rgb(255,122,122)
 0x2228,  // 32 :: rgb(69,137,68)
 0x7DAD,  // 33 :: rgb(255,105,105)
 0xFF5A,  // 34 :: rgb(255,216,216)
 0x298B,  // 35 :: rgb(80,97,92)
 0xFED6,  // 36 :: rgb(255,182,182)
 0xFD09,  // 37 :: rgb(255,70,70)
 0xFCA6,  // 38 :: rgb(255,46,46)
 0x1D49,  // 39 :: rgb(60,80,74)
 0x2508,  // 40 :: rgb(76,65,67)
 0xFE94,  // 41 :: rgb(255,166,166)
 0x7C84,  // 42 :: rgb(255,34,34)
 0xBDED,  // 43 :: rgb(126,127,110)
 0x14E3,  // 44 :: rgb(44,58,23)
 0x35AA,  // 45 :: rgb(104,105,85)
 0x7E10,  // 46 :: rgb(255,128,128)
 0x7DCE,  // 47 :: rgb(255,114,114)
 0x94A4,  // 48 :: rgb(44,46,35)
 0x7C63,  // 49 :: rgb(255,23,23)
 0x9CE6,  // 50 :: rgb(61,61,53)
 0xCA50,  // 51 :: rgb(149,151,133)
 0xAD28,  // 52 :: rgb(92,78,67)
 0x52D5,  // 53 :: rgb(166,178,176)
 0x7E93,  // 54 :: rgb(255,160,160)
 0x9D29,  // 55 :: rgb(61,77,77)
 0xFF7B,  // 56 :: rgb(255,224,224)
 0xFC00,  // 57 :: rgb(255,4,4)
 0x254B,  // 58 :: rgb(73,80,87)
 0xFFFF,  // 59 :: rgb(255,254,254)
 0x18E5,  // 60 :: rgb(50,55,40)
 0x7F39,  // 61 :: rgb(255,202,202)
 0x90E7,  // 62 :: rgb(37,60,54)
 0x7F9C,  // 63 :: rgb(255,228,228)
 0x4A95,  // 64 :: rgb(147,161,174)
 0xFE73,  // 65 :: rgb(255,156,156)
 0xB1AA,  // 66 :: rgb(100,110,85)
 0x2D6A,  // 67 :: rgb(91,91,86)
 0xFE52,  // 68 :: rgb(255,151,151)
 0xFC22,  // 69 :: rgb(255,14,14)
 0x7620,  // 70 :: rgb(239,138,0)
 0x9A16,  // 71 :: rgb(48,132,185)
 0x88EB,  // 72 :: rgb(20,61,92)
 0x20E6,  // 73 :: rgb(68,58,49)
 0x8863,  // 74 :: rgb(18,30,27)
 0xE720,  // 75 :: rgb(206,207,0)
 0xB169,  // 76 :: rgb(96,93,77)
 0x39EF,  // 77 :: rgb(117,120,121)
 0x77DD,  // 78 :: rgb(239,241,242)
 0x14A4,  // 79 :: rgb(39,40,36)
 0xADAD,  // 80 :: rgb(91,109,104)
 0xB26C,  // 81 :: rgb(97,156,97)
 0xE318,  // 82 :: rgb(201,197,194)
 0x8C61,  // 83 :: rgb(22,29,11)
 0x92DA,  // 84 :: rgb(35,183,210)
 0xFD4A,  // 85 :: rgb(255,83,83)
 0x4A52,  // 86 :: rgb(149,146,151)
 0x422F,  // 87 :: rgb(135,136,121)
 0x422E,  // 88 :: rgb(133,136,119)
 0xA528,  // 89 :: rgb(75,76,67)
 0xAD69,  // 90 :: rgb(91,93,73)
 0xDEF7,  // 91 :: rgb(193,189,186)
 0xAD89,  // 92 :: rgb(92,102,78)
 0x7FFF,  // 93 :: rgb(255,249,251)
 0xFFDE,  // 94 :: rgb(255,248,248)
 0xFC64,  // 95 :: rgb(255,30,30)
 0xF3E0,  // 96 :: rgb(234,255,0)
 0x7D4A,  // 97 :: rgb(255,79,79)
 0x7F5A,  // 98 :: rgb(255,211,211)
 0xFF18,  // 99 :: rgb(255,198,198)
 0x2949,  // 100 :: rgb(82,80,75)
 0xD739,  // 101 :: rgb(170,206,206)
 0xCE71,  // 102 :: rgb(155,158,138)
 0x4E10,  // 103 :: rgb(153,131,134)
 0x98C5,  // 104 :: rgb(52,51,42)
 0xFF9C,  // 105 :: rgb(255,232,232)
 0xA108,  // 106 :: rgb(68,68,62)
 0x5694,  // 107 :: rgb(175,160,162)
 0x7F7B,  // 108 :: rgb(255,220,220)
 0xFF5A,  // 109 :: rgb(255,213,213)
 0x7F18,  // 110 :: rgb(255,194,194)
 0x9908,  // 111 :: rgb(51,67,66)
 0x1D06,  // 112 :: rgb(61,64,49)
 0x1CE6,  // 113 :: rgb(56,55,49)
 0x11C4,  // 114 :: rgb(31,114,31)
 0x318C,  // 115 :: rgb(101,97,97)
 0x7CE7,  // 116 :: rgb(255,55,55)
 0x7DEF,  // 117 :: rgb(255,120,120)
 0x7E52,  // 118 :: rgb(255,145,145)
 0xA969,  // 119 :: rgb(85,95,70)
 0xD274,  // 120 :: rgb(161,158,163)
 0xBDCF,  // 121 :: rgb(120,117,122)
 0x7D29,  // 122 :: rgb(255,74,74)
 0xFCE7,  // 123 :: rgb(255,60,60)
 0xFC85,  // 124 :: rgb(255,38,38)
 0x5B5A,  // 125 :: rgb(179,212,212)
 0x8C84,  // 126 :: rgb(26,36,33)
 0x2D4A,  // 127 :: rgb(87,80,81)
 0x35CA,  // 128 :: rgb(103,113,81)
 0x18C6,  // 129 :: rgb(49,49,47)
 0x4E52,  // 130 :: rgb(158,145,147)
 0x7FDD,  // 131 :: rgb(255,242,242)
 0xAD49,  // 132 :: rgb(91,87,71)
 0x9104,  // 133 :: rgb(34,68,34)
 0x3E73,  // 134 :: rgb(123,154,153)
 0xB210,  // 135 :: rgb(102,134,133)
 0xB9CC,  // 136 :: rgb(117,119,102)
 0x1CE6,  // 137 :: rgb(54,58,46)
 0xA107,  // 138 :: rgb(67,68,58)
 0xAD4B,  // 139 :: rgb(90,87,94)
 0x422E,  // 140 :: rgb(132,136,115)
 0x952C,  // 141 :: rgb(41,75,98)
 0xC62F,  // 142 :: rgb(140,143,122)
 0x1083,  // 143 :: rgb(34,32,23)
 0x7D08,  // 144 :: rgb(255,64,64)
 0x3E0C,  // 145 :: rgb(123,128,98)
 0xB9E0,  // 146 :: rgb(117,127,0)
 0x98C5,  // 147 :: rgb(46,51,39)
 0xB58B,  // 148 :: rgb(105,103,88)
 0x9D29,  // 149 :: rgb(61,77,76)
 0x35AE,  // 150 :: rgb(108,105,113)
 0xC211,  // 151 :: rgb(135,132,137)
 0xB16B,  // 152 :: rgb(96,94,93)
 0x2112,  // 153 :: rgb(65,66,146)
 0x6718,  // 154 :: rgb(204,193,195)
 0x7ED6,  // 155 :: rgb(255,179,179)
 0x7E94,  // 156 :: rgb(255,163,163)
 0xFFBD,  // 157 :: rgb(255,238,238)
 0x7CC6,  // 158 :: rgb(255,49,49)
 0xFF39,  // 159 :: rgb(255,207,207)
 0xB5CB,  // 160 :: rgb(108,117,93)
 0xD292,  // 161 :: rgb(163,166,145)
 0xBA52,  // 162 :: rgb(118,148,147)
 0xA54B,  // 163 :: rgb(78,83,88)
 0xD694,  // 164 :: rgb(170,165,161)
 0x7EF7,  // 165 :: rgb(255,188,188)
 0x7F39,  // 166 :: rgb(255,204,204)
 0xFE31,  // 167 :: rgb(255,141,141)
 0x4293,  // 168 :: rgb(130,160,159)
 0x2529,  // 169 :: rgb(76,73,71)
 0x4A95,  // 170 :: rgb(149,161,174)
 0x6739,  // 171 :: rgb(207,204,202)
 0x4AB5,  // 172 :: rgb(146,172,171)
 0x7700,  // 173 :: rgb(236,195,4)
 0xFD4A,  // 174 :: rgb(255,86,86)
 0xFE52,  // 175 :: rgb(255,148,148)
 0x296B,  // 176 :: rgb(82,88,90)
 0xDAD4,  // 177 :: rgb(179,184,167)
 0x2106,  // 178 :: rgb(68,65,46)
 0x14C6,  // 179 :: rgb(40,48,46)
 0xDAD6,  // 180 :: rgb(185,181,177)
 0x7620,  // 181 :: rgb(236,138,4)
 0x0C63,  // 182 :: rgb(26,25,24)
 0x9926,  // 183 :: rgb(48,78,48)
 0x042F,  // 184 :: rgb(5,8,127)
 0x7D6B,  // 185 :: rgb(255,90,90)
 0xFD8D,  // 186 :: rgb(255,103,103)
 0x7EB5,  // 187 :: rgb(255,172,172)
 0x7D8C,  // 188 :: rgb(255,99,99)
 0xFDCE,  // 189 :: rgb(255,117,117)
 0xA548,  // 190 :: rgb(77,87,62)
 0x3E0D,  // 191 :: rgb(125,128,107)
 0xCE95,  // 192 :: rgb(157,166,176)
 0x90A5,  // 193 :: rgb(35,45,42)
 0x8CE3,  // 194 :: rgb(24,62,24)
 0x7EC9,  // 195 :: rgb(255,177,78)
 0x38A5,  // 196 :: rgb(116,41,41)
 0x6580,  // 197 :: rgb(206,97,0)
 0xFD6C,  // 198 :: rgb(255,95,95)
 0x116E,  // 199 :: rgb(29,88,119)
 0x1CC8,  // 200 :: rgb(60,49,69)
 0xFEB5,  // 201 :: rgb(255,175,175)
 0xFE94,  // 202 :: rgb(255,165,165)
 0x7E10,  // 203 :: rgb(255,131,131)
 0x56B5,  // 204 :: rgb(171,169,174)
 0xC694,  // 205 :: rgb(137,165,164)
 0x6FA0,  // 206 :: rgb(222,236,4)
 0xF16C,  // 207 :: rgb(233,95,96)
 0x1489,  // 208 :: rgb(42,31,71)
 0xFEC9,  // 209 :: rgb(253,181,74)
 0x15F6,  // 210 :: rgb(41,122,185)
 0xB58C,  // 211 :: rgb(103,102,101)
 0x2948,  // 212 :: rgb(84,80,63)
 0x1EDD,  // 213 :: rgb(58,177,238)
 0xAE78,  // 214 :: rgb(88,156,199)
 0x1D4B,  // 215 :: rgb(60,81,87)
 0x08E2,  // 216 :: rgb(15,57,15)
 0x3587,  // 217 :: rgb(105,97,55)
 0x8199,  // 218 :: rgb(0,102,204)
 0xD2B6,  // 219 :: rgb(163,175,182)
 0x8D6D,  // 220 :: rgb(24,93,106)
 0xD6D7,  // 221 :: rgb(172,182,191)
 0x0E59,  // 222 :: rgb(28,146,207)
 0x7FDE,  // 223 :: rgb(255,243,243)
 0x80CC,  // 224 :: rgb(0,51,102)
 0x7FFE,  // 225 :: rgb(251,250,250)
 0x4211,  // 226 :: rgb(134,131,138)
 0x0842,  // 227 :: rgb(17,16,16)
 0xEB0E,  // 228 :: rgb(212,197,116)
 0xDD84,  // 229 :: rgb(186,102,30)
 0x30C6,  // 230 :: rgb(96,48,48)
 0x9483,  // 231 :: rgb(41,35,28)
 0x2657,  // 232 :: rgb(70,144,192)
 0xAA9D,  // 233 :: rgb(79,167,235)
 0xAA34,  // 234 :: rgb(86,142,165)
 0x92DA,  // 235 :: rgb(36,183,210)
 0xD084,  // 236 :: rgb(164,35,30)
 0x560C,  // 237 :: rgb(169,131,96)
 0x108B,  // 238 :: rgb(34,31,88)
 0x3D65,  // 239 :: rgb(127,88,39)
 0x5E91,  // 240 :: rgb(188,160,143)
 0x9908,  // 241 :: rgb(49,70,64)
 0xA533,  // 242 :: rgb(76,78,157)
 0xC215,  // 243 :: rgb(133,133,175)
 0x092D,  // 244 :: rgb(14,73,103)
 0x0C44,  // 245 :: rgb(21,15,35)
 0x9C22,  // 246 :: rgb(59,14,13)
 0x7C9F,  // 247 :: rgb(255,33,255)
 0x12B8,  // 248 :: rgb(33,172,197)
 0x4A57,  // 249 :: rgb(144,145,187)
 0x1D29,  // 250 :: rgb(59,74,73)
 0x7C00,  // 251 :: rgb(255,0,0)
 0x18C5,  // 252 :: rgb(47,47,38)
 0x3DAB,  // 253 :: rgb(125,107,92)
 0xA4E6,  // 254 :: rgb(70,59,47)
 0x4D80,  // 255 :: rgb(160,96,0)
};