# include <bits/stdc++.h>
# define ll long long
using namespace std;

int binary_search( ll a[], int beg, int end, ll x)
{
	if(beg > end)
		return -1;
	else
	{
		int mid = (beg + end)/2;
		//cout<<mid<<" ";
		if(a[mid] > x)
			return binary_search(a, beg, mid -1, x);
		else if( a[mid] < x)
			return binary_search(a, mid + 1, end, x);
		else
			return mid;
	}
}
int main()
{
	ll n, k , x, q, type;
	ll *a = new ll[n];

	cin>>n>>q;

	for(int i=0; i<n; i++)
		cin>>a[i];
	
	while(q--)
	{
		cin>>x>>k>>type;

		int index = binary_search(a, 0 ,n, x);
		if(index != -1)
		{
			if(type == 0)
			{
				if(index + k >= n)
					cout<<-1<<endl;
				else
					cout<<a[k+index]<<endl;
			}
			else
			{
				if(index - k < 0)
					cout<<-1<<endl;
				else
					cout<<a[index - k]<<endl;
			}
			//cout<<index<<endl;
		}
		else
		{
			int lower = 0;
			while(lower < n && a[lower] < x)
				lower++;
			if(type == 0)
			{
				lower--;
				if(lower + k > n)
					cout<<-1<<endl;
				else
					cout<<a[lower+k]<<endl;
			}
			else
			{
				if(lower - k < 0)
					cout<<-1<<endl;
				else
					cout<<a[lower - k]<<endl;
			}
		}
	}
}