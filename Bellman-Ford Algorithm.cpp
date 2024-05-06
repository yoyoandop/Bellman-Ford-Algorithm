/*Edge 結構：代表圖中的一條邊 one line
numNodes：圖中節點的數量。 how many nodes
#umEdges：圖中邊的數量。   how many lines
edges 陣列：存儲所有的邊，用來描述圖的結構。
distances 陣列：存儲從起始節點到每個節點的最短路徑長度。
BellmanFord() 函式：實現了貝爾曼-福特算法，用於計算最短路徑和檢測負權環。
main() 函式：程序的入口，讀取輸入並調用 BellmanFord() 函式來處理每個測試用例。

所以就是先假設我們的圖是沒有負環的，然後有負環的話才會找到更短的路徑!!!!!

這個Bellman-Ford Algorithm程式的理念是找尋圖中有沒有負環，程式用來檢查是否有負環，先把每一個節點到原點的最短路徑算出來
如果在已經是最短路徑的情況下還能找到從原點到該節點的更短路徑
那麼代表存在負環 因為只有存在負環才會越來越負
如何更新最短路徑那就是看從原點到A點的距離是否大於從原點到B點的距離加上A點到B點的距離，
如果是大於的那麼代表原點到B點再到A點的距離比原點到A點的距離短，代表從原點到B點再到A點是更短的距離，比原點到A點的距離短，那麼我們就更新從原點到A點的值，代表原點到A點有更短的路徑
這個迴圈是 Bellman-Ford Algorithm 的核心部分，用於執行對每一個節點的鬆弛操作。在每一次迭代中，它會進行 numNodes - 1 次迭代。在一個沒有負權環的圖中，任意兩個節點之間的最短路徑最多經過所有的節點一次。
因此，最短路徑的長度最多是經過節點數減 1 條邊。，所以我們只需要執行 numNodes - 1 次迭代以確保所有節點的最短路徑被計算出來。
在每一次迭代中，內部的迴圈會遍
歷所有的邊，對每條邊進行鬆弛操作。鬆弛操作的目的是將從起點到各個節點的距離進行更新，以獲得更短的距離。因此，內部的迴圈需要遍歷所有的邊來確保每條邊都被考慮到。

總結來說，外部迴圈的次數確保了在有限次迭代內計算出所有節點的最短路徑，而內部迴圈則確保了所有的邊都被考慮到以進行鬆弛操作。

所以我們要先計算出原點到每一點的最短距離，接著如果點到點存在更短路徑的話就但表有負環
chinese->english translate:

e assume that our graph doesn't have a negative cycle, and if it does, it will find a shorter path!!!!

The concept of this Bellman-Ford Algorithm program is to detect whether there is a negative cycle in the graph. The program checks if there is a negative cycle by first calculating the shortest distance from each node to the source node. If, under the condition of already having the shortest paths, a shorter path from the source node to a particular node is found, it implies the existence of a negative cycle. This is because only in the presence of a negative cycle can the path become increasingly negative.

The loop in question is the core part of the Bellman-Ford Algorithm, responsible for performing relaxation operations on each node. In each iteration, it performs numNodes - 1 iterations. In a graph without a negative weight cycle, the shortest path between any two nodes passes through all nodes at most once. Therefore, the maximum length of the shortest path is numNodes - 1 edges. Thus, we need to execute numNodes - 1 iterations to ensure that the shortest paths for all nodes are calculated.

In each iteration, the inner loop traverses all edges to perform relaxation operations. The purpose of relaxation operations is to update the distances from the source node to each node to obtain shorter distances. Therefore, the inner loop needs to traverse all edges to ensure that each edge is considered for relaxation.

In summary, the number of iterations in the outer loop ensures that all nodes' shortest paths are computed within a finite number of iterations, while the inner loop ensures that all edges are considered for relaxation.

Translation:
"We first calculate the shortest distance from the source node to each node. Then, if a shorter path from one node to another is found, implying the existence of a negative cycle."

sample input
1
4 4
0 1 -1
1 2 -1
2 3 1
3 0 -1
out put
possible

sample input
1
5 5
0 1 -3
1 2 5
2 3 9
3 0 -7
4 0 -20
out put
not possible


this code have a jpg please see jpg
*/



#include<iostream>
using namespace std;

struct Edge
{
	int source, destination, weight;
};

int numNodes, numEdges;

Edge edges[2005];
long long distances[1005];

bool BellmanFord()
{
	distances[0] = 0;
	for (int i = 1; i < numNodes; i++)
		distances[i] = 1000000000000000LL;

	for (int i = 0; i < numNodes - 1; i++)
	{
		for (int j = 0; j < numEdges; j++)
		{
            cout <<"j::"<<j<<endl;
			if (distances[edges[j].source] > distances[edges[j].destination] + edges[j].weight){
				distances[edges[j].source] = distances[edges[j].destination] + edges[j].weight;
				cout<<"j is bingo:"<<j<<endl;
				cout<<"distances[edges[j].source]"<<distances[edges[j].source]<<endl;
			}
		}
	}

	bool hasNegativeCycle = false;

	for (int i = 0; i < numEdges; i++)
	{
		if (distances[edges[i].source] > distances[edges[i].destination] + edges[i].weight)
		{
		    cout <<"iii:"<<i<<endl;
			hasNegativeCycle = true;
			break;
		}
	}
	return !hasNegativeCycle;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCases, sourceNode, destinationNode, weight;
	cin >> testCases;
	while (testCases--)
	{
		cin >> numNodes >> numEdges;

		for (int i = 0; i < numEdges; i++)
		{
			cin >> sourceNode >> destinationNode >> weight;
			edges[i].source = sourceNode;
			edges[i].destination = destinationNode;
			edges[i].weight = weight;
		}

		if (BellmanFord())
			cout << "not possible\n";
		else
			cout << "possible\n";
	}
}

