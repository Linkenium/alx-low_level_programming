#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: text to write
 * 
 * Return: If the function fails - 0
 *         Otherwise - 1
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (0);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (0);

	close(fd);

	return (1);
}
