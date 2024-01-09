class Jar:
    def __init__(self, capacity=12):
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity must be a non-negative integer")
        self.capacity = capacity
        self.cookies = 0

    def __str__(self):
        return "🍪" * self.cookies

    def deposit(self, n):
        if self.cookies + n > self.capacity:
            raise ValueError("Exceeds jar capacity")
        self.cookies += n

    def withdraw(self, n):
        if n > self.cookies:
            raise ValueError("Not enough cookies to withdraw")
        self.cookies -= n

    @property
    def size(self):
        return self.cookies


def main():
    jar = Jar()
    print(f"Initial capacity: {jar.capacity}")
    print(f"Initial state: {str(jar)}")

    jar.deposit(10)
    print(f"State after deposit: {str(jar)}")

    jar.withdraw(1)
    print(f"State after withdrawal: {str(jar)}")


if __name__ == "__main__":
    main()
