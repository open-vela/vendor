# vendor 简介

\[ [English](README.md) | 简体中文 \]

`vendor` 仓库存放各芯片厂商（SoC Vendor）的板级支持包（BSP）、芯片驱动与产品工程。openvela 通过本仓库适配不同的芯片平台与开发板，是硬件移植（Porting）工作的主要目录。

## 目录结构

仓库顶层按**芯片厂商**组织，每个厂商一个目录，例如：

| 目录             | 说明                                               |
| ---------------- | -------------------------------------------------- |
| `allwinnertech/` | 全志（Allwinner）平台适配。                        |
| `bes/`           | 恒玄（BES）平台适配。                              |
| `espressif/`     | 乐鑫（Espressif）平台适配。                        |
| `flagchip/`      | 旗芯微（Flagchip）平台适配。                       |
| `gigadevice/`    | 兆易创新（GigaDevice）平台适配。                   |
| `infineon/`      | 英飞凌（Infineon）平台适配。                       |
| `sifli/`         | 思澈（SiFli）平台适配。                            |
| `st/`            | 意法半导体（ST）平台适配。                         |
| `xiaomi/`        | 小米自研平台适配。                                 |
| `template/`      | 厂商工程模板，用于快速生成新的厂商目录（见下文）。 |

> 以上为示例，实际包含的厂商以仓库内容为准。

每个厂商目录内部通常遵循如下结构：

| 子目录                   | 说明                                                    |
| ------------------------ | ------------------------------------------------------- |
| `chips/<chip>/`          | 芯片级驱动与硬件抽象（GPIO、SPI、I2C、HAL 等）。        |
| `boards/<chip>/<board>/` | 板级支持包：启动代码、引脚配置、`configs/` 编译配置等。 |

## 新增厂商适配

`template/` 提供了一份标准厂商工程模板，可借助其中的 `rename.py` 快速生成新平台的初始工程：

```bash
# 1. 复制模板为新的厂商目录
cp -r template <vendor_name>
cd <vendor_name>

# 2. 用实际的 vendor / board / chip 名称替换模板占位符
python rename.py <vendor_name> <board_name> <chip_name>

# 3. 清理模板自带文件
rm rename.py

# 4. 编译验证（以生成的板级配置路径为例）
./build.sh vendor/<vendor_name>/boards/<chip_name>/<board_name>/configs/nsh -j8
```

## 相关文档

- 芯片移植指南：参见 [芯片移植（Chip Porting）章节](https://github.com/open-vela/docs/blob/dev-ai-contest-2026/zh-cn/chip_porting/porting_guide.md)。
- 大赛参赛者请基于大赛分支 `dev-ai-contest-2026` 进行硬件适配开发。
