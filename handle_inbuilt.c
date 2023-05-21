#include "main.h"

int imbuilt(const char *str)
{
	return access(str, X_OK);
}
