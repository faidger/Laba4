#!/bin/bash
# run_all.sh — сборка, тесты и покрытие для C++ и Python
# Запуск: ./run_all.sh

set -e  # остановиться при первой ошибке

PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$PROJECT_DIR"

echo "===================================================="
echo "  Лабораторная работа №4 — полный прогон"
echo "  Проект: $PROJECT_DIR"
echo "===================================================="

# ---------- 1. Сборка C++ ----------
echo
echo ">>> [1/5] Сборка C++ проекта"
rm -rf build
mkdir -p build
cd build
cmake .. > /dev/null
make 2>&1 | tail -3
echo "    Сборка завершена: app, tests, libstructures.a"

# ---------- 2. Тесты C++ ----------
echo
echo ">>> [2/5] Запуск тестов C++"
./tests 2>&1 | tail -6

# ---------- 3. Покрытие C++ ----------
echo
echo ">>> [3/5] Генерация отчёта покрытия C++"
lcov --capture --directory . --output-file coverage.info \
     --ignore-errors mismatch,gcov,source,negative > /dev/null 2>&1
lcov --remove coverage.info '/usr/*' '*/tests/*' '*/build/CMakeFiles/*' \
     --output-file coverage.info \
     --ignore-errors unused,negative 2>&1 | tail -5
genhtml coverage.info --output-directory coverage_html > /dev/null 2>&1
echo "    HTML-отчёт: build/coverage_html/index.html"

# ---------- 4. Тесты Python ----------
echo
echo ">>> [4/5] Запуск Python-тестов"
cd "$PROJECT_DIR/python"
if [ ! -d "venv" ]; then
    echo "    Создаю виртуальное окружение..."
    python3 -m venv venv
    source venv/bin/activate
    pip install --quiet --upgrade pip
    pip install --quiet pytest pytest-cov
else
    source venv/bin/activate
fi

python -m pytest test_stack.py --cov=stack \
       --cov-report=html --cov-report=term 2>&1 | tail -12

# ---------- 5. Готово ----------
echo
echo "===================================================="
echo "  Готово!"
echo "===================================================="
echo "  Приложение:      build/app"
echo "  Тесты C++:       build/tests"
echo "  Покрытие C++:    build/coverage_html/index.html"
echo "  Покрытие Python: python/htmlcov/index.html"
echo "===================================================="
