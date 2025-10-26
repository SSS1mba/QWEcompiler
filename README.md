# QWE Compiler 🔮

## Описание

**QWE Compiler** - это компилятор для специализированного языка программирования, основанного на синтаксисе инвокера. Программа преобразует исходный код в исполняемый формат.

### Синтаксис языка и правила

#### 🇷🇺 Russian Version

1) **Программа начинается** с ключевого слова `base`

2) **Для установки клавиш ввода** используется конструкция:
input: zxcv

text
- В данном примере: 
  - `z` интерпретируется как `quas`
  - `x` интерпретируется как `wex` 
  - `c` интерпретируется как `exort`
  - `v` интерпретируется как `invoke`
- При отсутствии `input:` устанавливаются значения по умолчанию: `q w e r`
- Инструкция `input` должна стоять **ДО** `base`

3) **Код программы** - набор символов, например:
qwerwwwwrwwer

text

4) **Завершение программы** - ключевое слово `amien`

**Формат файлов:**
- Исходный код: `.qwe`
- Результат компиляции: `.qwExe`

#### 🇺🇸 English Version

1) **Program starts** with keyword `base`

2) **To set input keys** use construction:
input: zxcv

text
- In this example:
  - `z` interpreted as `quas`
  - `x` interpreted as `wex`
  - `c` interpreted as `exort` 
  - `v` interpreted as `invoke`
- If `input:` is not specified, default values will be set: `q w e r`
- Instruction `input` must be **BEFORE** `base`

3) **Program code** - character set, for example:
qwerwwwwrwwer

text

4) **Program ends** with keyword `amien`

**File formats:**
- Source code: `.qwe`
- Compilation result: `.qwExe`

## Примеры использования

### Пример 1: Базовая программа
**Файл: `example.qwe`**
input: qwer
base
qqqwer
amien

text

### Пример 2: Программа с пользовательскими клавишами
**Файл: `custom_input.qwe`**
input: asdf
base
aaasssdddfff
amien

text

### Пример 3: Программа с клавишами по умолчанию
**Файл: `default_input.qwe`**
base
qweqweqwe
amien

text

## Установка и использование

### Требования
- Windows 10/11
- Visual Studio 2019 или новее
- Поддержка C++17

### Инструкция по запуску

1. **Сборка проекта:**
   - Откройте `QWE_Compiler.sln` в Visual Studio
   - Выберите конфигурацию `Release` и платформу `x64`
   - Выполните сборку проекта (`Build → Build Solution`)

2. **Использование компилятора:**
Ознакомьтесь с правилами языка в README.txt

Создайте файл .qwe (например, input.qwe)

Запустите QWE_compiler.exe

Введите путь до файла input.qwe

Введите название для выходного файла (с путем при необходимости)

text

### Структура проекта
```text
QWE-Compiler/
├── src/
│ ├── Compiler.cpp # Основной компилятор
│ ├── Parser.cpp # Парсер исходного кода
│ ├── Lexer.cpp # Лексический анализатор
│ └── main.cpp # Точка входа
├── include/
│ ├── Compiler.h
│ ├── Parser.h
│ └── Lexer.h
├── examples/ # Примеры программ .qwe
├── QWE_Compiler.sln # Решение Visual Studio
└── README.md # Документация
```

text

## Тип лицензии

### MIT License

Этот проект распространяется под лицензией MIT.

```plaintext
Copyright (c) 2024 Golubev Maksim

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
