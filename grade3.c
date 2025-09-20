#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Score {
        char name[20];
        float math;
        float eng;
        float avg;
};
int main(void) {
        FILE *fp;
        fp = fopen("exams.txt", "r");
        char buf[200];
        struct Score score[100];

        int cnt=0;
        while ( fgets(buf, 200, fp) != NULL) {
                char *myname = strtok(buf, "\t");
                char *mymath = strtok(NULL, "\t");
                char *myeng = strtok(NULL, "\t");

                strcpy(score[cnt].name, myname);
                score[cnt].math = atof(mymath);
                score[cnt].eng = atof(myeng);
                cnt++;

        }
        fclose(fp);

        for(int i=0; i<cnt; i++) printf("%s %f %f\n", score[i].name, score[i].math, score[i].eng);
}
