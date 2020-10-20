#include <iostream>
#include <vector>

using namespace std;

template < typename T, typename V >
class LinkedHash {
private:
    T key;
    V value;
    LinkedHash* next = NULL;
public:
    LinkedHash() {
        this->value = NULL;
        this->key = NULL;
    }

    LinkedHash(T key, V value) {
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

    LinkedHash* getNext() {
        return next;
    }

    void setNext(LinkedHash* next) {
        this->next = next;
    }

    void add(T key, V value) {
        LinkedHash<T, V>* newOne1 = new LinkedHash;
        newOne1 = this->next;
        LinkedHash<T, V>* newOne = new LinkedHash(key, value);
        if (newOne1 == NULL) {
            next = newOne;
        }
        else {
            while (newOne1->next != NULL) {
                newOne1 = newOne1->next;
            }
            newOne1->next = newOne;
        }
    }

    int count() {
        LinkedHash<T, V>* current = this;
        int count = 0;
        if (this->value == NULL || this->value == -1) count--;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};

template < typename T, typename V>
int hashFunctionForNumbers(vector<LinkedHash<T, V>> table, T key) {
    T number = (sqrt(5) - 1) / 2;
    return (int)(table.size() * ((number * key) - (int)(number * key)));
}

template < typename T, typename V>
void AddForNumbers(vector<LinkedHash<T, V>>& table, T key, V value) {
    int position = hashFunctionForNumbers(table, key);
    if (table[position].getValue() == NULL || table[position].getValue() == -1) {
        table[position] = LinkedHash<T, V>(key, value);
        return;
    }
    table[position].add(key, value);
}

template < typename T, typename V>
V searchForNumbers(vector<LinkedHash<T, V>> table, T key) {
    int position = hashFunctionForNumbers(table, key);
    if (table[position].getKey() == key) {
        return table[position].getValue();
    }
    else {
        LinkedHash<T, V>* search = table[position].getNext();
        while (search->getKey() != key) {
            search = search->getNext();
        }
        return search->getValue();
    }
    return -1;
}

template < typename T, typename V>
void DeleteForNumbers(vector<LinkedHash<T, V>>& table, T key) {
    int position = hashFunctionForNumbers(table, key);
    if (table[position].getKey() == key) {
         table[position].setValue(-1); // value of deleted number will be always -1 like a returning of failed search
    }
    else {
        LinkedHash<T, V>* search = table[position].getNext();
        while (search->getKey() != key) {
            search = search->getNext();
        }
        search->setValue(-1); // same
    }
}

template < typename T, typename V>
int CountNumberOfElements(vector<LinkedHash<T, V>> table) {
    int count = 0;
    for (int i = 0; i < table.size(); i++) {
        count += table[i].count();
    }
    return count;
}

template < typename T, typename V>
vector<LinkedHash<T, V>> Rehashing(vector<LinkedHash<T, V>> table) {
    double count = CountNumberOfElements(table);
    double koeff = count / ((double)table.size());
    if (koeff >= 0.75) {
        vector<LinkedHash<double, int>> hashArray(table.size() * 2);
        for (int i = 0; i < table.size(); i++) {
            int t = table[i].count();
            if (t == 0) break;
            LinkedHash<T, V>* temp = table[i].getNext();
            AddForNumbers(hashArray, table[i].getKey(), table[i].getValue());
            t--;
            while (t != 0) {
                AddForNumbers(hashArray, temp->getKey(), temp->getValue());
                t--;
                temp = temp->getNext();
            }
            //del temp;
        }
        return hashArray;
    }
    else {
        return table;
    }
}

int main()
{
    vector<LinkedHash<double, int>> hashArray(5);
	LinkedHash<double, int> tmp(123123, 1);
    LinkedHash<double, int> tmp1(444, 12);
    LinkedHash<double, int> tmp2(12312, 15);
    LinkedHash<double, int> tmp4(123123, 1);

    AddForNumbers(hashArray, tmp.getKey(), tmp.getValue());
    AddForNumbers(hashArray, tmp1.getKey(), tmp1.getValue());
    AddForNumbers(hashArray, tmp2.getKey(), tmp2.getValue());
    AddForNumbers(hashArray, tmp4.getKey(), tmp4.getValue());
    double s = 12312;
    DeleteForNumbers(hashArray, s);
    int t = 123;
    AddForNumbers(hashArray, tmp2.getKey(), t);
    for (int i = 0; i < hashArray.size(); i++) {
        if (hashArray[i].getValue() != NULL)
            cout << hashArray[i].getValue() << " ";
        else cout << "0 ";
        if (hashArray[i].getNext() != NULL) {
            cout << "( " << hashArray[i].getNext()->getValue() << " )";
        }
    }
    cout << endl;
    //LinkedHash<double, int>* tmp3 =  hashArray[3].getNext()->getNext();
    //if (tmp3->getValue() != NULL)
    //cout << tmp3->getValue();
    cout << "Element with key 12312: " << searchForNumbers(hashArray, s) << endl;
    cout << "Number of elements in hash table: " << CountNumberOfElements(hashArray) << endl;

    vector<LinkedHash<double, int>> hashArray1 = Rehashing(hashArray);
    for (int i = 0; i < hashArray1.size(); i++) {
        if (hashArray1[i].getValue() != NULL)
            cout << hashArray1[i].getValue() << " ";
        else cout << "0 ";
        if (hashArray1[i].getNext() != NULL) {
            cout << "( " << hashArray1[i].getNext()->getValue() << " )";
        }
    }
	system("pause");
	return 0;
}