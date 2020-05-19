/*
思路：将互相连通的元素归为同一个集合
 */

class UnionFind
{
private:
	vector<int> parent;		//记录每个元素的根节点
	vector<int> rank;		//记录每个根节点的节点数
	int count;				//记录集合的数量

public:
	//构造函数
	UnionFind(输入数组){
		//用于根据输入数组初始化parent、rank和count
		//parent[i]=i;rank[i]=0;count++;
	}
	
	//寻找元素所在集合的根节点
	int find(int x){
		if(parent[i] != i){
			parent[i] = find(parent[i]);
		}
		return parent[i];
	}
	
	//结合两个结合的根节点
	void unite(int x, int y){
		int rootx = find(x);
		int rooty = find(y);
		if(rootx != rooty){
			//此处可以设定规则，决定将谁的根节点作为合并后的根节点
			parent[rooty] = rootx;
			//parent[rootx] = rooty;
			count--;
		}
	}

	//获得当前结合的数量
	int getCount() const{
		return count;
	}

};
