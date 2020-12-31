# Сравнение времени работы различных алгоритмов транспонирования матриц
Рассмотрим 3 алгоритма c асимптотикой O(n<sup>2</sup>):
1. `stupid` – идет по диагоналям матрицы, начиная с самой нижней и
заканчивая верхней, обращаясь к элементам различных массивов.
1. `naive` – наивый алгоритм, проходит последовательно по всем столбцам
и записывает значения из них в соответствующие строки.
1. `cacheOblivious` – кэш-эффективный алгоритм, на каждом этапе
разделяющий обрабатываемый участок пополам по большей стороне. После того,
как такой алгоритм доходит до достаточно маленького прямоугольника, он
транспонирует обрабатываемый участок наивно (данная модификация требуется,
чтобы добиться оптимального сотношения выгоды от учёта существования
кэша и затрат на рекурсивные вызовы). Он использует принцип пространственной
локальности кэш-памяти компьютера.

## Результаты тестирования
<p style="text-align: center;"><img
     src="Efficiency%20of%20matrix%20transposition%20algorithms.png"
     alt="Результаты тестирования"
     width="90%"/></p>
На графике видно, что при небольших размерах (не превышающих 2&middot;10<sup>3</sup>)
разность во времени работы описанных алгоритмов пренебрежимо мала, при этом
на бо&#x301;льших, чем 2.5&middot;10<sup>3</sup> она становится заметной.

Алгоритм (3) быстрее, чем (2), чуть меньше чем в 2 раза, и быстрее, чем (3),
заметно больше, чем в два раза.