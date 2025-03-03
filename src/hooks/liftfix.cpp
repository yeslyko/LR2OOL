#include "liftfix.h"

void liftfix::hook_draw_ln(safetyhook::Context& ctx)
{
	/* TODO: fix this ASAP, this doesn't work for 2p */
	*(float*)(ctx.esp + 0x20) += *(int*)offsets::adjust_y;
}

void liftfix::Install()
{
	using namespace safetyhook;
	draw_ln_hook = create_mid(offsets::draw_ln_1, hook_draw_ln);
}
