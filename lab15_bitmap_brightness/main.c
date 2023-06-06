// Finding the brightest square n by n in bmp image

#include <stdio.h>
#include "bitmap.h"


int main(int argc, char** argv)
{
	int n = atoi(argv[3]);
	//Добавить free
	FILE* fin = fopen(argv[1], "r");
	if (fin == NULL)
	{
		printf("File is not open");
		return 1;
	}
	
	// Чтение заголовка файла
	BitmapFileHeader header;
	readBitmapFile(&header, fin);
	
	// Чтение заголовка изображения
	BitmapInfoHeader bmiHeader;
	readBitmapInfo(&bmiHeader, fin);
	
	// Чтение матрицы цветов и создание матрицы яркости
	RGBTriple** rgb = (RGBTriple**)malloc(bmiHeader.biHeight * sizeof(RGBTriple*));
	long double** y = (long double**)malloc(bmiHeader.biHeight * sizeof(long double*));
	
	for (int i = 0; i < bmiHeader.biHeight; i++)
	{
		rgb[i] = (RGBTriple*)malloc(bmiHeader.biWidth * sizeof(RGBTriple));
		y[i] = (long double*)malloc(bmiHeader.biWidth * sizeof(long double));
	}
	
	for (int  i = 0; i < bmiHeader.biHeight; i++)
	{
		for (int j = 0; j < bmiHeader.biWidth; j++)
		{
			fread(&rgb[i][j].rgbBlue, 1, 1, fin);
			fread(&rgb[i][j].rgbGreen, 1, 1, fin);
			fread(&rgb[i][j].rgbRed, 1, 1, fin);
			
			
			y[i][j] = 0.299 * rgb[i][j].rgbRed;
			y[i][j] += 0.587 * rgb[i][j].rgbGreen;
			y[i][j] += 0.114 * rgb[i][j].rgbBlue;
			
			y[i][j] += (i != 0 ? y[i - 1][j] : 0);
			y[i][j] += (j != 0 ? y[i][j - 1] : 0);
			y[i][j] -= (i != 0 && j != 0 ? y[i - 1][j - 1] : 0);
		}
		fseek(fin, (4 - (bmiHeader.biWidth * 3) % 4) % 4, SEEK_CUR);
	}

	// Поиск максимальной яркости
	long double max = 0;
	int mx = n - 1, my = n - 1;
	for (int i = n - 1; i < bmiHeader.biHeight; i++)
	{
		for (int j = n - 1; j < bmiHeader.biWidth; j++)
		{
			long double temp = y[i][j];
			temp -= (i - n >= 0 ? y[i - n][j] : 0);
			temp -= (j - n >= 0 ? y[i][j - n] : 0);
			temp += (i - n >= 0 && j - n >= 0 ? y[i - n][j - n] : 0);
			
			
			
			if (temp > max)
			{
				max = temp;
				mx = i;
				my = j;
			}
		}
	}
	mx = mx - n + 1;
	my = my - n + 1;
	
	
	// Новый bmp файл
	FILE* fout = fopen(argv[2], "w");
	if (fout == NULL)
	{
		printf("Error2");
		return 2;
	}
	
	// Новый заголовок файла
	BitmapFileHeader header2;
	
	header2.bfType = header.bfType;
	header2.bfSize = 14 + 40 + n * n * 3;
	header2.bfReserved1 = header.bfReserved1;
	header2.bfReserved2 = header.bfReserved2;
	header2.bfOffBits = 14 + 40;
    
	writeBitmapFile(&header2, fout);
		
	// Новый заголовок изображения
	BitmapInfoHeader bmiHeader2;
	
	bmiHeader2.biSize = 40;
	bmiHeader2.biWidth = n;
	bmiHeader2.biHeight = n;
	bmiHeader2.biPlanes = bmiHeader.biPlanes;
	bmiHeader2.biBitCount = bmiHeader.biBitCount;
	bmiHeader2.biCompression = bmiHeader.biCompression;
	bmiHeader2.biSizeImage = bmiHeader.biSizeImage;
	bmiHeader2.biXPelsPerMeter = bmiHeader.biXPelsPerMeter;
	bmiHeader2.biYPelsPerMeter = bmiHeader.biYPelsPerMeter;
	bmiHeader2.biClrUsed = bmiHeader.biClrUsed;
	bmiHeader2.biClrImportant = bmiHeader.biClrImportant;
	
	writeBitmapInfo(&bmiHeader2, fout);
	
	
	// Новая картинка
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fwrite(&(rgb[i + mx][j + my].rgbBlue), 1, 1, fout);
			fwrite(&(rgb[i + mx][j + my].rgbGreen), 1, 1, fout);
			fwrite(&(rgb[i + mx][j + my].rgbRed), 1, 1, fout);
			//printf("%d %d\n", i + mx, j + my);
		}
		//printf("%d\t", i + mx);
		fseek(fout, (4 - (n * 3) % 4) % 4, SEEK_CUR);		
	}
	
	for (int i = 0; i < bmiHeader.biHeight; i++)
	{
		free(rgb[i]);
		free(y[i]);
	}
	free(rgb);
	free(y);

	fclose(fin);
	fclose(fout);
}











