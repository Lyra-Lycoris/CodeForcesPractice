#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

inline void optimize()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main()
{
	optimize();

	int _;
	cin >> _;
	while (_--)
	{

		ll n;
		cin >> n;
		vector<ll> a(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}

		vector<ll> s1(n + 1), s2(n + 1);

		for (int i = 1; i <= n; i++)
		{
			s1[i] = s1[i - 1] + (a[i] == 1 ? 1 : -1);
			s2[i] = s2[i - 1] + (a[i] <= 2 ? 1 : -1);
		}

		vector<ll> matMax(n + 1); // s2的后缀最大值
		matMax[n] = LLONG_MIN;
		for (ll i = n - 1; i >= 1; i--)
		{
			matMax[i] = max(s2[i], matMax[i + 1]);
		}
		bool ok = false;
		for (int i = 1; i <= n; i++)
		{
			if (s1[i] < 0)
			{
				continue;
			}
			if (i < n && matMax[i + 1] >= s2[i])
			{
				// 产生合法区间
				ok = true;
				break;
			}
		}

		cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}