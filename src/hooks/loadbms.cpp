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

static void store_random(int* note_mapping)
{
	loadbms::random_1p = 0;
	loadbms::random_2p = 0;

	for (int i = 0; i < 7; i++) {
		loadbms::random_1p += (i + 1) * pow(10, 7 - note_mapping[i]);
	}
	for (int i = 10; i < 17; i++) {
		loadbms::random_2p += (i + 1 - 10) * pow(10, 17 - note_mapping[i]);
	}
}

void loadbms::Install()
{
	using namespace safetyhook;
	reset_hook = create_mid(offsets::reset, [](safetyhook::Context& ctx) { count = 0; sum = 0; });
	sum_hook = create_mid(offsets::sum, [](safetyhook::Context& ctx) {
		count++;
		read_fpu_and_sum(ctx);
	});
	random_table_hook = create_mid(offsets::random_table, [](safetyhook::Context& ctx) {
		if (ctx.esi != 0x0F) return;
		store_random((int*)(ctx.esp + offsets::table));
	});
}