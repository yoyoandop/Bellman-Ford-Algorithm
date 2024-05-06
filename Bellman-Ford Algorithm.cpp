/*Edge ���c�G�N��Ϥ����@���� one line
numNodes�G�Ϥ��`�I���ƶq�C how many nodes
#umEdges�G�Ϥ��䪺�ƶq�C   how many lines
edges �}�C�G�s�x�Ҧ�����A�ΨӴy�z�Ϫ����c�C
distances �}�C�G�s�x�q�_�l�`�I��C�Ӹ`�I���̵u���|���סC
BellmanFord() �禡�G��{�F������-�֯S��k�A�Ω�p��̵u���|�M�˴��t�v���C
main() �禡�G�{�Ǫ��J�f�AŪ����J�ýե� BellmanFord() �禡�ӳB�z�C�Ӵ��եΨҡC

�ҥH�N�O�����]�ڭ̪��ϬO�S���t�����A�M�ᦳ�t�����ܤ~�|����u�����|!!!!!

�o��Bellman-Ford Algorithm�{�����z���O��M�Ϥ����S���t���A�{���Ψ��ˬd�O�_���t���A����C�@�Ӹ`�I����I���̵u���|��X��
�p�G�b�w�g�O�̵u���|�����p�U�ٯ���q���I��Ӹ`�I����u���|
����N��s�b�t�� �]���u���s�b�t���~�|�V�ӶV�t
�p���s�̵u���|���N�O�ݱq���I��A�I���Z���O�_�j��q���I��B�I���Z���[�WA�I��B�I���Z���A
�p�G�O�j�󪺨���N����I��B�I�A��A�I���Z������I��A�I���Z���u�A�N��q���I��B�I�A��A�I�O��u���Z���A����I��A�I���Z���u�A����ڭ̴N��s�q���I��A�I���ȡA�N����I��A�I����u�����|
�o�Ӱj��O Bellman-Ford Algorithm ���֤߳����A�Ω�����C�@�Ӹ`�I���P���ާ@�C�b�C�@�����N���A���|�i�� numNodes - 1 �����N�C�b�@�ӨS���t�v�����Ϥ��A���N��Ӹ`�I�������̵u���|�̦h�g�L�Ҧ����`�I�@���C
�]���A�̵u���|�����׳̦h�O�g�L�`�I�ƴ� 1 ����C�A�ҥH�ڭ̥u�ݭn���� numNodes - 1 �����N�H�T�O�Ҧ��`�I���̵u���|�Q�p��X�ӡC
�b�C�@�����N���A�������j��|�M
���Ҧ�����A��C����i���P���ާ@�C�P���ާ@���ت��O�N�q�_�I��U�Ӹ`�I���Z���i���s�A�H��o��u���Z���C�]���A�������j��ݭn�M���Ҧ�����ӽT�O�C���䳣�Q�Ҽ{��C

�`���ӻ��A�~���j�骺���ƽT�O�F�b���������N���p��X�Ҧ��`�I���̵u���|�A�Ӥ����j��h�T�O�F�Ҧ����䳣�Q�Ҽ{��H�i���P���ާ@�C

�ҥH�ڭ̭n���p��X���I��C�@�I���̵u�Z���A���ۦp�G�I���I�s�b��u���|���ܴN�����t��
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

