#include <iostream>
#include <vector>

using namespace std;

template < typename T, typename V >
class Hash {
private:
    T key;
    V value;
public:
    Hash() {
        this->value = NULL;
        this->key = NULL;
    }

    Hash(T key, V value) {
        this->key = key;
        this->value = value;
    }

    T getKey() {
        return key;
    }

    V getValue() {
        return value;
    }

    void setKey(T value) {
        this->key = value;
    }

    void setValue(V value) {
        this->value = value;
    }

};

template < typename T, typename V>
vector<Hash<T, V>> Rehashing(vector<Hash<T, V>> table) {
    double count = CountNumberOfElements(table);
    double koeff = count / ((double)table.size());
    if (koeff >= 0.75) {
        vector<Hash<double, int>> hashArray(table.size() * 2);
        for (int i = 0; i < table.size(); i++) {
            AddForNumbers(hashArray, table[i].getKey(), table[i].getValue());
        }
        return hashArray;
    }
    else {
        return table;
    }
}

template < typename T, typename V>
int hashFunctionForNumbers(vector<Hash<T, V>> table, T key) {
    T number = (sqrt(5) - 1) / 2;
    return (int)(table.size() * ((number * key) - (int)(number * key)));
}

template < typename T, typename V>
void AddForNumbers(vector<Hash<T, V>>& table, T key, V value) {
    table = Rehashing(table);
    int k = 0;
    int position = hashFunctionForNumbers(table, key);
    for (int i = 0; i = (table.size() / 2) + 1; i++) {
        int p = (position + k) % table.size();
        if (table[p].getValue() == NULL || table[p].getValue() == -1) {
            table[p] = Hash<T, V>(key, value);
            return;
        }
        k += 2;
    }
}

template < typename T, typename V>
V SearchForNumbers(vector<Hash<T, V>>& table, T key) {
    int k = 0;
    int position = hashFunctionForNumbers(table, key);
    for (int i = 0; i = (table.size() / 2); i++) {
        if (table[position + k].getKey() == key) {
            return table[position + k].getValue();
        }
        k += 2;
    }
    return -1;
}

template < typename T, typename V>
void DeleteForNumbers(vector<Hash<T, V>>& table, T key, V value) {
    int k = 0;
    int position = hashFunctionForNumbers(table, key);
    for (int i = 0; i < (table.size() / 2); i++) {
        if (table[position + k].getKey() == key) {
            table[position + k].setValue(NULL);
            break;
        }
        k += 2;
    }
}

template < typename T, typename V>
void PrintHashTable(vector<Hash<T, V>> table) {
    for (int i = 0; i < table.size(); i++) {
            cout << table[i].getValue() << " ";
    }
    cout << endl;
}

template < typename T, typename V>
int CountNumberOfElements(vector<Hash<T, V>> table) {
    int count = 0;
    for (int i = 0; i < table.size(); i++) {
        if (table[i].getValue() != NULL)
            count++;
    }
    return count;
}



int main()
{
    vector<Hash<double, int>> hashArray(5);

    Hash<double, int> tmp1(11.1, 1);
    Hash<double, int> tmp2(22.2, 2);
    Hash<double, int> tmp3(33.3, 3);
    Hash<double, int> tmp4(44.4, 4);
    Hash<double, int> tmp5(55.5, 5);
    Hash<double, int> tmp6(66.6, 6);

    AddForNumbers(hashArray, tmp1.getKey(), tmp1.getValue());
    AddForNumbers(hashArray, tmp2.getKey(), tmp2.getValue());
    AddForNumbers(hashArray, tmp3.getKey(), tmp3.getValue());
    AddForNumbers(hashArray, tmp4.getKey(), tmp4.getValue());
    AddForNumbers(hashArray, tmp5.getKey(), tmp5.getValue());
    AddForNumbers(hashArray, tmp6.getKey(), tmp6.getValue());


    PrintHashTable(hashArray);

    DeleteForNumbers(hashArray, tmp4.getKey(), tmp4.getValue());

    cout << "Table after deleting" << endl;

    PrintHashTable(hashArray);
    
    double key = 55.5;
    cout << "Searching for element with key " << key << " : " << SearchForNumbers(hashArray, key) << endl;
    

    system("pause");
    return 0;
}