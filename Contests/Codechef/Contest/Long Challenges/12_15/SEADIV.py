from sys import stdin, exit


def c7to10(n):
    s = 0
    i = 0
    while n:
        s += ((n % 10)*pow(7, i))
        n /= 10
        i += 1
    return s


def c10to7(n):
    s = 0
    i = 0
    while n:
        s += ((n % 7)*pow(10, i))
        n /= 7
        i += 1
    return s


def main():
    t = int(input())
    while t:
        a = int(raw_input())
        b = int(raw_input())
        l = int(raw_input())
        ca = c7to10(a)
        cb = c7to10(b)
        c = (ca/cb) % pow(7, l)
        print c10to7(c)
        t -= 1
    exit(0)
if __name__ == "__main__":
    main()
