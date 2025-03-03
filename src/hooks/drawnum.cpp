#include "drawnum.h"

int drawnum::hook_draw(void* drb, int src[17], int dst[11], void* T, int number, int x, int y)
{
	if (src[4] == 210) {
		y = *(int*)(offsets::judge_y);
	}

	if (src[4] == 108 && *(int*)offsets::ghost_setting == 1) {
		y = *(int*)(offsets::judge_y);
	}
	return draw_hook.call<int>(drb, src, dst, T, number, x, y);
}

void drawnum::Install()
{
	draw_hook = safetyhook::create_inline(reinterpret_cast<void*>(offsets::draw_num), reinterpret_cast<void*>(hook_draw));
}
