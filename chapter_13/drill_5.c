#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define SLEN 81

void append (FILE* source, FILE* dest);

int main (int argc, char *argv[])
{
	FILE *fa, *fs; //указателя на 2 файла
	//fa - на файл назначения
	//fs - на исходные данные
	int files = 0;
	//char file_app[SLEN]; // инициализация массива для названия файла назначения
	//char file_src[SLEN]; // инициализация масиива для названия исходного файла

	//puts("Enter name of setting file:");
	//gets(file_app); //куда пишем название файла

	if ((fa = fopen(file_app, "a")) == NULL) //"а" - создание и открытие файла
											// если указатель на него равен NULL то 
											// входим в цикл 
	{
		fprintf(stderr, "Can't open file %s\n", file_app); // по дключаем файл ошибок 
															// выводим сообщение об ошибке
		exit(2);  //выходим из программы
	}

	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) 
		// setvbuf - устанавливает буфер для испольхования функуий ввода вывода
		// fa - указатель на файл назначения
		// NULL - автоатически распределяет память под буффер
		// _IOFBF - полная буфферизация
		// BUFSIZE - размер массива 1024
		// функция возвращает 0 если при успешном завершении
	{
		fputs("Can't create output buffer\n", stderr); //stderr - целевой файл ошибок
		exit(3); //вывод сообщения об ошибке
	}

	puts("Enter name the fist source file (or new line for termination):");
	while(gets(file_src) && file_src[0] != '\0') // запись в массив названия исходного файла
	{
		if (strcmp(file_src, file_app) == 0) // сравнивается назавния файлов 
			//если вы ввели одиннаковые названия то это недопустимо
			fputs("Can't add file on ending oneself", stderr);
		else if ((fs = fopen(file_src, "r")) == NULL) //"r" - открыть файл для чтения
			fprintf(stderr, "Can't open file %s", file_src);
		else 
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)//создание буффера для исходных данных файла
			{
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa); //копирование из одного файла в другой 
			if(ferror(fs) != 0)
				//ferror = функция возвращает ненулевое значение когда произошла ошибка при чтении или записи
				fprintf(stderr, "Error during reading file %s.", file_src);
			if(ferror(fa) != 0)
				fprintf(stderr, "Error during file record %s.", file_app);
			fclose(fs); // закрытие файла с исходными данными
			files++;
			printf("File %s add.\n", file_src);
			puts("Enter name the next source file (or new line for termination):");

		}
	}
	printf("Done! Add %d files.\n", files);
	fclose(fa); // закрытие файла куда писали данные 
	return 0;
}

void append(FILE* source, FILE* dest)
{
	size_t bytes;
	static char temp[BUFSIZE]; // создание массива из 1024 элементов
	while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0) //запись данных из файла в буффер
		//temp = адрес куда считываются данные
		//sizeof(char) = размер элемнтов
		//BUFSIZE = колличество таких элементов
		//source = указатель на файл откуда пишем данные
		fwrite(temp, sizeof(char), bytes, dest);
		//temp = адрес откуда считываются данные
		//sizeof(char) = размер элемнтов
		//bytes = колличество таких элементов
		//source = указатель на файл куда пишем данные
}

