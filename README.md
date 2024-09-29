# Matrix Math
Динамическая библиотека на С++, подключаемая к интерпретатору Python.
Данная библиотека позволяет выполнять математические операции над матрицами (на данный момент реализована только операция перемножения матриц).

# Системные требования
Проект написан для Python `3.9` и выше.
Компиляция проверена на gcc версии `11.4.0` и `13.2.0`

# Установка
1. Скачать исходный код библиотеки
```bash
git clone https://github.com/anfrostdev/pyd-matrix-math.git
```
2. Скомпилировать модуль (собрать расширение)
```bash
python setup.py build
```
3. Установить модуль
```bash
python setup.py install
```

# Использование
Список функций:
## validate_possibility_multiply_matrix
Функция проверяет возможность перемножения матриц, зная только их конфигурацию (размеры и тип данных). Нужна для того, чтобы не загружать (скачивать, считывать) сами данные матриц, если перемножение невозможно.

```python
bool validate_possibility_multiply_matrix(tuple (list cfgMatrixOne, list cfgMatrixTwo))
```
где: `list cfgMatrix` — число строк матрицы (целое натуральное число), число столбцов матрицы (целое натуральное число), тип данных (строка `"int"` или `"double"`)

### Пример использования
```python
cfgMatrixOne = [3, 4, "int"]
cfgMatrixTwo = [4, 2, "double"]

if validate_possibility_multiply_matrix((cfgMatrixOne,  cfgMatrixTwo)):
  print("Can multiply")
else:
  print("Can't multiply")
```

### Пример вывода
```python
"Can multiply"
```

## multiply_two_matrix
Функция перемножает матрицы и возвращает результат в переменные

```python
void multiply_two_matrix(tuple (list cfgMatrixOne, list dataMatrixOne, list cfgMatrixTwo, list dataMatrixTwo, list cfgMatrixRes, list dataMatrixRes) )
```
где:
- `cfgMatrixRes` - число строк матрицы (целое натуральное число), число столбцов матрицы (целое натуральное число), тип данных (строка `"int"` или `"double"`);
- `dataMatrixRes` — матрица-результ (список списков)

### Пример использования
```python
cfgMatrixOne = [3, 2, "int"]
cfgMatrixTwo = [2, 4, "int"]
dataMatrixOne = [[1, 2], [3, 4], [5, 6]]
dataMatrixTwo = [[1, 2, 3, 4][5, 6, 7, 8]]
cfgMatrixRes = []
dataMatrixRes = []
multiply_two_matrix((cfgMatrixOne, dataMatrixOne, dataMatrixOne, dataMatrixTwo, cfgMatrixRes, dataMatrixRes))
print(cfgMatrixRes, dataMatrixRes)
```

### Пример вывода
```python
[3, 4, "int"] [[11, 14, 17, 20], [23, 30, 37, 44], [35, 46, 57, 68]]
```