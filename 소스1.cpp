#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Mobil {
	int weight;
	int num;
};

struct cmp {
	bool operator()(Mobil A, Mobil B) {
		if (A.weight > B.weight) {
			return true;
		}
		else if(A.weight == B.weight) {
			if (A.num < B.num) {
				return true;
			}
		}
		return false;
	}
};

int solution(vector<int> arr) {

	priority_queue<Mobil, vector<Mobil>, cmp> pq;

	for (auto x : arr) {
		Mobil mobil;
		mobil.weight = x;
		mobil.num = 1;
		pq.push(mobil);
	}

	Mobil first;
	Mobil second;
	int check = 0;
	int answer = 0;

	while (!pq.empty()) {
		if (check == 0) {
			first = pq.top();
			pq.pop();
			if (answer < first.num) answer = first.num;
		}
		if (pq.empty()) break;

		second = pq.top();
		pq.pop();

		cout << first.weight << " " << second.weight << endl;
		
		if (first.weight == second.weight) {
			Mobil next;
			next.weight = first.weight + second.weight;
			next.num = first.num + second.num;
			pq.push(next);
			if (answer < next.num) answer = next.num;
			check = 0;
		}
		else {
			first = second;
			check = 1;
			if (answer < first.num) answer = first.num;
		}
		
	}
	return answer;
}

int main() {
	vector<int> arr = {1,2,3,3,6};
	cout << solution(arr) << endl;
}
