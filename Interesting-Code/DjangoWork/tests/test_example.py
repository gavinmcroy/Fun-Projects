import pytest


@pytest.fixture
def fixture_1(scope="session"):
    print('run-fixture-1')
    return 1


@pytest.mark.slow
def test_example(fixture_1):
    print('Run test 1')
    num = fixture_1
    assert (num == 1)


def test_example1(fixture_1):
    print('Run test 2')
    num = fixture_1
    assert (num == 1)
