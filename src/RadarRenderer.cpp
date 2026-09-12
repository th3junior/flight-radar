#include "RadarRenderer.h"

void RadarRenderer::DrawBackground(
    LGFX_Sprite &buffer,
    int centerX,
    int centerY,
    int radius)
{
    // Fundo
    buffer.fillScreen(TFT_BLACK);

    // Cores do radar
    const uint32_t outerColor = lgfx::color888(0, 180, 80);
    const uint32_t gridColor  = lgfx::color888(0, 70, 35);
    const uint32_t centerColor = lgfx::color888(0, 255, 100);

    // Círculo externo
    buffer.drawCircle(
        centerX,
        centerY,
        radius,
        outerColor);

    // Círculos internos
    buffer.drawCircle(
        centerX,
        centerY,
        radius * 2 / 3,
        gridColor);

    buffer.drawCircle(
        centerX,
        centerY,
        radius / 3,
        gridColor);

    // Linha horizontal
    buffer.drawLine(
        centerX - radius,
        centerY,
        centerX + radius,
        centerY,
        gridColor);

    // Linha vertical
    buffer.drawLine(
        centerX,
        centerY - radius,
        centerX,
        centerY + radius,
        gridColor);

    // Ponto central
    buffer.fillCircle(
        centerX,
        centerY,
        2,
        centerColor);
}