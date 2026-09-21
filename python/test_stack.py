import pytest
from stack import Stack


def test_push_pop_top():
    s = Stack()
    s.push(1); s.push(2); s.push(3)
    assert s.top() == 3
    assert s.pop() == 3
    assert s.size() == 2


def test_empty_pop_raises():
    s = Stack()
    with pytest.raises(IndexError):
        s.pop()
    with pytest.raises(IndexError):
        s.top()


def test_clear_and_contains():
    s = Stack()
    s.push(5); s.push(7)
    assert s.contains(5)
    assert not s.contains(6)
    s.clear()
    assert s.empty()
    assert s.size() == 0


def test_str():
    s = Stack()
    s.push(1); s.push(2); s.push(3)
    assert str(s) == "Stack(top->bottom): 3 2 1"


def test_size_and_empty():
    s = Stack()
    assert s.empty()
    assert s.size() == 0
    s.push(10)
    assert not s.empty()
    assert s.size() == 1
