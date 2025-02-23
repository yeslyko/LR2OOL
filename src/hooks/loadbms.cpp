#include "hooks/loadbms.h"

static void read_fpu_and_sum(safetyhook::Context& ctx) {
	double intermediate = 0;

	/* unfortunately, ctx doesn't allow reading from fpu registers, maybe I should add this to safetyhook? */
	__asm {
		fxch ST(1)
		fst intermediate;
		fxch ST(1)
	}
	
	loadbms::sum += intermediate;
}

void loadbms::Install()
{
	using namespace safetyhook;

	reset_hook = create_mid(offsets::reset, [](safetyhook::Context& ctx) { count = 0, sum = 0; });
	reset_hook = create_mid(offsets::sum, [](safetyhook::Context& ctx) {
		count++;
		read_fpu_and_sum(ctx);
	});
}