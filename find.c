#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *file;
	int line, position, word_find, finish, pos_word;
	char c, name[256], word[256];

	line = position = 1;
	finish = word_find = pos_word = 0;

	switch(argc){ /*For any input*/
        case 1:
            printf("\nEnter name:\n");
            scanf("%s", name);
            printf("\nEnter word:\n");
            scanf("%s", word);
            break;
        case 2:
            strcpy(name, argv[1]);
            printf("\nEnter word:\n");
            scanf("%s", word);
            break;
        case 3:
            strcpy(name, argv[1]);
            strcpy(word, argv[2]);
            break;
	}

    printf("\nYour file: %s\nYour word: %s\n", name, word);

	if((file = fopen(name, "r")) == NULL){
        printf("\nCan't open the file\n");
    } else {
        while(!feof(file)){
            c = getc(file);
            if(word_find == 1){ /*if begin of word are simple*/
                pos_word++;
                if((int)strlen(word) == pos_word){ /*if word was found*/
                    pos_word = 0;
                    word_find = 0;
                    printf("\nResult:\n%d:%d %s\n", line, position - (int)strlen(word), word);
                    finish = 1;
                } else
                    if(c != word[pos_word]){
                        pos_word = 0;
                        word_find = 0;
                    }
            } else {
                if(c == word[0])
                    word_find = 1;
            }

            if(c == '\n'){
                line++;
                position = 1;
            }
            else position++;
        }
        if(finish == 0)
            printf("\n'%s' can't be find in '%s'\n", word, name);
        fclose(file);
    }
	return 0;
}
