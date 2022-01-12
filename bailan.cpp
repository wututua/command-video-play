#define _CRT_SECURE_NO_WARNINGS
#define FRAME_TOTAL_NUM 1801
#undef UNICODE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

void gotoxy(int x, int y)
{
	COORD p;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	p.X = x; p.Y = y;
	SetConsoleCursorPosition(handle, p);
}

int main()
{
	FILE* fp;
	clock_t start_time = 0, final_time = 0;
	int frame = 0, len;
	char buf[1024], file_name[] = "ASCII\\bailan (0).txt", num[5];
	getchar();
	PlaySound("bgm.wav", NULL, SND_FILENAME | SND_ASYNC);
	start_time = clock();
	while (frame <= FRAME_TOTAL_NUM)
	{
		strcpy(file_name, "ASCII\\bailan (");
		_itoa(frame, num, 10);
		strcat(file_name, num);
		strcat(file_name, ").txt");
		final_time = clock();
		if ((final_time - start_time) >= 40)
		{
			frame++;
			fp = fopen(file_name, "r");

			while (fgets(buf, 1024, fp) != NULL)
			{
				len = strlen(buf);
				buf[len - 1] = '\0';
				printf("%s %d \n", buf, len - 1);
			}

			fclose(fp);
			start_time += 40;
			gotoxy(0, 0);
		}
	}
	return 0;
}