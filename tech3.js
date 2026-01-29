function function1() {
    for (let i = 0; i < 100; i += 5) {
        function function2() {
            for (let i2 = 0; i2 < 100; i2 += 3) {
                function function3() {
                    for (let i3 = 0; i3 < 100; i3 += 1) {
                        if (i === i2 && i2 === i3) {
                            console.log(i);
                        }
                    }
                }function3();
            }
            
        }function2();
    }
}function1();