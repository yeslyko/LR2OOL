#include "liftfix.h"

void liftfix::hook_draw_ln(safetyhook::Context& ctx)
{
	*(float*)(ctx.esp + 0x20) += ctx.esi < 10 ? *(int*)offsets::adjust_y1 : *(int*)offsets::adjust_y2;
}

void liftfix::Install()
{
	using namespace safetyhook;
	draw_ln_hook = create_mid(offsets::draw_ln_1, hook_draw_ln);
}
