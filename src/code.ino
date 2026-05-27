#include <SD_MMC.h>
#include <Adafruit_ST7735.h>
#include <TinyGPS++.h>

#define TFT_CS  14
#define TFT_DC   2
#define TFT_RST  10
#define ZOOM    20

Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST);
TinyGPSPlus gps;
uint64_t tileX, tileY;

void gpsToTile(float lat, float lon) { // tile calculation for the tile API I used
  uint64_t n = 1ULL << ZOOM; // bit shifting for power of
  tileX = (lon + 180.0) / 360.0 * n;
  double r   = lat * PI / 180.0;
  tileY = (1.0 - log(tan(r) + 1.0 / cos(r)) / PI) / 2.0 * n;
}

void setup() {
  Serial2.begin(9600, SERIAL_8N1, 20, 21);
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);
  SD_MMC.begin("/sdcard", true);
}

void loop() {
  while (Serial2.available()) {
    gps.encode(Serial2.read());
  }

  if (gps.location.isUpdated()) {
    gpsToTile(gps.location.lat(), gps.location.lng());

    int width = tft.width();
    int height = tft.height();

    char path[48];
    // I store the bitmap as 16 bit (RGB565) without header, just raw pixels
    snprintf(path, sizeof(path), "/tiles_20/tile_%llu_%llu.bin", tileX, tileY); // %llu for long long (uint64_t)
    File f = SD_MMC.open(path);
    if (!f) return;

    const uint64_t size = 256 * 128 * 2;
    uint16_t pixels[size]; // don't know how much ram it has, so drawing first half
    f.seek(size);
    f.read((uint8_t*) &pixels, size);

    tft.drawRGBBitmap(0, 0, (uint16_t*) &pixels, 256, 128);

    f.seek(size);
    f.read((uint8_t*) &pixels, size); // read second half

    tft.drawRGBBitmap(0, 0, (uint16_t*) &pixels, 256, 128); // draw second half
    free(pixels);

    f.close();
  }
}