// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture0"), 0);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture1"), 1);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture2"), 2);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture3"), 3);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture4"), 4);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture5"), 5);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture6"), 6);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture7"), 7);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture8"), 8);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture9"), 9);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture10"), 10);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture11"), 11);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture12"), 12);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture13"), 13);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture14"), 14);
// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture15"), 15);
#include<stdio.h>

int main()
{
	char nbstr[10] = "Texture";
	int i = 7;
	int jtmp;
	for (int j = 0; j < 16; j++)
	{
		jtmp = j;
		while (jtmp > 9)
		{
			nbstr[i] = (jtmp / 10) + '0';
			jtmp %= 10;
			++i;
		}
		nbstr[i] = jtmp + '0';
		++i;
		nbstr[i] = '\0';
		printf("%i\n", printf("%s ", nbstr));
		i = 7;
		// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, nbstr), i);
	}
}