#include "input.h"
#include "overlay/overlay.h"

uint8_t input::GetMouseInput()
{
	if (overlay::open)
		return 0;
	else return get_mouse_input_hook.call<uint8_t>();
}

void input::Install()
{
	get_mouse_input_hook = safetyhook::create_inline(reinterpret_cast<void*>(offsets.get_mouse_input), reinterpret_cast<void*>(GetMouseInput));
}