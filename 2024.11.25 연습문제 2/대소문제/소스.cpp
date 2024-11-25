#include <stdio.h>

int main()
{
	char ch [31];
	int count = 0;

	printf("in put (0~30):");
	scanf_s("%30s", ch, (unsigned int)sizeof(ch));
	
	for (int i = 0; i < 31; ++i)
	{
		if (ch[i] >= 'A' && ch[i] <= 'Z')
		{
			ch[i] = ch[i]+32;
			++count;
		}
		else
		{
			ch[i] = ch[i];
		}
			
	}

	printf("¹Ù²ï¹®Àå : %s\n", ch);
	printf("¹Ù²ï ¹®ÀÚ ¼ö : %d", count);
	
}