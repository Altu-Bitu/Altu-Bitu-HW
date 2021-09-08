#include <iostream>

using namespace std;

int func(int n){
    int cnt = 0;
    bool arr[26];

    for (int i = 0; i < n; i++) {
        fill_n(arr, 26, false);
        int ch = 0;

        string word;
        cin >> word;

        arr[word[0] - 'a'] = true;
        for (int j = 1; j < word.length(); j++) {
            //cout << word[j] << ' ';
            if (arr[word[j] - 'a']) {
                if (word[j - 1] != word[j]) {
                    break;
                } else
                    ch++;
            } else {
                arr[word[j] - 'a'] = true;
                ch++;
            }
        }

        if (ch == word.length() - 1)
            cnt++;

    }

    return cnt;
}

int main() {
    int N;

    cin >> N;

    int answer = func(N);

    cout << answer;

}


