#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPH 1000
#define MAX_WORDS 100

typedef struct {
    char word[50];
    int count;
} WordFreq;

int main() {
    char paragraph[MAX_PARAGRAPH];
    WordFreq freq[MAX_WORDS];
    int wordCount = 0;
    printf("Enter a paragraph:\n");
    fgets(paragraph, MAX_PARAGRAPH, stdin);
    for (int i = 0; paragraph[i]; i++) {
        paragraph[i] = tolower(paragraph[i]);
    }
    char *token = strtok(paragraph, " ,.-?!;\n");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(freq[i].word, token) == 0) {
                freq[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && wordCount < MAX_WORDS) {
            strcpy(freq[wordCount].word, token);
            freq[wordCount].count = 1;
            wordCount++;
        }
        token = strtok(NULL, " ,.-?!;\n");
    }
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", freq[i].word, freq[i].count);
    }
    return 0;
}
