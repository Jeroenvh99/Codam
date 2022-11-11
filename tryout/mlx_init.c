glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture0"), 0);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture1"), 1);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture2"), 2);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture3"), 3);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture4"), 4);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture5"), 5);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture6"), 6);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture7"), 7);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture8"), 8);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture9"), 9);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture10"), 10);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture11"), 11);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture12"), 12);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture13"), 13);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture14"), 14);
glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, "Texture15"), 15);

char nbstr[10] = "Texture";
for (int i = 0; i < 16; i++)
{
	nbstr[7] = i + '0';
	if (i > 9)
	{
		nbstr[8] = i + '0';
		nbstr[9] = '\0';
	}
	else
	{
		nbstr[7] = '\0';
	}
	// glUniform1i(glGetUniformLocation(mlxctx->shaderprogram, nbstr), i);
}