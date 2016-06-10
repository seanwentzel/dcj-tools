#include<bits/stdc++.h>
#include "message.h"
#include COMPLETEME
#define mp make_pair
#define pb push_back
#define f(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define fiter(it,con) for(auto (it)=(con).begin(); (it)!=(con).end();++(it))
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef int id;

int maxsz = 5*1024*1024;
int llsz = 8;

void sendVectorChunk(id to, vll& foo) {
	PutInt(to,(int)foo.size());
	fiter(it,foo) {
		PutLL(to,*it);
	}
	Send(to);
}

void sendVector(id to, vll& foo) {
	int chunkSize = maxsz/llsz;
	vector<vll> chunks;
	vll currChunk;
	fiter(it, foo) {
		if(chunkSize == (int)currChunk.size()) {
			chunks.pb(currChunk);
			currChunk = vll();
		}
		currChunk.pb(*it);
	}
	if(currChunk.size() > 0) {
		chunks.pb(currChunk);
	}
	PutInt(to,(int)chunks.size());
	Send(to);
	fiter(chunk, chunks) {
		sendVectorChunk(to,*chunk);
	}
}

vll receiveVector(id from) {
	Receive(from);
	int numMsgs = GetInt(from);
	vll ans;
	f(i,0,numMsgs) {
		Receive(from);
		int msgSz = GetInt(from);
		f(j,0,msgSz) {
			ans.pb(GetLL(from));
		}
	}
	return ans;
}

void solve(id nodes, id me) {
	if(me==0) {
		//output
	}
}

int main() {
	id nodes = NumberOfNodes();
	id me = MyNodeId();
	solve(nodes, me);
	return 0;
}
