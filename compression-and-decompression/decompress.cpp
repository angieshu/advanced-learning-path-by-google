#include <iostream>
#include <ctype.h>

using namespace std;

class Decompress {
public:
	string decompress(string s) {
		if (s == "") {
			return "";
		}

		int ind = 0;
		string res = "";

		while (s[ind]) {
			res += this->readString(s, ind);
			ind++;
		}
		return res;
	}

	string readString(string s, int& ind) {
		int times = 0;
		string str = "";
		string to_print = "";
		bool open = false;

		while (s[ind] != ']') {
			if (isdigit(s[ind]) && !open) {
				times = times * 10 + (s[ind] - '0');
			} else if (isdigit(s[ind]) && open) {
				str += this->readString(s, ind);
			} else if (s[ind] == '[') {
				open = true;
			} else {
				str += s[ind];
			}
			ind++;
		}
		while (times--) {
			to_print += str;
		}
		while (s[ind + 1] && s[ind + 1] >= 'a' && s[ind + 1] <= 'z') {
			to_print += s[ind + 1];
			ind++;
		}
		return to_print;
	}
};


int main() {
	string s0 = "3[abc]4[ab]c";
	string s1 = "10[a]";
	string s2 = "2[3[ac]3[g]]";
	string s3 = "2[3[ac]k]";
	Decompress res;

	cout << "s0: " << res.decompress(s0) << endl;
	cout << "s1: " << res.decompress(s1) << endl;
	cout << "s2: " << res.decompress(s2) << endl;
	cout << "s3: " << res.decompress(s3) << endl;

}
