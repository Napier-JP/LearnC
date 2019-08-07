#include <stdio.h>

int main(void) {

    FILE* fp = fopen("score.tsv", "r");
    char line[256];
    while (fgets(line, 256, fp) != NULL){
        printf("LINE INPUT: %s", line);
        char name[256];
        int score[8];

        sscanf(line, "%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",
               &name, &score[0], &score[1], &score[2], &score[3], &score[4], &score[5], &score[6], &score[7]);

        printf("名前:%s\n", name);
        printf("国語:%d点 英語:%d点 数学:%d点 物理:%d点\n", score[0], score[1], score[2], score[3]);
        printf("化学:%d点 生物:%d点 地理:%d点 歴史:%d点\n", score[4], score[5], score[6], score[7]);

    }

    fclose(fp);

    return 0;
}
