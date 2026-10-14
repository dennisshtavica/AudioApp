#ifndef PLAYBACK_H
#define PLAYBACK_H

#include "miniaudio.h"

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);

#endif
