#include "libft.h"

void *ft_memallocexit(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL) {
		exit(137);
	}
	return (ptr);
}