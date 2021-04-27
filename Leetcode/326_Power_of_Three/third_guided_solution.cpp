n = 3^i
i = log3{n}
i = logb{n} / logb{3}
i가 정수이면 true
그런데 precision 문제가 있으므로 주의
5.0000001이나 4.9999999와 같은 케이스
자바에서는 epsilon이 1과 1보다 큰 수 중 가장 작은 수의 차이를 나타냄

따라서
return (Math.log(n) / Math.log(3) + epsilon) % 1 <= 2 * epsilon;
로 해결 가능