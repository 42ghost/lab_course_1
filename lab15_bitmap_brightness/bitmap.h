#ifndef BITMAP_H
#define BITMAP_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct
{
    uint16_t	bfType;
    uint32_t	bfSize;
    uint16_t	bfReserved1;
    uint16_t	bfReserved2;
    uint32_t	bfOffBits;
} BitmapFileHeader;

typedef struct
{
    uint32_t 	biSize;
    int32_t 	biWidth;
    int32_t 	biHeight;
    uint16_t 	biPlanes;
    uint16_t 	biBitCount;
    uint32_t 	biCompression;
    uint32_t 	biSizeImage;
    int32_t 	biXPelsPerMeter;
    int32_t 	biYPelsPerMeter;
    uint32_t 	biClrUsed;
    uint32_t 	biClrImportant;
} BitmapInfoHeader;

typedef struct
{
    uint16_t	rgbBlue;
    uint16_t	rgbGreen;
    uint16_t	rgbRed;
} RGBTriple;


void readBitmapFile( BitmapFileHeader*, FILE* );
void writeBitmapFile( BitmapFileHeader*, FILE* );

void readBitmapInfo( BitmapInfoHeader*, FILE* );
void writeBitmapInfo( BitmapInfoHeader*, FILE* );

#endif










