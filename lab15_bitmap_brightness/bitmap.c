#include "bitmap.h"


void readBitmapFile(BitmapFileHeader *header, FILE* fin)
{
	fread( &(header->bfType), sizeof(header->bfType), 1, fin );
	fread( &(header->bfSize), sizeof(header->bfSize), 1, fin );
	fread( &(header->bfReserved1), sizeof(header->bfReserved1), 1, fin );
	fread( &(header->bfReserved2), sizeof(header->bfReserved2), 1, fin );
	fread( &(header->bfOffBits), sizeof(header->bfOffBits), 1, fin );
}

void writeBitmapFile(BitmapFileHeader* header, FILE* fout)
{
	fwrite( &(header->bfType), sizeof(header->bfType), 1, fout );
	fwrite( &(header->bfSize), sizeof(header->bfSize), 1, fout );
	fwrite( &(header->bfReserved1), sizeof(header->bfReserved1), 1, fout );
	fwrite( &(header->bfReserved2), sizeof(header->bfReserved2), 1, fout );
	fwrite( &(header->bfOffBits), sizeof(header->bfOffBits), 1, fout );
}

void readBitmapInfo(BitmapInfoHeader *bmiHeader, FILE* fin)
{
	fread( &(bmiHeader->biSize), sizeof(bmiHeader->biSize), 1, fin );
	fread( &(bmiHeader->biWidth), sizeof(bmiHeader->biWidth), 1, fin );
	fread( &(bmiHeader->biHeight), sizeof(bmiHeader->biHeight), 1, fin );
	fread( &(bmiHeader->biPlanes), sizeof(bmiHeader->biPlanes), 1, fin );
	fread( &(bmiHeader->biBitCount), sizeof(bmiHeader->biBitCount), 1, fin );
	fread( &(bmiHeader->biCompression), sizeof(bmiHeader->biCompression), 1, fin );
	fread( &(bmiHeader->biSizeImage), sizeof(bmiHeader->biSizeImage ), 1, fin );
	fread( &(bmiHeader->biXPelsPerMeter), sizeof(bmiHeader->biXPelsPerMeter), 1, fin );
	fread( &(bmiHeader->biYPelsPerMeter), sizeof(bmiHeader->biYPelsPerMeter), 1, fin );
	fread( &(bmiHeader->biClrUsed), sizeof(bmiHeader->biClrUsed), 1, fin );
	fread( &(bmiHeader->biClrImportant), sizeof(bmiHeader->biClrImportant), 1, fin );
	
	fseek(fin, bmiHeader->biSize - 40, SEEK_CUR);
}

void writeBitmapInfo(BitmapInfoHeader* bmiHeader, FILE* fout)
{
	fwrite( &(bmiHeader->biSize), sizeof(bmiHeader->biSize), 1, fout );
	fwrite( &(bmiHeader->biWidth), sizeof(bmiHeader->biWidth), 1, fout );
	fwrite( &(bmiHeader->biHeight), sizeof(bmiHeader->biHeight), 1, fout );
	fwrite( &(bmiHeader->biPlanes), sizeof(bmiHeader->biPlanes), 1, fout );
	fwrite( &(bmiHeader->biBitCount), sizeof(bmiHeader->biBitCount), 1, fout );
	fwrite( &(bmiHeader->biCompression), sizeof(bmiHeader->biCompression), 1, fout );
	fwrite( &(bmiHeader->biSizeImage), sizeof(bmiHeader->biSizeImage ), 1, fout );
	fwrite( &(bmiHeader->biXPelsPerMeter), sizeof(bmiHeader->biXPelsPerMeter), 1, fout );
	fwrite( &(bmiHeader->biYPelsPerMeter), sizeof(bmiHeader->biYPelsPerMeter), 1, fout );
	fwrite( &(bmiHeader->biClrUsed), sizeof(bmiHeader->biClrUsed), 1, fout );
	fwrite( &(bmiHeader->biClrImportant), sizeof(bmiHeader->biClrImportant), 1, fout );
}














