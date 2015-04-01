#include <cstdio>
#include <climits>
 
int V;
long long int graph[6667][6667];

inline int minKey(long long int key[], bool mstSet[])
{
   
	long long int min = LLONG_MIN;
	int min_index;
	int v;
	for(v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] > min)
			min = key[v], min_index = v;
 
	return min_index;
}
 
inline int printMST(int parent[], int n)
{
	
}
 
int main()
{
	int t,e,d,n;
	scanf("%d",&t);
	while(t--){
		
		scanf("%d%d",&n,&d);
		long long int arr[6669][5];
		V=n;
		for(int i=0;i<n;i++)
		for(int j=0;j<d;j++)
			scanf("%lld",&arr[i][j]);
			
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			graph[i][j]=0;
			
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				
				unsigned long long int w=0;
				long long int a,b;
				
				for(int i=0;i<d;i++){
					a=arr[x][i];
					b=arr[y][i];
					w+=(a-b)*(a-b);
				}
				graph[x][y]=w;
				graph[y][x]=w;
			}
		}
		
		int parent[6667]; 
		long long int key[6667];   
		bool mstSet[6667];
	 
		 
		for (int i = 0; i < V; i++){
			key[i] = LLONG_MIN, mstSet[i] = false;
			parent[i]=0;
		}
		key[0] = 0;   
		parent[0] = -1;
	 
		for (int count = 0; count < V-1; count++){
			int u = minKey(key, mstSet);
			mstSet[u] = true;
			for (int v = 0; v < V; v++)
				if (graph[u][v] && mstSet[v] == false && graph[u][v] >  key[v])
					parent[v]  = u, key[v] = graph[u][v];
		}
		unsigned long long int prod=1;
		for (int i = 1; i < V; i++){
			//printf("%d \n",prod);
			if(graph[i][parent[i]]>0){
				long long int k=graph[i][parent[i]]%747474747;
				prod*=k;
			}
			prod=prod%747474747;
		}
		printf("%lld\n", prod);
	}
    return 0;
}
