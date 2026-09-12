#include "RadarRenderer.h"

void RadarRenderer::DrawBackground(
    LGFX_Sprite &buffer,
    int centerX,
    int centerY,
    int radius)
{
    buffer.fillScreen(TFT_BLACK);

    const uint32_t outerColor  = lgfx::color888(0, 180, 80);
    const uint32_t gridColor   = lgfx::color888(0, 70, 35);
    const uint32_t centerColor = lgfx::color888(0, 255, 100);
    const uint32_t textColor   = lgfx::color888(0, 220, 100);

    // Círculo externo
    buffer.drawCircle(
        centerX,
        centerY,
        radius,
        outerColor
    );

    // Círculos internos
    buffer.drawCircle(
        centerX,
        centerY,
        radius * 2 / 3,
        gridColor
    );

    buffer.drawCircle(
        centerX,
        centerY,
        radius / 3,
        gridColor
    );

    // Linha horizontal
    buffer.drawLine(
        centerX - radius,
        centerY,
        centerX + radius,
        centerY,
        gridColor
    );

    // Linha vertical
    buffer.drawLine(
        centerX,
        centerY - radius,
        centerX,
        centerY + radius,
        gridColor
    );

    // ==============================
    // PONTOS CARDEAIS
    // ==============================

    buffer.setTextColor(textColor);
    buffer.setTextSize(1);
    buffer.setTextDatum(middle_center);

    // Mantém as letras dentro do radar
    const int labelOffset = radius - 10;

    // Norte
    buffer.drawString(
        "N",
        centerX,
        centerY - labelOffset
    );

    buffer.drawString(
        "N",
        centerX + 1,
        centerY - labelOffset
    );

    // Sul
    buffer.drawString(
        "S",
        centerX,
        centerY + labelOffset
    );

    buffer.drawString(
        "S",
        centerX + 1,
        centerY + labelOffset
    );

    // Oeste
    buffer.drawString(
        "W",
        centerX - labelOffset,
        centerY
    );

    buffer.drawString(
        "W",
        centerX - labelOffset + 1,
        centerY
    );

    // Leste
    buffer.drawString(
        "E",
        centerX + labelOffset,
        centerY
    );

    buffer.drawString(
        "E",
        centerX + labelOffset + 1,
        centerY
    );

    // ==============================
    // CENTRO DO RADAR
    // ==============================

    buffer.fillCircle(
        centerX,
        centerY,
        2,
        centerColor
    );
}