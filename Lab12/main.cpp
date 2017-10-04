#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>

using namespace std;

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *stopword = fopen("stopwords.txt", "r");
    char word[100];
    int counter = 0;
    int counter2 = 0;
    set <string> stopwords;
    map <string, int> freq;
    while (!feof(stopword)) {
        fscanf(stopword, "%s", word);
        stopwords.insert(word);
    }
    while (!feof(input)) {
        fscanf(input, "%s", word);
        if (stopwords.count(word)){
            counter2++;
            freq[word]++;
        }
    }
    fclose(input);
    fclose(stopword);
    multimap <int, string > freq_rev;
    map<string, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++) {
        freq_rev.insert(make_pair(it->second, it->first));
    }
    int count;
    multimap <int, string>::reverse_iterator myit;
    cout << counter2 << endl;
    counter = freq.size();
    cout << counter << endl;
    for (myit = freq_rev.rbegin(), count = 0; count < counter ; myit++, count++)
        cout << (*myit).second << " " << (*myit).first << "%" << ((*myit).first / (float)counter2) * 100 << endl;
    
    return EXIT_SUCCESS;
}
