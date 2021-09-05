#include <iostream>

using namespace std;

int main() {
    int N;
    int cnt = 0;
    bool arr[26];
    cin >> N;

    for (int i = 0; i < N; i++) {
        fill_n(arr, 26, false);
        int ch = 0;

        string word;
        cin >> word;

        arr[word[0] - 'a'] = true;
        for (int j = 1; j < word.length(); j++) {
            //cout << word[j] << ' ';
            if (arr[word[j] - 'a']) {
                if (word[j - 1] != word[j]) {
                    //cout << "wrong" << '\n';
                    break;
                } else
                    ch++;
            } else {
                arr[word[j] - 'a'] = true;
                //cout << "good" << '\n';
                ch++;
            }
        }

        if (ch == word.length() - 1)
            cnt++;

    }
    cout << cnt;

}


