# vendor Overview

\[ English | [简体中文](README_zh-cn.md) \]

The `vendor` repository holds the board support packages (BSP), chip drivers, and product projects from various SoC vendors. openvela adapts to different chip platforms and development boards through this repository, making it the primary directory for hardware porting work.

## Recommended Contest Boards

| Board | Platform | Board Guide |
| ----- | -------- | ----------- |
| ESP32-S3 EYE | Espressif ESP32-S3 | [esp32s3-eye](https://github.com/open-vela/vendor_espressif/blob/dev-ai-contest-2026/boards/esp32s3/esp32s3-eye/README.md) |
| Gemini-S1 | Allwinner R528 | [r528s3-gemini-s1](https://github.com/open-vela/vendor_allwinnertech/blob/dev-ai-contest-2026/boards/r528/r528s3-gemini-s1/README.md) |
| LCKFB Huangshan Pi | SiFli SF32LB52 | [lckfb_huangshan_pi](https://github.com/open-vela/vendor_sifli/blob/dev-ai-contest-2026/boards/sf32lb52/lckfb_huangshan_pi/README.md) |

## Directory Structure

The top level is organized by **chip vendor**, one directory per vendor, for example:

| Directory | Description |
| --------- | ----------- |
| `allwinnertech/` | Allwinner platform support. |
| `bes/` | BES (Bestechnic) platform support. |
| `espressif/` | Espressif platform support. |
| `flagchip/` | Flagchip platform support. |
| `gigadevice/` | GigaDevice platform support. |
| `infineon/` | Infineon platform support. |
| `sifli/` | SiFli platform support. |
| `st/` | STMicroelectronics platform support. |
| `xiaomi/` | Xiaomi in-house platform support. |
| `template/` | Vendor project template for quickly creating a new vendor directory (see below). |

> The list above is illustrative; the actual set of vendors depends on the repository contents.

Each vendor directory typically follows this structure:

| Subdirectory | Description |
| ------------ | ----------- |
| `chips/<chip>/` | Chip-level drivers and hardware abstraction (GPIO, SPI, I2C, HAL, etc.). |
| `boards/<chip>/<board>/` | Board support package: boot code, pin configuration, `configs/` build configs, etc. |

## Adding a New Vendor

`template/` provides a standard vendor project template. Use its `rename.py` to quickly scaffold an initial project for a new platform:

```bash
# 1. Copy the template to a new vendor directory
cp -r template <vendor_name>
cd <vendor_name>

# 2. Replace the template placeholders with the actual vendor / board / chip names
python rename.py <vendor_name> <board_name> <chip_name>

# 3. Remove template-only files
rm rename.py

# 4. Build to verify (using the generated board config path as an example)
./build.sh vendor/<vendor_name>/boards/<chip_name>/<board_name>/configs/nsh -j8
```

## Related Documentation

- Chip porting guide: see the [Chip Porting guide](https://github.com/open-vela/docs/blob/dev-ai-contest-2026/en/chip_porting/porting_guide.md).
- Contest participants should base their hardware adaptation work on the contest branch `dev-ai-contest-2026`.
