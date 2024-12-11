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
    printf("�Է�:");
    fgets(Name, sizeof(Name), stdin);
    
    printf("����� �� ���: \"%s\"\n", Name);
    // '\n' ����
    Name[strcspn(Name, "\n")] = '\0';

    
    int start = 0;
    int len = strlen(Name);
    for (int i = 0; i <= len; i++) // '\0'�� üũ
    {
        if (Name[i] == ' ' || Name[i] == '\0')
        {
            ReverseWord(Name, start, i - 1); // �ܾ� ������ //
            start = i + 1; // ���� �ܾ� ���� ��ġ //
        }
    }

    printf("���� �� ���: \"%s\"\n", Name);
    return 0;
}

