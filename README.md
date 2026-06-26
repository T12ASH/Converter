# Converter

Консольная прогрмма на C++ для конвертации величин между единицами измерения: длина, температура и вес.

## Возможности

- **Длина**: километры (km), метры (m), сантиметры (cm), миллиметры (mm)
- **Температура**: Цельсий (C), Фаренгейт (F), Кельвин (K)
- **Вес**: килограммы (kg), граммы (g), фунты (lb), унции (oz)

## Сборка

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Использование

```
./converter <type> <value> <from> <to>
```

| Параметр | Описание                          |
|----------|------------------------------------|
| `type`   | `temperature` \| `weight` \| `length` |
| `value`  | нецелое числовое значение для конвертации  |
| `from`   | исходная единица измерения         |
| `to`     | целевая единица измерения          |

### Доступные единицы

- **temperature**: `C`, `F`, `K`
- **weight**: `kg`, `lb`, `g`, `oz`
- **length**: `km`, `m`, `cm`, `mm`

### Примеры

```bash
./converter temperature 100 C F
# Celsius = 100 -->convert to--> Fahrenheit = 212

./converter length 5 km m
# Kilometers = 5 -->convert to--> Meters = 5000

./converter weight 10 kg lb
# Kilogram = 10 -->convert to--> Pound = 22.046
```
