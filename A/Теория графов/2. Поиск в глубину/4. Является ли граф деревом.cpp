/*
* ------------ ПОИСК В ГЛУБИНУ ------------
^ O(n + m)
$ dfs_проверка_на_принадлежность_к_классу_деревьев
# dfs # список_смежности
? Дерево – связный ациклический граф. Связность означает наличие путей между любой парой вершин, а ацикличность – отсутствие циклов и то, что между парами вершин имеется только одному пути. Т.е. граф является деревом ТОГДА И ТОЛЬКО ТОГДА, когда количество ребер равно n-1 и при этом он связан - эти условия гарантируют, что граф ацикличен (потому что на образование цикла просто не остается ребер, т.к. как их всего на одно меньше, чем кол-во вершин).

? Проверка графа на связность производится обходом графа. Если при этом остались непосещенные вершины, то граф не связный. Кроме того, нужно подсчитать кол-во ребер.

? Граф представлен списками смежности d (на март 2021 года vector <vector <int>> или matrix - это представление графа в виде матрицы смежности или списка смежности). Используется алгоритм dfs и массив used. 
*/

bool isTree(const matrix& d) {
    int amount(0);

    for (const auto& i : d) 
        amount += i.size();
    
    amount /= 2; // для неориентированного графа, потому что в матрице смежности ребра неориентированного графа учтены два раза

    dfs(0);

    return count(used.begin(), used.end(), 0) == 0 && amount == n - 1;
}