#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Struct {
    int string_num;
    int first_element;
    vector<pair<int, int>> arr; //column_num, value
};


bool cmp(Struct a, Struct b) {
    return a.first_element < b.first_element;
}


void add(vector<Struct>& arr, int i, int j, int value) {
    if (value == 0)
        return;
    for (int k = 0; k < arr.size(); k++) {
        if (arr[k].string_num == i) {
            for (int l = 0; l < arr[k].arr.size(); l++) {
                if (arr[k].arr[l].first == j) {
                    arr[k].arr[l].second = value;
                    return;
                }
            }
            arr[k].arr.push_back({ j, value });
            return;
        }

    }
    arr.push_back({ i, value, {{j, value}} });

}


void output(vector<Struct>& arr, int n, int m) {
    int prev = 0;
    int prev1;
    for (int k = 0; k < arr.size(); k++) {
        while (prev < arr[k].string_num) {
            for (int h = 0; h < m; h++)
                cout << "0 ";
            cout << "\n";
            prev++;
        }
        prev1 = 0;
        for (int i = 0; i < arr[k].arr.size(); i++) {
            while (prev1 < arr[k].arr[i].first) {
                cout << "0 ";
                prev1++;
            }
            cout << arr[k].arr[i].second << " ";
            prev1++;
        }
        while (prev1 < m) {
            cout << "0 ";
            prev1++;
        }
        cout << "\n";
        prev++;
    }
    for (int g = prev; g < n; g++) {
        for (int h = 0; h < m; h++)
            cout << "0 ";
        cout << "\n";
    }
}

void str(vector<Struct>& arr) {
    vector<int> temp(arr.size());
    for (int k = 0; k < arr.size(); k++) {
        temp[k] = arr[k].string_num;

    }
    sort(arr.begin(), arr.end(), cmp);
    for (int k = 0; k < arr.size(); k++) {
        arr[k].string_num = temp[k];

    }
}


int main() {
    vector<Struct> arr;
    cout << "Enter number of lines: --> ";
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter number of coloumns: --> ";
        cin >> m;
        for (int j = 0; j < m; j++) {
            int c;
            cin >> c;
            add(arr, i, j, c);
        }

    }
    str(arr);
    output(arr, n, m);
    return 0;
}
