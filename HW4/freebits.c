//Lily Tran
//4. Completion: This function acts as a destructor and frees the struct and bitmap itself

#include <stdlib.h>
#include "bits.h"

void
freebits(struct bits *struct_free, uint32_t *bits)
{
	int n = sizeof(struct_free) / sizeof(bits);
	for (int i = 0; i < n; ++i)
	{
		free(struct_free[i].bits);
	}

	free(struct_free);
}
