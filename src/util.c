#include "util.h"

void util_xy_from_offset(int *x, int *y, int offset, int width) {
	*y = (offset / width);
	*x = (offset - *y * width);
}