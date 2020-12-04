#include <obs-module.h>
#include <util/base.h>
#include "https-server.h"

bool obs_module_load(void)
{	
	init();
	return true;
}

OBS_DECLARE_MODULE()