//TC: O(row*col)
//SC: O(ro*col)
#include<bits/stdc++.h>
using namespace std;

class disjoin{
	vector<int> parent,rank;
	int n;
    public:
	disjoin(int data)
	{
		n=data;
		for(int i=0;i<n;i++)
		{
			parent.push_back(i);
			rank.push_back(0);
		}
	}
	int find(int a)
	{
		if(parent[a]!=a) parent[a]=find(parent[a]);
		return parent[a];
	}
	void Union(int a,int b)
	{
		int xval=find(a);
		int yval=find(b);
        
        if(xval==yval) return;
        if(rank[xval]>rank[yval]) parent[yval]=xval;
        else if(rank[xval]<rank[yval]) parent[xval]=yval;
        else{
        	parent[yval]=xval;
        	rank[xval]+=1;
        }
	}
};
int f(vector<vector<int>> a)
{
    int count=0;
	int row=a.size();
	int col=a[0].size();
	int n=row;
	int m=col;
    int totalsize =row*col;
    disjoin d(totalsize);
    vector<int>frequency(totalsize,0);

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(a[i][j]==0) continue;
			
		
			
			for(int delrow=-1;delrow<=1;delrow++)
			{
				for(int delcol=-1;delcol<=1;delcol++)
				{
					int newrow=delrow+i;
					int newcol=delcol+j;
			
					
					if(newcol>=0 && newcol<col && newrow>=0 && newrow<row && a[newrow][newcol]==1) {
						d.Union(i*col+j,newrow*col+newcol);

					}

				}
			}
			
		}
	}
    
    
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(a[i][j]==1)
			{
				int x=d.find(i*col+j);
				
				if(frequency[x]==0)
				{
					count++;
					frequency[x]++;
				}
			
			}
		}
	}
	return count;
}
int main()
{

	vector<vector<int>> a={ { 1, 1, 0, 0, 0 },
                            { 0, 1, 0, 0, 1 },
                            { 1, 0, 0, 1, 1 },
                             { 0, 0, 0, 0, 0 },
                             { 1, 0, 1, 0, 1 }};

    
    cout<<"Number od islands is:"<<f(a);
	return 0;
}
