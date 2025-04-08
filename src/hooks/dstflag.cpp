#include "dstflag.h"

bool dstflag::GetDstFlag(void* game, unsigned dst)
{
	return get_dst_flag_hook.call<bool>(game, dst);
}

void dstflag::Install()
{
	get_dst_flag_hook = safetyhook::create_inline(reinterpret_cast<void*>(offsets::get_dst_flag), reinterpret_cast<void*>(GetDstFlag));
}
