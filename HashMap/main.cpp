#include<iostream>
#include<list>
#include<string>

using namespace std;

template<typename K, typename V>
struct Pair{
    K key;
    V value;
};

int HashFunction(string key){
    int hash = 0;
    for(char c: key){
        hash = hash * 26 + c;
    }
    return hash;
}

template<typename K, typename V>
class HashMap{
    private:
        static const int SIZE = 100;
        list<Pair<K,V>> table[SIZE];
    public:
        void Insert(K key, V value){
            int index = HashFunction(key) % SIZE;
            for (auto& pair : table[index]){
                if( pair.key == key){
                    pair.value = value;
                    return;
                }
            }
            table[index].push_back({key, value});
        }

        V Get(K key){
            int index = HashFunction(key) % SIZE;

            for(auto pair : table[index]){
                if(pair.key == key){
                    return pair.value;
                }
            }
            throw std::invalid_argument("Key not found");
        }

        void Remove(K key){
            int index = HashFunction(key) % SIZE;

            for(auto it = table[index].begin(); it != table[index].end(); it++){
                if(it->key == key){
                    table[index].erase(it);
                    return;
                }
            }

        }
};

int main(){
    HashMap<string, int> hm;
    hm.Insert("Sivaprasad", 1230);
    hm.Insert("Tamatam", 12);
    hm.Insert("Digital", 34);

    cout<<hm.Get("Sivaprasad")<<endl;
    cout<<hm.Get("Tamatam")<<endl;
    cout<<hm.Get("Digital")<<endl;

    hm.Remove("Digital");
    
    cout<<hm.Get("Sivaprasad")<<endl;
    cout<<hm.Get("Tamatam")<<endl;
    cout<<hm.Get("Digital")<<endl;

    return 0;

}