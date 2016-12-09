#include "gba.h"
#include "sprite.h"

// ���ׂẴX�v���C�g��\�������Ȃ�
void InitializeSprites(OAMEntry* sprites)
{
	int loop;
	for(loop = 0; loop < 128; loop++)
	{
		sprites[loop].attribute0 = 160;  //y to > 159
		sprites[loop].attribute1 = 240;  //x to > 239
	}
}

// �X�v���C�g�̈ʒu��ύX
void MoveSprite(OAMEntry* sp, int x, int y)
{
	if(x < 0)
		x = 512 + x;
	if(y < 0)
		y = 256 + y;

	sp->attribute1 = sp->attribute1 & 0xFE00;
	sp->attribute1 = sp->attribute1 | x;
	
	sp->attribute0 = sp->attribute0 & 0xFF00;
	sp->attribute0 = sp->attribute0 | y;
}	


// �X�v���C�g�̈ʒu���擾
void GetSpritePos(OAMEntry* sp, unsigned short *x, unsigned short *y)
{
	*x = sp->attribute1 & 0x1FF;
	*y = sp->attribute0 & 0x0FF;
}

/* -----------------------------------------  /
	SetSpriteSize
	�X�v���C�g�̌`���ݒ�
	sp�E�E�E�ύX����X�v���C�g���w��
	size�E�ESP_SIZE_8,SP_SIZE_16,SP_SIZE_32,SP_SIZE_64�̂����ꂩ
	form�E�ESP_SQUARE,SP_TALL,SP_WIDE
	color�E�ESP_COLOR_16,SP_COLOR_256
/ ------------------------------------------ */
void SetSpriteSize(OAMEntry* sp,u16 size,u16 form,u16 color)
{	

	sp->attribute0 &= 0x1FFF;
	sp->attribute0 |= color | form | (160);
	
	sp->attribute1 &= 0x3FFF;
	sp->attribute1 |= size | (240);
}

// �X�v���C�g�L�����N�^��ύX
void ChangeSprite(OAMEntry* sp, int ch)
{
	sp->attribute2 = sp->attribute2 & 0xFC00;
	
	sp->attribute2 = sp->attribute2 | ch;
}

void SpritePriority(OAMEntry* sp, int ch)
{
	sp->attribute2 = sp->attribute2 & 0xF3FF;
	sp->attribute2 = sp->attribute2 | SP_PRIORITY(ch);
}

u16 GetSpritePriority(OAMEntry* sp)
{
	return ( (sp->attribute2 & 0x0C00) >> 10);

}


void SpritePalette(OAMEntry* sp, int ch)
{
	sp->attribute2 = sp->attribute2 & 0x0FFF;
	sp->attribute2 = sp->attribute2 | SP_PALETTE(ch);
}

void SpriteMode(OAMEntry* sp, int ch)
{
	sp->attribute0 = sp->attribute0 & 0xF3FF;
	sp->attribute0 = sp->attribute0 | (ch << 10);
}

void SpritesErase(OAMEntry* sp)
{

		sp->attribute1 = sp->attribute1 & 0xFE00;
		sp->attribute1 = sp->attribute1 | 240;
		
		sp->attribute0 = sp->attribute0 & 0xFF00;
		sp->attribute0 = sp->attribute0 | 160;

}

