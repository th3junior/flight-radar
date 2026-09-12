#pragma once

#include "LGFX.h"

class RadarRenderer
{
public:
    RadarRenderer() = default;

    void DrawBackground(LGFX_Sprite &buffer, int centerX, int centerY, int radius);
};