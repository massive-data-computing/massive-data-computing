#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int md() {
        mkdir("a", 0777);
        mkdir("a/b", 0777);
        mkdir("a/b/c", 0777);

        system("touch f1.txt");
        system("touch a/f2.txt");
        system("touch a/b/f3.txt");
        system("touch a/b/c/f4.txt");
        return 0;
}


void mydir(char *path, char *tab) {
	md();

        DIR *dir = opendir(path);
	/////// base case ////////////
	

	//////////////////////////////

	printf("%s[%s]\n", tab, path);

        struct dirent *dent;
        while( (dent = readdir(dir)) != NULL ) {
		if(dent->d_type == DT_DIR && strcmp(dent->d_name, ".")!=0 && strcmp(dent->d_name, "..")!=0) {
			char path2[500];
			char tab2[500];
		 	sprintf(path2, "%s/%s", path, dent->d_name);	

			sprintf(tab2, "%s", tab);

			mydir(path2, tab2);
		}
		else if(dent->d_type == DT_REG)
			printf("%s%s\n", tab, dent->d_name);
        }
}


int main(void) {
	md();
	mydir(".", "");

	return 0;
}
