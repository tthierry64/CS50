class Jar:
    # constructor
    def __init__(self, capacity=12):
        if capacity < 1:
            raise ValueError("Wrong capacity Value")
        self._capacity = capacity
        self._n = int(input("How many cookies in the initial Jar? : n = "))

    # str
    def __str__(self):
        return "The Jar has " + "🍪" * self._n + " inside (x" + str(self._n) +")"

    # methode
    def deposit(self, n):
        if self._n + n > self._capacity:
            raise ValueError("Exceed Capacity")
        self._n += n

    def withdraw(self, n):
        if self._n < n:
            raise ValueError("The Jar does not have enough cookies to re remove")
        self._n -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._n

pot = Jar()
print(pot)
n = int(input("How many cookies moved ?: "))
move = input("Deposit or Withdraw ? : ")
if move == "Deposit":
    pot.deposit(n)
else:
    pot.withdraw(n)
print("The Jar has " + "🍪" * pot.size + " inside (x" + str(pot.size) +")")