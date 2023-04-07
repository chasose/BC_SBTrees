#include <map>

template <typename Key, typename Data>
class Map
{
public:
    using key_type = Key;
    Map() : map_() {}
    ~Map() {}

    void insert(Key key, Data data)
    {
        map_.insert(std::make_pair(key, data));
    }

    std::pair<const Key, Data>* find(Key key)
    {
        auto it = map_.find(key);
        if (it != map_.end()) {
            return &(*it);
        }
        else {
            return nullptr;
        }
    }

    void remove(Key key)
    {
        auto it = map_.find(key);
        if (it != map_.end()) {
            map_.erase(it);
        }
    }

    void clear()
    {
        map_.clear();
    }

private:
    std::map<Key, Data> map_;
};