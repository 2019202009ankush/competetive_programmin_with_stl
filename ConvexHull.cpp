#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x,y;
};
bool tochange(Point p,Point q,Point r)
{
	int x1 =  q.x - p.x;
	int y1= q.y-p.y;
	int x2 = r.x - q.x;
	int y2 = r.y - q.y;
	int value = x1*y2 - y1*x2;
	return value>0;
}
void convexhull(Point points[] ,int n)
{
	vector<Point> hull;
	int left =0;
	for(int i=1;i<n;i++)
	{
		if(points[i].x<points[left].x)
		{
			left = i;
		}
	}
	int p=left;
	do{
		hull.push_back(points[p]);
	   int q = (p+1)%n;
	   for(int i=0;i<n;i++)
	   {
	   	 if(tochange(points[p],points[q],points[i]))
	   	 {
	   	 	q=i;
	   	 	
	   	 }
	   }
	   p=q;
	   
	}while(p!=left);
	for(auto c:hull)
	{
		cout<<c.x<<" "<<c.y<<endl;
	}
}
int main()
{
	Point points[7]={ {0,4} ,{1,1} ,{2,2} , {4,4} , {4,0} , {0,0} , {3,3}};
	convexhull(points,7);
	
}
