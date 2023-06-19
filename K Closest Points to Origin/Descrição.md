# [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/description/)

No problema "973. K Closest Points to Origin", queremos encontrar os k pontos mais próximos da origem (0, 0) em um plano cartesiano X-Y. Temos um conjunto de pontos representados por coordenadas [xi, yi].

Para medir a proximidade de um ponto em relação à origem, usamos a distância euclidiana. Isso significa calcular a distância entre o ponto atual e a origem usando a fórmula matemática √(x1 - x2)2 + (y1 - y2)2, onde (x1, y1) são as coordenadas do ponto atual e (x2, y2) são as coordenadas da origem (0, 0).

O objetivo é retornar os k pontos que estão mais próximos da origem. Podemos apresentar a resposta em qualquer ordem, mas sabemos que a resposta será única, exceto pela ordem dos pontos.

Para resolver o problema, precisamos calcular a distância euclidiana entre cada ponto e a origem. Em seguida, selecionamos os k pontos com as menores distâncias e os retornamos como resultado.

[Solução desenvolvida](https://leetcode.com/problems/k-closest-points-to-origin/submissions/974712638/)
