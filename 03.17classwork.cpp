#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <dirent.h>
using namespace std;

/*
 * Текстовый файл содержит произвольные слова на английском языке, по 1 слову в строке,
 * не более 40 слов в файле, длина слова ограничена 80 символами. Переписать слова начинающиеся
 * с буквы «A/a» в другой файл, а все остальные слова в другой.
 */
void splitFile() {
	char *path = "a.txt";
	char *patha = "b.txt";
	char *pathna = "c.txt";
	FILE *f, *a, *na;
	f = fopen(path, "r");
	if (!f) {
		cout << "Couldn't open file!" << endl;
		return;
	}

	a = fopen(patha, "w+");
	if (!a) {
		cout << "Couldn't create file!" << endl;
		return;
	}
	na = fopen(pathna, "w+");
	if (!na) {
		cout << "Couldn't create file!" << endl;
		return;
	}
	char *line = new char[81] { };
	while (!feof(f)) {
		char *fg = fgets(line, 81, f);
		if (fg && strlen(fg)) {
			if (line[0] == 'A' || line[0] == 'a') {
				fputs(line, a);
			} else {
				fputs(line, na);
			}
		}
	}
	delete[] line;
	fclose(f);
	fclose(a);
	fclose(na);
}

/*
 * В данном текстовом файле удалить все слова, которые содержат хотя бы одну цифру.
 */
bool containsNumbers(char *l) {
	while (*l) {
		if (*l >= '0' && *l <= '9')
			return true;
		l++;
	}
	return false;
}

void numberless() {
	char *pathin { "a.txt" }, *pathout { "o.txt" };
	FILE *in, *out;
	in = fopen(pathin, "r");
	out = fopen(pathout, "w");
	char *line = new char[81] { };
	while (!feof(in)) {
		char *fg = fgets(line, 81, in);
		if (fg && strlen(fg)) {
			if (!containsNumbers(line))
				fputs(line, out);
		}
	}
	delete[] line;
	fclose(in);
	fclose(out);
}

/*
 * Текстовый файл содержит записи о телефонах и их владельцах. Переписать в другой файл телефоны
 * тех владельцев, фамилии которых начинаются с букв К и С.
 */
char* firstLetter(char *line) {
	char *l = line;
	while (*l && (*l < 'A' || *l > 'Z'))
		l++;
	if (!*l)
		return nullptr;
	return l;
}

void phoneKC() {
	char *pathin { "phone.txt" }, *pathout { "kc.txt" };
	FILE *in, *out;
	in = fopen(pathin, "r");
	out = fopen(pathout, "w");
	char *line = new char[81] { };
	while (!feof(in)) {
		char *fg = fgets(line, 81, in);
		if (fg && strlen(fg)) {
			char *fl = firstLetter(line);
			if (*fl == 'K' || *fl == 'C')
				fputs(line, out);
		}
	}
	delete[] line;
	fclose(in);
	fclose(out);
}

void ioTest() {
	DIR *dp;
	struct dirent *ep;

	dp = opendir("./");
	if (dp != NULL) {
		while (ep = readdir(dp)) {
			char *name = ep->d_name;
			size_t len = strlen(name);
			if (strcmp(name + len - 4, ".txt") == 0)
				cout<<name<<endl;;
		}
		(void) closedir(dp);
	} else
		perror("Couldn't open the directory");
	return;
}

int main() {
//splitFile();
	//numberless();
	//phoneKC();
	ioTest();
	return 0;
}
