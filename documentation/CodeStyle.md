# Змінні

використовуємо snake_case

```c++
snake_case_t var_name
```

Якщо хочемо використати тип __локально__, наприклад тип для змінної що _відповідає за температуру у нас інт_ тобто якщо
```c++
class BoilingWater {
	int tempetature;
};
```

то варто зробити дефайн, а саме
```c++
using tempetature_t = int;

class BoilingWater {
	tempetature_t tempetature;
};
```

Якщо ж маємо щось по типу `exit_code_t` тобто тип, що використовується по всьому проєкту, тоді ми записуємо в ~/config/Defines.h наступне

```c++
#define exit_code_t short
// або 
using exit_code_t = short;
```
# Класи
Використовуємо CamelCase
```c++
class ClassName{};
```

Розділяємо на `ClassName.h` та `ClassName.cpp`, перші знаходяться в папці ~/include, а другі в ~/src

# Функції
Використовуємо snake_case

Якщо функція `void`, то вона має повертати exit_code_t
де код відповідає за наступне
0) загальна проблема
1) все добре

