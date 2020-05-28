#include "BasicVoice.h"
#include <string>
#include <iostream>
#include <fstream>
#include "FemaleVoice.h"
#include "stdc++.h"

using namespace std;
const int MAXN = 1e2 + 5;
typedef long long ll;
int a[MAXN][MAXN];
int out[MAXN][MAXN];
int cnt1 = -1, cnt2 = 0;
int pedals = 0;
string line_1 = "";
vector<vector<int>> peds;
vector<int> tempv;
vector <string> weaving_result;


set<int> se;
int n, m;

int bdec(string n)
{
	string num = n;
	int dec_value = 0;

	int base = 1;

	int len = num.size();
	for (int i = len - 1; i >= 0; i--) {
		if (num[i] == '1')
			dec_value += base;
		base = base * 2;
	}

	return dec_value;
}

vector<int> e;
bool d = 0;
void check(int i, ll x, ll v, int cnt)
{
	if (x and x == v and cnt >= 2)
	{
		d = 1;
		return;
	}
	if (i == e.size())
		return;

	check(i + 1, x, v, cnt);
	if (e[i] != v)
		check(i + 1, x | e[i], v, cnt + 1);

}

void dec_b(int x)
{
	cnt1++;
	cnt2 = 0;
	stack<int> s;
	while (x)
	{
		s.push(x % 2);
		x /= 2;
	}
	int diff = abs(m - (int)s.size());
	while (diff--) {
		//cout << 0 << " ";
		out[cnt1][cnt2++] = 0;
	}
	while (s.size())
	{
		//cout << s.top() << ' ';
		out[cnt1][cnt2++] = s.top();
		s.pop();
	}

	cout << '\n';
}

void pedalcheck(int i) {
	cout << "Pedals to press on step " << i + 1 << ": ";
	string ss = "Pedals to press on step "+ to_string(i+1)+" : ";
	
	for (int j = 0; j <= cnt1; j++) {
		bool flag = true;
		for (int k = 0; k < m; k++) {
			if (a[i][k] != out[j][k]) {
				flag = false;
				break;
			}
		}
		if (!flag)
			continue;
		cout << j + 1;
		ss += to_string(j + 1);
		weaving_result[i] = ss;
		return;
	}
	for (int j = 0; j <= cnt1; j++) {
		bool flag = true;
		for (int k = 0; k < m; k++) {
			if (a[i][k] - out[j][k] == -1) {
				flag = false;
				break;
			}
		}
		if (!flag)
			continue;
		tempv.push_back(j + 1);
		cout << j + 1 << ' ';
		ss += to_string(j + 1); 
		ss += " ";
	}
	
	cout << i << ss << endl;
	
}

void pedalgen() {
	for (int i = 0; i < n; i++) {
		vector<int> tempv;
		pedalcheck(i);
		peds.push_back(tempv);
		cout << endl;
	}
}


int main()
{
	ofstream myfile;
	myfile.open("stepfile.txt");
	cin >> n >> m;
	weaving_result.resize
	
	(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	cout << endl << endl;

	for (int i = 0; i < n; i++)
	{
		string tmp = "";
		for (int j = 0;j < m; j++)
			tmp += (char)('0' + a[i][j]);

		se.insert(bdec(tmp));
	}


	for (auto &k : se)
		e.push_back(k);




	bool ex = 0;


	while (1)
	{
		if (ex)
			break;
		ex = 1;
		for (int i = 0; i < e.size(); i++)
		{
			d = 0;
			check(0, 0, e[i], 0);
			if (d)
			{
				e.erase(e.begin() + i);
				ex = 0;
				break;
			}
		}

	}

	for (auto &k : e)
		dec_b(k);

	cout << endl << endl;


	pedals = cnt1 + 1;
	line_1 = "There are " + to_string(pedals) + "blades needed";
	cout << line_1 << endl;
	for (int i = 0; i < pedals; i++) {
		printf("Blade tied to pedal %d: ", i + 1);
		for (int j = 0; j < cnt2;j++) {
			printf("%d ", out[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	//peds.resize(pedals);
	pedalgen();
BasicVoice* b1 = NULL;


string cc = "there are " + to_string(pedals) + " blades needed";
	b1 = new FemaleVoice;// we create a new femalevoice
	b1->setSpeech(cc);
	b1->outSpeech();
	delete b1;//after outputing that voice , we delete that object
	for (int i = 0; i < pedals; i++) {
		string ss = "Blade ties to pedal " + to_string(i + 1) + " is ";
		for (int j = 0; j < m; j++) {
			ss += to_string(out[i][j]) + " ";
		}
		b1 = new FemaleVoice;// we create a new femalevoice
		b1->setSpeech(ss);
		b1->outSpeech();
		delete b1;//after outputing that voice , we delete that object
	}
	for (int i = 0; i < weaving_result.size(); i++) {
		b1 = new FemaleVoice;// we create a new femalevoice
		b1->setSpeech(weaving_result[i]);
		b1->outSpeech();
		delete b1;//after outputing that voice , we delete that object
	}
	
	
	return 0 ;

}

/*int main()
{


	

	
}*/