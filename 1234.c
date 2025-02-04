#include <stdio.h>
#include <ctype.h>

void main ()
{

	char sentenca[51], saida[51], lixo;
	short i, j;
	short posicao;

	while (scanf("%[^\n]", sentenca) != EOF)
	{
		scanf("%c", &lixo); // Trata o buffer do scanf;

		i = 0;
		j = 0;
		posicao = 0;

		while (sentenca[i])
		{	
			if (sentenca[i] == ' ')
				saida[j++] = sentenca[i++];

			else if(islower(sentenca[i]) && posicao % 2 == 0)
			{
				saida[j++] = toupper(sentenca[i]);
				posicao++;
				i++;
			}
			else if (isupper(sentenca[i]) && posicao % 2 != 0)
			{
				saida[j++] = tolower(sentenca[i]);
				posicao++;
				i++;
			}
			else
			{
				saida[j++] = sentenca[i++];
				posicao++;
			}
		}

	saida[j] = '\0';
	printf("%s\n", saida);
		
	}

}
