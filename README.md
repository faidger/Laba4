# Лабораторная работа №4

**Тема:** Реализация структур данных и тестирование

## Цель работы

Реализовать основные структуры данных на C++, покрыть их тестами и получить отчёт о покрытии кода. Дополнительно — реализовать одну структуру на Python и протестировать её.

## Реализованные структуры данных

### C++
| Структура | Файл | Операции |
|---|---|---|
| Stack | include/Stack.h, src/Stack.cpp | push, pop, top, empty, size, clear, contains, print |
| Queue | include/Queue.h, src/Queue.cpp | enqueue, dequeue, front, empty, size, clear, contains, print |
| BinaryTree | include/BinaryTree.h, src/BinaryTree.cpp | insert, remove, contains, print, clear, size, empty |

### Python
| Структура | Файл | Операции |
|---|---|---|
| Stack | python/stack.py | push, pop, top, empty, size, clear, contains, __str__ |

## Структура проекта

    Laba4/
    ├── include/         (Stack.h, Queue.h, BinaryTree.h)
    ├── src/             (Stack.cpp, Queue.cpp, BinaryTree.cpp, main.cpp)
    ├── tests/           (test_structures.cpp)
    ├── python/          (stack.py, test_stack.py, htmlcov/)
    ├── build/           (coverage_html/)
    ├── CMakeLists.txt
    └── README.md

## Сборка и запуск (C++)

Установка зависимостей (Ubuntu):

    sudo apt install -y build-essential cmake libgtest-dev lcov

Сборка:

    mkdir -p build && cd build
    cmake ..
    make

Запуск приложения:

    ./app

Запуск тестов:

    ./tests

Результат: 12/12 тестов пройдено.

## Покрытие кода (C++)

    lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch,gcov,source,negative
    lcov --remove coverage.info '/usr/*' '*/tests/*' '*/build/CMakeFiles/*' --output-file coverage.info --ignore-errors unused,negative
    genhtml coverage.info --output-directory coverage_html

Открыть отчёт:

    xdg-open coverage_html/index.html

Результат: 76.9% строк, 87.5% функций.

## Python-часть

Установка:

    cd python
    python3 -m venv venv
    source venv/bin/activate
    pip install pytest pytest-cov

Запуск тестов с покрытием:

    python -m pytest test_stack.py --cov=stack --cov-report=html --cov-report=term -v

Результат: 5/5 тестов пройдено, покрытие 100%.

Открыть отчёт:

    xdg-open htmlcov/index.html

## Список тестов

C++ (Google Test):

- StackTest: PushPopTop, EmptyPopThrows, ClearAndContains, SizeAfterOps
- QueueTest: EnqueueDequeue, EmptyDequeueThrows, ContainsAndClear, SizeAfterOps
- BinaryTreeTest: InsertAndContains, RemoveLeafAndRoot, EmptyAndClear, RemoveWithTwoChildren

Python (pytest):

- test_push_pop_top
- test_empty_pop_raises
- test_clear_and_contains
- test_str
- test_size_and_empty

## Итог

- Программа с реализацией трёх структур данных на C++
- Консольное приложение с командами
- 12 модульных тестов на Google Test
- Покрытие C++ >= 70% (получено 76.9%)
- HTML-отчёт покрытия (lcov/genhtml)
- Python-реализация стека
- 5 тестов на pytest, покрытие 100%
- HTML-отчёт покрытия (pytest-cov)
