#include <iostream> 
#include <vector> 

using std::vector;
using std::cout;
using std::cin;

void print_prefs(vector<vector<int> >& prefs, int n) {
     for (auto i = prefs.begin() ; i<prefs.end() ; i++) {
        for (auto j = i->begin() ; j<i->end() ; j++)
            cout << *j <<" ";
        cout <<"\n";  
        //similarly you can do other things
    }
}

vector<vector<int> > read_men_prefs(int n) {
    vector<vector<int> > mat; 
    for (int i = 0; i < n; ++i) {
        int idx;
        cin >> idx; //vill göra någon slags skip här ist
        vector<int> vec;
        for (int j = 0; j < n; ++j) {
            int pref; 
            cin >> pref; 
            vec.push_back(pref);
        }
        mat.push_back(vec);
    }
    return mat; 
}

vector<vector<int> > read_women_prefs(int n) {
    vector<vector<int> > mat; 
    for (int i = 0; i < n; ++i) {
        int idx;
        cin >> idx; //vill göra någon slags skip här ist
        vector<int> vec(n);
        for (int j = 1; j <= n; ++j) {
            int pref; 
            cin >> pref; 
            vec.at(pref-1) = j; 
        }
        mat.push_back(vec);
    }
    return mat; 
}

void read_prefs(vector<vector<int> >& men, vector<vector<int> >& women) {
    int n; 
    cin >> n; 
    vector<vector<int> > m(n, vector<int>(n));
    vector<vector<int> > w(n, vector<int>(n));
    for (int i = 0; i < 2*n; ++i) {
        int id;
        cin >> id; 
        // cout << m[id];
        break;
    }
}

int main() {
    int n;
    cin >> n;
    cout << n << "\n"; 
    vector<vector<int> > test(n, vector<int>(n));
    vector<vector<int> > test2(n);

    print_prefs(test, n);
    test2[0].push_back(1);
    cout << test2[2].empty() << "\n";

    // auto men = read_men_prefs(n);
    // print_prefs(men, n);
    // auto women = read_women_prefs(n);
    // print_prefs(women, n);
}