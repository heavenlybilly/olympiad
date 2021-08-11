/*
* ------------ Сумма степеней двойки ------------
& динамика - 3
~ двумерная_динамика ~ одномерная_динамика
? решение за O(n*log(n)). Чтобы избежать дублирования разложений, слагаемые будем размещать в порядке неубывания. Итак, сначала найдем степень двойки такую, что она наибольшая из меньших, чем n, степеней двойки. Параметрами ДП будет выступать сама число n и максимальная степень двойки maxp, которая может выступатьв разложении.

> count[n][maxp] = sum(count[n - 2^i][i], 0 <= i <= maxp, 2^i = n)

warning: вариант решения за O(n)
? на самом деле я бы сам врядли догадался до такого. Разбор этого примера есть на (https://www.youtube.com/watch?v=4NNjJ19fxI0) с 7:20 по 24:42.

todo: разбор задачи с решением двумерной динамикой

*/



//& вариант решения за O(n)
#include <iostream>
#include <vector>

using namespace std;

int main() {
	// ...
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector <int> d(n+2);
	d[1] = 1;
	d[2] = 2;

	for (int i(3); i <= n; i++) {
		d[i] = d[i / 2] + d[i - 2];
	}

	cout << d[n];

	return 0;
}