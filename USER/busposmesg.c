/*
	�ļ�����      busposmesg.c
	�ļ������� ����վ����Ϣ
	�޸�ʱ�䣺 2019��5��1��
	���ߣ�	     ������
	����˵���� ��
	
*/
#include "busposmesg.h"
#include <string.h>

const double pos_gpsmesg[POS_NUM][2] = {
						{21.1470552758,110.2990288084},{21.1297094859,110.3182969010},{21.1331244653,110.3290156582},
						{21.1460370322,110.3482318478},{21.1569863932,110.3641227803},{21.1686338800,110.3829590482},
						{21.1767912071,110.3904953509},{21.1824816814,110.3953417960}, {21.1892920632,110.3865342185},
						};

const char pos_cname[POS_NUM][8][16] = {
{
{0x10,0x60,0x02,0x0C,0xC0,0x10,0x08,0xF7,0x14,0x54,0x94,0x14,0xF4,0x04,0x00,0x00},
{0x04,0x04,0x7C,0x03,0x00,0x01,0x1D,0x13,0x11,0x55,0x99,0x51,0x3F,0x11,0x01,0x00},/*"��",0*/
{0x10,0x60,0x02,0x8C,0x00,0x10,0x91,0x96,0x90,0xF0,0x90,0x94,0x93,0x10,0x00,0x00},
{0x04,0x04,0x7E,0x01,0x00,0x04,0x04,0x04,0x04,0xFF,0x04,0x04,0x04,0x04,0x04,0x00},/*"��",1*/
{0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xFF,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00},
{0x80,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00},/*"��",2*/
{0x40,0x30,0x11,0x96,0x90,0x90,0x91,0x96,0x90,0x90,0x98,0x14,0x13,0x50,0x30,0x00},
{0x04,0x04,0x04,0x04,0x04,0x44,0x84,0x7E,0x06,0x05,0x04,0x04,0x04,0x04,0x04,0x00},/*"ѧ",3*/
},
{
{0x10,0x60,0x02,0x0C,0xC0,0x10,0x08,0xF7,0x14,0x54,0x94,0x14,0xF4,0x04,0x00,0x00},
{0x04,0x04,0x7C,0x03,0x00,0x01,0x1D,0x13,0x11,0x55,0x99,0x51,0x3F,0x11,0x01,0x00},/*"��",0*/
{0x00,0x00,0xFE,0x12,0x92,0x92,0x92,0x92,0x52,0x52,0x52,0x52,0x12,0x1E,0x00,0x00},
{0x80,0x60,0x1F,0x20,0x24,0x24,0x24,0x7F,0x92,0x92,0x92,0x92,0x90,0x80,0xE0,0x00},/*"β",1*/
{0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00},
{0x04,0x03,0x00,0xFF,0x00,0x03,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00,0x00},/*"��",2*/

},
{

{0x00,0xF8,0x00,0x00,0xFF,0x40,0x20,0x18,0x0F,0x18,0x68,0x08,0x08,0x08,0x08,0x00},
{0x00,0x1F,0x00,0x00,0xFF,0x00,0x00,0x7F,0x21,0x21,0x3F,0x21,0x21,0x7F,0x00,0x00},/*"��",0*/
{0x00,0x08,0x88,0x48,0x28,0x18,0x0F,0xE8,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00},
{0x00,0x20,0x11,0x09,0x05,0x41,0x81,0x7F,0x01,0x01,0x05,0x09,0x11,0x20,0x00,0x00},/*"��",1*/
{0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00},
{0x04,0x03,0x00,0xFF,0x00,0x03,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00,0x00},/*"��",2*/

},
 {
{0x00,0x10,0x10,0x10,0x10,0xD0,0x30,0xFF,0x30,0xD0,0x10,0x10,0x10,0x10,0x00,0x00},
{0x10,0x08,0x04,0x02,0x01,0x00,0x00,0xFF,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x00},/*"ľ",0*/
{0x00,0x20,0x20,0x21,0x22,0x2C,0x20,0x20,0x20,0x28,0x24,0x23,0x20,0x20,0x00,0x00},
{0x40,0x40,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x40,0x40,0x00},/*"��",1*/
{0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00},
{0x04,0x03,0x00,0xFF,0x00,0x03,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00,0x00},/*"��",2*/

},

 {
{0x10,0x4C,0x44,0x44,0x44,0x44,0x45,0xC6,0x44,0x44,0x44,0x44,0x44,0x54,0x0C,0x00},
{0x40,0x40,0x44,0x44,0x44,0x44,0x44,0x7F,0x44,0x44,0x54,0x64,0x44,0x40,0x40,0x00},/*"��",0*/
{0x10,0x60,0x02,0x8C,0x00,0x24,0x24,0x2F,0xE4,0x24,0x24,0xE4,0x2F,0x24,0x24,0x00},
{0x04,0x04,0x7E,0x01,0x00,0xFF,0x11,0x09,0x07,0x19,0x09,0x07,0x49,0x91,0x7F,0x00},/*"��",1*/
{0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00},
{0x04,0x03,0x00,0xFF,0x00,0x03,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00,0x00},/*"��",2*/

},

{
{0x02,0x02,0x02,0x02,0xC2,0xB2,0x8E,0x82,0x82,0x82,0x82,0x82,0x82,0x02,0x02,0x00},
{0x08,0x04,0x02,0x01,0xFF,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0xFF,0x00,0x00,0x00},/*"ʯ",0*/
{0x00,0x00,0x10,0x60,0x04,0x18,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x81,0x81,0x41,0x41,0x21,0x11,0x09,0x07,0x01,0x05,0x09,0x11,0x21,0xC1,0x01,0x00},/*"ͷ",1*/
{0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00},
{0x04,0x03,0x00,0xFF,0x00,0x03,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00,0x00},/*"��",2*/

},
{
{0x10,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0xF0,0x10,0x11,0x16,0xD0,0x10,0x10,0x00},
{0x80,0x40,0x20,0x18,0x06,0x41,0x20,0x10,0x3F,0x44,0x42,0x41,0x40,0x40,0x78,0x00},/*"��",0*/
{0x20,0x20,0x20,0xFF,0x20,0x22,0x14,0x90,0x10,0x00,0xF8,0x00,0x00,0xFF,0x00,0x00},
{0x40,0x40,0x20,0x13,0x0C,0x14,0x22,0x41,0xF8,0x00,0x0F,0x40,0x80,0x7F,0x00,0x00},/*"��",1*/
{0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00},
{0x04,0x03,0x00,0xFF,0x00,0x03,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00,0x00},/*"��",2*/
},
{
{0x10,0x60,0x02,0x8C,0x00,0x88,0x88,0xFF,0x88,0x88,0x00,0xFE,0x22,0x22,0xFE,0x00},
{0x04,0x04,0x7E,0x01,0x00,0x1F,0x08,0x08,0x08,0x9F,0x60,0x1F,0x42,0x82,0x7F,0x00},/*"��",0*/
{0x40,0x40,0x42,0x44,0x58,0xC0,0x40,0x7F,0x40,0xC0,0x50,0x48,0x46,0x40,0x40,0x00},
{0x80,0x80,0x40,0x20,0x18,0x07,0x00,0x00,0x00,0x3F,0x40,0x40,0x40,0x40,0x78,0x00},/*"��",1*/
{0x00,0x3E,0x22,0xE2,0x22,0x3E,0x00,0x10,0x88,0x57,0x24,0x54,0x8C,0x00,0x00,0x00},
{0x40,0x7E,0x40,0x3F,0x22,0x22,0x00,0x01,0xFE,0x42,0x42,0x42,0xFE,0x01,0x01,0x00},/*"·",2*/
{0x00,0x00,0xFC,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0xFC,0x00,0x00,0x00},
{0x00,0x00,0x7F,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x7F,0x00,0x00,0x00},/*"��",3*/
},
{
{0x10,0x60,0x02,0x0C,0xC0,0x10,0x08,0x27,0x24,0x24,0x24,0x24,0x24,0x04,0x00,0x00},
{0x04,0x04,0x7C,0x03,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x3F,0x40,0xF0,0x00},/*"��",0*/
{0x00,0x08,0x88,0x48,0x28,0x18,0x0F,0xE8,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00},
{0x08,0x08,0x09,0x09,0x09,0x09,0x09,0xFF,0x09,0x09,0x09,0x09,0x09,0x08,0x08,0x00},/*"��",1*/
{0x04,0xE4,0x24,0x24,0x64,0xA4,0x24,0x3F,0x24,0xA4,0x64,0x24,0x24,0xE4,0x04,0x00},
{0x00,0xFF,0x00,0x08,0x09,0x09,0x09,0x7F,0x09,0x09,0x09,0x48,0x80,0x7F,0x00,0x00},/*"��",2*/
{0x00,0xC8,0x08,0x09,0x0E,0xE8,0x08,0x00,0x00,0x00,0xFF,0x10,0x10,0x10,0x10,0x00},
{0x10,0x30,0x17,0x10,0x0E,0x09,0x08,0xFF,0x41,0x41,0x41,0x41,0x41,0xFF,0x00,0x00},/*"վ",3*/


}
 
};
const char daole[][16] ={
{0x42,0x62,0x52,0x4A,0xC6,0x42,0x52,0x62,0xC2,0x00,0xF8,0x00,0x00,0xFF,0x00,0x00},
{0x40,0xC4,0x44,0x44,0x7F,0x24,0x24,0x24,0x20,0x00,0x0F,0x40,0x80,0x7F,0x00,0x00},/*"��",0*/
{0x00,0x02,0x02,0x02,0x02,0x02,0x02,0xE2,0x22,0x12,0x0A,0x06,0x02,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",1*/
{0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x33,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",2*/

};
const char gj[][16] = {
{0x00,0x80,0x40,0x20,0x18,0x06,0x80,0x00,0x07,0x18,0x20,0x40,0x80,0x00,0x00,0x00},
{0x01,0x00,0x20,0x70,0x28,0x26,0x21,0x20,0x20,0x24,0x38,0x60,0x00,0x01,0x01,0x00},/*"��",0*/
{0x08,0x08,0x88,0x68,0x08,0x08,0x09,0x0E,0x08,0x08,0x88,0x28,0x48,0x88,0x08,0x00},
{0x80,0x81,0x40,0x40,0x21,0x22,0x14,0x08,0x14,0x22,0x41,0x40,0x80,0x81,0x80,0x00},/*"��",1*/
{0x40,0x42,0xCC,0x00,0x00,0x82,0x92,0x92,0xF2,0x9E,0x92,0x92,0xF2,0x82,0x80,0x00}
};

const char productionmsg[][16] = {
{0x40,0x42,0xCC,0x00,0x00,0x82,0x92,0x92,0xF2,0x9E,0x92,0x92,0xF2,0x82,0x80,0x00},
{0x00,0x00,0x7F,0x20,0x10,0x00,0xFC,0x44,0x44,0x44,0x44,0x44,0xFC,0x00,0x00,0x00},/*"��",0*/
{0x40,0x40,0x44,0x44,0x54,0x64,0x45,0x46,0x44,0x64,0x54,0x44,0x44,0x40,0x40,0x00},
{0x00,0x00,0x00,0xFF,0x49,0x49,0x49,0x49,0x49,0x49,0x49,0xFF,0x00,0x00,0x00,0x00},/*"��",1*/
{0x10,0x10,0xFF,0x10,0x90,0x82,0x56,0x3A,0x12,0x7F,0x11,0x39,0x55,0x90,0x80,0x00},
{0x42,0x82,0x7F,0x01,0x00,0x00,0xFF,0x49,0x49,0x7F,0x49,0x49,0xFF,0x00,0x00,0x00},/*"��",2*/
{0x10,0x10,0x10,0xFF,0x10,0x90,0x00,0xFE,0x82,0x82,0x82,0x92,0xA2,0x9E,0x00,0x00},
{0x04,0x44,0x82,0x7F,0x01,0x00,0x00,0xFF,0x80,0x43,0x2C,0x10,0x2C,0x43,0x80,0x00},/*"��",3*/
{0x00,0x00,0x22,0x32,0x2A,0xA6,0xA2,0x62,0x21,0x11,0x09,0x81,0x01,0x00,0x00,0x00},
{0x00,0x42,0x22,0x13,0x0B,0x42,0x82,0x7E,0x02,0x02,0x0A,0x12,0x23,0x46,0x00,0x00},/*"ϵ",4*/
{0x20,0x30,0xAC,0x63,0x30,0x00,0x88,0xC8,0xA8,0x99,0x8E,0x88,0xA8,0xC8,0x88,0x00},
{0x22,0x67,0x22,0x12,0x12,0x80,0x40,0x30,0x0F,0x00,0x00,0x3F,0x40,0x40,0x71,0x00},/*"ͳ",5*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",6*/



};
const char schoolname[][16] = {
{0x10,0x60,0x02,0x0C,0xC0,0x10,0x08,0xF7,0x14,0x54,0x94,0x14,0xF4,0x04,0x00,0x00},
{0x04,0x04,0x7C,0x03,0x00,0x01,0x1D,0x13,0x11,0x55,0x99,0x51,0x3F,0x11,0x01,0x00},/*"��",0*/
{0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xFF,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00},
{0x80,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00},/*"��",1*/
{0x00,0x00,0xF8,0x88,0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x88,0xF8,0x00,0x00,0x00},
{0x00,0x00,0x1F,0x08,0x08,0x08,0x08,0x7F,0x88,0x88,0x88,0x88,0x9F,0x80,0xF0,0x00},/*"��",2*/
{0x20,0x10,0x4C,0x47,0x54,0x54,0x54,0x54,0x54,0x54,0x54,0xD4,0x04,0x04,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x30,0x40,0xF0,0x00},/*"��",3*/

};
const char author[][16] = {
{0x10,0x60,0x02,0x8C,0x00,0x02,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x82,0x00,0x00},
{0x04,0x04,0x7E,0x01,0x40,0x40,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x00},/*"��",0*/
{0x20,0x20,0x24,0x24,0x24,0xA4,0x24,0x24,0x20,0xFF,0x20,0x22,0x2C,0x20,0x20,0x00},
{0x40,0xC0,0x7E,0x40,0x40,0x3F,0x22,0x22,0x20,0x03,0x0C,0x10,0x20,0x40,0xF8,0x00},/*"��",1*/
{0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0x10,0x10,0xD0,0xFF,0xD0,0x10,0x10,0x10,0x00},
{0x04,0x03,0x00,0xFF,0x00,0x11,0x08,0x04,0x03,0x00,0xFF,0x00,0x03,0x04,0x08,0x00},/*"��",2*/


};

const char taitou[][16] = {
{0x00,0x00,0xFF,0x88,0x88,0x48,0x48,0x00,0x7F,0x88,0x84,0x84,0x82,0xE0,0x00,0x00},
{0x04,0x04,0x05,0x04,0x04,0x04,0x04,0xFF,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00},/*"��",0*/
{0x00,0x10,0x60,0x80,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0xC0,0x30,0x00,0x00},
{0x40,0x40,0x40,0x43,0x40,0x7F,0x40,0x40,0x40,0x7F,0x42,0x41,0x40,0x40,0x40,0x00},/*"ҵ",1*/
{0x40,0x40,0x42,0xCC,0x00,0x40,0xA0,0x9E,0x82,0x82,0x82,0x9E,0xA0,0x20,0x20,0x00},
{0x00,0x00,0x00,0x3F,0x90,0x88,0x40,0x43,0x2C,0x10,0x28,0x46,0x41,0x80,0x80,0x00},/*"��",2*/
{0x40,0x40,0x42,0xCC,0x00,0x40,0x40,0x40,0x40,0xFF,0x40,0x40,0x40,0x40,0x40,0x00},
{0x00,0x00,0x00,0x7F,0x20,0x10,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",3*/
{0x00,0x80,0x60,0xF8,0x07,0x40,0x30,0x0F,0xF8,0x88,0x88,0x88,0x88,0x08,0x08,0x00},
{0x01,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x08,0x08,0x08,0x08,0x08,0x00,0x00},/*"��",4*/
{0x00,0x00,0x00,0x7E,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x7E,0x00,0x00,0x00,0x00},
{0x00,0xFE,0x42,0x42,0x42,0xFE,0x00,0x00,0x00,0xFE,0x42,0x42,0x42,0xFE,0x00,0x00},/*"Ʒ",5*/

};

const char title[][16] = {
{0x04,0x24,0x44,0x84,0x64,0x9C,0x40,0x30,0x0F,0xC8,0x08,0x08,0x28,0x18,0x00,0x00},
{0x10,0x08,0x06,0x01,0x82,0x4C,0x20,0x18,0x06,0x01,0x06,0x18,0x20,0x40,0x80,0x00},/*"��",0*/
{0x40,0x40,0x42,0xCC,0x00,0x00,0xFC,0x04,0x02,0x00,0xFC,0x04,0x04,0xFC,0x00,0x00},
{0x00,0x40,0x20,0x1F,0x20,0x40,0x4F,0x44,0x42,0x40,0x7F,0x42,0x44,0x43,0x40,0x00},/*"ӭ",1*/
{0x40,0x48,0x4A,0x4A,0xEA,0x0A,0x0A,0xFE,0x09,0x09,0xE9,0x49,0x49,0x28,0x80,0x00},
{0x22,0x22,0x11,0x11,0x0B,0x04,0x02,0xFF,0x02,0x04,0x09,0x12,0x12,0x22,0x23,0x00},/*"��",2*/
{0x00,0x80,0x60,0x1E,0x20,0xC0,0x00,0xFF,0x00,0x80,0x60,0x1E,0x20,0xC0,0x00,0x00},
{0x41,0x40,0x44,0x44,0x44,0x44,0x44,0x7F,0x44,0x44,0x44,0x44,0x44,0x40,0x40,0x00},/*"��",3*/

};
const char syz[][16] = {
{0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00},
{0x40,0x40,0x40,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00},/*"��",0*/
{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"һ",2*/
{0x00,0xC8,0x08,0x09,0x0E,0xE8,0x08,0x00,0x00,0x00,0xFF,0x10,0x10,0x10,0x10,0x00},
{0x10,0x30,0x17,0x10,0x0E,0x09,0x08,0xFF,0x41,0x41,0x41,0x41,0x41,0xFF,0x00,0x00},/*"վ",3*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",2*/
};
const char xyz[][16] = {
{0x02,0x02,0x02,0x02,0x02,0x02,0xFE,0x02,0x02,0x42,0x82,0x02,0x02,0x02,0x02,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00},/*"��",1*/
{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"һ",2*/
{0x00,0xC8,0x08,0x09,0x0E,0xE8,0x08,0x00,0x00,0x00,0xFF,0x10,0x10,0x10,0x10,0x00},
{0x10,0x30,0x17,0x10,0x0E,0x09,0x08,0xFF,0x41,0x41,0x41,0x41,0x41,0xFF,0x00,0x00},/*"վ",3*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",2*/
};
const char wd[][16] = {
{0x10,0x60,0x02,0x8C,0x00,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00,0x00},
{0x04,0x04,0x7E,0x01,0x40,0x7E,0x42,0x42,0x7E,0x42,0x7E,0x42,0x42,0x7E,0x40,0x00},/*"��",0*/
{0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0x25,0x26,0x24,0xFC,0x24,0x24,0x24,0x04,0x00},
{0x40,0x30,0x8F,0x80,0x84,0x4C,0x55,0x25,0x25,0x25,0x55,0x4C,0x80,0x80,0x80,0x00},/*"��",1*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",2*/

};
const char sd[][16] = {
{0x10,0x60,0x02,0x8C,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00,0x00},
{0x04,0x04,0x7E,0x01,0x44,0x48,0x50,0x7F,0x40,0x40,0x7F,0x50,0x48,0x44,0x40,0x00},/*"ʪ",0*/
{0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0x25,0x26,0x24,0xFC,0x24,0x24,0x24,0x04,0x00},
{0x40,0x30,0x8F,0x80,0x84,0x4C,0x55,0x25,0x25,0x25,0x55,0x4C,0x80,0x80,0x80,0x00},/*"��",1*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",2*/
};
const char nyr[][16] = 
{
{0x00,0x20,0x18,0xC7,0x44,0x44,0x44,0x44,0xFC,0x44,0x44,0x44,0x44,0x04,0x00,0x00},
{0x04,0x04,0x04,0x07,0x04,0x04,0x04,0x04,0xFF,0x04,0x04,0x04,0x04,0x04,0x04,0x00},/*"��",0*/
{0x00,0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0xFE,0x00,0x00,0x00},
{0x80,0x40,0x30,0x0F,0x02,0x02,0x02,0x02,0x02,0x02,0x42,0x82,0x7F,0x00,0x00,0x00},/*"��",1*/
{0x00,0x00,0x00,0xFE,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0xFE,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0xFF,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0xFF,0x00,0x00,0x00,0x00},/*"��",2*/
};



const char zlay1[][16] = {
{0x04,0x04,0xF4,0x54,0x35,0x9E,0x94,0x94,0x94,0xBE,0x55,0x54,0xF4,0x04,0x04,0x00},
{0x08,0x08,0x0B,0x0A,0x1A,0x6A,0x0A,0x0A,0x4A,0x8A,0x7E,0x0A,0x0B,0x08,0x08,0x00},/*"��",0*/
{0x20,0x20,0x24,0x24,0x24,0x24,0xBF,0x64,0x24,0x34,0x28,0x24,0x22,0x20,0x20,0x00},
{0x10,0x08,0x04,0x02,0x3F,0x45,0x44,0x44,0x42,0x42,0x42,0x41,0x78,0x00,0x00,0x00},/*"��",1*/
{0x80,0x64,0x2C,0x34,0x24,0x24,0xEC,0x32,0x22,0x22,0x32,0x2E,0x23,0xA2,0x60,0x00},
{0x00,0x41,0x21,0x91,0x89,0x87,0x4D,0x55,0x25,0x25,0x55,0x4D,0x81,0x80,0x80,0x00},/*"��",2*/
{0x40,0x70,0x4C,0x43,0xC0,0x30,0x00,0x10,0x10,0xFF,0x10,0x10,0x10,0xF0,0x00,0x00},
{0x10,0x38,0x14,0x13,0x14,0xB8,0x40,0x30,0x0E,0x01,0x40,0x80,0x40,0x3F,0x00,0x00},/*"��",3*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x58,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",4*/
{0x40,0x42,0xCC,0x00,0x00,0x44,0x54,0x54,0x54,0x7F,0x54,0x54,0x54,0x44,0x40,0x00},
{0x00,0x00,0x7F,0x20,0x10,0x00,0xFF,0x15,0x15,0x15,0x55,0x95,0x7F,0x00,0x00,0x00},/*"��",5*/
{0x00,0x80,0x60,0xF8,0x07,0x40,0x20,0x18,0x0F,0x08,0xC8,0x08,0x08,0x28,0x18,0x00},
{0x01,0x00,0x00,0xFF,0x00,0x10,0x0C,0x03,0x40,0x80,0x7F,0x00,0x01,0x06,0x18,0x00},/*"��",6*/
{0x00,0x20,0x22,0x2C,0x20,0x20,0xE0,0x3F,0x20,0x20,0x20,0x20,0xE0,0x00,0x00,0x00},
{0x80,0x40,0x20,0x10,0x08,0x06,0x01,0x00,0x01,0x46,0x80,0x40,0x3F,0x00,0x00,0x00},/*"Ϊ",7*/

};

const char zlay2[][16] = {
{0x04,0x04,0x04,0x84,0xE4,0x3C,0x27,0x24,0x24,0x24,0x24,0xE4,0x04,0x04,0x04,0x00},
{0x04,0x02,0x01,0x00,0xFF,0x09,0x09,0x09,0x09,0x49,0x89,0x7F,0x00,0x00,0x00,0x00},/*"��",0*/
{0x20,0x18,0x0A,0xAA,0xAA,0xAA,0x0A,0xFE,0x0A,0xAA,0xAA,0xAA,0x0A,0x28,0x18,0x00},
{0x02,0x02,0xFA,0x0A,0x0A,0x7A,0x0E,0x0A,0x7A,0x0A,0x4A,0x8A,0x7A,0x02,0x02,0x00},/*"��",1*/
{0x00,0x02,0xF2,0x92,0x92,0xFE,0x92,0x92,0x92,0xFE,0x92,0x92,0xF2,0x02,0x00,0x00},
{0x00,0x02,0x82,0x92,0x9A,0x56,0x63,0x22,0x32,0x4A,0x46,0x42,0x82,0x02,0x00,0x00},/*"Ҫ",2*/
{0x00,0xF8,0x0C,0x0B,0x08,0x08,0xF8,0x40,0x30,0x8F,0x08,0x08,0x08,0xF8,0x00,0x00},
{0x00,0x7F,0x21,0x21,0x21,0x21,0x7F,0x00,0x00,0x00,0x43,0x80,0x40,0x3F,0x00,0x00},/*"��",3*/
{0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x00,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x00},/*"��",4*/
{0x40,0x40,0x42,0xCC,0x00,0x00,0x00,0x00,0x00,0xFF,0x40,0x40,0x40,0x40,0x00,0x00},
{0x00,0x00,0x00,0x3F,0x50,0x48,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x00},/*"��",5*/
{0x00,0x00,0xFC,0x04,0x84,0x74,0x84,0x05,0xFE,0x04,0x84,0x74,0x84,0x04,0x04,0x00},
{0x40,0x30,0x4F,0x41,0x44,0x44,0x44,0x45,0x7F,0x45,0x44,0x44,0x44,0x41,0x40,0x00},/*"��",6*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x18,0x24,0x24,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",7*/

};
const char riqi[][16] = {
{0x00,0x00,0x00,0xFE,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0xFE,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0xFF,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0xFF,0x00,0x00,0x00,0x00},/*"��",0*/
{0x00,0x04,0xFF,0x24,0x24,0x24,0xFF,0x04,0x00,0xFE,0x22,0x22,0x22,0xFE,0x00,0x00},
{0x88,0x48,0x2F,0x09,0x09,0x19,0xAF,0x48,0x30,0x0F,0x02,0x42,0x82,0x7F,0x00,0x00},/*"��",1*/
};
const char shijian[][16] = {

{0x00,0xFC,0x84,0x84,0x84,0xFC,0x00,0x10,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x00},
{0x00,0x3F,0x10,0x10,0x10,0x3F,0x00,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00},/*"ʱ",0*/
{0x00,0xF8,0x01,0x06,0x00,0xF0,0x12,0x12,0x12,0xF2,0x02,0x02,0x02,0xFE,0x00,0x00},
{0x00,0xFF,0x00,0x00,0x00,0x1F,0x11,0x11,0x11,0x1F,0x00,0x40,0x80,0x7F,0x00,0x00},/*"��",1*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",4*/

};
const char sudu[][16] = {

{0x40,0x40,0x42,0xCC,0x00,0x04,0xF4,0x94,0x94,0xFF,0x94,0x94,0xF4,0x04,0x00,0x00},
{0x00,0x40,0x20,0x1F,0x20,0x48,0x44,0x42,0x41,0x5F,0x41,0x42,0x44,0x48,0x40,0x00},/*"��",0*/
{0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0x25,0x26,0x24,0xFC,0x24,0x24,0x24,0x04,0x00},
{0x40,0x30,0x8F,0x80,0x84,0x4C,0x55,0x25,0x25,0x25,0x55,0x4C,0x80,0x80,0x80,0x00},/*"��",1*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",4*/
};
const char zdxz[][16] = {
{0x00,0xC8,0x08,0x09,0x0E,0xE8,0x08,0x00,0x00,0x00,0xFF,0x10,0x10,0x10,0x10,0x00},
{0x10,0x30,0x17,0x10,0x0E,0x09,0x08,0xFF,0x41,0x41,0x41,0x41,0x41,0xFF,0x00,0x00},/*"վ",0*/
{0x00,0x00,0xC0,0x40,0x40,0x40,0x7F,0x48,0x48,0x48,0x48,0xC8,0x08,0x08,0x00,0x00},
{0x80,0x40,0x37,0x04,0x04,0x14,0x64,0x04,0x14,0x64,0x04,0x07,0x10,0xE0,0x00,0x00},/*"��",1*/
{0x40,0x40,0x42,0xCC,0x00,0x50,0x4E,0xC8,0x48,0x7F,0xC8,0x48,0x48,0x40,0x00,0x00},
{0x00,0x40,0x20,0x1F,0x20,0x50,0x4C,0x43,0x40,0x40,0x4F,0x50,0x50,0x5C,0x40,0x00},/*"ѡ",2*/
{0x10,0x10,0xFF,0x10,0x00,0x82,0x86,0x4A,0x52,0xA2,0x52,0x4A,0x86,0x80,0x80,0x00},
{0x42,0x82,0x7F,0x01,0x00,0x10,0x12,0x12,0x12,0xFF,0x12,0x12,0x12,0x10,0x00,0x00},/*"��",3*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",4*/

};

const char zuozhuan[][16] ={

{0x08,0x08,0x08,0x08,0x88,0x78,0x0F,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00},
{0x20,0x10,0x48,0x46,0x41,0x41,0x41,0x41,0x7F,0x41,0x41,0x41,0x41,0x40,0x40,0x00},/*"��",0*/
{0xC8,0xB8,0x8F,0xE8,0x88,0x88,0x40,0x48,0x48,0xE8,0x5F,0x48,0x48,0x48,0x40,0x00},
{0x08,0x18,0x08,0xFF,0x04,0x04,0x00,0x02,0x0B,0x12,0x22,0xD2,0x0A,0x06,0x00,0x00},/*"ת",1*/
};

const char youzhuan[][16] ={

{0x08,0x08,0x08,0x08,0xC8,0x38,0x0F,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00},
{0x08,0x04,0x02,0x01,0xFF,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0xFF,0x00,0x00,0x00},/*"��",0*/
{0xC8,0xB8,0x8F,0xE8,0x88,0x88,0x40,0x48,0x48,0xE8,0x5F,0x48,0x48,0x48,0x40,0x00},
{0x08,0x18,0x08,0xFF,0x04,0x04,0x00,0x02,0x0B,0x12,0x22,0xD2,0x0A,0x06,0x00,0x00},/*"ת",1*/

};
const char dianbo[][16] = {
{0x00,0x04,0xF4,0x54,0x5F,0x54,0xF4,0x04,0x02,0xF2,0x1A,0xD6,0x12,0xF2,0x02,0x00},
{0x00,0x90,0x5F,0x35,0x15,0x35,0x5F,0x90,0x80,0x4F,0x30,0x0F,0x10,0x2F,0xC0,0x00},/*"��",0*/
{0x48,0x44,0xF3,0x42,0x46,0xFA,0x42,0x0A,0xC4,0x43,0x42,0xF6,0x4A,0x42,0xC2,0x00},
{0x90,0x50,0x3F,0x15,0x35,0x5F,0x90,0x60,0x1F,0x82,0x5E,0x23,0x52,0x8E,0x80,0x00},/*"��",1*/
{0x40,0x40,0x42,0xCC,0x00,0x08,0x48,0x88,0x08,0x08,0x08,0xFF,0x08,0x08,0x08,0x00},
{0x00,0x40,0x20,0x1F,0x20,0x40,0x40,0x41,0x40,0x48,0x50,0x4F,0x40,0x40,0x40,0x00},/*"��",2*/
{0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xFF,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00},
{0x80,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00},/*"��",3*/

};
const char chaosu[][16] = {

{0x40,0x48,0x48,0x48,0xFF,0x48,0x48,0x42,0xA2,0x9E,0x82,0xA2,0xC2,0xBE,0x00,0x00},
{0x80,0x60,0x1F,0x20,0x7F,0x44,0x44,0x40,0x4F,0x48,0x48,0x48,0x48,0x4F,0x40,0x00},/*"��",0*/
{0x40,0x40,0x42,0xCC,0x00,0x04,0xF4,0x94,0x94,0xFF,0x94,0x94,0xF4,0x04,0x00,0x00},
{0x00,0x40,0x20,0x1F,0x20,0x48,0x44,0x42,0x41,0x5F,0x41,0x42,0x44,0x48,0x40,0x00},/*"��",1*/
{0x12,0xEA,0xAF,0xAA,0xEA,0x0F,0xFA,0x02,0x88,0x8C,0x57,0x24,0x54,0x8C,0x84,0x00},
{0x02,0x02,0xEA,0xAA,0xAA,0xAB,0xAA,0xAB,0xAA,0xAA,0xAA,0xAA,0xEA,0x02,0x02,0x00},/*"��",2*/
{0x80,0xA0,0x90,0x8E,0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x88,0x88,0x80,0x80,0x00},
{0x00,0x00,0x00,0xFC,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0xFC,0x00,0x00,0x00,0x00},/*"��",3*/

};
const char set[][16] = {
{0x40,0x42,0xCC,0x00,0x00,0x82,0x92,0x92,0xF2,0x9E,0x92,0x92,0xF2,0x82,0x80,0x00},
{0x00,0x00,0x7F,0x20,0x10,0x00,0xFC,0x44,0x44,0x44,0x44,0x44,0xFC,0x00,0x00,0x00},/*"��",0*/
{0x04,0x04,0x24,0x24,0x24,0x24,0x25,0x26,0x24,0x24,0x24,0x24,0x24,0x04,0x04,0x00},
{0x00,0x00,0xF9,0x49,0x49,0x49,0x49,0x49,0x49,0x49,0x49,0x49,0xF9,0x00,0x00,0x00},/*"��",1*/
{0x40,0x40,0x42,0xCC,0x00,0x40,0xA0,0x9E,0x82,0x82,0x82,0x9E,0xA0,0x20,0x20,0x00},
{0x00,0x00,0x00,0x3F,0x90,0x88,0x40,0x43,0x2C,0x10,0x28,0x46,0x41,0x80,0x80,0x00},/*"��",2*/
{0x00,0x17,0x15,0xD5,0x55,0x57,0x55,0x7D,0x55,0x57,0x55,0xD5,0x15,0x17,0x00,0x00},
{0x40,0x40,0x40,0x7F,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x7F,0x40,0x40,0x40,0x00},/*"��",3*/
{0x00,0x00,0xF8,0x88,0x88,0x88,0x88,0x08,0x08,0xFF,0x08,0x09,0x0A,0xC8,0x08,0x00},
{0x80,0x60,0x1F,0x00,0x10,0x20,0x1F,0x80,0x40,0x21,0x16,0x18,0x26,0x41,0xF8,0x00},/*"��",0*/
{0x08,0x08,0x08,0xF8,0x08,0x08,0x08,0x10,0x10,0xFF,0x10,0x10,0x10,0xF0,0x00,0x00},
{0x10,0x30,0x10,0x1F,0x08,0x88,0x48,0x30,0x0E,0x01,0x40,0x80,0x40,0x3F,0x00,0x00},/*"��",1*/
{0x02,0x02,0xFE,0x92,0x92,0x92,0xFE,0x02,0x06,0xFC,0x04,0x04,0x04,0xFC,0x00,0x00},
{0x08,0x18,0x0F,0x08,0x08,0x04,0xFF,0x04,0x84,0x40,0x27,0x18,0x27,0x40,0x80,0x00},/*"ȡ",0*/
{0x10,0x60,0x02,0x0C,0xC0,0x00,0xE2,0x2C,0x20,0x3F,0x20,0x28,0xE6,0x00,0x00,0x00},
{0x04,0x04,0x7C,0x03,0x00,0x00,0xFF,0x09,0x09,0x09,0x49,0x89,0x7F,0x00,0x00,0x00},/*"��",1*/

};
const char yuyan[][16] = {
{0x00,0x00,0xF0,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x10,0xF0,0x00,0x00,0x00},
{0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0xFF,0x04,0x04,0x04,0x04,0x0F,0x00,0x00,0x00},/*"��",0*/
{0x08,0x08,0x08,0x38,0xC8,0x08,0x09,0x0E,0x08,0x08,0xC8,0x38,0x08,0x08,0x08,0x00},
{0x80,0x80,0x40,0x40,0x20,0x11,0x0A,0x04,0x0A,0x11,0x20,0x40,0x40,0x80,0x80,0x00},/*"��",1*/
{0x04,0x04,0x04,0xC4,0x4F,0x44,0x44,0xF4,0x44,0x44,0x4F,0xC4,0x04,0x04,0x04,0x00},
{0x84,0x84,0x44,0x47,0x24,0x14,0x0C,0x07,0x0C,0x14,0x24,0x47,0x44,0x84,0x84,0x00},/*"Ӣ",2*/
{0x40,0x42,0xCC,0x00,0x00,0x82,0x92,0x92,0xF2,0x9E,0x92,0x92,0xF2,0x82,0x80,0x00},
{0x00,0x00,0x7F,0x20,0x10,0x00,0xFC,0x44,0x44,0x44,0x44,0x44,0xFC,0x00,0x00,0x00},/*"��",3*/
{0x10,0x60,0x02,0x8C,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00},
{0x04,0x04,0x7E,0x01,0x00,0xFE,0x88,0x48,0x48,0x00,0x7E,0x90,0x88,0x88,0xE4,0x00},/*"��",4*/
{0x40,0x40,0x20,0x20,0x50,0x48,0x44,0x43,0x44,0x48,0x50,0x20,0x20,0x40,0x40,0x00},
{0x00,0x00,0x00,0xFE,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0xFE,0x00,0x00,0x00,0x00},/*"��",5*/
};
const char timeandlanguage[][16]= {
{0x00,0xFC,0x84,0x84,0x84,0xFC,0x00,0x10,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x00},
{0x00,0x3F,0x10,0x10,0x10,0x3F,0x00,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00},/*"ʱ",0*/
{0x00,0xF8,0x01,0x06,0x00,0xF0,0x12,0x12,0x12,0xF2,0x02,0x02,0x02,0xFE,0x00,0x00},
{0x00,0xFF,0x00,0x00,0x00,0x1F,0x11,0x11,0x11,0x1F,0x00,0x40,0x80,0x7F,0x00,0x00},/*"��",1*/
{0x00,0x00,0xE0,0x9F,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x08,0x00,0x00},
{0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x48,0x80,0x40,0x3F,0x00,0x00,0x00},/*"��",2*/
{0x40,0x42,0xCC,0x00,0x00,0x82,0x92,0x92,0xF2,0x9E,0x92,0x92,0xF2,0x82,0x80,0x00},
{0x00,0x00,0x7F,0x20,0x10,0x00,0xFC,0x44,0x44,0x44,0x44,0x44,0xFC,0x00,0x00,0x00},/*"��",3*/
{0x04,0x04,0x24,0x24,0x24,0x24,0x25,0x26,0x24,0x24,0x24,0x24,0x24,0x04,0x04,0x00},
{0x00,0x00,0xF9,0x49,0x49,0x49,0x49,0x49,0x49,0x49,0x49,0x49,0xF9,0x00,0x00,0x00},/*"��",4*/

};
const char dingwei[][16] ={
{0x10,0x0C,0x44,0x44,0x44,0x44,0x45,0xC6,0x44,0x44,0x44,0x44,0x44,0x14,0x0C,0x00},
{0x80,0x40,0x20,0x1E,0x20,0x40,0x40,0x7F,0x44,0x44,0x44,0x44,0x44,0x40,0x40,0x00},/*"��",0*/
{0x00,0x80,0x60,0xF8,0x07,0x10,0x90,0x10,0x11,0x16,0x10,0x10,0xD0,0x10,0x00,0x00},
{0x01,0x00,0x00,0xFF,0x40,0x40,0x41,0x5E,0x40,0x40,0x70,0x4E,0x41,0x40,0x40,0x00},/*"λ",1*/
};

const char tuoluoyi[][16] = {
{0x00,0xFE,0x02,0x22,0xDA,0x06,0x20,0xD8,0x08,0x09,0x0E,0x08,0x88,0x28,0x18,0x00},
{0x00,0xFF,0x08,0x10,0x08,0x07,0x00,0x3F,0x44,0x44,0x42,0x41,0x40,0x78,0x00,0x00},/*"��",0*/
{0x00,0xF8,0x08,0xFF,0x08,0xF8,0x00,0x3E,0xAA,0x6A,0x3E,0x2A,0xAA,0x3E,0x00,0x00},
{0x20,0x63,0x21,0x1F,0x11,0x39,0x48,0x29,0x09,0x8D,0xFB,0x09,0x08,0x2C,0x58,0x00},/*"��",1*/
{0x00,0x80,0x60,0xF8,0x07,0x00,0x1C,0xE0,0x01,0x06,0x00,0xE0,0x1E,0x00,0x00,0x00},
{0x01,0x00,0x00,0xFF,0x00,0x80,0x40,0x20,0x13,0x0C,0x13,0x20,0x40,0x80,0x80,0x00},/*"��",2*/
};
const char shizhe[][16] = {
{0x40,0x40,0x42,0xCC,0x00,0x40,0xA0,0x9E,0x82,0x82,0x82,0x9E,0xA0,0x20,0x20,0x00},
{0x00,0x00,0x00,0x3F,0x90,0x88,0x40,0x43,0x2C,0x10,0x28,0x46,0x41,0x80,0x80,0x00},/*"��",0*/
{0x00,0x17,0x15,0xD5,0x55,0x57,0x55,0x7D,0x55,0x57,0x55,0xD5,0x15,0x17,0x00,0x00},
{0x40,0x40,0x40,0x7F,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x7F,0x40,0x40,0x40,0x00},/*"��",1*/
};

const char dakai[][16] = {
{0x10,0x10,0x10,0xFF,0x10,0x90,0x04,0x04,0x04,0x04,0xFC,0x04,0x04,0x04,0x04,0x00},
{0x04,0x44,0x82,0x7F,0x01,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00},/*"��",0*/
{0x80,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x80,0x00},
{0x00,0x80,0x40,0x30,0x0F,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00},/*"��",1*/

};
const char guanbi[][16] = {
{0x00,0x00,0x10,0x11,0x16,0x10,0x10,0xF0,0x10,0x10,0x14,0x13,0x10,0x00,0x00,0x00},
{0x81,0x81,0x41,0x41,0x21,0x11,0x0D,0x03,0x0D,0x11,0x21,0x41,0x41,0x81,0x81,0x00},/*"��",2*/
{0x00,0xF8,0x01,0x22,0x20,0x22,0x22,0xA2,0xFA,0x22,0x22,0x22,0x02,0xFE,0x00,0x00},
{0x00,0xFF,0x00,0x08,0x04,0x02,0x11,0x20,0x1F,0x00,0x00,0x40,0x80,0x7F,0x00,0x00},/*"��",3*/
};
const char jingweidu[][16] = {
{0x20,0x30,0xAC,0x63,0x20,0x18,0x80,0x82,0x42,0x22,0x12,0x1A,0x26,0x42,0x80,0x00},
{0x22,0x67,0x22,0x12,0x12,0x12,0x40,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x40,0x00},/*"��",0*/
{0x20,0x30,0xAC,0x63,0x20,0x18,0x00,0x08,0x48,0x48,0xFF,0x48,0x48,0x48,0x08,0x00},
{0x22,0x67,0x22,0x12,0x12,0x12,0x00,0x02,0x02,0x02,0xFF,0x02,0x12,0x22,0x1E,0x00},/*"γ",1*/
{0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0x25,0x26,0x24,0xFC,0x24,0x24,0x24,0x04,0x00},
{0x40,0x30,0x8F,0x80,0x84,0x4C,0x55,0x25,0x25,0x25,0x55,0x4C,0x80,0x80,0x80,0x00},/*"��",2*/
{0x90,0x52,0x34,0x10,0xFF,0x10,0x34,0x52,0x80,0x70,0x8F,0x08,0x08,0xF8,0x08,0x00},
{0x82,0x9A,0x56,0x63,0x22,0x52,0x8E,0x00,0x80,0x40,0x33,0x0C,0x33,0x40,0x80,0x00},/*"��",3*/
{0x10,0x10,0xFF,0x10,0x90,0x00,0xFE,0x92,0x92,0x92,0xF2,0x92,0x92,0x9E,0x80,0x00},
{0x42,0x82,0x7F,0x01,0x80,0x60,0x1F,0x00,0xFC,0x44,0x47,0x44,0x44,0xFC,0x00,0x00},/*"��",4*/
};
const char jingdu[][16] = {
{0x20,0x30,0xAC,0x63,0x20,0x18,0x80,0x82,0x42,0x22,0x12,0x1A,0x26,0x42,0x80,0x00},
{0x22,0x67,0x22,0x12,0x12,0x12,0x40,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x40,0x00},/*"��",0*/
{0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0x25,0x26,0x24,0xFC,0x24,0x24,0x24,0x04,0x00},
{0x40,0x30,0x8F,0x80,0x84,0x4C,0x55,0x25,0x25,0x25,0x55,0x4C,0x80,0x80,0x80,0x00},/*"��",2*/
};

const char weidu[][16] = {
{0x20,0x30,0xAC,0x63,0x20,0x18,0x00,0x08,0x48,0x48,0xFF,0x48,0x48,0x48,0x08,0x00},
{0x22,0x67,0x22,0x12,0x12,0x12,0x00,0x02,0x02,0x02,0xFF,0x02,0x12,0x22,0x1E,0x00},/*"γ",1*/
{0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0x25,0x26,0x24,0xFC,0x24,0x24,0x24,0x04,0x00},
{0x40,0x30,0x8F,0x80,0x84,0x4C,0x55,0x25,0x25,0x25,0x55,0x4C,0x80,0x80,0x80,0x00},/*"��",2*/
};