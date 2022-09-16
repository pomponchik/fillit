# Fillit - впихиваем тетраминки в квадрат

Есть такая популярная игра - [тетрис](https://en.wikipedia.org/wiki/Tetris). Суть геймплея в том, что откуда-то сверху падают фигурки ([тетраминки](https://en.wikipedia.org/wiki/Tetromino)), заполняя собой стакан, а игрок управляет траекторией их падения так, чтобы они заполнили его максимально плотно.

- [**О чем это?**](#о-чем-это)
- [**Как это запустить?**](#как-это-запустить)
- [**Формат ввода**](#формат-ввода)
- [**Формат вывода**](#формат-вывода)
- [**Алгоритм**](#алгоритм)


### О чем это?

Задача программы - впихнуть переданный ей набор тетраминок в максимально маленький квадрат. При этом, если существует несколько вариантов размещения фигурок в квадрате заданного размера, она выберет тот, при котором фигурки располагаются как можно ближе к порядку их подачи, который отсчитывается справа налево и сверху вниз. Также программа может вращать каждую тетраминку, чтобы она лучше подходила.


### Как это запустить?

Программу для начала нужно скомпилировать:

```bash
$ make
```

Затем запустить, передав ей путь к файлу, где описан набор тетраминок:

```bash
$ ./fillit examples/1.txt
```

По итогу она распечатывает что-то похожее на это:

```
.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```


### Формат ввода

[Тетрамино](https://en.wikipedia.org/wiki/Tetromino) - это фигурка, которая состоит из четырех квадратов, слитых между собой сторонами. Существует всего 5 видов "базовых" тетраминок, не считая их отзеркаленных версий:

![тетраминки](https://upload.wikimedia.org/wikipedia/commons/b/b1/Tetris_Opener.jpg)

В файле для нашей программы тетраминка должна быть обозначена квадратом 4 на 4 символа, где занятые ею клеточки "закрашены" [диезами](https://ru.wikipedia.org/wiki/%D0%97%D0%BD%D0%B0%D0%BA_%D1%80%D0%B5%D1%88%D1%91%D1%82%D0%BA%D0%B8), а пустые - точками. Он может выглядеть примерно так:

```
....
....
..##
.##.

....
.##.
..#.
..#.

....
....
..##
..##

....
..#.
..#.
.##.

....
....
.###
..#.
```

### Формат вывода

Выше уже был показан пример результата работы программы, посмотрим на него еще раз:

```
.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```

Это квадрат, в котором пустые клеточки показаны точками, а занятые тетраминками - в виде латинских букв. Чтобы можно было визуально "разлепить" комок тетраминок, клеточки каждой из них показаны отображаются своей уникальной буквой, по алфавиту в порядке следования фигурок в файле.


### Алгоритм

Для решения задачи используется так называемый [поиск с возвратом](https://upload.wikimedia.org/wikipedia/commons/thumb/5/50/All_5_free_tetrominoes.svg/1920px-All_5_free_tetrominoes.svg.png), он же backtracking.

Программа перебирает поля разного размера, начиная с самого маленького. Если в поле в принципе возможно впихнуть тетраминки (то есть в нем тупо хватает клеточек), начинается более подробная проверка. Создается пустое поле и в нем последовательно размещаются тетраминки, одна за другой, справа налево и сверху вниз. Если очередная тетраминка не влезает, происходит "возврат" - мы пробуем сдвинуть предыдущую тетраминку, после чего повторяем попытку размещения первой. Это происходит рекурсивно, цепочка возвратов может дойти до самой первой тетраминки. За счет этого фигурки могут очень сильно перетасоваться относительно исходного порядка, но в то же время стараются выстроиться в максимальном соответствии с ним.
