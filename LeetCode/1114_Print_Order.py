from threading import Condition

class Foo:
    def __init__(self):
        self.condition = Condition()
        self.allow_second = self.allow_third = False

    def first(self, printFirst: 'Callable[[], None]') -> None:
        with self.condition:
            printFirst()
            self.allow_second = True
            self.condition.notify_all()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.condition:
            self.condition.wait_for(lambda: self.allow_second)
            printSecond()
            self.allow_third = True
            self.condition.notify_all()

    def third(self, printThird: 'Callable[[], None]') -> None:
        with self.condition:
            self.condition.wait_for(lambda: self.allow_third)
            printThird()