#include <stdio.h>
#include <string.h>

void ReverseWord(char* word, int start, int end)
{
    while (start < end)
    {
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char Name[20]; 
    printf("입력:");
    fgets(Name, sizeof(Name), stdin);
    
    printf("지우기 전 출력: \"%s\"\n", Name);
    // '\n' 제거
    Name[strcspn(Name, "\n")] = '\0';

    
    int start = 0;
    int len = strlen(Name);
    for (int i = 0; i <= len; i++) // '\0'도 체크
    {
        if (Name[i] == ' ' || Name[i] == '\0')
        {
            ReverseWord(Name, start, i - 1); // 단어 뒤집기 //
            start = i + 1; // 다음 단어 시작 위치 //
        }
    }

    printf("지운 후 출력: \"%s\"\n", Name);
    return 0;
}

