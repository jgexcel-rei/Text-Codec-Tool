# 多模式文本编码与加解密工具

一个基于 C 语言实现的简单文本编码、加密与解密工具，支持多种常见的文本处理方式，通过菜单循环交互，可连续处理多条文本。

## 功能

| 模块 | 编码 / 加密 | 解码 / 解密 | 说明 |
|------|------------|------------|------|
| **凯撒密码 (Shift5)** | Shift5_lock | Shift5_unlock | 仅支持英文字母，移位数为 5，原地操作 |
| **URL 编码** | URL_lock | URL_unlock | 对 URL 中的特殊字符进行百分号编码 |
| **Base64 编码** | Base64_lock | Base64_unlock | 标准 Base64 编码，支持解码校验 |
| **摩斯电码** | Morse_Code_lock | Morse_Code_unlock | 支持常见字母、数字的摩斯电码转换 |

启动后通过菜单选择功能 → 输入文本 → 选择编码/解码模式，完成后自动返回菜单，输入 `q!` 退出。

## 编译

```bash
gcc -O2 main.c Base64.c URL.c Shift5.c "Morse Code.c" -o main.exe
```

## 项目结构

```
Text-Codec-Tool/
├── main.c          # 主程序（菜单循环）
├── Base64.h / .c   # Base64 编码模块
├── URL.h / .c      # URL 编码模块
├── Shift5.h / .c   # 凯撒密码（移位 5）模块
├── Morse Code.h / .c # 摩斯电码模块
├── Readme.md
└── .gitignore
```
