i = 0
j = float(input("Enter a number: "))
k = (j + 13) / 27

while (k < 10):
    k += 1;
    i = 3 * k - 1;
    print("i: " + str(i));
    print("k: " + str(k));
    print("j: " + str(j));
    print();