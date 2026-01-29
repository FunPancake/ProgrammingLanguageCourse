def function1():
    for i in range(0, 100, 5):
        def function2():
            for i2 in range(0, 100, 3):
                def function3():
                    for i3 in range(100):
                        if i == i2 == i3:
                            print(i)
                function3()
        function2()
function1()