#include <stdio.h>
#include <string.h>

// 문자열 선언 및 확인
char *parent = "acabacdbac";
char *pattern = "abacdab";

void check(char* parent, char *pattern, int start){
    int found = 1;
    int patternSize = strlen(pattern);
    for (int i = 0; i < patternSize; i++){
        if (parent[start + i] != pattern[i]){
            found = 0;
            break;
        }
    }
    if (found){
        printf("[인덱스 %d에서 매칭 발생]\n", start + 1);
    }
}

void rabinKarp(char* parent, char *pattern){
    int parentSize = strlen(parent);
    int patternSize = strlen(pattern);
    int parentHash = 0, patternHash = 0, poewer = 1;
    for(int i = 0); i <= parentSize - patternSize; i++){
        if (i == 0){
            // 패턴 문자열 : abacdab
            for (int j=0; j < patternSize; j++){
                parentHash = parentHash + parent[patternSize - 1 - j] * power;
                patternHash = patternHash + pattern[patternSize - 1 -j] * power;
                if (j < patternSize - 1) power = power * 2;
            }
        }
        else  {
            parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize -1 + i];
        }
        if (parentHash == patternHash){
        check(parent, pattern, i);
        }   
    }
}

int main(void){
    rabinKarp(parent, pattern);
    system("pause");
}