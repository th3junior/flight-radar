#include "RadarRenderer.h"

void RadarRenderer::DrawBackground(
    LGFX_Sprite &buffer,
    int centerX,
    int centerY,
    int radius,
    float rangeKm)
{
    buffer.fillScreen(TFT_BLACK);

    const uint32_t outerColor = lgfx::color888(0, 180, 80);
    const uint32_t gridColor = lgfx::color888(0, 70, 35);
    const uint32_t centerColor = lgfx::color888(0, 255, 100);
    const uint32_t textColor = lgfx::color888(0, 220, 100);

    // ==============================
    // CÍRCULOS DO RADAR
    // ==============================

    buffer.drawCircle(
        centerX,
        centerY,
        radius,
        outerColor);

    buffer.drawCircle(
        centerX,
        centerY,
        radius * 2 / 3,
        gridColor);

    buffer.drawCircle(
        centerX,
        centerY,
        radius * 2 / 3 - 1,
        gridColor);

    buffer.drawCircle(
        centerX,
        centerY,
        radius / 3,
        gridColor);

    buffer.drawCircle(
        centerX,
        centerY,
        radius / 3 - 1,
        gridColor);

    // ==============================
    // LINHAS DE REFERÊNCIA
    // ==============================

    buffer.drawLine(
        centerX - radius,
        centerY,
        centerX + radius,
        centerY,
        gridColor);

    buffer.drawLine(
        centerX,
        centerY - radius,
        centerX,
        centerY + radius,
        gridColor);

    // ==============================
    // PONTOS CARDEAIS
    // ==============================

    buffer.setTextColor(textColor);
    buffer.setTextSize(1);
    buffer.setTextDatum(middle_center);

    const int labelOffset = radius - 10;

    // Norte
    buffer.drawString(
        "N",
        centerX,
        centerY - labelOffset);

    buffer.drawString(
        "N",
        centerX + 1,
        centerY - labelOffset);

    // Sul
    buffer.drawString(
        "S",
        centerX,
        centerY + labelOffset);

    buffer.drawString(
        "S",
        centerX + 1,
        centerY + labelOffset);

    // Oeste
    buffer.drawString(
        "W",
        centerX - labelOffset,
        centerY);

    buffer.drawString(
        "W",
        centerX - labelOffset + 1,
        centerY);

    // Leste
    buffer.drawString(
        "E",
        centerX + labelOffset,
        centerY);

    buffer.drawString(
        "E",
        centerX + labelOffset + 1,
        centerY);

    // ==============================
    // ESCALA
    // ==============================
    String rangeText = String((int)rangeKm) + " km";

    buffer.setTextColor(textColor);
    buffer.setTextSize(1);
    buffer.setTextDatum(middle_center);

    buffer.drawString(
        rangeText,
        centerX + radius - 20,
        centerY + 8);
    // ==============================
    // CENTRO DO RADAR
    // ==============================

    buffer.fillCircle(
        centerX,
        centerY,
        2,
        centerColor);
}